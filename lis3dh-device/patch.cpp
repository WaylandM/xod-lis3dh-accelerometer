// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/adafruit/Adafruit_Sensor"
#pragma XOD require "https://github.com/adafruit/Adafruit_LIS3DH"
#pragma XOD require "https://github.com/adafruit/Adafruit_BusIO"

//Include C++ libraries
{{#global}}
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LIS3DH.h>
{{/global}}

struct State {
    uint8_t mem[sizeof(Adafruit_LIS3DH)];
};

// Define our custom type as a pointer on the class instance.
using Type = Adafruit_LIS3DH*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);
    auto address = getValue<input_ADDR>(ctx);

    // Create a new object in the memory area reserved previously.
    Type sensor = new (state->mem) Adafruit_LIS3DH();

    if (!sensor->begin(address)) {
      raiseError(ctx);
      return;
    }

    emitValue<output_DEV>(ctx, sensor);
}
