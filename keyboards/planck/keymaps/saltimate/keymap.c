/* Copyright 2015-2017 Jack Humbert
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
// #include "muse.h" //idk maybe i can use it some how?


enum planck_layers {
  _QWERTY,
  _CALC,
  _NAVI,
  _ADJUST
};


//idk what the fuck this is for
// enum planck_keycodes {
//   QWERTY = SAFE_RANGE,
//   COLEMAK,
//   DVORAK,
//   PLOVER,
//   BACKLIT,
//   EXT_PLV
// };


// my mods
#define ENAV LT(_NAVI, KC_ESC) // t KC_ESC, h mo(navi)
#define LBAR LT(_CALC, KC_SPC)// t space, h mo(calc), (tt tg(calc). see tapdance?)
#define RBAR LSFT(KC_TAB) // t tab, h shift, tt capslock???

#define TADJUST TG(_ADJUST)

#define CLEFT LCTL(KC_LEFT)
#define CRGHT LCTL(KC_RGHT)
#define CDOWN LCTL(KC_DOWN)
#define CUP LCTL(KC_UP)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ~ `  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ENAV |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ctrl |      | os   | alt  | LBAR        | RBAR        | menu |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
     KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
       ENAV,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
    XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_ENT ,
    KC_LCTL, XXXXXXX, KC_LGUI, KC_LALT,    LBAR,    LBAR,    RBAR,    RBAR,  KC_APP, XXXXXXX, XXXXXXX, XXXXXXX   
),


/* Calc
 * ,-----------------------------------------------------------------------------------.
 * | ~ `  |  !   |  @   |  #   |  $   |  %   |   ^  |   7  |   8  |   9  |  -   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | trns |  &   |  _   |  /   |  *   |  (   |   )  |   4  |   5  |   6  |  +   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  |   |      |  <   |  >   |  [   |   ]  |   1  |   2  |   3  |  =   |enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | num  |      |      |     trns    |       0     |  .   |      |      | calc |
 * `-----------------------------------------------------------------------------------'
 */
[_CALC] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC,  KC_P7,    KC_P8,   KC_P9, KC_MINS, KC_BSPC,
    _______, KC_AMPR, KC_UNDS, KC_SLSH, KC_ASTR, KC_LPRN, KC_RPRN,  KC_P4,    KC_P5,   KC_P6, KC_PLUS, XXXXXXX,
    XXXXXXX, KC_PIPE, XXXXXXX, KC_LABK, KC_RABK, KC_LBRC, KC_RBRC,  KC_P1,    KC_P2,   KC_P3,  KC_EQL,  KC_ENT,
    _______, XXXXXXX, XXXXXXX, _______, _______, _______,   KC_P0,  KC_P0,   KC_DOT, XXXXXXX, XXXXXXX, KC_CALC
),

/* Navigation
 * ,-----------------------------------------------------------------------------------.
 * |  adj |  F1  |  F2  |  F3  |  F4  |      | ctrL | ctrD | ctrU | ctrR |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | trns |  F5  |  F6  |  F7  |  F8  |      | left | down |  up  | rght |      |  del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 | F12  |      | Home |      |      | END  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ctrl |      |      | alt  |   trns      |    RBAR     | menu |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAVI] = LAYOUT_planck_grid(
    TADJUST,   KC_F1,   KC_F2,   KC_F3,   KC_F4, XXXXXXX,   CLEFT,   CDOWN,     CUP,   CRGHT, XXXXXXX, KC_BSPC,
    _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, XXXXXXX, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,  KC_DEL,
    XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, XXXXXXX, KC_HOME, XXXXXXX, XXXXXXX,  KC_END, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, _______, _______,    LBAR,    LBAR,    LBAR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),


/* Adjust (Lower + Raise)
 *                      nkro, numlock?, 
 * ,-----------------------------------------------------------------------------------.
 * | adj  | reset| debug|      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | trns |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    TADJUST, RESET,   DEBUG,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

