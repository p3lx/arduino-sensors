#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;
File myFile;

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; }

  if (!SD.begin(chipSelect)) {
    Serial.println("SD initialization failed!");
    while (1)
      ;
  }

  myFile = SD.open("data.csv");

  if (myFile) {
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    myFile.close();
  } else {
    Serial.println("Error: Could not open data.csv");
  }
}

void loop() {}