
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10

//RF24 declaration
RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";



// the setup function runs once when you press reset or power the board
void setup() {
  //pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  //pinMode(LED_BUILTIN, HIGH);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();

  

}

// the loop function runs over and over again forever
void loop() {
  
  while(!Serial.available()) {}
  String buffer = Serial.readStringUntil("\n");
  //String buffer = "5";
  buffer.trim();
  int ESCode = buffer.toInt();
  //char buffer[] = "hello";

  //while (!radio.available()){}
  radio.write(&ESCode, sizeof(ESCode));
  //radio.write(&buffer,sizeof(buffer));
  Serial.println(String(ESCode));

  
  delay(1000);


  
}
