#define PWMA 3
#define AIN1 5
#define AIN2 4
#define STBY 6
#define BIN1 7
#define BIN2 8
#define PWMB 9

void setup() {
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  digitalWrite(STBY, HIGH);
}

void loop() {

}

void Motor(int left, int right) {
  if (left == 0 and right == 0) {
    digitalWrite(STBY, LOW);
  }

  if (left > 0) {
    digitalWrite(PWMA, left);
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  }
  else if (left < 0) {
    left = -(left);
    digitalWrite(PWMA, left);
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  } 

  if (right > 0) {
    digitalWrite(PWMB, right);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  }
  else if (right < 0) {
    right = -(right);
    digitalWrite(PWMB, right);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  }
}