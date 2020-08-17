// Tell XOD where it could download the library:
#pragma XOD require "https://github.com/Seeed-Studio/Seeed_Arduino_LIS3DHTR"

//Include C++ libraries
{{#global}}
#include <Wire.h>
#include <LIS3DHTR.h>
#define WIRE Wire
{{/global}}

struct State {
    uint8_t mem[sizeof(LIS3DHTR<TwoWire>)];
};

// Define our custom type as a pointer on the class instance.
using Type = LIS3DHTR<TwoWire>*;

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // It should be evaluated only once on the first (setup) transaction
    if (!isSettingUp())
        return;

    auto state = getState(ctx);
    auto address = getValue<input_ADDR>(ctx);

    // Create a new object in the memory area reserved previously.
    Type sensor = new (state->mem) LIS3DHTR<TwoWire>();
    
    sensor->begin(WIRE, address);
    delay(100);

    if (!sensor) {
      raiseError(ctx);
      return;
    }
    
    sensor->setOutputDataRate(LIS3DHTR_DATARATE_50HZ);
    

    emitValue<output_DEV>(ctx, sensor);
}
