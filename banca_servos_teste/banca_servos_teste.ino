#include <Servo.h>

Servo servo1;
Servo servo2;
//Servo servo3;

int angle = 0;

int minAngle = 0;
int maxAngle = 180;

int minPulseWidth = 580;
int maxPulseWidth = 2770;

void setup() {
  Serial.begin(9600);

  servo1.attach(5, minPulseWidth, maxPulseWidth);
  servo2.attach(6, minPulseWidth, maxPulseWidth);
//  servo3.attach(7, minPulseWidth, maxPulseWidth);

  servo1.writeMicroseconds(map(45, minAngle, maxAngle, minPulseWidth, maxPulseWidth));
  servo2.writeMicroseconds(map(90, minAngle, maxAngle, minPulseWidth, maxPulseWidth));
//  servo3.writeMicroseconds(map(90, minAngle, maxAngle, minPulseWidth, maxPulseWidth));
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    if (input.length() > 0) {
      Serial.println(input);
      input.trim();

      if (isdigit(input[0])) {
        int servoNumber = input.substring(0, 1).toInt();
        int servoAngle = input.substring(1).toInt();

        if (servoNumber == 1) {
          servo1.writeMicroseconds(map(servoAngle, minAngle, maxAngle, minPulseWidth, maxPulseWidth));
          Serial.print("Servo 1 moved to angle: ");
          Serial.println(servoAngle);
        }
        else if (servoNumber == 2) {
          servo2.writeMicroseconds(map(servoAngle, minAngle, maxAngle, minPulseWidth, maxPulseWidth));
          Serial.print("Servo 2 moved to angle: ");
          Serial.println(servoAngle);
        }
        else if (servoNumber == 3) {
//          servo3.writeMicroseconds(map(servoAngle, minAngle, maxAngle, minPulseWidth, maxPulseWidth));
          Serial.print("Servo 3 moved to angle: ");
          Serial.println(servoAngle);
        }
      }
    }
  }
}
