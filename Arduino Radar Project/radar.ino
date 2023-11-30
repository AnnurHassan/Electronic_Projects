#include <Servo.h>
const int trigPin = 3;
const int echoPin = 4;
const int buzzer = 5;
const int led = 6;

Servo servoMotor;

int angle = 0;
int distance = 0;
int duration = 0;

void setup() {
  servoMotor.attach(2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  for (angle = 0; angle <= 180; angle += 1) {
    servoMotor.write(angle);
    delay(30);
    distance = cal_distance();
    Serial.println(distance);
  }
  
  for (angle = 180; angle >= 0; angle -= 1) {
    servoMotor.write(angle);
    delay(30);
    distance = cal_distance();
    Serial.println(distance);
  }
}

int cal_distance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2 ;
  
  if (distance < 20) {
  	digitalWrite(led, HIGH);
  	digitalWrite(buzzer, HIGH);
    // Led On if the distance is withing 20 mm
  }
  else{
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    //Led off if the distance is not within 20 mm
  }  
  return distance;
}
