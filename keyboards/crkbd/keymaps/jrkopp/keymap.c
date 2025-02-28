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
#include "jk_tapdance.h"

#include "process_tap_dance.h"

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_MED] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_finished, layer_reset),
    [TD_SPACE_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_finished, layer_reset),
    [TD_TAB_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_finished, layer_reset),
    [TD_BSPC_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_finished, layer_reset),
    [TD_ENT_MS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_finished, layer_reset),
    [TD_DEL_MED] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_finished, layer_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------|.           ,---------------------------------------------------------------.
             KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_LBRC,               KC_RBRC,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
        //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
            KC_MINS,     LGA,     LAS,     LCD,     LSF,    KC_G, KC_LT_LP,             KC_GT_RP,    KC_H,     RSJ,     RCK,     RAL,    RGSC, KC_QUOT,
        //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
           KC_AM_EX,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_EQL,
        //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
                                                       TDESME, TDSN, TDTS,            TDBS, TDENMS, TDDM
               //`-------------------------------------------------------'            `-----------------------------------------------------------'
        ),
    [SYMBOL] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------|.           ,---------------------------------------------------------------.
           KC_TILDE, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_LBRC,               KC_RBRC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
             KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_LT_LP,             KC_GT_RP,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
        //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
              KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
        //|--------+--------+--------+--------+--------+--------+--------|            |---------+--------+--------+--------+--------+--------+--------|
                                                       TDESME, TDSN, TDTS,            TDBS, TDENMS, TDDM
               //`-------------------------------------------------------'            `-----------------------------------------------------------'
        ),
    [NAV] = LAYOUT_split_3x6_3_ex2(
        //,--------------------------------------------------------------.            ,--------------------------------------------------------------.
            _______,    UNDO,     CUT,    COPY,   PASTE, _______, _______,              _______,     CBS, KC_HOME,     CLA,     CRA,  KC_END,    CDEL,
        //|--------+--------+--------+--------+--------+--------|--------|            |--------|--------+--------+--------+--------+--------+--------|
            _______, _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,              _______, KC_BSPC, KC_LEFT,   KC_UP, KC_DOWN, KC_RIGHT, KC_DEL,
        //|--------+--------+--------+--------+--------+--------|--------|            |--------+--------+--------+--------+--------+--------+--------|
            _______,    UNDO,     CUT,    COPY,   PASTE, _______,                                _______,   CHOME, KC_PGUP, KC_PGDN,    CEND,  KC_INS,
        //|--------+--------+--------+--------+--------+--------+--------|            |--------+--------+--------+--------+--------+--------+--------|
                                                       TDESME, TDSN, TDTS,            TDBS, TDENMS, TDDM
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
                                                       TDESME, TDSN, TDTS,            TDBS, TDENMS, TDDM
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
                                                       TDESME, TDSN, TDTS,            TDBS, TDENMS, TDDM
               //`-------------------------------------------------------'            `-----------------------------------------------------------'
        )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
  switch (keycode) {
    case KC_LT_LP:
      if (record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
          // Send "(" when Shift is held
          tap_code16(KC_LPRN);
        } else {
          // Send "<" when Shift is not held
          tap_code16(KC_LT);
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
    case TDESME:
      if (record->event.pressed) {
        set_tap_dance_layer(KC_ESC, MEDIA);
      }
      return true;
    case TDSN:
      if (record->event.pressed) {
        set_tap_dance_layer(KC_SPACE, NAV);
      }
      return true;
    case TDTS:
      if (record->event.pressed) {
        set_tap_dance_layer(KC_TAB, SYMBOL);
      }
      return true;
    case TDBS:
      if (record->event.pressed) {
        set_tap_dance_layer(KC_BSPC, SYMBOL);
      }
      return true;
    case TDENMS:
      if (record->event.pressed) {
        set_tap_dance_layer(KC_ENTER, MOUSE);
      }
      return true;
    case TDDM:
      if (record->event.pressed) {
        set_tap_dance_layer(KC_DEL, MEDIA);
      }
      return true;
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

void housekeeping_task_user(void) {
  achordion_task();
}

