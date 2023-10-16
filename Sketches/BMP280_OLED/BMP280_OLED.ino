#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

float seaLevelPressure = 1010.0;
bool showAlti = true;

void setup() {

	Serial.begin(9600);

	display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

	display.setTextSize(2);
	display.setTextColor(WHITE);

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

	display.clearDisplay();

	if (showAlti) {

		display.setCursor(15, 10);

		display.print((int) ((bmp.readTemperature() * 9.0) / 5.0 + 32));
		display.print(" F");

		display.setCursor(15, 40);

		display.print((int) alti);
		display.print(" m");

	} else {

		display.setCursor(15, 10);

		display.print((int) bmp.readTemperature());
		display.print(" C");

		display.setCursor(15, 40);

		display.print((int) (bmp.readPressure() / 100));
		display.print(" hPa");
	}

	display.display();

	delay(3500);
}
