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
#include "foobarMacro.h"

#define _______ KC_TRNS

enum custom_keycodes {
    Z_NSSTR = SAFE_RANGE,
    Z_NSLOG,
    Z_ATQOT,
    Z_ARROW,
    Z_STCMT,
    Z_ENCMT,
};

enum tap_dance_declarations {
  TD_PL_MN = 0,
  TD_MU_DV,
  TD_RN_STP,
  TD_EXPOSE,
  TD_BRKPNT,
  TD_CV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // See https://docs.qmk.fm/keycodes.html

[0] = KEYMAP( /* Base */
  TD(TD_BRKPNT),    KC_F16,    KC_F17,    KC_F18,    KC_F19, \
  TD(TD_RN_STP),    TG(2),    OSL(1),  LGUI(LSFT(KC_LBRC)),    LGUI(LSFT(KC_RBRC)),   \
  TD(TD_EXPOSE), LGUI(KC_H),    TD(TD_CV),    LCTL(KC_LEFT),    LCTL(KC_RGHT)   \
),

[1] = KEYMAP( /* First Layer */
  _______,   _______, _______, Z_STCMT, Z_ENCMT, \
  _______, _______, _______, Z_NSLOG, Z_ATQOT,   \
  RESET, _______, Z_NSSTR, _______, Z_ARROW  \
),

[2] = KEYMAP( /* First Layer */
  TD(TD_MU_DV), KC_BSPC, KC_P7, KC_P8, KC_P9, \
  TD(TD_PL_MN),_______ , KC_P4, KC_P5, KC_P6,   \
  KC_PDOT, KC_P0, KC_P1, KC_P2, KC_P3  \
),

};

qk_tap_dance_action_t tap_dance_actions[] = {
  // See https://docs.qmk.fm/tap_dance.html
  [TD_PL_MN] = ACTION_TAP_DANCE_DOUBLE(KC_PPLS, KC_PMNS),
  [TD_MU_DV] = ACTION_TAP_DANCE_DOUBLE(KC_PAST, KC_PSLS),
  [TD_RN_STP] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_R), LGUI(KC_DOT)),
  [TD_EXPOSE] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_UP), LCTL(KC_DOWN)),
  [TD_BRKPNT] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_BSLS), LGUI(KC_Y)),
  [TD_CV] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_V),LGUI(KC_C)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // See https://docs.qmk.fm/macros.html
  if (record->event.pressed) {
    switch(keycode) {
      case Z_NSSTR:
        SEND_STRING("NSString*");
        return true; break;
      case Z_NSLOG:
        SEND_STRING("NSLog(@\"\");"SS_TAP(X_LEFT)SS_TAP(X_LEFT)SS_TAP(X_LEFT));
        return true; break;
      case Z_ATQOT:
        SEND_STRING("@\"%@\",");
        return true; break;
      case Z_ARROW:
        SEND_STRING("->");
        return true; break;
      case Z_STCMT:
        SEND_STRING("/*");
        return true; break;
      case Z_ENCMT:
        SEND_STRING("*/");
        return true; break;
    }
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
