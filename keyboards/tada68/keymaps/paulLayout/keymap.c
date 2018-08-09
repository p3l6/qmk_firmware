#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _NL 2

enum custom_keycodes {
    Z_NSSTR = SAFE_RANGE,
    Z_NSLOG,
    Z_ATQOT,
    Z_ARROW,
    Z_STCMT,
    Z_ENCMT,
    Z_SFRMT,
    Z_PARAM,
};

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BL] = LAYOUT_ansi(
  KC_GESC,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,  KC_MINS, KC_EQL,   KC_BSPC,  KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,  KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
  MO(_FL),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L, KC_SCLN, KC_QUOT,     KC_ENT,   LT(_FL,KC_PGUP),  \
  KC_LSFT,     KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH,      KC_RSFT, KC_UP,  KC_PGDN, \
  KC_LCTL, KC_LALT, KC_LGUI,                KC_SPC,                      KC_RGUI, KC_RCTL, TG(_NL), KC_LEFT, KC_DOWN, KC_RGHT),

[_FL] = LAYOUT_ansi(
  KC_ESC, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,    _______,         KC_HOME ,  \
  KC_BSPC,KC_SLCK, KC_PAUS,LCTL(KC_UP),_______,BL_TOGG,BL_DEC,BL_INC,_______,_______,_______,Z_STCMT,Z_ENCMT, Z_SFRMT, KC_END, \
  _______,KC_MUTE, KC_VOLD, KC_VOLU, _______,_______,_______,_______,_______,Z_NSLOG,Z_PARAM, Z_ATQOT,    KC_PENT,    _______, \
  KC_CAPS,KC_MRWD, KC_MPLY, KC_MFFD, _______,_______,Z_NSSTR,_______,_______,Z_ARROW,_______,         KC_BTN1,KC_MS_U,KC_BTN2, \
  _______,_______, LCTL(LALT(KC_DOWN)),                  KC_ENT,     _______,  KC_NO,  KC_NO,         KC_MS_L,KC_MS_D,KC_MS_R),

[_NL] = LAYOUT_ansi(
  _______,_______,_______,_______,_______,_______,_______,KC_PSLS,KC_PAST,KC_PMNS,_______,_______,_______,_______    ,_______,  \
  _______,  _______,_______,_______,_______,_______,  KC_P7,  KC_P8,  KC_P9,KC_PPLS,_______,_______,_______,_______  ,_______, \
  _______,   _______,_______,_______,_______,_______,  KC_P4,  KC_P5,  KC_P6,KC_PENT,_______,_______,      _______   ,_______, \
  _______,     KC_F16 , KC_F17, KC_F18, KC_F19,_______,  KC_P1,  KC_P2,  KC_P3,KC_PENT,_______,  _______,     _______,_______, \
  _______,_______,_______,                        KC_P0,               KC_PDOT,_______,KC_TRNS,       _______,_______,_______),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // See https://docs.qmk.fm/macros.html
  if (record->event.pressed) {
    switch(keycode) {
      case Z_NSSTR:
        SEND_STRING("NSString*");
        return false; break;
      case Z_NSLOG:
        SEND_STRING("NSLog(@\"\");"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        return false; break;
      case Z_ATQOT:
        SEND_STRING("@\"%@\",");
        return false; break;
      case Z_ARROW:
        SEND_STRING("->");
        return false; break;
      case Z_STCMT:
        SEND_STRING("/*");
        return false; break;
      case Z_ENCMT:
        SEND_STRING("*/");
        return false; break;
      case Z_SFRMT:
        SEND_STRING("\\()"SS_TAP(X_LEFT));
        return false; break;
      case Z_PARAM:
        SEND_STRING(":()"SS_TAP(X_LEFT));
        return false; break;
    }
  }
  return true;
}

void led_set_user(uint8_t usb_led) {
	if ( (usb_led & (1<<USB_LED_CAPS_LOCK)) || (layer_state & (1<<_NL)) ) {
        // Turn capslock on
        PORTB &= ~(1<<2);
    } else {
        // Turn capslock off
        PORTB |= (1<<2);
    }
}
