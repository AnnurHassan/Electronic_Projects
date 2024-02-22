#define PWMA 3
#define AIN1 5
#define AIN2 4
#define STBY 6
#define BIN1 7
#define BIN2 8
#define PWMB 9
#define button1 10
#define button2 12

void setup() {
  // put your setup code here, to run once:
  // pinModes for controlling motor
    pinMode(PWMA, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMB, OUTPUT);
    digitalWrite(STBY, HIGH);
}

void runMotor(int left, int right) {
  digitalWrite(STBY, HIGH);

  if (left == 0 and right == 0) {
    digitalWrite(STBY, LOW);
  }

  if (left > 0) {
    analogWrite(PWMA, left);
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  }

  else if (left < 0) {
    left = -(left);
    analogWrite(PWMA, left);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  } 

  if (right > 0) {
    analogWrite(PWMB, right);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  }

  else if (right < 0) {
    right = -(right);
    analogWrite(PWMB, right);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  }
}

void start() {
  runMotor(120,120);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button_1 = digitalRead(button1);
  int button_2 = digitalRead(button2);

  if (button_1 == 1) start();
}
