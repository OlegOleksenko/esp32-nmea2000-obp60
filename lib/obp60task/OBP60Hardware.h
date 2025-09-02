    // General hardware definitions
    // CAN and RS485 bus pin definitions see obp60task.h

#ifdef HARDWARE_V21
    // Direction pin for RS485 NMEA0183
    #define OBP_DIRECTION_PIN 8
    // I2C
    #define I2C_SPEED 10000UL       // 10kHz clock speed on I2C bus
    #define OBP_I2C_SDA 47
    #define OBP_I2C_SCL 21
    // DS1388 RTC
    #define DS1388_I2C_ADDR 0x68    // Addr. 0x68
    // BME280
    #define BME280_I2C_ADDR 0x76    // Addr. 0x76 (0x77)
    // BMP280
    #define BMP280_I2C_ADDR 0x77    // Addr. 0x77 (0x76) Attention: Pull up resistor
    // BMP085 / BMP180
    #define BMP180_I2C_ADDR 0x77    // Addr. 0x77 (fix)
    // SHT21 / HUT21
    #define SHT21_I2C_ADDR 0x40     // Addr. 0x40 (fix)
    // AS5600
    #define AS5600_I2C_ADDR 0x36    // Addr. 0x36 (fix)
    // INA219
    #define SHUNT_VOLTAGE 0.075     // Shunt voltage in V by max. current (75mV)
    #define INA219_I2C_ADDR1 0x40   // Addr. 0x41 (fix A0 = 5V, A1 = GND) for battery
    #define INA219_I2C_ADDR2 0x41   // Addr. 0x44 (fix A0 = GND, A1 = 5V) for solar panels
    #define INA219_I2C_ADDR3 0x45   // Addr. 0x45 (fix A0 = 5V, A1 = 5V) for generator
    // INA226
    #define INA226_I2C_ADDR1 0x41   // Addr. 0x41 (fix A0 = 5V, A1 = GND) for battery
    #define INA226_I2C_ADDR2 0x44   // Addr. 0x44 (fix A0 = GND, A1 = 5V) for solar panels
    #define INA226_I2C_ADDR3 0x45   // Addr. 0x45 (fix A0 = 5V, A1 = 5V) for generator
    // Horter modules
    #define PCF8574_I2C_ADDR1 0x20  // First digital out module
    // FRAM (e.g. MB85RC256V)
    #define FRAM_I2C_ADDR 0x50
    // SPI (E-Ink display, Extern Bus)
    #define OBP_SPI_CS 1
    #define OBP_SPI_DC 2
    #define OBP_SPI_RST 42
    #define OBP_SPI_BUSY 41
    #define OBP_SPI_CLK 40
    #define OBP_SPI_DIN 39
    #define SHOW_TIME 6000        // Show time in [ms] for logo and WiFi QR code
    #define FULL_REFRESH_TIME 600 // Refresh cycle time in [s][600...3600] for full display update (very important healcy function)

    // GPS (NEO-6M, NEO-M8N, ATGM336H)
    #define OBP_GPS_RX 7
    #define OBP_GPS_TX 3
    // 1Wire (DS18B20)
    #define OBP_1WIRE 17         // External 1Wire
    // Buzzer
    #define OBP_BUZZER 18
    #define TONE1 1500          // 1500Hz
    #define TONE2 2500          // 2500Hz
    #define TONE3 3500          // 3500Hz
    #define TONE4 4000          // 4000Hz
    // Analog Input
    #define OBP_ANALOG0    6    // Analog input for voltage power supply
    #define MIN_VOLTAGE 10.0    // Min voltage for under voltage detection (then goto deep sleep)
    #define POWER_FAIL_TIME 2   // in [ms] Accept min voltage until 2 x 1ms (for under voltage gaps by engine start)
    // Touch buttons
    #define TP1 46              // Left outside
    #define TP2 45
    #define TP3 10
    #define TP4 11
    #define TP5 12
    #define TP6 13               // Right outside

    // Flash LED (1x WS2812B)
    #define NUM_FLASH_LED 1         // Number of flash LED
    #define OBP_FLASH_LED 48         // GPIO port
    // Backlight LEDs (6x WS2812B)
    #define NUM_BACKLIGHT_LED 6     // Number of Backlight LEDs
    #define OBP_BACKLIGHT_LED 48    // GPIO port
    // Power Rail
    #define OBP_POWER_50 48          // 5.0V power rail
#endif

// Hardware configuration for OBP40

