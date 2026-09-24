## ARDUINO IDE AND LIBRARY INSTALLATION
For the Arduino Uno CO2, temperature, pressure and humidity meter

### STEP 1: DOWNLOAD AND INSTALL ARDUINO IDE

1. Visit the official Arduino software page:
   https://www.arduino.cc/en/software/

2. Download the latest stable Arduino IDE 2 for your operating system.

3. Install the application:
   - Windows: open the downloaded .exe file and follow the installer.
   - macOS: open the downloaded .dmg file and drag Arduino IDE into the
     Applications folder.
   - Linux: download the AppImage, open its file properties and enable
     "Allow executing file as program", then open the AppImage.

4. Launch Arduino IDE. Keep your computer connected to the internet for
   the board package and library installations below.

Official installation instructions:
https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE


### STEP 2: INSTALL SUPPORT FOR THE ARDUINO UNO

1. Open Tools > Board > Boards Manager in Arduino IDE.

2. Search for:
   Arduino AVR Boards

3. Select the package published by Arduino and click Install.
   If it is already installed, you can continue.

4. Select:
   Tools > Board > Arduino AVR Boards > Arduino Uno

This is the board selection for the classic Uno R3 (ATmega328P).


### STEP 3: INSTALL THE REQUIRED LIBRARIES

1. Open Tools > Manage Libraries.

2. Search for and install each of the following libraries:

   Library: Adafruit BME280 Library
   Author: Adafruit
   Purpose: Reads temperature, atmospheric pressure and relative humidity.

   Library: Adafruit Unified Sensor
   Author: Adafruit
   Purpose: Dependency used by the BME280 library.

   Library: Adafruit BusIO
   Author: Adafruit
   Purpose: Communication support used by the sensor library.

   Library: SD
   Author: Arduino
   Purpose: Saves measurements to the SD card.

3. If the BME280 installation asks whether to install dependencies,
   choose Install All. Afterwards, check that all four libraries above
   show as installed.

4. Wire and SPI are supplied with the Arduino AVR board package.
   You do not need to download them separately.

NOTE: Install the SD library even if you initially test without an SD
module. The supplied meter sketch includes SD.h even when ENABLE_SD is 0.

Official Arduino library installation instructions:
https://support.arduino.cc/hc/en-us/articles/5145457742236-Install-libraries-in-the-Arduino-IDE

Official Adafruit BME280 Arduino setup instructions:
https://learn.adafruit.com/adafruit-bme280-humidity-barometric-pressure-temperature-sensor-breakout/arduino-test

### STEP 4: WIRING

| MicroSD Card Adapter | Arduino UNO |
| :------------------: | :---------: |
| CS                   |         ~10 |
| SCK                  |          13 |
| MOSI                 |         ~11 |
| MISO                 |          12 |
| VCC                  |          5V |
| GND                  |         GND |

| BME/BMP280 | Arduino UNO        |
| :--------: | :----------------: |
| VIN        |                 5V |
| GND        |                GND |
| SCL        | SCL (2 above AREF) |
| SDA        | SDA (1 above AREF) |        


