#include <BaseX.h>
#include <M5Stack.h>
#include <PS4Controller.h>

BASE_X base_x = BASE_X();

// the setup routine runs once when M5Stack starts up
void setup() {
    // Initialize the M5Stack object
    M5.begin(true, false, true, true);
    M5.Power.begin();

    Serial.begin(115200);
    PS4.begin((char *)"24:0A:C4:5A:2E:5E");

    // set mode
    base_x.SetMode(1, NORMAL_MODE);
    base_x.SetMode(2, NORMAL_MODE);

    // LCD display
    M5.Lcd.print("setup.");
}

// the loop routine runs over and over again forever
void loop() {
    M5.update();

    if (PS4.isConnected()) {
        Serial.println("Connected!");
        if (PS4.event.analog_move.stick.lx) {
            Serial.print("Left Stick x at ");
            Serial.println(PS4.data.analog.stick.lx, DEC);
        }
        if (PS4.event.analog_move.stick.ly) {
            Serial.print("Left Stick y at ");
            Serial.println(PS4.data.analog.stick.ly, DEC);
            if (PS4.data.analog.stick.ly < 10 &&
                PS4.data.analog.stick.ly > -10) {
                base_x.SetMotorSpeed(1, 0);
            } else {
                base_x.SetMotorSpeed(1, -PS4.data.analog.stick.ly);
            }
        }
        if (PS4.event.analog_move.stick.ry) {
            Serial.print("Right Stick y at ");
            Serial.println(PS4.data.analog.stick.ry, DEC);
            if (PS4.data.analog.stick.ry < 10 &&
                PS4.data.analog.stick.ry > -10) {
                base_x.SetMotorSpeed(2, 0);
            } else {
                base_x.SetMotorSpeed(2, -PS4.data.analog.stick.ry);
            }
        }
    } else {
        base_x.SetMotorSpeed(1, 0);
        base_x.SetMotorSpeed(2, 0);
    }

    delay(100);
}
