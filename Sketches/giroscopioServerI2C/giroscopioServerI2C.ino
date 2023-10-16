    /////////////////////////////////////////////////////////////////
   //         ESP32 Web Server Project  v1.00                     //
  //       Get the latest version of the code here:              //
 //         http://educ8s.tv/esp32-web-server                   //
/////////////////////////////////////////////////////////////////

#include <MPU6050_tockn.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <WebServer.h>  //https://github.com/bbx10/WebServer_tng
#include <LiquidCrystal_I2C.h>

#define endereco 0x27
#define colunas 16
#define linhas 2

#ifndef STASSID
#define STASSID "NETGEAR"
#define STAPSK "12345678"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

MPU6050 mpu6050(Wire);

WebServer server ( 80 );

float x = 0;
float y = 0;
float z = 0;

//iniciando objetos
LiquidCrystal_I2C lcd(endereco, colunas, linhas);

String getPage(){
  String page = "<html lang=en-EN><head><meta http-equiv='refresh' content='60'/>";
  page += "<title>ESP8266 Giroscope WebServer</title>";
  page += "<style> body { background-color: #fffff; font-family: Arial, Helvetica, Sans-Serif; Color: #000000; }</style>";
  page += "</head><body><h1>ESP32 WebServer</h1>";
  page += "<h3>GY-521 Sensor</h3>";
  page += "<ul><li>x: ";
  page += x;
  page += "</li>";
  page += "<li>y: ";
  page += y;
  page += "</li>";
  page += "<li>z: ";
  page += z;
  page += "</li></ul>";
  page += "</body></html>";
  return page;
}

void handleRoot(){ 
    server.send ( 200, "text/html", getPage() );
}

void setup() {
  Serial.begin(9600);


  lcd.init();
  //liga a iluminação do display
  lcd.backlight();
  //limpar o display
  lcd.clear();
  
  //giroscope
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  Serial.println ( "Giroscope Started" );
  
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  lcd.print(WiFi.localIP());

  server.on ( "/", handleRoot );
  server.begin();
  Serial.println ( "HTTP server started" );
}

void loop() 
{

  mpu6050.update();
    Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  x=mpu6050.getAngleX();
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  y=mpu6050.getAngleY();
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());
  z=mpu6050.getAngleZ();  
  server.handleClient();
  Serial.println ( "HTTP server running" );
  delay(1000);  
}
