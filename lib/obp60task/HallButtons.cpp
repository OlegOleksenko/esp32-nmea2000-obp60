#include "HallButtons.h"

HallButtons* HallButtons::instance = nullptr;

HallButtons::HallButtons(const int *pins, int numButtons, int threshold, float adaptRate, float filterAlpha) {
  static_assert(MAX_BUTTONS <= 16, "MAX_BUTTONS should be <= 16 (mask is uint16_t)");
  if(numButtons > MAX_BUTTONS){
    Serial.println("Error: numButtons exceeds MAX_BUTTONS!");
    abort();
  }

  _pins = pins;
  _numButtons = numButtons;
  _threshold = threshold;
  _adaptRate = adaptRate;
  _filterAlpha = filterAlpha;

  for(int i = 0; i < MAX_BUTTONS; i++){
    _baseline[i] = 0;
    _filtered[i] = 0;
    _buttonState[i] = false;
    _pressStart[i] = 0;
  }
}

void HallButtons::begin(){
  Serial.println("Calibrating DRV5053 buttons...");
  for(int i = 0; i < _numButtons; i++) {
    // ADC calibration
    adcAttachPin(_pins[i]);
    analogReadResolution(12); // 12-bit precision
    long sum = 0;
    for(int j = 0; j < 200; j++){
      sum += analogRead(_pins[i]);
      delay(2);
    }
    _baseline[i] = sum / 200.0f;
    _filtered[i] = _baseline[i];
    Serial.printf("Button %d baseline: %.1f\n", i, _baseline[i]);
  }

  instance = this;
  xTaskCreate(readTask, "HallButtonTask", 4096, nullptr, 1, nullptr);
}

bool HallButtons::isPressed(int index){
  if(index < 0 || index >= _numButtons){
    return false;
  }
  return _buttonState[index];
}

void HallButtons::setPressCallback(ButtonCallback cb){
  pressCallback = cb;
}
void HallButtons::setReleaseCallback(ButtonCallback cb){
  releaseCallback = cb;
}
void HallButtons::setShortPressCallback(ButtonCallback cb){
  shortPressCallback = cb;
}
void HallButtons::setLongPressCallback(ButtonCallback cb){
  longPressCallback = cb;
}
void HallButtons::setCombinationCallback(CombinationCallback cb, uint16_t mask){
  combinationCallback = cb;
  combinationMask = mask;
}

void HallButtons::readTask(void *pvParameters){
  while(true){
    if(instance){
      instance->readButtons();
      vTaskDelay(pdMS_TO_TICKS(10)); // 100 Hz polling
    }
  }
}

void HallButtons::readButtons(){
  uint16_t currentMask = 0;
  unsigned long now = millis();

  for(int i = 0; i < _numButtons; i++){
    int raw =analogRead(_pins[i]);

    // Exponential Smoothing (EMA)
    _filtered[i] = _filterAlpha * raw + (1 - _filterAlpha) * _filtered[i];

    float diff = _filtered[i] - _baseline[i];

    if(abs(diff) > _threshold){
      currentMask |= (1 << i);

      if(!_buttonState[i]){
        _buttonState[i] = true;
        _pressStart[i] = now;
        if(pressCallback){
          pressCallback(i);
        }
      } else {
        if(now - _pressStart[i] >= LONG_PRESS_TIME && longPressCallback){
          longPressCallback(i);
          _pressStart[i] = now + 100000; // block repeated long presses
        }
      }
    } else {
      if(_buttonState[i]){
        _buttonState[i] = false;
        unsigned long duration = now - _pressStart[i];
        if(releaseCallback){
          releaseCallback(i);
        }
        if(duration < LONG_PRESS_TIME && shortPressCallback){
          shortPressCallback(i);
        }
      }
      // Adaptive base
      _baseline[i] += diff * _adaptRate;
    }
  }

  // Combination detection
  if(combinationCallback && (currentMask & combinationMask) == combinationMask){
    combinationCallback(currentMask);
  }
}
/*
Використання (main.cpp)
#include <Arduino.h>
#include "HallButtons.h"

const int pins[6] = {1, 2, 3, 4, 5, 6}; // приклад пінів ADC
HallButtons buttons(pins, 6, 80, 0.005, 0.2);

void onPress(int idx) { Serial.printf("Button %d PRESS\n", idx); }
void onRelease(int idx) { Serial.printf("Button %d RELEASE\n", idx); }
void onShort(int idx) { Serial.printf("Button %d SHORT\n", idx); }
void onLong(int idx) { Serial.printf("Button %d LONG\n", idx); }
void onCombo(uint16_t mask) { Serial.printf("Combo detected mask: 0x%X\n", mask); }

void setup() {
    Serial.begin(115200);
    buttons.begin();
    buttons.setPressCallback(onPress);
    buttons.setReleaseCallback(onRelease);
    buttons.setShortPressCallback(onShort);
    buttons.setLongPressCallback(onLong);
    buttons.setCombinationCallback(onCombo, (1<<0) | (1<<2)); // кнопки 0+2
}

void loop() {
    delay(100);
}

*/