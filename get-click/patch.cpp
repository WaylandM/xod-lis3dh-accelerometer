
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `Adafruit_LIS3DH` class instance
    auto sensor = getValue<input_DEV>(ctx);

    uint8_t click = sensor->getClick();

    if (click == 0) {
        emitValue<output_DONE>(ctx, 1);
        return;
    }
    
    if (! (click & 0x30)) {
        emitValue<output_DONE>(ctx, 1);
        return;
    }

    if (click & 0x10)
        emitValue<output_SNG>(ctx, 1);
    if (click & 0x20)
        emitValue<output_DBL>(ctx, 1);
    
    emitValue<output_DONE>(ctx, 1);
}
