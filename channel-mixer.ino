#include <Servo.h>

float pitch;
float roll;

float rightResult;
float leftResult;

int leftServoPin = A0;
int rightServoPin = A1;

int pitchPin = A3;
int rollPin = A2;

Servo leftServo;
Servo rightServo;

void setup() {
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(pitchPin, INPUT); // Pitch max 1990 min 995
  pinMode(rollPin, INPUT); // Roll max 1990 (right) min 995 (left)
  leftServo.attach(leftServoPin);
  rightServo.attach(rightServoPin);
}

void loop() {
  pitch = -(pulseIn(pitchPin, HIGH) - 1492.5) / 497.5;
  roll = (pulseIn(rollPin, HIGH) - 1492.5) / 497.5;

  rightResult = pitch * -0.5 + roll * -0.5;
  leftResult = pitch * -0.5 + roll * 0.5;

  rightServo.write(rightResult * 90 + 90);
  leftServo.write(leftResult * 90 + 90);


  delay(20);
}
