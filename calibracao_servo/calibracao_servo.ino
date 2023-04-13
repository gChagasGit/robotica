#include <Servo.h>

Servo myServo;

int angle = 0;

int minAngle = 0;
int maxAngle = 180;

int minPulseWidth = 580;
int maxPulseWidth = 2770;

void setup() {
  Serial.begin(9600);
  myServo.attach(5, minPulseWidth, maxPulseWidth);
  myServo.writeMicroseconds(map(90, minAngle, maxAngle, minPulseWidth, maxPulseWidth));
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    if (input.length() > 0) {
      input.trim();
      angle = input.toInt();
      myServo.writeMicroseconds(map(angle, minAngle, maxAngle, minPulseWidth, maxPulseWidth));
      Serial.print("Servo moved to angle: ");
      Serial.println(angle);
    }
  }
}
