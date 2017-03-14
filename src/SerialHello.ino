// Simple 9600-baud "Hello World" program

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  Serial.println("Hello World!");
}
