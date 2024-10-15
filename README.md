
# sketch_oct15a.ino 解析
## Arduino LED控制程序介紹

這段程式碼實現了一個Arduino LED控制系統，通過兩個按鈕來控制三個LED的不同亮燈模式。

### 硬件設置

- 三個LED連接到引腳4、5和0
- 兩個按鈕分別連接到引腳16和2
- 使用內部上拉電阻，按鈕按下時為低電平

### 全局變量

```cpp
const int button2Pin = 14;  // 第二個按鈕引腳
bool p16 = digitalRead(16);  // 存儲引腳16的狀態
bool flag = LOW;  // 防止按鈕重複觸發的標誌
int led_sequence = 0;  // LED序列計數器
```

### 初始化函數 (setup)

```cpp
void setup() {
  Serial.begin(9600);  // 初始化串口通信
  pinMode(16, INPUT_PULLUP);  // 設置按鈕1引腳
  pinMode(2, INPUT_PULLUP);   // 設置按鈕2引腳
  pinMode(4, OUTPUT);  // 設置LED引腳
  pinMode(5, OUTPUT);
  pinMode(0, OUTPUT);
  digitalWrite(4, LOW);  // 初始化LED為關閉狀態
  digitalWrite(5, LOW);
  digitalWrite(0, LOW);
}
```

### 主循環函數 (loop)

主循環函數執行以下操作：

1. 讀取兩個按鈕的狀態
2. 通過串口輸出按鈕1的狀態
3. 根據按鈕狀態控制LED：
   - 如果按鈕2被按下，自動循環LED狀態
   - 如果按鈕1被按下，手動改變LED狀態
4. 使用標誌位防止按鈕1重複觸發

### LED狀態切換函數 (changeLEDState)

這個函數負責改變LED的亮燈模式：

1. 首先關閉所有LED
2. 根據`led_sequence`變量設置不同的LED組合
3. `led_sequence`範圍為0-7，對應8種不同的LED狀態
4. 每次調用後`led_sequence`增加1，超過7後重置為0

### LED狀態組合

1. 只亮引腳0的LED
2. 只亮引腳5的LED
3. 同時亮引腳5和0的LED
4. 只亮引腳4的LED
5. 同時亮引腳4和0的LED
6. 同時亮引腳4和5的LED
7. 同時亮三個LED
8. 全部LED關閉


這個程序展示了如何使用Arduino控制多個LED，並通過不同的按鈕輸入實現複雜的控制邏輯。它可以作為基礎，進一步擴展為更複雜的LED控制系統或其他互動項目。
