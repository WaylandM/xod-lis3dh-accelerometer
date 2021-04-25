
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
        
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_LIS3DH` class instance
    auto sensor = getValue<input_DEV>(ctx);

    sensor->setDataRate((lis3dh_dataRate_t)getValue<input_RATE>(ctx));

    emitValue<output_DONE>(ctx, 1);
}
