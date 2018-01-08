#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

enum custom_keycodes {
    Z_NSSTR = SAFE_RANGE,
    Z_NSLOG,
    Z_ATQOT,
    Z_ARROW,
    Z_STCMT,
    Z_ENCMT,
    Z_SFRMT,
};

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |Fn     |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Alt | Cmd|        Space          |Cmd| FN| alt|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  KC_GESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_GRV, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_DEL, \
  MO(_FL) , KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGUP,  \
  KC_LSFT,     KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_PGDN, \
  KC_LCTL,KC_LALT, KC_LGUI,                KC_SPC,                        KC_RGUI,MO(_FL),KC_RALT, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |Esc| F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|       |    |
   * |----------------------------------------------------------------|
   * | Bksp|bdn|bup|exp|  |Bl-|BL |BL+|   |   |   | M | M |  M   |    |
   * |----------------------------------------------------------------|
   * |  Fn  |mut|vdn|vup|   |   |   |   |   |  M|   | M |Num Ret |Hme |
   * |----------------------------------------------------------------|
   * |  CAPS  |prv|ply|nxt|   |   | M |   |   | M |   |      |   |End |
   * |----------------------------------------------------------------|
   * |    |    |    |            Enter     |Dup| Fn | F16|F17|F18|f19 |
   * `----------------------------------------------------------------'
   */
[_FL] = KEYMAP_ANSI(
  KC_ESC, KC_F1 ,KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______ ,  \
  KC_BSPC,KC_SLCK, KC_PAUS, LCTL(KC_UP), _______,BL_DEC,BL_TOGG,BL_INC,_______,_______, _______,    Z_STCMT,Z_ENCMT,Z_SFRMT,_______, \
  _______,KC_MUTE, KC_VOLD, KC_VOLU, _______,_______,_______,_______,_______,Z_NSLOG,_______, Z_ATQOT,    KC_PENT, KC_HOME, \
  KC_CAPS,KC_MRWD, KC_MPLY, KC_MFFD, _______,_______,Z_NSSTR,_______,_______,Z_ARROW,_______,_______, _______, KC_END, \
  _______,_______,_______,                 KC_ENT,          LCTL(LALT(KC_DOWN)),_______,KC_F16,KC_F17,KC_F18, KC_F19),
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
    }
  }
  return true;
}
