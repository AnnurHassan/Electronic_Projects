#define IR_s4 1
#define IR_s5 2
#define IR_s6 3
#define IR_s3 4
#define IR_s2 5
#define IR_s1 6
#define MOTOR_SPEED 180
//right motor
int enableRightMotor=6;
int rightMotorPin1=7;
int rightMotorPin2=8;

//Left motor
int enableLeftMotor=5;
int leftMotorPin1=9;
int leftMotorPin2=10;
void setup() {
  // put your setup code here, to run once:
pinMode(enableRightMotor, OUTPUT);
pinMode(rightMotorPin1, OUTPUT);
pinMode(rightMotorPin2, OUTPUT);
  
pinMode(enableLeftMotor, OUTPUT);
pinMode(leftMotorPin1, OUTPUT);
pinMode(leftMotorPin2, OUTPUT);

pinMode(IR_s1, INPUT);
pinMode(IR_s2, INPUT);
pinMode(IR_s3, INPUT);
pinMode(IR_s4, INPUT);
pinMode(IR_s5, INPUT);
pinMode(IR_s6, INPUT);
rotateMotor(0,0); 
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 int IR_s4_value = analogRead(IR_s4);
 int IR_s5_value = analogRead(IR_s5);
 int IR_s6_value = analogRead(IR_s6);
 int IR_s3_value = analogRead(IR_s3);
 int IR_s2_value = analogRead(IR_s2);
 int IR_s1_value = analogRead(IR_s1);


  //If none of the sensors detects black line, then go straight
  if (IR_s1_value== 0 && IR_s2_value==0 && IR_s3_value==1023 && IR_s4_value==1023 && IR_s5_value==0 && IR_s6_value==0 )
  {
    rotateMotor(MOTOR_SPEED, MOTOR_SPEED);
  }
  //halka left
  else if (IR_s1_value== 0 && IR_s2_value==1023 && IR_s3_value==1023 && IR_s4_value==1023 && IR_s5_value==0 && IR_s6_value==0)
  {
      rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 
  }
  //halka right
  else if (IR_s1_value== 0 && IR_s2_value==0 && IR_s3_value==1023 && IR_s4_value==1023 && IR_s5_value==1023 && IR_s6_value==0)
  {
      rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 
  }
  // hard right
  else if (IR_s1_value== 0 && IR_s2_value==0 && IR_s3_value==1023 && IR_s4_value==1023 && IR_s5_value==1023 && IR_s6_value==1023)
  {
      rotateMotor(-MOTOR_SPEED, MOTOR_SPEED); 
  }
  // hard left
  else if (IR_s1_value== 1023 && IR_s2_value==1023 && IR_s3_value==1023 && IR_s4_value==1023 && IR_s5_value==0 && IR_s6_value==0)
  {
      rotateMotor(MOTOR_SPEED, -MOTOR_SPEED); 
  } 
  //If both the sensors detect black line, then stop 
  else 
  {
    rotateMotor(0, 0);
  }
}

void rotateMotor(int rightMotorSpeed, int leftMotorSpeed)
{
  
  if (rightMotorSpeed < 0)
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,HIGH);    
  }
  else if (rightMotorSpeed > 0)
  {
    digitalWrite(rightMotorPin1,HIGH);
    digitalWrite(rightMotorPin2,LOW);      
  }
  else
  {
    digitalWrite(rightMotorPin1,LOW);
    digitalWrite(rightMotorPin2,LOW);      
  }

  if (leftMotorSpeed < 0)
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,HIGH);    
  }
  else if (leftMotorSpeed > 0)
  {
    digitalWrite(leftMotorPin1,HIGH);
    digitalWrite(leftMotorPin2,LOW);      
  }
  else 
  {
    digitalWrite(leftMotorPin1,LOW);
    digitalWrite(leftMotorPin2,LOW);      
  }
  analogWrite(enableRightMotor, abs(rightMotorSpeed));
  analogWrite(enableLeftMotor, abs(leftMotorSpeed));

}