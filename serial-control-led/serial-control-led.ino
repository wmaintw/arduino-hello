const byte LED = 13;
char val;

void setup()
{
  pinMode( 13 , OUTPUT);
  Serial.begin(57600);
  Serial.println("Welcome to Arduino!");
}

void loop()
{
  if (Serial.available()) {
    val = Serial.read();
    switch (val) {
      case '0':
        digitalWrite(LED, LOW);
        Serial.println("LED OFF");
        break;
      case '1':
        digitalWrite(LED, HIGH);
        Serial.println("LED ON");
        break;
      default:
        Serial.println("Unkown command");
    }
  }

  if () {
  }
}


