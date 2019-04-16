#include "gherkin.h"

#define BASE_L  0
#define NUM_L   1
#define FUN_L   2
#define ARROW_L  3
#define TOP_L   4 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE_L] = KEYMAP(
		KC_Q,     KC_W, KC_E, KC_R, KC_T,    KC_Y,   KC_U, KC_I, KC_O, KC_P,
		KC_A,        KC_S, KC_D, KC_F, KC_G,    KC_H,   KC_J, KC_K, KC_L, KC_SPC, 
		MT(MOD_LCTL,KC_Z), MT(MOD_LALT,KC_X), MT(MOD_LGUI,KC_C),
		 MT(MOD_RGUI,KC_V), LT(FUN_L,KC_B), LT(NUM_L,KC_N), 
 		  LT(ARROW_L,KC_M), LT(TOP_L,KC_ESC), KC_BSPC, MT(MOD_RSFT,KC_ENT)),

[NUM_L] = KEYMAP(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, 
		KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,  KC_TRNS),

[FUN_L] = KEYMAP(
		KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_TRNS, 
		KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[ARROW_L] = KEYMAP(
		KC_GRV,  KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, 
		KC_TAB,  KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_COMM, KC_DOT,  KC_SLSH, KC_SCLN, KC_QUOT, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[TOP_L] = KEYMAP(
		KC_TILD, KC_HOME, KC_PGUP, KC_TRNS, KC_TRNS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, 
		KC_TRNS, KC_END,  KC_PGDN, KC_TRNS, KC_TRNS, KC_LABK, KC_RABK, KC_QUES, KC_COLN, KC_DQUO, 
		RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
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
