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
    Z_M1 = SAFE_RANGE,
    Z_M2,
    Z_M3,
    Z_M4,
    Z_M5,
    Z_M6,
    Z_M7,
    Z_M8,
    Z_M9,
    Z_M10,
    Z_M11,
    Z_M12,
    Z_M13,
    Z_M14,
    Z_M15,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // See https://docs.qmk.fm/keycodes.html

[0] = KEYMAP( /* Base */
  Z_M1,  Z_M2,  Z_M3,  Z_M4,  Z_M5,\
  Z_M6,  Z_M7,  Z_M8,  Z_M9,  Z_M10,\
  Z_M11, Z_M12, Z_M13, Z_M14, Z_M15\
),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // See https://docs.qmk.fm/macros.html
  if (record->event.pressed) {
    switch(keycode) {
      case Z_M1: SEND_STRING("You should direct that question to the CSMs, I mean the TCs, or whatever they are calling themselves now."); return true; break;
      case Z_M2: SEND_STRING("to handle life\n    put joy into the world\nend to handle life"); return true; break;
      case Z_M3: SEND_STRING("eggy"); return true; break;
      case Z_M4: SEND_STRING("100% Test coverage."); return true; break;
      case Z_M5: SEND_STRING("eggplant.io"); return true; break;
      case Z_M6: SEND_STRING("<placeholder text, fill in with witty message>"); return true; break;
      case Z_M7: SEND_STRING("Agile! Jira! Scrum!"); return true; break;
      case Z_M8: SEND_STRING("Wow the customers by boldly innovating at warp speed."); return true; break;
      case Z_M9: SEND_STRING("It's not a bug, it's a feature."); return true; break;
      case Z_M10: SEND_STRING("I can't talk right now, I'm on a call with the UK. Ask me again at 11."); return true; break;
      case Z_M11: SEND_STRING("John Spita has reported a bug."); return true; break;
      case Z_M12: SEND_STRING("Eggplant AKA Testplant AKA Redstone"); return true; break;
      case Z_M13: SEND_STRING("@matt.hicks Hey I seem to be having some trouble with eggplant. "); return true; break;
      case Z_M14: SEND_STRING("Did I mention the Gartner magic quadrant?"); return true; break;
      case Z_M15: SEND_STRING("A bug? Better go to boulder beer to think about it."); return true; break;
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
