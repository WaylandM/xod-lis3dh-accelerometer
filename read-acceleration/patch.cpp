
struct State {
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {
    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;

    // Get a pointer to the `LIS3DHTR` class instance
    auto sensor = getValue<input_DEV>(ctx);
    emitValue<output_X>(ctx, sensor->getAccelerationX());
    emitValue<output_Y>(ctx, sensor->getAccelerationY());
    emitValue<output_Z>(ctx, sensor->getAccelerationZ());
    emitValue<output_DONE>(ctx, 1);
}
