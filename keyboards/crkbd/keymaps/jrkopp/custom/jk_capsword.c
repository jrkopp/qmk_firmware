#include "caps_word.h"
#include "action_util.h"
#include "quantum.h"
#include "jk_keycodes.h"

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            rgblight_sethsv(0, 0, 48); // white at 25% brightness
            return false;  // Deactivate Caps Word.
    }
}