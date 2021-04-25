
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_LIS3DH` class instance
    auto sensor = getValue<input_DEV>(ctx);

    sensor->setRange((lis3dh_range_t)getValue<input_RANGE>(ctx));

    emitValue<output_DONE>(ctx, 1);
}
