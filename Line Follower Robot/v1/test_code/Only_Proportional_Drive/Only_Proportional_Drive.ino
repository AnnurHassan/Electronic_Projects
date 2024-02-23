// for I/O
#define Sensor_1 A1
#define Sensor_2 A2
#define Sensor_3 A3
#define Sensor_4 A4
#define Sensor_5 A5
#define Sensor_6 A6

#define PWMA 3
#define AIN1 5
#define AIN2 4
#define STBY 6
#define BIN1 7
#define BIN2 8
#define PWMB 9
#define button1 10
#define button2 12

// tunable constants
const double Kp = 1.5; // if increased: turns will be taken faster, oscilates. if lower: turn slowly and might miss
const double Kd = 0.5; // if increased: turns will be fast and smooth. if lower: it get jerky

int BASE_SPEED = 200;

double error;
double previous_error;

double proportional;
double derivative;
double delta;

// to store sensor readings
int sensor_values[6];


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(Sensor_1, INPUT);
    pinMode(Sensor_2, INPUT);
    pinMode(Sensor_3, INPUT);
    pinMode(Sensor_4, INPUT);
    pinMode(Sensor_5, INPUT);
    pinMode(Sensor_6, INPUT);

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

int normalizeSensorReading(int sensorReading){
    // converting signals to digital since line's existence is boolean
    if (sensorReading > 500)
    {
        return 100;
    }
    else
    {
        return 0;
    }
}

int calculateError(int sensor_values[])
{
    // assumes 6 sensors are used
    int sensor_weights[] = {-2, -1, 0, 0, 1, 2};
    int sensor_reading = 0;
    int weighted_reading = 0;
    int weighted_sum = 0;

    for (int i = 0; i < 6; i++)
    {
        sensor_reading = sensor_values[i];

        weighted_reading = sensor_reading * sensor_weights[i];
        weighted_sum = weighted_sum + weighted_reading;
    }

    if (sensor_values[0] == 100 && sensor_values[1] == 0){
      return weighted_sum * 2;
    } else if (sensor_values[4] == 0 && sensor_values[5] == 100) {
      return weighted_sum * 2;
    } else {
      return weighted_sum;
    }
}

void start(){
  while(1){
    sensor_values[0] = normalizeSensorReading(analogRead(Sensor_1));
    sensor_values[1] = normalizeSensorReading(analogRead(Sensor_2));
    sensor_values[2] = normalizeSensorReading(analogRead(Sensor_3));
    sensor_values[3] = normalizeSensorReading(analogRead(Sensor_4));
    sensor_values[4] = normalizeSensorReading(analogRead(Sensor_5));
    sensor_values[5] = normalizeSensorReading(analogRead(Sensor_6));

    error = calculateError(sensor_values);
    proportional = Kp * error;
    derivative = Kd * (error - previous_error);
    delta = proportional + derivative;


    if (delta > 0){
      runMotor(BASE_SPEED - 2*delta, BASE_SPEED);
    } else {
      runMotor(BASE_SPEED, BASE_SPEED + delta);
    }

    previous_error = error;
    //runMotor(BASE_SPEED - proportional, BASE_SPEED + proportional);
    
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int button_1 = digitalRead(button1);
  int button_2 = digitalRead(button2);

  if (button_1 == 1) start();
}
