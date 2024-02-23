// for I/O
#define Sensor_1 A1
#define Sensor_2 A2
#define Sensor_3 A3
#define Sensor_4 A4
#define Sensor_5 A5
#define Sensor_6 A6

int threshold;
int minValues[6];
int maxValues[6];

void setup(){
    Serial.begin(9600);
    pinMode(Sensor_1, INPUT);
    pinMode(Sensor_2, INPUT);
    pinMode(Sensor_3, INPUT);
    pinMode(Sensor_4, INPUT);
    pinMode(Sensor_5, INPUT);
    pinMode(Sensor_6, INPUT);
  }

void runMotor(int left, int right)
{
  digitalWrite(STBY, HIGH);

  if (left == 0 and right == 0)
  {
    digitalWrite(STBY, LOW);
  }

  if (left > 0)
  {
    analogWrite(PWMA, left);
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  }

  else if (left < 0)
  {
    left = -(left);
    analogWrite(PWMA, left);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  }

  if (right > 0)
  {
    analogWrite(PWMB, right);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  }

  else if (right < 0)
  {
    right = -(right);
    analogWrite(PWMB, right);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  }
}

void readSensors(){
  while(1){
    Serial.print("Readings: ");
    Serial.print(analogRead(Sensor_1));
    Serial.print(" ");
    Serial.print(analogRead(Sensor_2));
    Serial.print(" ");
    Serial.print(analogRead(Sensor_3));
    Serial.print(" ");
    Serial.print(analogRead(Sensor_4));
    Serial.print(" ");
    Serial.print(analogRead(Sensor_5));
    Serial.print(" ");
    Serial.print(analogRead(Sensor_6));
    Serial.println(" ");
  }
}

void calibrate(){
  for ( int i = 1; i < 6; i++)
  {
    minValues[i] = analogRead(i);
    maxValues[i] = analogRead(i);
  }
  
  for (int i = 0; i < 3000; i++)
  {
    runMotor(50, -50);

    for ( int i = 1; i < 6; i++)
    {
      if (analogRead(i) < minValues[i])
      {
        minValues[i] = analogRead(i);
      }
      if (analogRead(i) > maxValues[i])
      {
        maxValues[i] = analogRead(i);
      }
    }

    for ( int i = 1; i < 6; i++)
    {
      threshold[i] = (minValues[i] + maxValues[i]) / 2;
      Serial.print(threshold[i]);
      Serial.print("   ");
    }
  }

void loop(){
    int button_1 = digitalRead(button1);
    int button_2 = digitalRead(button2);

    if (button_1 == 1) start();
}

