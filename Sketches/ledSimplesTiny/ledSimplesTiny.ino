void setup()
{
  pinMode(D2, OUTPUT); //led
}

void loop()
{
  digitalWrite(D2, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(D2, LOW);
  delay(500); // Wait for 1000 millisecond(s)
}
