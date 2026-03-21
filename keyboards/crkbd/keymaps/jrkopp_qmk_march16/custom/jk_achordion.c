#include "../features/achordion.h"
#include "jk_macros.h"

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {

  // Allow same-hand holds for layer tap keys.
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return true;  // Same hand is ok for layer tap keys
  }

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 3) { return true; }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case LGA:
    case LAS:
    case LCD:
    case LSF:
    case RGSC:
    case RAL:
    case RCK:
    case RSJ:
      return 3000;  // Must hold down the HRM while typing the following key
  }
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;  // Set to zerp for layer-tap keys.
  }
  return TAPPING_TERM; // Otherwise use a timeout of 800 ms.
}

bool achordion_eager_mod(uint8_t mod) {
  return false;
}

uint16_t achordion_streak_chord_timeout(
    uint16_t tap_hold_keycode, uint16_t next_keycode) {
  if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
    return 0;  // Disable streak detection on layer-tap keys.
  }
  return 400;  // Default of 100 ms.
}
