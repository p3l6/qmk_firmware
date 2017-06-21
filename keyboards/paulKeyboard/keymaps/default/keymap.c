/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "paulKeyboard.h"

#define BASE_LAYER 0
#define FN_LAYER   1
#define FLIP_LAYER 2

#define _______ KC_TRNS


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE_LAYER] = KEYMAP(
  KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSPC, KC_BSLS, \
   KC_TAB,     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,    KC_DEL, \
MO(FN_LAYER),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,     KC_ENT, MO(FN_LAYER), \
    KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,    KC_UP,    KC_RSFT, \
      KC_LCTL,  KC_LALT,  KC_LGUI, MO(FLIP_LAYER),    KC_SPC,  KC_SPC,                   KC_RGUI,   KC_LEFT, KC_DOWN, KC_RIGHT  \
),
[FN_LAYER] = KEYMAP(
  KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F16,  KC_F17,  KC_F18,  KC_F19, \
   KC_BSPC,  KC_SLCK, KC_PAUS, LCTL(KC_UP), LGUI(KC_TILD), _______, _______, _______, _______, _______, _______,    M(0),   M(1),    KC_GRV, \
    _______,   KC_MUTE, KC_VOLD, KC_VOLU, LGUI(KC_TAB), _______, _______, _______, _______, _______, _______, M(2),    KC_PENT, _______, \
    KC_CAPS,     KC_MRWD, KC_MPLY, KC_MFFD, _______, _______,     M(4), _______, _______,    M(3), _______,   KC_PGUP,    _______, \
      _______,  _______,  _______, _______,     _______, _______,                        _______,   KC_HOME, KC_PGDN,  KC_END  \
),
[FLIP_LAYER] = KEYMAP(
  KC_MINS,    KC_0,    KC_9,    KC_8,    KC_7,    KC_6,  KC_EQL, _______, KC_NLCK, KC_PEQL, KC_PSLS, KC_PAST, _______, _______,   RESET, \
   KC_BSPC,     KC_P,    KC_O,    KC_I,    KC_U,    KC_Y, _______, _______,   KC_P7,  KC_P8,  KC_P9,  KC_PMNS, _______,   _______, \
     KC_ENT,   KC_SCLN,    KC_L,    KC_K,    KC_J,    KC_H, KC_QUOT, _______,   KC_P4,  KC_P5,  KC_P6, KC_PPLS,    _______, _______, \
  OSM(MOD_LSFT),  KC_SLSH, KC_DOT, KC_COMM,    KC_M,    KC_N, _______, _______,    KC_P1,  KC_P2,  KC_P3,   KC_PENT,    _______, \
      KC_LCTL,  KC_LALT,  KC_LGUI, _______,      KC_SPC,  KC_SPC,                        KC_P0,   KC_PDOT, KC_PENT, _______  \
),
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0: // block comment  / *
          if (record->event.pressed) {
          } else {
            return MACRO( T(SLSH), D(LSFT), T(8), U(LSFT),  END);
          }
          break;

        case 1: // block comment  * /
          if (record->event.pressed) {
          } else {
            return MACRO(  D(LSFT), T(8), U(LSFT), T(SLSH),  END);
          }
          break;

        case 2: // @"%@"
          if (record->event.pressed) {
          } else {
            return MACRO( D(LSFT), T(2), T(QUOT), T(5), T(2), T(QUOT), U(LSFT),  END);
          }
          break;

        case 3: // ->
          if (record->event.pressed) {
          } else {
            return MACRO( T(MINS), D(LSFT), T(DOT), U(LSFT),  END);
          }
          break;
	case 4: // NSString*
          if (record->event.pressed) {
          } else {
            return MACRO( D(LSFT), T(N), T(S), T(S), U(LSFT), T(T),T(R),T(I),T(N),T(G), D(LSFT), T(8), U(LSFT),  END);
          }
          break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
