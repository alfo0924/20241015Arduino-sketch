

void setup() {
  // 設置初始化代碼，只運行一次
  Serial.begin(9600);  // 初始化串口通信，波特率為9600
  pinMode(13,INPUT);
}



void loop() {
int val = analogRead(13);
Serial.println(val/409);


delay(100);
// int val2 = (val/10);
// if (val2 <= 409 && val2 >= 350 ){
//   Serial.println(10);
// }
// else if(val2 <=349 && val2 >=200 ){
//   Serial.println(9);
// }
// else if(val2 <=199 && val2 >=150 ){
//   Serial.println(8);
// }
// else if(val2 <=149 && val2 >=120 ){
//   Serial.println(7);
// }
// else if(val2 <=119 && val2 >=100 ){
//   Serial.println(6);
// }
// else if(val2 <=99 && val2 >=80 ){
//   Serial.println(5);
// }
// else if(val2 <=79 && val2 >=60){
//   Serial.println(4);
// }
// else if(val2 <=59 && val2 >=40){
//   Serial.println(3);
// }
// else if(val2 <=39 && val2 >=20){
//   Serial.println(2);
// }
// else if(val2 <=19 && val2 >=5 ){
//   Serial.println(1);
// }

}
