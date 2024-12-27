#include "wait.h"
#include "quantum.h"

uint32_t flash_led(uint32_t next_trigger_time, void *cb_arg) {
    static uint32_t _hue_countdown = 50;
    rgblight_sethsv(_hue_countdown * 5, 230, 70);
    _hue_countdown--;
    if (_hue_countdown == 0) {
        rgblight_setrgb(0, 0, 0);
        return 0;
    }
    return 100;
}

void keyboard_post_init_user(void) {
    defer_exec(50, flash_led, NULL);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 1: rgblight_setrgb(0, 0, 255); break;
        case 2: rgblight_setrgb(0, 255, 0); break;
        case 3: rgblight_setrgb(255, 0, 0); break;
        default: rgblight_setrgb(0, 0, 0); break;
    }
    return state;
}
