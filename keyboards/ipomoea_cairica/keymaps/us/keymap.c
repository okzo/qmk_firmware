/* Copyright 2020 kamuwo
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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _FN
};

#define KC_FN MO(_FN)


// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    QMKBEST
};


/* Qwerty
 * ,-----------------------------------------.   ,---------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   |   6  |   7  |   8  |   9  |   0  |  -_  |  +=  |BackSp| Grav |PageUp|
 * |------+------+------+------+------+-------.  '.------+------+------+------+------+------+------+------+-----+------|
 * | Tab   |   Q  |   W  |   E  |   R  |   T  |   |   Y  |   U  |   I  |   O  |   P  |  {   |  }   |     |\     |PageDn|
 * |-------+-----+------+------+------+--------.  '.------+------+------+------+------+------+------+-----------|------|
 * | Caps   |   A  |   S  |   D  |   F  |   G  |   |   H  |   J  |   K  |   L  |   ;  |  :   |     Enter        | Home |
 * |--------+----+------+------+------+---------.  '------+------+------+------+------+------+------+-----------+------|
 * | Shift   |   Z  |   X  |   C  |   V  |   B  |   |   N  |   M  |   <  |   >  |   ,  |   .  |   /  | Shift    | End  |
 * |-------+-+---+------+------+------+---------' ,-+------+------+------+------+------+------+------------------------.
 * | Ctrl  |  GUI  |  Alt   |  Fn   |  Space  |   |     Space    | Ctrl  |  Alt  |  Fn   | Left  | Down |  Up   | Right|
 * `------------------------------------------'   '--------------------------------------------------------------------'
 */

/* FN
 * ,-----------------------------------------.   ,---------------------------------------------------------------------.
 * |  Z/H |  F1  |  F2  |  F3  |  F4  |  F5  |   |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |      |      |      |
 * |------+------+------+------+------+-------.  '.------+------+------+------+------+------+------+------+-----+------|
 * |       |M Prev|M Play|M Next|      |      |   |      |PageUp|  Up  |PageDn|PrtScr|ScrLck| Pause|            |      |
 * |-------+-----+------+------+------+--------.  '.------+------+------+------+------+------+------+-----------|------|
 * |        |      |Vol Up|Vol Dn| Mute |      |   | Home | Left | Down | Right|Insert|Delete|                  |      |
 * |--------+----+------+------+------+---------.  '------+------+------+------+------+------+------+-----------+------|
 * |         | App  |      |      |      |      |   | End  |      |      |      |      |      |      |          |      |
 * |-------+-+---+------+------+------+---------' ,-+------+------+------+------+------+------+------------------------.
 * |       |       |       |       |          |   |                |        |          |          |     |       |      |
 * `------------------------------------------'   '--------------------------------------------------------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT( \
     //------0+-------1+-------2+-------3+-------4+-------5|   |-------0+-------1+-------2+-------3+-------4+-------5+-------6+-------7+-------8+-------9/
      KC_ESC  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,    KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,KC_EQL  ,KC_BSPC ,KC_GRV  ,KC_PGUP , \
      KC_TAB  ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,    KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,KC_LBRC ,KC_RBRC ,KC_NUHS ,         KC_PGDN , \
      KC_CLCK ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,    KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,KC_QUOT ,KC_ENT  ,                  KC_HOME , \
      KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,    KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RO   ,KC_RSFT ,KC_UP   ,         KC_END  , \
      KC_LCTL ,KC_LGUI ,KC_LALT ,KC_FN   ,KC_SPC  ,             KC_SPC  ,XXXXXXX ,KC_RCTL ,KC_RALT ,KC_FN   ,KC_LEFT ,KC_DOWN ,KC_UP   ,         KC_RGHT   \
    ),
    [_FN] = LAYOUT( \
     //------0+-------1+-------2+-------3+-------4+-------5|   |-------0+-------1+-------2+-------3+-------4+-------5+-------6+-------7+-------8+-------9/
      KC_GRV  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,    KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,KC_DEL  ,_______ ,_______ , \
      _______ ,KC_MPRV ,KC_MPLY ,KC_MNXT ,_______ ,_______ ,    _______ ,KC_PGUP ,KC_UP   ,KC_PGDN ,KC_PSCR ,KC_SLCK ,KC_PAUSE,_______ ,         _______ , \
      _______ ,_______ ,KC_VOLD ,KC_VOLU ,KC_MUTE ,_______ ,    KC_HOME ,KC_LEFT ,KC_DOWN ,KC_RIGHT,KC_INS  ,KC_DEL  ,_______ ,                  _______ , \
      _______ ,KC_APP  ,_______ ,_______ ,_______ ,_______ ,    KC_END  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,         XXXXXXX , \
      _______ ,_______ ,_______ ,_______ ,_______ ,             _______ ,XXXXXXX ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,         _______   \
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        default:
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
