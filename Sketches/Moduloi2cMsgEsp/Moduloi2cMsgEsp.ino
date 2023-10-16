

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define endereco 0x27
#define colunas 16
#define linhas 2

//iniciando objetos
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup()
{
  //verifica endereço de memória da placa LED
  //nosso modelo é baseado no PCF8574
      
      //Serial.begin(9600);
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
}

void loop()
{
  lcd.clear();
   lcd.print("##FATEC##");
  delay(2000); //5 sengundos
  lcd.setCursor(0,1); //posiciona o cursor na primeira coluna e 
  //linha 2
  lcd.print("BEBEDOURO");
  delay(5000);
  //desliga o led
  lcd.noBacklight();
  delay(2000);
  //liga a iluminação do display
  lcd.backlight();
  //limpar o display
  lcd.clear();
  lcd.print("BIG DATA");
  delay(3000); //5 sengundos
  lcd.setCursor(0,1); //posiciona o cursor na primeira coluna e 
  //linha 2
  lcd.print("#VEM");
  delay(5000); //5 sengundos
  lcd.noBacklight();
  delay(2000);
  lcd.backlight();
}
