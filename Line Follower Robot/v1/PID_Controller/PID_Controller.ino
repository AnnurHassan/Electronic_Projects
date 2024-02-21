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
const double Kp = 1.0; // if increased: turns will be taken faster, oscilates. if lower: turn slowly and might miss
const double Ki = 0.0; // no idea how to tune lol
const double Kd = 0.05; // if increased: turns will be fast and smooth. if lower: it get jerky

const double BASE_SPEED = 125;

// time related const and vars
const unsigned long dt = 100; //timestep in ms
unsigned long previous_time = 0;
unsigned long current_time;
unsigned long elapsed_time;

// values related to error
double previous_error = 0;
double error;

// for pid calculations
double proportional;
double derivative;
double integral = 0;
unsigned int delta; 

// to store sensor readings
unsigned int sensor_values[6];

void setup()
{
    // TODO: configure the pins required to read sensor data and to use motors
    Serial.begin(9600);

    // Setting pinMode for the sensors as input
    pinMode(Sensor_1, INPUT);
    pinMode(Sensor_2, INPUT);
    pinMode(Sensor_3, INPUT);
    pinMode(Sensor_4, INPUT);
    pinMode(Sensor_5, INPUT);
    pinMode(Sensor_6, INPUT);

    // pinModes for controlling motor
    pinMode(PWMA, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
    pinMode(PWMB, OUTPUT);
    digitalWrite(STBY, HIGH);
}

int normalizeSensorReading(int sensorReading){
    // converting signals to digital since line's existence is boolean
    if (sensorReading > 500)
    {
        return 32;
    }
    else
    {
        return 0;
    }
}

int calculateError(int sensor_values[])
{
    // assumes 6 sensors are used
    unsigned int sensor_weights[] = {-2, -1, 0, 0, 1, 2};
    int sensor_reading = 0;
    int weighted_reading = 0;
    int weighted_sum = 0;

    for (int i = 0; i < 6; i++)
    {
        sensor_reading = normalizeSensorReading(sensor_values[i]);

        weighted_reading = sensor_reading * sensor_weights[i];
        weighted_sum = weighted_sum + weighted_reading;
    }

    return weighted_sum;
}

void runMotor(int left, int right) {
  digitalWrite(STBY, HIGH);

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

void init()
{
    current_time = millis();
    elapsed_time = current_time - previous_time;

    if (elapsed_time >= dt)
    {
        // read the sensor value here and store inside sensor_values
        sensor_values[0] = analogRead(Sensor_1);
        sensor_values[1] = analogRead(Sensor_2);
        sensor_values[2] = analogRead(Sensor_3);
        sensor_values[3] = analogRead(Sensor_4);
        sensor_values[4] = analogRead(Sensor_5);
        sensor_values[5] = analogRead(Sensor_6);

        // Calculate error
        error = calculateError(sensor_values);

        // Proportional term
        proportional = Kp * error;

        // Integral term using trapezoidal rule
        integral = integral + 0.5 * (error + previous_error) * (elapsed_time / 1000.0);

        // Derivative term
        derivative = Kd * (error - previous_error) / (elapsed_time / 1000.0);

        // PID output
        delta = proportional + Ki * integral + derivative;

        // Run motor as expected
        runMotor(BASE_SPEED - delta, BASE_SPEED + delta);

        // Update variables for next iteration
        previous_error = error;
        previous_time = current_time;
    }
}

void loop() {
  int button_1 = digitalRead(button1);
  int button_2 = digitalRead(button2);

  if (button_1 == 1) init();
}
