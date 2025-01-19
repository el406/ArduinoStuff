#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define Motor_Pin 0
#define MIN_THROTTLE 217
#define MAX_THROTTLE 410


Adafruit_PWMServoDriver testMotor = Adafruit_PWMServoDriver(0x40);


void setup() {
  // put your setup code here, to run once:
  testMotor.begin();
  testMotor.setPWMFreq(50); //forum said 50 was accurate
  //testMotor.setPWM(0,0,MAX_THROTTLE);
  testMotor.writeMicroseconds(0, 2000);
  testMotor.writeMicroseconds(1, 2000);
  testMotor.writeMicroseconds(2, 2000);
  testMotor.writeMicroseconds(3, 2000);
  delay(2000);
  //testMotor.setPWM(0,0,MIN_THROTTLE);
  testMotor.writeMicroseconds(0, 1000);
  testMotor.writeMicroseconds(1, 1000);
  testMotor.writeMicroseconds(2, 1000);
  testMotor.writeMicroseconds(3, 1000);
  delay(2000);



}

void loop() {
  // put your main code here, to run repeatedly:
  //testMotor.setPWM(0,0,MIN_THROTTLE);
  testMotor.writeMicroseconds(0, 1000);
}


// Servo og refrence
/*#include <Servo.h>

Servo esc;  // create servo object to control the ESC

// Set your PWM pin
int escPin = 9;

void setup() {
  esc.attach(escPin);  // Attach the ESC to the pin
  Serial.begin(9600);
  
  Serial.println("Starting ESC Calibration...");

  // Max throttle (for calibrating the maximum value)
  esc.writeMicroseconds(2000);
  Serial.println("Max throttle...");
  delay(2000);  // Wait for 2 seconds

  // Min throttle (for calibrating the minimum value)
  esc.writeMicroseconds(1000);
  Serial.println("Min throttle...");
  delay(2000);  // Wait for 2 seconds

  Serial.println("ESC Calibration Done. Waiting for commands...");
}

void loop() {
  // In this example, we keep the ESC at the minimum throttle position
  esc.writeMicroseconds(1000);
}*/

