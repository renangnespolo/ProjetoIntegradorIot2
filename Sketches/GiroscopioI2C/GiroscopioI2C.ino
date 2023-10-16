#include <MPU6050_tockn.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

MPU6050 mpu6050(Wire);

#define endereco 0x27
#define colunas 16
#define linhas 2

//iniciando objetos
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

void setup()
{
  //verifica endereço de memória da placa LED
  //nosso modelo é baseado no PCF8574
      
   Serial.begin(9600);
      //while(!Serial);
      //Serial.println("iniciando comunicação I2C");
      //Wire.begin();
      //Serial.println("fim Setup");
  
  //inicia a comunicação com o display
  lcd.init();
  //liga a iluminação do display
  lcd.backlight();
  //limpar o display
  lcd.clear();

  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  lcd.clear();
  mpu6050.update();
  String l1="";
  String l2="";
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  l1 = l1+"x"+mpu6050.getAngleX();
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  l1 = l1+" y"+mpu6050.getAngleY();
  lcd.print(l1);
  lcd.setCursor(0,1);
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());
  l2 = l2+"z"+mpu6050.getAngleZ();
  lcd.print(l2);
  delay(2000);
}
