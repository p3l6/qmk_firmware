#include "gherkin.h"

#define BASE_L  0
#define TOP_L   1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE_L] = KEYMAP(
		MO(TOP_L),   KC_T,   KC_W,   KC_BSLS,   KC_R,   KC_SLSH,   S(KC_E),  KC_LSFT,  S(KC_G),   KC_EQL,
		KC_BSPC,    KC_L,    KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_G,    KC_H,
		KC_LEFT, KC_RGHT, KC_GT, KC_LT, KC_1, KC_2, KC_4, KC_8, KC_6,  KC_5),

[TOP_L] = KEYMAP(
		KC_TRNS, KC_TRNS, S(KC_W), LCTL(KC_W), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PLUS,
		KC_TRNS, KC_TRNS, KC_DOT, LALT(KC_DOT), KC_3, KC_TRNS, KC_MINS, LALT(LCTL(KC_F)), KC_TRNS, LCTL(KC_EQL),
		KC_LBRC, KC_PIPE, KC_COLN, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	keyevent_t event = record->event;
    (void)event;

	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

}
