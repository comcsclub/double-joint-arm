void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(LED_BUILTIN , OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, HIGH);
  for (int I = 0; I < 200; I++) {
    digitalWrite(3, HIGH);
    delayMicroseconds(700);
    digitalWrite(3, LOW);
    delayMicroseconds(700);
  }
  digitalWrite(LED_BUILTIN,HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN,LOW);
  delay(500);
}
