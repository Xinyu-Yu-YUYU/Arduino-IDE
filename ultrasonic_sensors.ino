int trigPin = 2; //设置发射脚位
int echoPin = 8; //设置接收脚位
int ledPin = 7; //设置控制led灯的引脚
long duration; //回响信号高电平持续时间（单位：微秒）
long cm;//距离（单位：cm）

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(ledPin,INPUT);
}

void loop() {
  //用低高低电平发射一个脉冲
  //微秒级延时
  digitalWrite(trigPin,LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  //读取脉冲宽度，即为高电平持续时间
  duration = pulseIn(echoPin,HIGH);
  //注意pulseIn以微秒为单位
  cm = (duration * 0.034) / 2;

  //若距离在2-10cm之间则点亮led
  if(cm < 10){
    digitalWrite(ledPin,HIGH);
  }else{
    digitalWrite(ledPin,LOW);
  }
  delay(1);
}