#ifdef BOARD_OBP40S3
    // Direction pin for RS485 NMEA0183
    #define OBP_DIRECTION_PIN 8
    // I2C
    #define I2C_SPEED 100000UL       // 100kHz clock speed on I2C bus
    #define OBP_I2C_SDA 21
    #define OBP_I2C_SCL 47
    // DS1388 RTC
    #define DS1388_I2C_ADDR 0x68    // Addr. 0x68
    // BME280
    #define BME280_I2C_ADDR 0x76    // Addr. 0x76 (0x77)
    // BMP280
    #define BMP280_I2C_ADDR 0x77    // Addr. 0x77 (0x76) Attention: Pull up resistor
    // BMP085 / BMP180
    #define BMP180_I2C_ADDR 0x77    // Addr. 0x77 (fix)
    // SHT21 / HUT21
    #define SHT21_I2C_ADDR 0x40     // Addr. 0x40 (fix)
    // AS5600
    #define AS5600_I2C_ADDR 0x36    // Addr. 0x36 (fix)
    // INA219
    #define SHUNT_VOLTAGE 0.075     // Shunt voltage in V by max. current (75mV)
    #define INA219_I2C_ADDR1 0x40   // Addr. 0x41 (fix A0 = 5V, A1 = GND) for battery
    #define INA219_I2C_ADDR2 0x41   // Addr. 0x44 (fix A0 = GND, A1 = 5V) for solar panels
    #define INA219_I2C_ADDR3 0x45   // Addr. 0x45 (fix A0 = 5V, A1 = 5V) for generator
    // INA226
    #define INA226_I2C_ADDR1 0x41   // Addr. 0x41 (fix A0 = 5V, A1 = GND) for battery
    #define INA226_I2C_ADDR2 0x44   // Addr. 0x44 (fix A0 = GND, A1 = 5V) for solar panels
    #define INA226_I2C_ADDR3 0x45   // Addr. 0x45 (fix A0 = 5V, A1 = 5V) for generator
    // Horter modules
    #define PCF8574_I2C_ADDR1 0x20  // First digital out module
    // FRAM (e.g. MB85RC256V)
    #define FRAM_I2C_ADDR 0x50
    // SPI (E-Ink display, Extern Bus)
    #define OBP_SPI_CS 1        //CS
    #define OBP_SPI_DC 2        //D/C
    #define OBP_SPI_RST 42      //RES
    #define OBP_SPI_BUSY 41     //BUSY
    #define OBP_SPI_CLK 40      //SCL
    #define OBP_SPI_DIN 39      //SDA
    #define SHOW_TIME 6000        // Show time in [ms] for logo and WiFi QR code
    #define FULL_REFRESH_TIME 600 // Refresh cycle time in [s][600...3600] for full display update (very important healcy function)
    // SPI SD-Card
    #define SD_SPI_CS GPIO_NUM_38
    #define SD_SPI_MOSI GPIO_NUM_37
    #define SD_SPI_CLK GPIO_NUM_36
    #define SD_SPI_MISO GPIO_NUM_35

    // GPS (NEO-6M, NEO-M8N, ATGM336H)
    #define OBP_GPS_RX 7
    #define OBP_GPS_TX 3
    // 1Wire (DS18B20)
    #define OBP_1WIRE 17        // External 1Wire
    // Buzzer
    #define OBP_BUZZER 18
    #define TONE1 1500          // 1500Hz
    #define TONE2 2500          // 2500Hz
    #define TONE3 3500          // 3500Hz
    #define TONE4 4000          // 4000Hz
    // Analog Input
    #define OBP_ANALOG0 6       // Analog input for voltage power supply
    #define MIN_VOLTAGE 10.0    // Min voltage for under voltage detection (then goto deep sleep)
    #define POWER_FAIL_TIME 2   // in [ms] Accept min voltage until 2 x 1ms (for under voltage gaps by engine start)
    // Buttons
    #define UP 46                // Wheel up
    #define DOWN 10              // Wheel down
    #define CONF 11              // Wheel press
    #define MENUE 12             // Button top
    #define EXIT 13              // Button bottom

    // Flash LED (1x WS2812B)
    #define NUM_FLASH_LED 1         // Number of flash LED
    #define OBP_FLASH_LED 48        // GPIO port (power LED)
    // Backlight LEDs (6x WS2812B)
    #define NUM_BACKLIGHT_LED 6     // Number of Backlight LEDs
    #define OBP_BACKLIGHT_LED 48    // GPIO port (power LED)
    // Power Rail
    #define OBP_POWER_50 48         // Power LED
    #define OBP_POWER_EPD 4         // ePaper power
    #define OBP_POWER_SD 5         // SD card power
    // Deep sleep wakeup
    #define OBP_WAKEUP_LEVEL 0      // //1 = High, 0 = Low, depends on switch
    #define OBP_WAKEWUP_PIN GPIO_NUM_11// Wakeup pin, same as CONF (wheel press)
                                      // Must define as GPIO_NUM_X
#endif

