
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_LIS3DH` class instance
    auto sensor = getValue<input_DEV>(ctx);

    sensor->setClick(getValue<input_MODE>(ctx),
                     getValue<input_THRESHOLD>(ctx),
                     getValue<input_T_LIMIT>(ctx),
                     getValue<input_T_LATENCY>(ctx),
                     getValue<input_T_WINDOW>(ctx));

    emitValue<output_DONE>(ctx, 1);
}
