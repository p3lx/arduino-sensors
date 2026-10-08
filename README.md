## ARDUINO IDE AND LIBRARY INSTALLATION
For the Arduino Uno CO2, temperature, pressure and humidity meter

### STEP 1: DOWNLOAD AND INSTALL ARDUINO IDE

1. Visit the official Arduino software page:
   https://www.arduino.cc/en/software/

2. Download the latest stable Arduino IDE 2 for your operating system.

3. Install the application:
 - Windows:
   * Open the downloaded .exe file.
   * Follow the instruction in the installer.
 - macOS:
   * Open the downloaded .dmg file and drag Arduino IDE into the
     Applications folder.
 - Linux:
   * Download the AppImage.
   * Open its file properties and enable "Allow executing file as program".
   * Then open the AppImage.
   * (There's also an *unofficial* flatpak version of the IDE on flathub. It might work for you.)

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

 - Library: Adafruit BME280 Library
    * Author: Adafruit
    * Purpose: Reads temperature, atmospheric pressure and relative humidity.

 - Library: Adafruit Unified Sensor
    * Author: Adafruit
    * Purpose: Dependency used by the BME280 library.
    * (*Dependency of Adafruit BME280 Library*)

 - Library: Adafruit BusIO
    * Author: Adafruit
    * Purpose: Communication support used by the sensor library.
    * (*Dependency of Adafruit BME280 Library*)

 - Library: SD
    * Author: Arduino
    * Purpose: Saves measurements to the SD card.

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

## WIRING
The wiring between the Arduino and the two modules is laid out in these tables.

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

For an example layout with bread board, there's a [diagram](diagram.png).

## RUNNING CODE
With the Arduino IDE up and running, the Arduino connected, and the required libraries installed:
 - Clone [this repository](.) to your PC.
 - First on the top-left of the Arduino IDE, select *File*, in the drop-down menu select *Open...*, then navigate to the included source code from this repository. Inside the [*sd-erase*](./sd-erase) folder, open the [*sd-erase.ino*](./sd-erase/sd-erase.ino) source file.
 - Upload this source file to the Arduino from the IDE's *Upload* (->) button. It should now start to run.
 - Once this has erased the SD card, you can start the measurement by uploading [*p-t-rh.ino*](./p-t-rh/p-t-rh.ino) to the Arduino.
 - Measurements should now show up in the [Serial Monitor tool](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-monitor/) if you open it. They will also be written to the SD card.
 - Now that he measuring code is uploaded, you can also unplug the Arduino form your computer and hook it up to a battery / DC power supply and leave it to record measurements to the SD card.
 - To extract the data from the SD card, you can use the [*sd-extract.ino*](./sd-extract/sd-extract.ino) source file to print the contents of the data file into the serial console.
 - After running [*sd-extract.ino*](./sd-extract/sd-extract.ino), the measurements (including time-stamps) should end up in the serial console.
 - You can now copy that data from the console to a separate file on your computer and process it however you like.
 - You can also open the Arduino IDE's built-in [Serial Plotter Tool](https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-plotter/) to display the data.

## TROUBLESHOOTING
 - If you'r on linux and are receiving the error: `OS error: cannot open port /dev/ttyACM0: Permission denied`:
   * Run `ls -l /dev/ttyACM0` to view which group has the required permission.
   * Add your user to this group with `sudo usermod -aG dialout "$USER"`. (Were `dialout` is the name of the user group.)
   * Sign out and back in or reboot.


## THE EXPERIMENT
Assuming up to date with the above instructions, the experiment proceeds as follows. 
 - In the lab Ortsteijn in the Minnaert building, configure the device on a table and run the code. 
 - After one minute, stop the code from your computer. 
 - It may be that the power bank cuts off, in that case try again untill it reaches a minute. We assume Adruino device does not draw enough power. 
 - Read the SD card using the code appended in the GitHub repo.  
