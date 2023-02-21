void beginSerial() {
  Serial.begin(115200);
  delay(10);
  Serial.println("");
  Serial.println("");
  Serial.println(SKETCH);
  Serial.println(VERSION);
  Serial.println("");
}
