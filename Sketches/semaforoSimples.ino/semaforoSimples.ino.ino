void setup()
{
    pinMode(0,OUTPUT);
    Serial.begin(9600);
    pinMode(5,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(D0,OUTPUT);
  
}


void loop() {
  digitalWrite(5, HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
  digitalWrite(5, LOW);
  digitalWrite(4, HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
  digitalWrite(4, LOW);
  digitalWrite(D0, HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
  digitalWrite(D0, LOW);

}
