#include <Arduino.h>
#include "RoboClawMotor.h"
#include "G2PololuMotor.h"
#include "RadioController.h"
#include "M3USDigitalEncoder.h"
#include "Led.h"

const float wheel_max = 0.25;

RoboClaw roboclaw1(&Serial3, 10000);
RoboClaw roboclaw2(&Serial4, 10000);
RoboClaw roboclaw3(&Serial5, 10000);

// Rover
RoboClawMotor wheel1(roboclaw1, 1);
RoboClawMotor wheel2(roboclaw1, 2);
RoboClawMotor wheel3(roboclaw2, 1);
RoboClawMotor wheel4(roboclaw2, 2);

// Steering
G2PololuMotor steering(37, 38);

// Encoder
M3USDigitalEncoder encoder(6);

// GRP
G2PololuMotor gpr1(33, 34);
G2PololuMotor gpr2(23, 22);
G2PololuMotor gpr3(36, 41);

// Solar Panels
G2PololuMotor panel(19, 18);

// Radio Controller
RadioController radio;
RadioControllerStick radio_wheel(radio, 7);
RadioControllerStick radio_steering(radio, 8);
RadioControllerThreeWaySwitch radio_driving(radio, 9);
RadioControllerThreeWaySwitch radio_ros(radio, 10);

RadioControllerThreeWaySwitch radio_gpr(radio, 12);
RadioControllerThreeWaySwitch radio_panel(radio, 11);

// Indicator
Led on(13);
Led radio_led(30);
Led gpr_led(31);
Led steering_led(29);

void testPrint(char *variable, float value) {
    Serial.print(variable);
    Serial.print(" : ");
    Serial.print(value);
    Serial.print("\n");
}

void testRadio() {
    testPrint("Speed", radio_wheel.value());
    testPrint("Angle", radio_steering.value());
    testPrint("Driving", radio_driving.value());
    testPrint("Driving", radio_ros.value());
}

void gprUpdate() {
    switch (radio_gpr.value()) {
    case -1:
        gpr1.speed(1);
        gpr2.speed(1);
        gpr3.speed(1);
        break;
    case 0:
        gpr1.speed(0);
        gpr2.speed(0);
        gpr3.speed(0);
        break;
    case 1:
        gpr1.speed(-1);
        gpr2.speed(-1);
        gpr3.speed(-1);
        break;
    }
}

void panelUpdate(){
    switch (radio_panel.value()) {
    case -1:
        panel.speed(1);
        break;
    case 0:
        panel.speed(0);
        break;
    case 1:
        panel.speed(-1);
        break;
    }
}

void steeringUpdate(){
    float s = radio_steering.value();
    steering.speed(-s);
}

void wheelUpdate(){
    float s = radio_wheel.value();
    //Serial.println(s);
    s = map(s, -1.0, 1.0, wheel_max, -wheel_max);
    wheel1.speed(s);
    wheel2.speed(s);
    wheel3.speed(s);
    wheel4.speed(s);
}

void setup() {
    Serial.begin(115200);
    roboclaw1.begin(115200);
    roboclaw2.begin(115200);
    roboclaw3.begin(115200);
    on.on();
}

void loop() {
    Serial.println(encoder.angle());
    gprUpdate();
    panelUpdate();
    steeringUpdate();
    wheelUpdate();
}
