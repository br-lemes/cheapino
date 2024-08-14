#include "wait.h"
#include "quantum.h"

void fix_setrgb(uint8_t r, uint8_t g, uint8_t b) {
    rgblight_setrgb(g, r, b);
}

uint32_t flash_led(uint32_t next_trigger_time, void *cb_arg) {
    static uint8_t _color_index = 3;
    switch (_color_index++) {
        case  0: fix_setrgb(  0, 255,   0); break;
        case  1: fix_setrgb(  0, 255, 128); break;
        case  2: fix_setrgb(  0, 255, 255); break;
        case  3: fix_setrgb(  0, 128, 255); break;
        case  4: fix_setrgb(  0,   0, 255); break;
        case  5: fix_setrgb(127,   0, 255); break;
        case  6: fix_setrgb(255,   0, 255); break;
        case  7: fix_setrgb(255,   0, 127); break;
        case  8: fix_setrgb(255,   0,   0); break;
        case  9: fix_setrgb(255, 128,   0); break;
        case 10: fix_setrgb(255, 255,   0); break;
        case 11: fix_setrgb(128, 255,   0); break;
        default: fix_setrgb(0, 0, 0); return 0;
    }
    return 100;
}

void keyboard_post_init_user(void) {
    defer_exec(50, flash_led, NULL);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 1: fix_setrgb(0, 0, 255); break;
        case 2: fix_setrgb(0, 255, 0); break;
        default: fix_setrgb(0, 0, 0); break;
    }
    return state;
}
