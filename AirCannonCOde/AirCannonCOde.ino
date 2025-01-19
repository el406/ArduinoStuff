#define BUTTON_PIN 12
#define RELAY_PIN 13

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);
  //Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  if(digitalRead(BUTTON_PIN))
  {
    digitalWrite(RELAY_PIN, HIGH);
  }
  else
  {digitalWrite(RELAY_PIN, LOW);}
  //delay(1000);

}
