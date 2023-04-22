#include <Servo.h>

Servo servo1;
//Servo servo2;
//Servo servo3;

int angles[3] = {0, 90, 90}; // array que armazena os ângulos dos 3 servos

int minAngle = 0;
int maxAngle = 180;

int minPulseWidth = 580;
int maxPulseWidth = 2770;

void setup() {
  Serial.begin(9600);
  servo1.attach(5, minPulseWidth, maxPulseWidth);
//  servo2.attach(6, minPulseWidth, maxPulseWidth);
//  servo3.attach(7, minPulseWidth, maxPulseWidth);
  
  servo1.writeMicroseconds(map(angles[0], minAngle, maxAngle, minPulseWidth, maxPulseWidth));
//  servo2.writeMicroseconds(map(angles[1], minAngle, maxAngle, minPulseWidth, maxPulseWidth));
//  servo3.writeMicroseconds(map(angles[2], minAngle, maxAngle, minPulseWidth, maxPulseWidth));
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    if (input.length() > 0) {
      input.trim();
      int spacePos1 = input.indexOf(',');
      int spacePos2 = input.lastIndexOf(',');
      if (spacePos1 > 0 && spacePos2 > spacePos1) {
        angles[0] = input.substring(0, spacePos1).toInt();
        angles[1] = input.substring(spacePos1+1, spacePos2).toInt();
        angles[2] = input.substring(spacePos2+1).toInt();
        servo1.writeMicroseconds(map(angles[0], minAngle, maxAngle, minPulseWidth, maxPulseWidth));
//        servo2.writeMicroseconds(map(angles[1], minAngle, maxAngle, minPulseWidth, maxPulseWidth));
//        servo3.writeMicroseconds(map(angles[2], minAngle, maxAngle, minPulseWidth, maxPulseWidth));
      }
      Serial.println("Servos moved to angles: " + String(angles[0]) + " " + String(angles[1]) + " " + String(angles[2]));
    }
  }
}
