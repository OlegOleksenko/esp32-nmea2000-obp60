#pragma  once

#include <Arduino.h>
#include "driver/adc.h"

#define LONG_PRESS_TIME 1000

class HallButtons {
public:
  typedef void (*ButtonCallback)(int index);
  typedef void (*CombinationCallback)(uint16_t mask);

  HallButtons(const int *pins, int numButtons, int treshhold = 80, float adaptRate = 0.005, float filterAlpha = 0.02);

  void begin();

  void setPressCallback(ButtonCallback cb);
  void setReleaseCallback(ButtonCallback cb);
  void setShortPressCallback(ButtonCallback cb);
  void setLongPressCallback(ButtonCallback cb);
  void setCombinationCallback(CombinationCallback cb, uint16_t mask);

  bool isPressed(int index);

private:
  static void readTask(void *pvParameters);
  void readButtons();

  const int *_pins;
  int _numButtons;
  int _threshold;
  float _adaptRate;
  float _filterAlpha;

  float *_baseline;
  float *_filtered;
  float *_buttonState;
  unsigned long *_pressStart;

  ButtonCallback pressCallback = nullptr;
  ButtonCallback releaseCallback = nullptr;
  ButtonCallback shortPressCallback = nullptr;
  ButtonCallback longPressCallback = nullptr;
  CombinationCallback combinationCallback = nullptr;
  uint16_t combinationMask = 0;

  static HallButtons *instance;
};