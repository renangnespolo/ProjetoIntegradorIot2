// C++ code
//

long distance=0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT); //limpa o trigger (Varredura da onda)
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    //Ajusta o pino do trigger do sensor ultrasonico
    //para o estado HIGH (ligado) durante 10 microsegundos
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    //Lê o pulso refletido no pino echo e retorna o tempo da
    //viagem sonora sound wave travel em microsegundos
    return pulseIn(echoPin, HIGH);
}
void setup()
{
    pinMode(0, OUTPUT);
    Serial.begin(9600);
    pinMode(5,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(D0,OUTPUT);
  
}

void loop()
{
    tone(0,523,1000); //soa um tom 60 (C5 = 523 Hz)
    distance = 0.01723 * readUltrasonicDistance(D4, D5);
    Serial.println(distance);
    if(distance < 10)
    {
      digitalWrite(5, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(D0, LOW);
    }
    else
    {
      if(distance < 20)
        {
          digitalWrite(5, LOW);
          digitalWrite(4, HIGH);
          digitalWrite(D0, LOW);
        }
        else
        {
          digitalWrite(5, LOW);
          digitalWrite(4, LOW);
          digitalWrite(D0, HIGH);
        }
    }
  delay(10); // Wait for 1000 millisecond(s)
}
