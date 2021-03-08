#include <M5Stack.h>

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

    // LCD display
    M5.Lcd.print("Hello world! motor");

    // set mode
    int8_t mode = NORMAL_MODE;
    uint8_t pos = 0;  // motor 1
    M5.I2C.writeByte(BASE_X_ADDR, BASE_X_CONFIG_ADDR + (0x10 * pos), mode);
}

// the loop routine runs over and over again forever
void loop() {
    M5.update();

    uint8_t pos = 0;  // motor 1

    // set motor speed
    uint8_t addr = BASE_X_PWM_DUTY_ADDR + pos;
    uint8_t duty = 10;
    M5.I2C.writeByte(BASE_X_ADDR, addr, duty);

    // get motor speed
    uint8_t read_data;
    M5.I2C.readByte(BASE_X_ADDR, addr, &read_data);
    M5.Lcd.print(read_data);

    delay(1000);
}
