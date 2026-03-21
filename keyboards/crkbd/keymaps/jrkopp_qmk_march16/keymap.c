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

// Modifiers and Masks
#include "modifiers.h"
#include <stdbool.h>

#include <action_layer.h>

#include "achordion.h"

#include "jk_layers.h"
#include "jk_keycodes.h"
#include "jk_macros.h"
#include "jk_combos.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------|.           ,---------------------------------------------------------------.
             KC_DEL,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, _______,               _______,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
             KC_TAB,     LGA,     LAS,     LCD,     LSF,    KC_G, _______,               _______,    KC_H,     RSJ,     RCK,     RAL,    RGSC,  KC_ENT,
        //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
            KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_QUOT, KC_RSFT,
        //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
                                                       LTESME, LTSN, LTTS,            LTBS, LTENMS, LTDM
               //`-------------------------------------------------------'            `-----------------------------------------------------------'
        ),
    [SYMBOL] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------|.           ,---------------------------------------------------------------.
             KC_DEL, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, _______,               _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
          KC_TAB, KC_BSLS, KC_LT, KC_LBRC, KC_LPRN, LSFT(KC_LBRC), _______,            _______, RSFT(KC_RBRC), KC_RPRN, KC_RBRC, KC_GT, KC_SLSH, KC_ENT,
        //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
            KC_LSFT,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_RSFT,
        //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
                                                       LTESME, LTSN, LTTS,            LTBS, LTENMS, LTDM
               //`-------------------------------------------------------'            `-----------------------------------------------------------'
        ),
    [NAV] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.            ,--------------------------------------------------------------.
             KC_DEL, _______, SELWBAK, SELLINE, SELWORD, _______, _______,              _______, -------, KC_HOME,  KC_DEL, KC_PGUP, KC_BSPC, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|--------|            |--------|--------+--------+--------+--------+--------+--------|
             KC_TAB,    SALL, KC_LALT, KC_LCTL, KC_LSFT, _______, _______,             _______, _______,  KC_END,   KC_UP, KC_PGDN, KC_RIGHT, KC_ENT,
        //|--------+--------+--------+--------+--------+--------|--------|            |--------+--------+--------+--------+--------+--------+--------|
            KC_LSFT,    UNDO,     CUT,    COPY,   PASTE, _______,                                _______, KC_LEFT, KC_DOWN,KC_RIGHT, KC_RSFT, KC_RSFT,
        //|--------+--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------+--------|
                                                       LTESME, LTSN, LTTS,            LTBS, LTENMS, LTDM
               //`-------------------------------------------------------'            `-----------------------------------------------------------'
        ),
    [MOUSE] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.            ,--------------------------------------------------------------.
             KC_DEL, _______, SELWBAK, SELLINE, SELWORD, _______, _______,              _______, _______, OM_BTN1, OM_DBL1, OM_BTN2, OM_W_UP, KC_BSPC,
        //|--------+--------+--------+--------+--------+--------|--------|            |--------|--------+--------+--------+--------+--------+--------|
             KC_TAB,    SALL, KC_LALT, KC_LCTL, KC_LSFT, _______, _______,              _______, _______, OM_HLD1,    OM_U, OM_REL1, OM_W_DN, KC_ENT,
        //|--------+--------+--------+--------+--------+--------|--------|            |--------+--------+--------+--------+--------+--------+--------|
            KC_LSFT,    UNDO,     CUT,    COPY,   PASTE, _______,                                _______,    OM_L,    OM_D,    OM_R, _______, KC_RSFT,
        //|--------+--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------+--------|
                                                       LTESME, LTSN, LTTS,            LTBS, LTENMS, LTDM
               //`-------------------------------------------------------'            `-----------------------------------------------------------'
        ),
    [FUN] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.            ,--------------------------------------------------------------.
             KC_DEL,   KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_VOLU, KC_MUTE,              _______, KC_PPLS,    KC_7,    KC_8,    KC_9, KC_PMNS, KC_BSPC
        //|--------+--------+--------+--------+--------+--------|--------|            |--------|--------+--------+--------+--------+--------+--------|
             KC_TAB,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_VOLD, KC_MUTE,              _______, KC_PDOT,    KC_4,    KC_5,    KC_6, KC_PAST, KC_PENT,
        //|--------+--------+--------+--------+--------+--------|--------|            |--------+--------+--------+--------+--------+--------+--------|
            KC_LSFT,   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_MPLY, KC_MUTE,                          KC_0,    KC_1,    KC_2,    KC_3, KC_PSLS, KC_PENT,
        //|--------+--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------+--------|
                                                       LTESME, LTSN, LTTS,            LTBS, LTENMS, LTDM
               //`-------------------------------------------------------'            `-----------------------------------------------------------'
        )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
  switch (keycode) {
    case KC_DELETE:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          // Send "(" when Shift is held
          tap_code16(KC_ESC);
        } else {
          // Send "<" when Shift is not held
          tap_code16(KC_DELETE);
        }
      }
      return false; // Skip the "send key event" part
    case KC_GT_RP:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          // Send ")" when Shift is held
          tap_code16(KC_RPRN);
        } else {
          // Send ">" when Shift is not held
          tap_code16(KC_GT);
        }
      }
      return false; // Skip the "send key event" part
    case KC_AM_EX:
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
        break;
  }
  return true; // Process all other keycodes normally
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

void housekeeping_task_user(void) {
  achordion_task();
}

