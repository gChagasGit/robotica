#include <Servo.h>

Servo servos[3];

int angle = 0;

int minAngle = 0;
int maxAngle = 180;

int minPulseWidth = 580;
int maxPulseWidth = 2770;

void setup() {
  Serial.begin(9600);

  servos[0].attach(5, minPulseWidth, maxPulseWidth);
  servos[1].attach(6, minPulseWidth, maxPulseWidth);
  servos[2].attach(7, minPulseWidth, maxPulseWidth);

  servos[0].write(map(45, minAngle, maxAngle, 0, 180));
  servos[1].write(map(90, minAngle, maxAngle, 0, 180));
  servos[2].write(map(90, minAngle, maxAngle, 0, 180));
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

        if (servoNumber >= 1 && servoNumber <= 3) {
          servos[servoNumber - 1].write(map(servoAngle, minAngle, maxAngle, 0, 180));
          Serial.print("Servo ");
          Serial.print(servoNumber);
          Serial.print(" moved to angle: ");
          Serial.println(servoAngle);
        }
      }
    }
  }
}
