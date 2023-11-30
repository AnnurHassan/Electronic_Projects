# Arduino Radar Project
An Arduino-based radar system using positional Micro Servo and HC-SR04 Ultrasonic Sound Sensor. The ultrasonic sensor is attached on the top of the servo motor. The servo rotates 180 degrees from left to right and the SR04 checks for any object within the pre-determined distance. A buzzer is used to alert when an object is detected along with a lead. The code for Arduino has been uploaded above. A video of the project is also given above. Some Images of the schematics and PCB are below.

# PCB Design
Even though the project has been built completely on breadboard, I have made a custom PCB for this. I am still learning the concept of PCB therefore kept it very simple.

- The PCB is made based on an Arduino NANO. Soldering some Female header pins instead of directly soldering the Arduino will give it more modular characteristics. Header pins for the Sound sensor, servo and external power are provided. Therefore making it a completely plug-and-play setup. (Connect the jumper cable and upload the code and you are good to go.)
  
- Vcc and GND pins of both the Ultrasonic Sensor and Servo are attached to Arduino +5V and GND.
  
- The Trig and Echo pin on the HC_SR04 are connected to D7 and D8 on Arduino NANO respectively.
  
- The servo motor is connected to the D6 on the Arduino NANO.
  
- For battery power 2 header pins are provided, directly connected to the Vin and GND of the Arduino.
  
- Lastly, Two operational LEDs connected to D4 and D5 respectively. You can set them up however you need.

The schematic and PCB are built using EASYEDA. Check them out [here](https://easyeda.com/editor#id=|7617aa49451e4fcd877120587bd70e5b|61210422480b409aa4e4f2f1ace844e6)

![image](https://github.com/AnnurHassan/Learning-Robotics/assets/39032781/5f3e0b88-c7d0-43f8-bc15-e67085ab7a4b)

![image](https://github.com/AnnurHassan/Learning-Robotics/assets/39032781/cda89ee4-89b6-4ff0-96d7-a1a4aa1568a8)

![Screenshot 2023-11-30 065424](https://github.com/AnnurHassan/Learning-Robotics/assets/39032781/d8a01d1a-dda6-4d56-a7bc-ea1ca99eea60)


# Circuit Simulation
A Circuit Simulation has been done beforehand on a breadboard using [Tinker Cad](https://www.tinkercad.com/things/ii6DmvlBP4N-arduino-radar-with-servo?sharecode=iMrb3cnjyWKvaaCzIIbWedqESPEBbU1Ovds1hmxR_tY)

![image](https://github.com/AnnurHassan/Electronics-Projects/assets/39032781/aa4b971c-8ddb-49e1-8459-ee25be9f91db)

# Build on Breadboard

![image](https://github.com/AnnurHassan/Electronics-Projects/assets/39032781/63ab9fc7-1a50-45fa-93bf-4fb3e10f1cfd)

![image](https://github.com/AnnurHassan/Electronics-Projects/assets/39032781/e7b8f453-f015-4a0e-8c5c-addd68abf0fa)


