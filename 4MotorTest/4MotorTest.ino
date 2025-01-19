#include <Servo.h>
#define MOTOR_ONE 9
#define MOTOR_TWO 6

Servo ESC_1;
//Servo ESC_2;

void setup() {
  // put your setup code here, to run once:
  ESC_1.attach(MOTOR_ONE, 1000, 2000);
  //ESC_2.attach(MOTOR_TWO, 1000, 2000);

}

void loop() {
  // put your main code here, to run repeatedly:
  ESC_1.write(180);
  //ESC_2.attach(100);

}



