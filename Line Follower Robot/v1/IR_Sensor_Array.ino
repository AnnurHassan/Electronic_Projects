// Defining all the pinouts to the arduino
#define Sensor_1 A1
#define Sensor_2 A2
#define Sensor_3 A3
#define Sensor_4 A4
#define Sensor_5 A5
#define Sensor_6 A6

void setup() {
    // Starting Serial Communication
    Serial.begin(9600);

    // Setting pinMode for the sensors as input
    pinMode(Sensor_1, INPUT);
    pinMode(Sensor_2, INPUT);
    pinMode(Sensor_3, INPUT);
    pinMode(Sensor_4, INPUT);
    pinMode(Sensor_5, INPUT);
    pinMode(Sensor_6, INPUT);

}

void loop() {
    //storing the reading from the sensors and conveting to digtal(i.e 0 and 1)

    int SV_1 = invert(analogRead(Sensor_1));
    int SV_2 = invert(analogRead(Sensor_2));
    int SV_3 = invert(analogRead(Sensor_3));
    int SV_4 = invert(analogRead(Sensor_4));
    int SV_5 = invert(analogRead(Sensor_5));
    int SV_6 = invert(analogRead(Sensor_6));

    // Printing values to Serial Monitor
    Serial.print("Readings: ");
    Serial.print(SV_1);
    Serial.print(" ");
    Serial.print(SV_2);
    Serial.print(" ");
    Serial.print(SV_3);
    Serial.print(" ");
    Serial.print(SV_4);
    Serial.print(" ");
    Serial.print(SV_5);
    Serial.print(" ");
    Serial.print(SV_6);
    Serial.println(" ");


}

// This function converts the analog readings to 0 and 1
int invert(int val) {
    if (val < 500) return 1; 
    else return 0;
}
