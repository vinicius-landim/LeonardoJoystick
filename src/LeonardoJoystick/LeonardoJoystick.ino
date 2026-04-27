#include <Joystick.h>

const int PIN_SENSOR = A0; 
const int ADC_MAX_VALUE = 1023; //10-bit ADC resolution
const int JOYSTICK_RANGE_MIN = -32768; //16-bit signed integer minimum (HID standard)
const int JOYSTICK_RANGE_MAX = 32767;  //16-bit signed integer maximum (HID standard)

Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
  0, 0,                  // Button Count, Hat Switch Count
  true, false, false,    // X-Axis enabled
  false, false, false,   // Rx, Ry, Rz
  false, false,          // Rudder, Throttle
  false, false, false    // Accelerator, Brake, Steering
);

int currentSensorValue = 0;
int scaledPosition = 0;

void setup() {
  pinMode(PIN_SENSOR, INPUT);

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(JOYSTICK_RANGE_MIN, JOYSTICK_RANGE_MAX);
}

void loop() {
  currentSensorValue = analogRead(PIN_SENSOR);

  // Maps 10-bit hardware to 16-bit software scale
  scaledPosition = map(currentSensorValue, 0, ADC_MAX_VALUE, JOYSTICK_RANGE_MIN, JOYSTICK_RANGE_MAX);

  Joystick.setXAxis(scaledPosition);

  delay(10);
}

