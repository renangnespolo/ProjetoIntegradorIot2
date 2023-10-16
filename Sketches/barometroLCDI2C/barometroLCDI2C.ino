#include <Adafruit_BMP280.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define endereco 0x27
#define colunas 16
#define linhas 2

LiquidCrystal_I2C lcd(endereco, colunas, linhas);

Adafruit_BMP280 bmp;
float seaLevelPressure = 1010.0;
bool showAlti = true;

void setup() {
  //barometro
  Serial.begin(9600);
  bmp.begin(0x76);

  //ldc i2c
  lcd.init();
  //liga a iluminação do display
  lcd.backlight();
  //limpar o display
  lcd.clear();
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

  lcd.clear();
  String temp = String(bmp.readTemperature())+"º";
   lcd.print(temp);
  //delay(2000); //5 sengundos
  lcd.setCursor(0,1); //posiciona o cursor na primeira coluna e  
  //linha 2
  String alt = String(alti)+" m";
  lcd.print(alt);
  delay(3500);
}
