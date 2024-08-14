#include QMK_KEYBOARD_H

// KC_SCLN  çÇ
// KC_SLSH  ;:
// KC_GRV   '"
// KC_QUOT  ~^
// KC_LBRC  ´`
// KC_RBRC  [{
// KC_BSLS  ]}
// KC_NUBS  \|
// KC_INT1  /?

#define TH_Q LT(0, KC_Q)
#define TH_W LT(0, KC_W)
#define TH_F LT(0, KC_F)
#define TH_P LT(0, KC_P)
#define TH_B LT(0, KC_B)
#define TH_J LT(0, KC_J)
#define TH_L LT(0, KC_L)
#define TH_U LT(0, KC_U)
#define TH_Y LT(0, KC_Y)
#define TH_SCLN LT(0, KC_SCLN)

#define TH_Z LT(0, KC_Z)
#define TH_X LT(0, KC_X)
#define TH_C LT(0, KC_C)
#define TH_D LT(0, KC_D)
#define TH_V LT(0, KC_V)
#define TH_K LT(0, KC_K)
#define TH_H LT(0, KC_H)
#define TH_COMM LT(0, KC_COMM)
#define TH_DOT LT(0, KC_DOT)
#define TH_INT1 LT(0, KC_INT1)

#define TH_G LT(0, KC_G)
#define TH_M LT(0, KC_M)

#define TH_F11 LT(0, KC_F11)
#define TH_F12 LT(0, KC_F12)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_split_3x5_3(
		TH_Q, TH_W, TH_F, TH_P, TH_B,
			TH_J, TH_L, TH_U, TH_Y, TH_SCLN,
		LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), TH_G,
			TH_M, RSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O),
		TH_Z, TH_X, TH_C, TH_D, TH_V,
			TH_K, TH_H, TH_COMM, TH_DOT, TH_INT1,
		LT(1, KC_SPC), LT(2, KC_TAB), LT(3, KC_NO),
			LT(3, KC_NO), KC_ENT, KC_BSPC
	),
	[1] = LAYOUT_split_3x5_3(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_PGUP, KC_HOME, KC_UP, KC_END, KC_INS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
			KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,
		LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_Y),
			TH_F11, TH_F12, KC_APP, KC_PSCR, KC_CAPS,
		KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_TRNS, KC_TRNS
	),
	[2] = LAYOUT_split_3x5_3(
		KC_ESC, KC_GRV, KC_QUOT, KC_LBRC, KC_NUBS,
			KC_RBRC, KC_BSLS, KC_MINUS, KC_EQUAL, KC_SLSH,
		LGUI_T(KC_F1), LALT_T(KC_F2), LCTL_T(KC_F3), LSFT_T(KC_F4), KC_F5,
			KC_F6, RSFT_T(KC_F7), LCTL_T(KC_F8), LALT_T(KC_F9), LGUI_T(KC_F10),
		KC_1, KC_2, KC_3, KC_4, KC_5,
			KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_TRNS, KC_TRNS, KC_TRNS,
			KC_TRNS, KC_TRNS, KC_TRNS
	),
	[3] = LAYOUT_split_3x5_3(
		KC_Q, KC_W, KC_F, KC_P, KC_B,
			KC_J, KC_L, KC_U, KC_Y, KC_SCLN,
		KC_A, KC_R, KC_S, KC_T, KC_G,
			KC_M, KC_N, KC_E, KC_I, KC_O,
		KC_Z, KC_X, KC_C, KC_D, KC_V,
			KC_K, KC_H, KC_COMM, KC_DOT, KC_INT1,
		KC_SPC, KC_TAB, KC_TRNS,
			KC_TRNS, KC_ENT, KC_BSPC
	)
};

static bool process_hold(keyrecord_t* record, uint16_t keycode) {
	if (record->tap.count == 0) {
		if (record->event.pressed) {
			tap_code16(keycode);
		}
		return false;
	}
	return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	switch (keycode) {
		case TH_Q: return process_hold(record, KC_ESC);
		case TH_W: return process_hold(record, KC_GRV);
		case TH_F: return process_hold(record, KC_QUOT);
		case TH_P: return process_hold(record, KC_LBRC);
		case TH_B: return process_hold(record, KC_NUBS);
		case TH_J: return process_hold(record, KC_RBRC);
		case TH_L: return process_hold(record, KC_BSLS);
		case TH_U: return process_hold(record, KC_MINUS);
		case TH_Y: return process_hold(record, KC_EQUAL);
		case TH_SCLN: return process_hold(record, KC_SLSH);
		case TH_Z: return process_hold(record, KC_1);
		case TH_X: return process_hold(record, KC_2);
		case TH_C: return process_hold(record, KC_3);
		case TH_D: return process_hold(record, KC_4);
		case TH_V: return process_hold(record, KC_5);
		case TH_K: return process_hold(record, KC_6);
		case TH_H: return process_hold(record, KC_7);
		case TH_COMM: return process_hold(record, KC_8);
		case TH_DOT: return process_hold(record, KC_9);
		case TH_INT1: return process_hold(record, KC_0);
		case TH_G: return process_hold(record, KC_NO);
		case TH_M: return process_hold(record, KC_NO);
		case TH_F11: return process_hold(record, KC_F11);
		case TH_F12: return process_hold(record, KC_F12);
	}
	return true;
}

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
