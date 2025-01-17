
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


# sketch_oct15b.ino 解析
## Arduino LED 漸亮效果程序

這段程式碼實現了一個簡單的 Arduino LED 控制系統，主要功能是讓一個 LED 從暗到亮逐漸增加亮度。

### 硬件設置

- 一個 LED 連接到引腳 4
- 兩個按鈕分別連接到引腳 16 和 2（雖然在當前的 `loop` 函數中未使用）

### 全局變量

```cpp
const int button2Pin = 14;  // 第二個按鈕引腳（當前未使用）
```

### 初始化函數 (setup)

```cpp
void setup() {
  Serial.begin(9600);  // 初始化串口通信，波特率為9600
  pinMode(16, INPUT_PULLUP);  // 設置引腳16為輸入模式，啟用內部上拉電阻
  pinMode(2, INPUT_PULLUP);   // 設置第二個按鈕引腳為輸入模式，啟用內部上拉電阻
  pinMode(4, OUTPUT);  // 設置引腳4為輸出模式（LED連接處）
  pinMode(5, OUTPUT);  // 設置引腳5為輸出模式
  pinMode(0, OUTPUT);  // 設置引腳0為輸出模式
  digitalWrite(4, LOW);  // 初始化引腳4為低電平
  digitalWrite(5, LOW);  // 初始化引腳5為低電平
  digitalWrite(0, LOW);  // 初始化引腳0為低電平
}
```

這個函數完成以下初始化工作：

1. 設置串口通信，便於調試
2. 配置兩個按鈕引腳為輸入模式，並啟用內部上拉電阻
3. 設置三個 LED 引腳為輸出模式
4. 初始化所有 LED 為關閉狀態（低電平）

### 主循環函數 (loop)

```cpp
void loop() {
  for(int i=0; i<255 ; i++){
    analogWrite(4,i);
    delay(100);
  }
}
```

主循環函數執行以下操作：

1. 使用 `for` 循環，從 0 到 254 遍歷
2. 在每次循環中，使用 `analogWrite` 函數設置引腳 4 的 PWM 值
3. 每次設置後延遲 100 毫秒

### 程序功能解析

- **漸亮效果**：通過逐漸增加 PWM 值（0 到 254），實現 LED 從完全熄滅到最大亮度的漸變效果
- **PWM 控制**：`analogWrite` 函數用於產生 PWM 信號，控制 LED 亮度
- **循環結構**：使用 `for` 循環重複執行漸亮過程
- **延遲控制**：每次亮度變化後的 100 毫秒延遲控制了整個漸亮過程的速度

### 注意事項

1. 雖然程式碼中設置了兩個按鈕和三個 LED 引腳，但當前的 `loop` 函數只使用了引腳 4
2. 其他引腳（0 和 5）以及按鈕（引腳 16 和 2）的設置目前未被使用
3. 程序會不斷重複執行漸亮效果，沒有重置或暫停機制


# sketch_oct15c.ino 解析
## 模擬輸入讀取程序

這段程式碼實現了一個簡單的Arduino模擬輸入讀取系統，主要功能是讀取模擬引腳的值並進行簡單處理。

### 硬件設置

- 一個模擬輸入設備（如可變電阻器）連接到引腳13

### 初始化函數 (setup)

```cpp
void setup() {
  Serial.begin(9600);  // 初始化串口通信，波特率為9600
  pinMode(13, INPUT);  // 設置引腳13為輸入模式
}
```

這個函數完成以下初始化工作：

1. 設置串口通信，波特率為9600，用於數據輸出
2. 配置引腳13為輸入模式，準備讀取模擬值

### 主循環函數 (loop)

```cpp
void loop() {
  int val = analogRead(13);
  Serial.println(val/409);
  delay(100);
}
```

主循環函數執行以下操作：

1. 使用`analogRead`函數讀取引腳13的模擬值
2. 將讀取的值除以409，然後通過串口輸出
3. 延遲100毫秒後進行下一次讀取

### 程序功能解析

- **模擬讀取**：`analogRead`函數讀取模擬輸入，返回0-1023之間的值
- **數值處理**：將讀取的值除以409，effectively mapping the range 0-1023 to 0-2.5
- **串口輸出**：處理後的值通過串口輸出，便於觀察和調試
- **延遲控制**：每次讀取後延遲100毫秒，控制讀取頻率

### 注釋掉的代碼部分

程式中包含了一段被注釋掉的代碼，這部分實現了一個更詳細的值映射機制：

- 將原始讀數除以10（`val2 = val/10`）
- 根據`val2`的值範圍，輸出1到10之間的整數
- 這種映射方式可以將模擬輸入值分為10個不同的等級

### 可能的應用和擴展

1. **電位器讀取**：如果連接的是電位器，這個程序可以用來讀取電位器的位置
2. **光敏電阻應用**：如果使用光敏電阻，可以用來測量環境光強度
3. **溫度感測器**：配合溫度感測器使用，可以讀取環境溫度
