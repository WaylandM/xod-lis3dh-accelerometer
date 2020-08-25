
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_LIS3DH` class instance
    auto sensor = getValue<input_DEV>(ctx);

    int16_t adc;
    uint16_t volt;

    adc = lis.readADC(1);
    volt = map(adc, -32512, 32512, 1800, 900);
    emitValue<output_X>(ctx, volt);

    adc = lis.readADC(2);
    volt = map(adc, -32512, 32512, 1800, 900);
    emitValue<output_Y>(ctx, volt);

    adc = lis.readADC(3);
    volt = map(adc, -32512, 32512, 1800, 900);
    emitValue<output_Z>(ctx, volt);

    emitValue<output_DONE>(ctx, 1);
}
