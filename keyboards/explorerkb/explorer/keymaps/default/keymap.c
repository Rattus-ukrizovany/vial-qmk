/*
 * Copyright 2025 @DreaM117er
 * Copyright 2025 74th
 * Copyright 2025 QMK
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

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

     [0] = LAYOUT(
         KC_ESC,  KC_Q, KC_W,    KC_E,    KC_R,    KC_T,  TO(1),            KC_Y,  KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
         KC_LSFT, KC_A, KC_S,    KC_D,    KC_F,    KC_G,  XXXXXXX, XXXXXXX, KC_H,  KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT,
         KC_LCTL, KC_Z, KC_X,    KC_C,    KC_V,    KC_B,  XXXXXXX, XXXXXXX, KC_N,  KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_QUOT,
                        XXXXXXX, XXXXXXX, KC_LALT, MO(1), KC_SPC,  KC_RSFT, MO(2), XXXXXXX, XXXXXXX, XXXXXXX,
         ),
     [1] = LAYOUT(
         KC_ESC,  KC_PSLS, KC_1,    KC_2,    KC_3,          KC_PLUS, TO(0),            KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX, KC_BSPC,
         KC_TAB,  KC_PAST, KC_4,    KC_5,    KC_6,          KC_MINS, XXXXXXX, XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_ENT,
         KC_LCTL, KC_DOT,  KC_7,    KC_8,    KC_9,          KC_0,    XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                           XXXXXXX, XXXXXXX, OSM(MOD_LALT), KC_LGUI, KC_ENT,  KC_RSFT, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX
         ),
     [2] = LAYOUT(
         KC_TILD,      XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, KC_EQL,  TO(3),            KC_F1,   KC_F2,   KC_F3,  KC_F12, XXXXXXX, KC_DEL,
         LALT(KC_TAB), XXXXXXX, KC_DLR,  KC_PERC, KC_CIRC, KC_UNDS, XXXXXXX, XXXXXXX, KC_F4,   KC_F5,   KC_F6,  KC_F11, KC_VOLU, KC_TRNS,
         KC_TRNS,      XXXXXXX, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_VOLD, KC_TRNS,
                       XXXXXXX, XXXXXXX, KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX
         ),
     [3] = LAYOUT(
         XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  KC_SCRL, KC_PAUS, TO(0),            RGB_HUI,  RGB_SAI, RGB_VAI, RGB_SPI, KC_PSCR, XXXXXXX,
         KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_HUD,  RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX,
         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX
         )
 };

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU)
            },
    [1] =   {
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [2] =   {
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
    [3] =   {
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            },
};

 #define SCROLL_SCALE_PERCENT 5

 int32_t scroll_amount_h = 0;
 int32_t scroll_amount_v = 0;

 report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
     scroll_amount_h += mouse_report.h * SCROLL_SCALE_PERCENT;
     scroll_amount_v += mouse_report.v * SCROLL_SCALE_PERCENT;
     int8_t h = scroll_amount_h / 100;
     int8_t v = scroll_amount_v / 100;
     scroll_amount_h -= h*100;
     scroll_amount_v -= v*100;

     mouse_report.h = h;
     mouse_report.v = v;
     return mouse_report;
 }

