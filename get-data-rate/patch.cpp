
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
    
    switch (sensor->getDataRate()) {
        case LIS3DH_DATARATE_1_HZ: state->view = CStringView("1 Hz"); break;
        case LIS3DH_DATARATE_10_HZ: state->view = CStringView("10 Hz"); break;
        case LIS3DH_DATARATE_25_HZ: state->view = CStringView("25 Hz"); break;
        case LIS3DH_DATARATE_50_HZ: state->view = CStringView("50 Hz"); break;
        case LIS3DH_DATARATE_100_HZ: state->view = CStringView("100 Hz"); break;
        case LIS3DH_DATARATE_200_HZ: state->view = CStringView("200 Hz"); break;
        case LIS3DH_DATARATE_400_HZ: state->view = CStringView("400 Hz"); break;

        case LIS3DH_DATARATE_POWERDOWN: state->view = CStringView("Powered Down"); break;
        case LIS3DH_DATARATE_LOWPOWER_5KHZ: state->view = CStringView("5 Khz Low Power"); break;
        case LIS3DH_DATARATE_LOWPOWER_1K6HZ: state->view = CStringView("16 Khz Low Power"); break;
    }

    //emitValue<output_RATE>(ctx, sensor->getDataRate());
    emitValue<output_RATE>(ctx, XString(&state->view));
    emitValue<output_DONE>(ctx, 1);
            
}
