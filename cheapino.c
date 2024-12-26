#include "wait.h"
#include "quantum.h"

uint32_t flash_led(uint32_t next_trigger_time, void *cb_arg) {
    static uint8_t _color_index = 3;
    switch (_color_index++) {
        case  0: rgblight_setrgb(  0, 255,   0); break;
        case  1: rgblight_setrgb(  0, 255, 128); break;
        case  2: rgblight_setrgb(  0, 255, 255); break;
        case  3: rgblight_setrgb(  0, 128, 255); break;
        case  4: rgblight_setrgb(  0,   0, 255); break;
        case  5: rgblight_setrgb(127,   0, 255); break;
        case  6: rgblight_setrgb(255,   0, 255); break;
        case  7: rgblight_setrgb(255,   0, 127); break;
        case  8: rgblight_setrgb(255,   0,   0); break;
        case  9: rgblight_setrgb(255, 128,   0); break;
        case 10: rgblight_setrgb(255, 255,   0); break;
        case 11: rgblight_setrgb(128, 255,   0); break;
        default: rgblight_setrgb(0, 0, 0); return 0;
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
