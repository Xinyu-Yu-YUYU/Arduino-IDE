void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("LDR reading:");//串口监视器输出
  Serial.println(analogRead(A0));//输出LDR读数
  delay(10);
}
