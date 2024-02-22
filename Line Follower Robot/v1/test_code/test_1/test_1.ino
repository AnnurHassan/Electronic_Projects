#define IR_s1 A6
#define IR_s2 A5
#define IR_s3 A4
#define IR_s4 A3
#define IR_s5 A2
#define IR_s6 A1
#define MOTOR_SPEED 180

#define button_1 10
#define button_2 12

//right motor
int PWMB=9;
int AIN1=7;
int AIN2=8;

//Left motor
int PWMA=3;
int BIN1=5;
int BIN2=4;
void setup() {
  // put your setup code here, to run once:
pinMode(PWMB, OUTPUT);
pinMode(AIN1, OUTPUT);
pinMode(AIN2, OUTPUT);
  
pinMode(PWMA, OUTPUT);
pinMode(BIN1, OUTPUT);
pinMode(BIN2, OUTPUT);

pinMode(IR_s1, INPUT);
pinMode(IR_s2, INPUT);
pinMode(IR_s3, INPUT);
pinMode(IR_s4, INPUT);
pinMode(IR_s5, INPUT);
pinMode(IR_s6, INPUT);

pinMode(6, OUTPUT);
digitalWrite(6, HIGH);

rotateMotor(0,0); 
Serial.begin(9600);

}

int invert(int value) {
  if (value < 500) return 1;
  else return 0;
}

void start() {
  while(1) {
    // put your main code here, to run repeatedly:
 int IR_s4_value = invert(analogRead(IR_s4));
 int IR_s5_value = invert(analogRead(IR_s5));
 int IR_s6_value = invert(analogRead(IR_s6));
 int IR_s3_value = invert(analogRead(IR_s3));
 int IR_s2_value = invert(analogRead(IR_s2));
 int IR_s1_value = invert(analogRead(IR_s1));

  // Serial.print("Readings: ");
  // Serial.print(IR_s1_value);
  // Serial.print(" ");
  // Serial.print(IR_s2_value);
  // Serial.print(" ");
  // Serial.print(IR_s3_value);
  // Serial.print(" ");
  // Serial.print(IR_s4_value);
  // Serial.print(" ");
  // Serial.print(IR_s5_value);
  // Serial.print(" ");
  // Serial.print(IR_s6_value);
  // Serial.println(" ");


  //shoja
  if (IR_s1_value== 0 && IR_s2_value==0 && IR_s3_value==1 && IR_s4_value==1 && IR_s5_value==0 && IR_s6_value==0 )
  {
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
  }
  //halka left
  else if (IR_s1_value== 0 && IR_s2_value==1 && IR_s3_value==1 && IR_s4_value==1 && IR_s5_value==0 && IR_s6_value==0) rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 
  else if (IR_s1_value== 0 && IR_s2_value==1 && IR_s3_value==1 && IR_s4_value==0 && IR_s5_value==0 && IR_s6_value==0) rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 

  // hard left
  else if (IR_s1_value==1 && IR_s2_value==1 && IR_s3_value==1 && IR_s4_value==1 && IR_s5_value==0 && IR_s6_value==0) rotateMotor(MOTOR_SPEED, -MOTOR_SPEED); 

  //halka right
  else if (IR_s1_value== 0 && IR_s2_value==0 && IR_s3_value==1 && IR_s4_value==1 && IR_s5_value==1 && IR_s6_value==0) rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 
  else if (IR_s1_value== 0 && IR_s2_value==0 && IR_s3_value==0 && IR_s4_value==1 && IR_s5_value==1 && IR_s6_value==0) rotateMotor(-MOTOR_SPEED, MOTOR_SPEED);

  // hard right
  else if (IR_s1_value== 0 && IR_s2_value==0 && IR_s3_value==1 && IR_s4_value==1 && IR_s5_value==1 && IR_s6_value==1) rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 

  //If both the sensors detect black line, then stop 
  else 
  {
    rotateMotor(0, 0);
  }
  }
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  
  if (rightMotorSpeed < 0)
  {
    digitalWrite(AIN1,LOW);
    digitalWrite(AIN2,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(AIN1,HIGH);
    digitalWrite(AIN2,LOW);      
  }
  else
  {
    digitalWrite(AIN1,LOW);
    digitalWrite(AIN2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(BIN1,LOW);
    digitalWrite(BIN2,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(BIN1,HIGH);
    digitalWrite(BIN2,LOW);      
  }
  else 
  {
    digitalWrite(BIN1,LOW);
    digitalWrite(BIN2,LOW);      
  }
  analogWrite(PWMB, abs(rightMotorSpeed));
  analogWrite(PWMA, abs(leftMotorSpeed));

}

void loop() {
  if (digitalRead(button_1) == 1) start();
}