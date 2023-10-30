#define PIN_RELAY1 GPIO_NUM_32
#define PIN_RELAY2 GPIO_NUM_33

//The setup function is called once at startup of the sketch
void setup()
{
  Serial.begin(9600);
  delay(10);
  Serial.println("Hallo!");

  pinMode(PIN_RELAY1, OUTPUT);
  digitalWrite(PIN_RELAY1, 0);

  pinMode(PIN_RELAY2, OUTPUT);
  digitalWrite(PIN_RELAY2, 0);
}

// The loop function is called in an endless loop
void loop()
{
//  Serial.println("Hallo!");
  if (Serial.available() > 0) {
    int c = Serial.read();
    switch (c) {
      case '0':
        digitalWrite(PIN_RELAY1, 0);
        digitalWrite(PIN_RELAY2, 0);
        break;
      case '1':
        digitalWrite(PIN_RELAY1, 1);
        digitalWrite(PIN_RELAY2, 0);
        break;
      case '2':
        digitalWrite(PIN_RELAY1, 0);
        digitalWrite(PIN_RELAY2, 1);
        break;
      case '3':
        digitalWrite(PIN_RELAY1, 1);
        digitalWrite(PIN_RELAY2, 1);
        break;
    }
  }
}
