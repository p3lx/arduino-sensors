#include <SPI.h>
#include <SD.h>
#include <Adafruit_BME280.h>

const int chipSelect = 10;
const int statusLed = 13;

const int time_step = 10000;

Adafruit_BME280 bme;
float lastT, lastP, lastH;

File myFile;
unsigned long lastLogTime = 0;
int lineCounter = 1;

void setup() {
  Serial.begin(9600);

  pinMode(statusLed, OUTPUT);
  Serial.println(F("--- SYSTEM STARTUP ---"));

  Serial.print(F("Initializing SD card... "));
  if (!SD.begin(chipSelect)) {
    Serial.println(F("FAILED!"));
    while (1)
      ;
  }

  Serial.println(F("SUCCESS!"));
  if (!SD.exists("data.csv")) {
    myFile = SD.open("data.csv", FILE_WRITE);
    if (myFile) {
      myFile.println(F("Time (seconds),Temperature (C),Pressure (Pa),Humidity (%)"));
      myFile.close();
      Serial.println(F("Created new data.csv file."));
    }
  } else {
    Serial.println(F("Found existing data.csv file."));
  }

  Serial.print(F("Initializing BME280 sensor... "));
  int status = bme.begin(0x76);
  if (!status) {
    Serial.println(F("FAILED! Check wiring. Freezing system."));
    while (1)
      ;
  }
  Serial.println(F("SUCCESS!"));

  Serial.println(F("Ready! Starting loop...\n"));
}

void loop() {
  if (millis() - lastLogTime >= time_step) {
    lastLogTime = millis();
    Serial.print(F("[Loop] Requesting BME280 data... "));

    lastT = bme.readTemperature();
    lastP = bme.readPressure();
    lastH = bme.readHumidity();

    int secondsPassed = lineCounter * (time_step / 1000);

    Serial.print(F("T: ")); Serial.print(lastT); Serial.print(F(" C | "));
    Serial.print(F("P: ")); Serial.print(lastP); Serial.print(F(" Pa | "));
    Serial.print(F("H: ")); Serial.print(lastH); Serial.print(F(" % | Writing to SD...\n"));

  myFile = SD.open("data.csv", FILE_WRITE);
  if (myFile) {
    myFile.print(secondsPassed);
    myFile.print(",");
    myFile.print(lastT);
    myFile.print(",");
    myFile.print(lastP);
    myFile.print(",");
    myFile.println(lastH);
    myFile.close();

    lineCounter++;
    Serial.println(F("DONE!"));
    digitalWrite(statusLed, HIGH);
    delay(150);
    
    digitalWrite(statusLed, LOW);
} else {
      Serial.println(F("SD WRITE ERROR!"));
}
  }
}