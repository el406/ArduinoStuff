#include <Adafruit_PWMServoDriver.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>
#include <Wire.h>

#define CE_PIN 9
#define CSN_PIN 10
#define MOTOR_PIN_ONE 6
#define MOTOR_ONE 0
#define MOTOR_TWO 1
#define MOTOR_THREE 2
#define MOTOR_FOUR 3

// BLDC manager init
Adafruit_PWMServoDriver BLDCManager = Adafruit_PWMServoDriver(0x40);


// radio setup
RF24 radio(CE_PIN, CSN_PIN); // CE, CSN
const byte address[6] = "00001";

// Servo Driver init

void setup() {
  BLDCManager.begin();
  BLDCManager.setPWMFreq(50.0f);
  for (int i = 0; i < 4; ++i)
  {
    BLDCManager.writeMicroseconds(i, 1000);
  }
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
}

void loop() {
 
  if (radio.available()) {
    //char buffer[32] = '';
    Serial.println("reading...");
    int buffer=0;
    radio.read(&buffer, sizeof(buffer));
    int ESC_ID;
    int value;
    if(buffer < 100)
    {
      ESC_ID = floor(buffer/10);
      value = 0;
    }
    else{
      (buffer > 1000 ? ESC_ID = floor(buffer/1000) : ESC_ID = floor(buffer/100));
      (buffer > 1000 ? value = buffer - (ESC_ID*1000) : value = buffer - (ESC_ID*100));
      //Serial.println(String(ESC_ID));
     
    }


    float inputValue = map(value, 0,100, 1000, 2000);
    float inputAmpedDown = map(value, 0, 100, 1440,2000);

    //Serial.println(buffer);
    switch (ESC_ID){
      case 1:
        Serial.println("Changing motor one");
        Serial.println(String(inputValue));
        BLDCManager.writeMicroseconds(MOTOR_ONE, inputValue);
        break;
      case 2:
        Serial.println("Changing motor two");
        BLDCManager.writeMicroseconds(MOTOR_TWO, inputValue);
        break;
      case 3:
        Serial.println("Changing motor three");
        BLDCManager.writeMicroseconds(MOTOR_THREE, inputValue);
        break;
      case 4:
        Serial.println("Changing motor four");
        BLDCManager.writeMicroseconds(MOTOR_FOUR, inputAmpedDown);
        break;
      case 5:
        Serial.println("Changing ALL MOTORS");
        BLDCManager.writeMicroseconds(MOTOR_ONE, inputValue);
        BLDCManager.writeMicroseconds(MOTOR_TWO, inputValue);
        BLDCManager.writeMicroseconds(MOTOR_THREE, inputValue);
        BLDCManager.writeMicroseconds(MOTOR_FOUR, inputAmpedDown);
        break;
    }
  }
}

