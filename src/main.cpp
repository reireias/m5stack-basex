#include <M5Stack.h>
#include <PS4Controller.h>

#define BASE_X_ADDR (0x22)

#define BASE_X_SERVO_ANGLE_ADDR (0x00)
#define BASE_X_SERVO_PULSE_ADDR (0x10)
#define BASE_X_PWM_DUTY_ADDR (0x20)
#define BASE_X_ENCODER_ADDR (0x30)
#define BASE_X_SPEED_ADDR (0x40)

#define BASE_X_CONFIG_ADDR (0x50)

#define NORMAL_MODE (0x00)
#define POSITION_MODE (0x01)
#define SPEED_MODE (0x02)

// the setup routine runs once when M5Stack starts up
void setup() {
    // Initialize the M5Stack object
    // M5.begin();
    M5.begin(true, false, true, true);
    M5.Power.begin();
    Serial.begin(115200);
    PS4.begin("24:0A:C4:5A:2E:5E");

    // LCD display
    M5.Lcd.print("Hello world! motor");

    // set mode
    /* int8_t mode = NORMAL_MODE; */
    /* uint8_t pos = 0;  // motor 1 */
    /* M5.I2C.writeByte(BASE_X_ADDR, BASE_X_CONFIG_ADDR + (0x10 * pos), mode);
     */
    /* Serial.begin(115200); */
    /* uint8_t bt_mac[6]; */
    /* esp_read_mac(bt_mac, ESP_MAC_BT); */
    /* Serial.printf("Bluetooth Mac Address =>
     * %02X:%02X:%02X:%02X:%02X:%02X\r\n", */
    /*               bt_mac[0], bt_mac[1], bt_mac[2], bt_mac[3], bt_mac[4], */
    /*               bt_mac[5]); */
}

// the loop routine runs over and over again forever
void loop() {
    M5.update();

    /* uint8_t pos = 0;  // motor 1 */

    /* // set motor speed */
    /* uint8_t addr = BASE_X_PWM_DUTY_ADDR + pos; */
    /* uint8_t duty = 10; */
    /* M5.I2C.writeByte(BASE_X_ADDR, addr, duty); */

    /* // get motor speed */
    /* uint8_t read_data; */
    /* M5.I2C.readByte(BASE_X_ADDR, addr, &read_data); */
    /* M5.Lcd.print(read_data); */
    if (PS4.isConnected()) {
        Serial.println("Connected!");
        if (PS4.data.button.up) Serial.println("Up Button");
        if (PS4.data.button.down) Serial.println("Down Button");
        if (PS4.data.button.left) Serial.println("Left Button");
        if (PS4.data.button.right) Serial.println("Right Button");

        if (PS4.data.button.upright) Serial.println("Up Right");
        if (PS4.data.button.upleft) Serial.println("Up Left");
        if (PS4.data.button.downleft) Serial.println("Down Left");
        if (PS4.data.button.downright) Serial.println("Down Right");

        if (PS4.data.button.triangle) Serial.println("Triangle Button");
        if (PS4.data.button.circle) Serial.println("Circle Button");
        if (PS4.data.button.cross) Serial.println("Cross Button");
        if (PS4.data.button.square) Serial.println("Square Button");

        if (PS4.data.button.l1) Serial.println("l1 Button");
        if (PS4.data.button.r1) Serial.println("r1 Button");

        if (PS4.data.button.l3) Serial.println("l3 Button");
        if (PS4.data.button.r3) Serial.println("r3 Button");

        if (PS4.data.button.share) Serial.println("Share Button");
        if (PS4.data.button.options) Serial.println("Options Button");

        if (PS4.data.button.ps) Serial.println("PS Button");
        if (PS4.data.button.touchpad) Serial.println("Touch Pad Button");

        if (PS4.data.button.l2) {
            Serial.print("l2 button at ");
            Serial.println(PS4.data.analog.button.l2, DEC);
        }
        if (PS4.data.button.r2) {
            Serial.print("r2 button at ");
            Serial.println(PS4.data.analog.button.r2, DEC);
        }

        if (PS4.event.analog_move.stick.lx) {
            Serial.print("Left Stick x at ");
            Serial.println(PS4.data.analog.stick.lx, DEC);
        }
        if (PS4.event.analog_move.stick.ly) {
            Serial.print("Left Stick y at ");
            Serial.println(PS4.data.analog.stick.ly, DEC);
        }
        if (PS4.event.analog_move.stick.rx) {
            Serial.print("Right Stick x at ");
            Serial.println(PS4.data.analog.stick.rx, DEC);
        }
        if (PS4.event.analog_move.stick.ry) {
            Serial.print("Right Stick y at ");
            Serial.println(PS4.data.analog.stick.ry, DEC);
        }

        if (PS4.data.status.charging)
            Serial.println("The controller is charging");
        if (PS4.data.status.audio)
            Serial.println("The controller has headphones attached");
        if (PS4.data.status.mic)
            Serial.println("The controller has a mic attached");

        Serial.print("Battey Percent : ");
        Serial.println(PS4.data.status.battery, DEC);

        Serial.println();
    }
    delay(1000);
}
