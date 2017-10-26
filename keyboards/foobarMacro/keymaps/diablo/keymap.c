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
    Z_X = SAFE_RANGE,

    Z_HA, Z_1A, Z_2A,
    Z_HS, Z_1S, Z_2S,
    Z_HD, Z_1D, Z_2D,
    Z_HF, Z_1F, Z_2F, Z_3F,
};

enum tap_dance_declarations {
  TD_NOT_USED = 0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // See https://docs.qmk.fm/keycodes.html

[0] = KEYMAP( /* Base */
  MO(1),   KC_Q,    KC_W,    KC_E,   KC_T, \
  KC_LSFT, KC_A,    KC_S,    KC_D,   KC_F, \
  KC_C,    KC_LALT, KC_LGUI, KC_SPC, KC_NO \
),

[1] = KEYMAP( /* First Layer */
  _______, Z_X,     KC_M,    _______, KC_B,    \
  MO(2),   S(KC_J), KC_K,    KC_Y,    KC_U, \
  KC_O,    _______, RESET,   _______, KC_NO  \
),

[2] = KEYMAP( /* First Layer */
  _______, Z_HA,  Z_HS,  Z_HD,  Z_1F,    \
  MO(2),   Z_1A,  Z_1S,  Z_1D,  Z_2F, \
  Z_3F,    Z_2A,  Z_2S,  Z_2D,  KC_NO  \
),

};

qk_tap_dance_action_t tap_dance_actions[] = {};


static struct _Rep {
  struct _Delay {
    uint16_t a;
    uint16_t s;
    uint16_t d;
    uint16_t f;
  } delay;
  struct _Timer {
    uint16_t a;
    uint16_t s;
    uint16_t d;
    uint16_t f;
  } timer;
} Rep;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // See https://docs.qmk.fm/macros.html
  if (record->event.pressed) {
    switch(keycode) {
      case Z_X:
        Rep.delay.a = Rep.delay.s = Rep.delay.d = Rep.delay.f = 0;
        Rep.timer.a = Rep.timer.s = Rep.timer.d = Rep.timer.f = 0;
        return false; break;

      case Z_HA: Rep.delay.a = 500;  Rep.timer.a = timer_read(); return false; break;
      case Z_1A: Rep.delay.a = 1000; Rep.timer.a = timer_read(); return false; break;
      case Z_2A: Rep.delay.a = 2000; Rep.timer.a = timer_read(); return false; break;

      case Z_HS: Rep.delay.s = 500;  Rep.timer.s = timer_read(); return false; break;
      case Z_1S: Rep.delay.s = 1000; Rep.timer.s = timer_read(); return false; break;
      case Z_2S: Rep.delay.s = 2000; Rep.timer.s = timer_read(); return false; break;

      case Z_HD: Rep.delay.d = 500;  Rep.timer.d = timer_read(); return false; break;
      case Z_1D: Rep.delay.d = 1000; Rep.timer.d = timer_read(); return false; break;
      case Z_2D: Rep.delay.d = 2000; Rep.timer.d = timer_read(); return false; break;

      case Z_HF: Rep.delay.f = 500;  Rep.timer.f = timer_read(); return false; break;
      case Z_1F: Rep.delay.f = 1000; Rep.timer.f = timer_read(); return false; break;
      case Z_2F: Rep.delay.f = 2000; Rep.timer.f = timer_read(); return false; break;
      case Z_3F: Rep.delay.f = 3000; Rep.timer.f = timer_read(); return false; break;

    }
  }
  return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {
  if (Rep.delay.a && timer_elapsed(Rep.timer.a) >= Rep.delay.a) {
    register_code(KC_A);
    unregister_code(KC_A);
    Rep.timer.a = timer_read();
  }
  if (Rep.delay.s && timer_elapsed(Rep.timer.s) >= Rep.delay.s) {
    register_code(KC_S);
    unregister_code(KC_S);
    Rep.timer.s = timer_read();
  }
  if (Rep.delay.d && timer_elapsed(Rep.timer.d) >= Rep.delay.d) {
    register_code(KC_D);
    unregister_code(KC_D);
    Rep.timer.d = timer_read();
  }
  if (Rep.delay.f && timer_elapsed(Rep.timer.f) >= Rep.delay.f) {
    register_code(KC_F);
    unregister_code(KC_F);
    Rep.timer.f = timer_read();
  }
}

void led_set_user(uint8_t usb_led) {

}
