# m5stack-basex
M5Stack + BaseX with PlatformIO.

## Connect PS4 Controller
see: https://qiita.com/Geek493/items/8402ad875b88822e75ab

### 1. Check M5Stack bluetooth MAC address
```cpp
void setup() {
    Serial.begin(115200);

    // detect mac address
    uint8_t bt_mac[6];
    esp_read_mac(bt_mac, ESP_MAC_BT);
    Serial.printf("Bluetooth Mac Address => %02X:%02X:%02X:%02X:%02X:%02X\r\n", bt_mac[0], bt_mac[1], bt_mac[2], bt_mac[3], bt_mac[4], bt_mac[5]);
}
```

### 2. Write MAC address to PS4 controller
Write M5Stack's MAC address to PS4 controller.
