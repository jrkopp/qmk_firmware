/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include QMK_KEYBOARD_H

//  Pull in dd keycodes to maintain header compatibility
#include "keycodes.h"

// US ANSI shifted keycode aliases
#include "keymap_us.h"

// Modifiers and Masks
#include "modifiers.h"
#include <stdbool.h>

#include "quantum_keycodes.h"
#include <action_layer.h>

enum layer_names {
    BASE = 0,
    SYMBOL,
    NAV,
    MOUSE,
    MEDIA,
};

enum custom_keycodes {
    KC_LT_LP = SAFE_RANGE,
    KC_RT_RP,
    KC_BG_AP,
    MNW,
    MSW,
    MSE,
    MNE
};

#define LGA LGUI_T(KC_A)
#define LAS LALT_T(KC_S)
#define LCD LCTL_T(KC_D)
#define LSF LSFT_T(KC_F)  
#define RGSC RGUI_T(KC_SCLN)
#define RAL RALT_T(KC_L)
#define RCK RCTL_T(KC_K)
#define RSJ RSFT_T(KC_J)
#define CBS LCTL(KC_BSPC)
#define CRA LCTL(KC_RIGHT)
#define CLA LCTL(KC_LEFT)
#define CDEL LCTL(KC_DEL)
#define CHOME LCTL(KC_HOME)
#define CEND LCTL(KC_END)
#define UNDO LCTL(KC_Z)
#define COPY LCTL(KC_C)
#define CUT LCTL(KC_X)
#define PASTE LCTL(KC_V)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------|.           ,---------------------------------------------------------------.
       KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LBRC,               KC_RBRC,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
      KC_MINS,      LGA,    LAS,     LCD,     LSF,    KC_G, KC_LT_LP,             KC_RT_RP,    KC_H,     RSJ,     RCK,     RAL,    RGSC, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
         LT(MEDIA, KC_ESC),   LT(NAV,KC_TAB),   LT(SYMBOL,KC_SPACE),            LT(SYMBOL, KC_ENTER),  LT(MOUSE, KC_BSPC),  LT(MEDIA, KC_DEL)
         //`-------------------------------------------------------'            `-----------------------------------------------------------'
  ),
    [SYMBOL] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------|.           ,---------------------------------------------------------------.
     KC_TILDE, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_LBRC,               KC_RBRC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_LT_LP,             KC_RT_RP,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
        LT(MEDIA, KC_ESC),   LT(NAV,KC_TAB),   LT(SYMBOL,KC_SPACE),             LT(SYMBOL, KC_ENTER),  LT(MOUSE, KC_BSPC),   LT(MEDIA, KC_DEL)
        //`--------------------------------------------------------'            `------------------------------------------------------------'
  ),
    [NAV] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.            ,--------------------------------------------------------------.
      _______,    UNDO,     CUT,    COPY,   PASTE, _______, _______,              _______,     CBS, KC_HOME,     CLA,     CRA,  KC_END,    CDEL,
  //|--------+--------+--------+--------+--------+--------|--------|            |--------|--------+--------+--------+--------+--------+--------|
      _______, _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,              _______, KC_BSPC, KC_LEFT,   KC_UP, KC_DOWN,KC_RIGHT,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|--------|            |--------+--------+--------+--------+--------+--------+--------|
      _______,    UNDO,     CUT,    COPY,   PASTE, _______,                       _______,   CHOME, KC_PGUP, KC_PGDN,    CEND,  KC_INS,
  //|--------+--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------+--------|
         LT(MEDIA, KC_ESC),   LT(NAV,KC_TAB),   LT(SYMBOL,KC_SPACE),            LT(SYMBOL, KC_ENTER),  LT(MOUSE, KC_BSPC),  LT(MEDIA, KC_DEL)
         //`-------------------------------------------------------'            `-----------------------------------------------------------'
  ),

    [MOUSE] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.            ,--------------------------------------------------------------.
      MS_WHLU, MS_BTN1,     MNW,   MS_UP,     MNE, MS_ACL0, _______,              _______, _______,   PASTE,    COPY,     CUT,    UNDO, _______,
  //|--------+--------+--------+--------+--------+--------|--------|            |--------|--------+--------+--------+--------+--------+--------|
      MS_WHLD, MS_BTN2, MS_LEFT, _______, MS_RGHT, MS_ACL1, _______,              _______, _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
  //|--------+--------+--------+--------+--------+--------|--------|            |--------+--------+--------+--------+--------+--------+--------|
      _______, MS_BTN3,     MSW, MS_DOWN,     MSE, MS_ACL2,                                _______,   PASTE,    COPY,     CUT,    UNDO, _______,
  //|--------+--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------+--------|
         LT(MEDIA, KC_ESC),   LT(NAV,KC_TAB),   LT(SYMBOL,KC_SPACE),            LT(SYMBOL, KC_ENTER),  LT(MOUSE, KC_BSPC),  LT(MEDIA, KC_DEL)
         //`-------------------------------------------------------'            `-----------------------------------------------------------'
  ),

    [MEDIA] = LAYOUT_split_3x6_3_ex2(
  //,--------------------------------------------------------------.            ,--------------------------------------------------------------.
      _______, KC_MPLY, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,              _______, _______,    KC_7,    KC_8,    KC_9, KC_PAST, KC_PSLS,
  //|--------+--------+--------+--------+--------+--------|--------|            |--------|--------+--------+--------+--------+--------+--------|
      _______, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU, _______, _______,              _______, KC_PDOT,    KC_4,    KC_5,    KC_6, KC_PPLS, KC_PMNS,
  //|--------+--------+--------+--------+--------+--------|--------|            |--------+--------+--------+--------+--------+--------+--------|
      _______, UG_NEXT, UG_HUED, UG_SATD, UG_VALD, _______,                                   KC_0,    KC_1,    KC_2,    KC_3, KC_PENT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------+--------|
         LT(MEDIA, KC_ESC),   LT(NAV,KC_TAB),   LT(SYMBOL,KC_SPACE),            LT(SYMBOL, KC_ENTER),  LT(MOUSE, KC_BSPC),  LT(MEDIA, KC_DEL)
         //`-------------------------------------------------------'            `-----------------------------------------------------------'

  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_LT_LP:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          // Send "(" when Shift is held
          tap_code16(KC_LPRN);
        } else {
          // Send "<" when Shift is not held
          tap_code16(KC_COMM);
        }
      }
      return false; // Skip the "send key event" part
    case KC_RT_RP:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          // Send ")" when Shift is held
          tap_code16(KC_RPRN);
        } else {
          // Send ">" when Shift is not held
          tap_code16(KC_LT);
        }
      }
      return false; // Skip the "send key event" part
    case KC_BG_AP:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          // Send "!" when Shift is held
          tap_code16(KC_EXLM);
        } else {
          // Send "&" when Shift is not held
          tap_code16(KC_AMPR);
        }
      }
      return false; // Skip the "send key event" part
    case MNW:
        if (record->event.pressed) {
            mousekey_on(KC_MS_LEFT);
            mousekey_on(KC_MS_UP);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_LEFT);
            mousekey_off(KC_MS_UP);
            mousekey_send();
        }
        return false; // Indicates that the keycode was handled
    case MSW:
        if (record->event.pressed) {
            mousekey_on(KC_MS_LEFT);
            mousekey_on(KC_MS_DOWN);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_LEFT);
            mousekey_off(KC_MS_DOWN);
            mousekey_send();
        }
        return false; // Indicates that the keycode was handled
    case MSE:
        if (record->event.pressed) {
            mousekey_on(KC_MS_RIGHT);
            mousekey_on(KC_MS_DOWN);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_RIGHT);
            mousekey_off(KC_MS_DOWN);
            mousekey_send();
        }
        return false; // Indicates that the keycode was handled
        case MNE:
          if (record->event.pressed) {
              mousekey_on(KC_MS_RIGHT);
              mousekey_on(KC_MS_UP);
              mousekey_send();
          } else {
              mousekey_off(KC_MS_RIGHT);
              mousekey_off(KC_MS_UP);
              mousekey_send();
          }
          return false; // Indicates that the keycode was handled
    default:
      return true; // Process all other keycodes normally
  }
}

void keyboard_post_init_user(void) {
  // Enable RGB lighting
  rgblight_enable();
  // Set the RGB mode to solid color
  rgblight_mode(1);  // 1 = static light mode
  // Set the color to white
  rgblight_sethsv(0, 0, 48); // white at 25% brightness
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case BASE:
      rgblight_sethsv(0, 0, 48); // white at 25% brightness
      break;
    case SYMBOL:
      rgblight_sethsv(0, 200, 48);  // red at 25% brightness
      break;
    case NAV:
      rgblight_sethsv(85, 200, 48); // green at 25% brightness
      break;
    case MOUSE:
      rgblight_sethsv(85, 200, 48); // green at 25% brightness
      break;
    case MEDIA:
      rgblight_sethsv(170, 200, 48);  // blue at 25% brightness
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv(0, 0, 48); // white at 25% brightness
      break;
    }
  return state;
}
