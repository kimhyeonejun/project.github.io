#include <SoftwareSerial.h>

int trig = 12;
int echo = 11;
int led = 10;
int Tone = 9;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led, OUTPUT);
  pinMode(Tone, OUTPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  digitalWrite(echo, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH);
  float distance = ((float)(340*duration) / 10000) / 2 ; 

  int interval1 = map(distance, 30, 122, 125, 300);
  int interval2 = map(distance, 122, 244, 400, 700);

  if (distance > 244){
    digitalWrite(led, LOW);
    noTone(9);
    Serial.print(distance);
    Serial.println("cm");
  }

  else if(distance >= 122 && distance < 244){
    digitalWrite(led, HIGH);
    tone(9, 65, interval2);
    delay(interval2);
    Serial.print(distance);
    Serial.println("cm");
  }

  else if(distance >= 30 && distance< 122){
    digitalWrite(led, HIGH);
    tone(9, 130, interval1);
    delay(interval1);
    Serial.print(distance);
    Serial.println("cm");
  }

  else if(distance >= 15 && distance < 30){
    digitalWrite(led, HIGH);
    tone(9, 261, 125);
    Serial.print(distance);
    Serial.println("cm");
  }

   else if(distance < 15){
    digitalWrite(led, HIGH);
    tone(9, 261);
    Serial.print(distance);
    Serial.println("cm");
  }
   
  delay(200);
}