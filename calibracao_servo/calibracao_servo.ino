#include <Servo.h>

Servo myServo, myServo2;

int angle = 0;

int minAngle = 0;
int maxAngle = 180;

int minPulseWidth = 580;
int maxPulseWidth = 2770;

void setup() {
  Serial.begin(9600);
  myServo.attach(5, minPulseWidth, maxPulseWidth);
  myServo.writeMicroseconds(map(90, minAngle, maxAngle, minPulseWidth, maxPulseWidth));

  myServo2.attach(6, minPulseWidth, maxPulseWidth);
  myServo2.writeMicroseconds(map(90, minAngle, maxAngle, minPulseWidth, maxPulseWidth));
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    if (input.length() > 0) {
      input.trim();
      int servoNumber = input.substring(0,1).toInt();
      int servoAngle = input.substring(1).toInt();

      angle = servoAngle;

      if (servoNumber == 1) {
        myServo.writeMicroseconds(map(angle, minAngle, maxAngle, minPulseWidth, maxPulseWidth));
        Serial.print("Servo 1 moved to angle: ");
        Serial.println(angle);
      }
      else
      if (servoNumber == 2) {
        myServo2.writeMicroseconds(map(angle, minAngle, maxAngle, minPulseWidth, maxPulseWidth));
        Serial.print("Servo 1 moved to angle: ");
        Serial.println(angle);
      }
    }
  }
}
