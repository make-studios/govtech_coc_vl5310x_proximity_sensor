/* This example shows how to use continuous mode to take
range measurements with the VL53L0X. It is based on
vl53l0x_ContinuousRanging_Example.c from the VL53L0X API.
The range readings are in units of mm. */

#include <VL53L0X.h>
#include <Wire.h>

VL53L0X sensor;

void setup() {
  Serial.begin(9600);
  // Use 21, 22 as SDA/SCL
  Wire.begin();

  // Use non-standard SDA/SCL pins
  // Wire.begin(5, 17);

  sensor.setTimeout(500);
  if (!sensor.init()) {
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {
    }
  }

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor.startContinuous();
}

void loop() {
  Serial.print(sensor.readRangeContinuousMillimeters());
  if (sensor.timeoutOccurred()) {
    Serial.print(" TIMEOUT");
  }

  Serial.println();
}
