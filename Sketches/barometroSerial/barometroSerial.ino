//#include "Adafruit_BMP280.h"
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;
float seaLevelPressure = 1010.0;
bool showAlti = true;

void setup() {

  Serial.begin(9600);

  //display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  //display.setTextSize(2);
  //display.setTextColor(WHITE);

  bmp.begin(0x76);
}

void loop() {

  showAlti = !showAlti;

  Serial.print("Temperature = ");
  Serial.print(bmp.readTemperature());
  Serial.println(" C");

  Serial.print((bmp.readTemperature() * 9.0) / 5.0 + 32);
  Serial.println(" F");

  Serial.print("Pressure = ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  float alti = bmp.readAltitude(seaLevelPressure);

  Serial.print("Altitude = ");
  Serial.print(alti);
  Serial.println("m");

  Serial.println();

  //display.clearDisplay();

  delay(3500);
}
