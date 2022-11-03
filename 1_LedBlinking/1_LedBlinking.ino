#define blueLED 02

void setup() {
   pinMode(blueLED, OUTPUT);
}

void loop() {
  digitalWrite(blueLED, !HIGH);
  delay(1000);
  digitalWrite(blueLED, !LOW);
  delay(1000);
}
