int trigPin = 9;
int echoPin = 10;
int greenLed = 4;
int redLed = 5;
int buzzer = 6;

long duration;
float distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  /*send a short pulse from the sensor */
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  /*find how long the echo takes and chnage to cm */
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  /*show the distance*/
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  /*actions for if a car closer than 100 cm*/
  if (distance < 100)
  {
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
    tone(buzzer, 1000);
    Serial.println("Status: OCCUPIED");
  }
  else
  {
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    noTone(buzzer);
    Serial.println("Status: AVAILABLE");
  }

  delay(200);
}