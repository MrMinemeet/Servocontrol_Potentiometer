#include <Servo.h>

#define potPin    0      // Potentiometer Pin   - Analog Input
#define servoPin  3      // Servomotor Pin      - Digital Output(PWM)
#define MaxAngle  180    // Max. Angle          - Depends on your Servo Motor

int value = 0;
int angle = 0;
Servo servo;

void setup() {
  pinMode(potPin, INPUT);
  Serial.begin(9600);                         // Starts serial
  servo.attach(servoPin);                     // Binds servo to servoPin
}

void loop() {
  value = analogRead(potPin);                 // Read analogvalue to value
  Serial.println(value);                      // Puts value to serial

  angle = map(value, 0, 1023, 0, MaxAngle);   // converts value (0-1023) to angle of servo(0-180)
  Serial.print(angle);                        // Puts angle to serial
  Serial.println("°");
  
  servo.write(angle);                         // Sets servo to angle
  delay(50);
}
