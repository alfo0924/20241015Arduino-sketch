// 設置第二個按鈕的引腳
const int button2Pin = 14;  // 假設第二個按鈕連接到引腳14

void setup() {
  // 設置初始化代碼，只運行一次
  Serial.begin(9600);  // 初始化串口通信，波特率為9600
  pinMode(16, INPUT_PULLUP);  // 設置引腳16為輸入模式，啟用內部上拉電阻
  pinMode(2, INPUT_PULLUP);  // 設置第二個按鈕引腳為輸入模式，啟用內部上拉電阻
  pinMode(4, OUTPUT);  // 設置引腳4為輸出模式
  pinMode(5, OUTPUT);  // 設置引腳5為輸出模式
  pinMode(0, OUTPUT);  // 設置引腳0為輸出模式
  digitalWrite(4, LOW);  // 初始化引腳4為低電平
  digitalWrite(5, LOW);  // 初始化引腳5為低電平
  digitalWrite(0, LOW);  // 初始化引腳0為低電平
}



void loop() {
  for(int i=0; i<255 ; i++){
    analogWrite(4,i);
    delay(100);
  }
}
