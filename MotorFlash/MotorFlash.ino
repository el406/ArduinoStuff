#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

// ESC parameters
int escChannel = 0; // Channel where the ESC is connected
int minPulse = 1000; // Min throttle pulse width in microseconds
int maxPulse = 2000; // Max throttle pulse width in microseconds

void setup() {
  Serial.begin(9600);
  Serial.println("Starting ESC Calibration...");

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  delay(10);

  // Max throttle (for calibrating the maximum value)
  //pwm.setPWM(escChannel, 0, pulseWidthToPwm(maxPulse));
  pwm.writeMicroseconds(escChannel, 20000);
  Serial.println("Max throttle...");
  delay(2000);

  // Min throttle (for calibrating the minimum value)
  pwm.setPWM(escChannel, 0, pulseWidthToPwm(minPulse));
  Serial.println("Min throttle...");
  delay(2000);

  Serial.println("ESC Calibration Done. Waiting for commands...");
}

void loop() {
  // Keep the ESC at minimum throttle
  pwm.setPWM(escChannel, 0, pulseWidthToPwm(minPulse));
}

int pulseWidthToPwm(int microseconds) {
  // Converts microseconds to PWM value
  int pwmVal = (microseconds * 4096) / 20000;
  return pwmVal;
}
