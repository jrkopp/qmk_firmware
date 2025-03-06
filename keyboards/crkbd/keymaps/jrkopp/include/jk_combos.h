#pragma once

#include "process_combo.h"
#include "caps_word.h"
#include "quantum.h"
#include "jk_macros.h"
#include "action_layer.h"

enum combo_events {
    VC_CW_TOGG = 0
};

const uint16_t PROGMEM vc_combo[] = {KC_V, KC_C, COMBO_END};

combo_t key_combos[] = {
  [VC_CW_TOGG] = COMBO_ACTION(vc_combo)
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case VC_CW_TOGG:
      if (pressed) {
        if (!is_caps_word_on()) {
          caps_word_on();
          rgblight_sethsv(30, 255, 48); // orange at 25% brightness
        } else {
          caps_word_off();
          rgblight_sethsv(0, 0, 48); // white at 25% brightness
        }
      }
      break;
  }
}