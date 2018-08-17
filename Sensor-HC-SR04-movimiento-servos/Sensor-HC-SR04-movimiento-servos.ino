//Gatdev

int led1=3;
int led2=7;
int led3=8;
int echo=5;
int trigger=2;
#include <Servo.h>
Servo servoMotor;
unsigned tiempo, dist;
void setup() {
 
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, INPUT);
  servoMotor.attach(9);
  Serial.begin(9600);
}
void loop() {
  int LE=1;
  int LA=0;
  
 
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    tiempo = pulseIn(echo, HIGH);
    dist = tiempo/58;
    if(dist>40&&dist<50)
    {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    delay(10);
    servoMotor.write(45);
    Serial.print(dist);
    Serial.println("cm");
    }
    if(dist>30&&dist<40)
    {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    delay(10);
    servoMotor.write(90);
    Serial.print(dist);
    Serial.println("cm");
    }
        if(dist>20&&dist<30)
    {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    delay(10);
    servoMotor.write(180);
    Serial.print(dist);
    Serial.println("cm");
    }
         if(dist<20)
         
    {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    delay(10);
    servoMotor.write(0);
    Serial.print(dist);
    Serial.println("cm");
    }
}
