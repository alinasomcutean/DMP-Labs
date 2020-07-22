

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Light: "); 
  float light = readLight();
}
