
struct State {
    CStringView view;
};

{{ GENERATED_CODE }}

void evaluate(Context ctx) {

    // The node responds only if there is an input pulse
    if (!isInputDirty<input_UPD>(ctx))
        return;
    
    // Get a pointer to the `Adafruit_LIS3DH` class instance
    auto sensor = getValue<input_DEV>(ctx);

    auto state = getState(ctx);
    
    switch (sensor->getRange()) {
        case LIS3DH_RANGE_16_G: state->view = CStringView("+/- 16g"); break;
        case LIS3DH_RANGE_8_G: state->view = CStringView("+/- 8g"); break;
        case LIS3DH_RANGE_4_G: state->view = CStringView("+/- 4g"); break;
        case LIS3DH_RANGE_2_G: state->view = CStringView("+/- 2g"); break;
    }

    emitValue<output_RANGE>(ctx, XString(&state->view));
    emitValue<output_DONE>(ctx, 1);

}
