/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    WIN_BASE,
    MAC_FN1,
    WIN_FN1,
    FN2,
};

#define KC_A_HR MT(MOD_LGUI, KC_A)
#define KC_S_HR MT(MOD_LALT,KC_S)
#define KC_D_HR MT(MOD_LSFT,KC_D)
#define KC_F_HR MT(MOD_LCTL,KC_F)
#define KC_G_HR MT(MOD_LCTL | MOD_LSFT | MOD_LALT,KC_G)
#define KC_J_HR MT(MOD_LCTL | MOD_RCTL,KC_J)
#define KC_K_HR MT(MOD_LSFT | MOD_RSFT,KC_K)
#define KC_L_HR MT(MOD_LALT | MOD_RALT,KC_L)
#define KC_SCLN_HR MT(MOD_LGUI | MOD_RGUI,KC_SCLN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_MPLY,
        KC_LCTL, KC_A_HR,  KC_S_HR,  KC_D_HR, KC_F_HR, KC_G_HR, KC_H,    KC_J_HR, KC_K_HR, KC_L_HR, KC_SCLN_HR,KC_QUOT,           KC_ENT,           KC_MNXT,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        MO(MAC_FN1), KC_LOPTN, KC_LCMMD,                            KC_SPC,                             KC_RCMMD, MO(MAC_FN1),MO(FN2),KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI,  KC_LALT,                             KC_SPC,                             KC_RALT,  MO(WIN_FN1),MO(FN2),KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_FN1] = LAYOUT_ansi_67(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_MCTRL,KC_LNPAD,RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,  _______,            _______,          KC_END,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, NK_TOGG, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______),

    [WIN_FN1] = LAYOUT_ansi_67(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FILE, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          RGB_TOG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, P2P4G,   _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______,  _______,            _______,          KC_END,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, NK_TOGG, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______),

    [FN2] = LAYOUT_ansi_67(
        KC_TILD, KC_F1,    KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          RGB_TOG,
        _______, _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______, _______,  _______, _______, _______,  _______, _______, _______, _______, _______, _______,  _______,            _______,          _______,
        _______,           _______, _______, _______,  _______, BAT_LVL, _______, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN1]  = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_FN1]  = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [FN2]     = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

const uint16_t PROGMEM esc_combo[] = {KC_J_HR, KC_K_HR, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_D_HR, KC_F_HR, COMBO_END};
const uint16_t PROGMEM bspc_combo[] = {KC_K_HR, KC_L_HR, COMBO_END};
combo_t key_combos[] = {
    COMBO(esc_combo, KC_ESC),
    COMBO(tab_combo, KC_TAB),
    COMBO(bspc_combo, KC_BSPC),
};

// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}
