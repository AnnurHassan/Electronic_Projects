// for I/O
#define Sensor_1 A1
#define Sensor_2 A2
#define Sensor_3 A3
#define Sensor_4 A4
#define Sensor_5 A5
#define Sensor_6 A6

void setup(){
    Serial.begin(9600);
    pinMode(Sensor_1, INPUT);
    pinMode(Sensor_2, INPUT);
    pinMode(Sensor_3, INPUT);
    pinMode(Sensor_4, INPUT);
    pinMode(Sensor_5, INPUT);
    pinMode(Sensor_6, INPUT);
  }

void loop(){
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

