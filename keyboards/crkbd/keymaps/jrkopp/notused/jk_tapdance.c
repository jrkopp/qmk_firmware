#include "action_layer.h"
#include "jk_tapdance.h"

// ADD TO KEYMAP.C
// tap_dance_action_t tap_dance_actions[] = {
//     [TD_ESC_MED] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_finished, layer_reset),
//     [TD_SPACE_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_finished, layer_reset),
//     [TD_TAB_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_finished, layer_reset),
//     [TD_BSPC_SYM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_finished, layer_reset),
//     [TD_ENT_MS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_finished, layer_reset),
//     [TD_DEL_MED] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, layer_finished, layer_reset)
// };

// ADD TO JK_MACROS.H
// #define TDESME TD(TD_ESC_MED)
// #define TDSN TD(TD_SPACE_NAV)
// #define TDTS TD(TD_TAB_SYM)
// #define TDBS TD(TD_BSPC_SYM)
// #define TDENMS TD(TD_ENT_MS)
// #define TDDM TD(TD_DEL_MED)


static td_layer_t layer_tap_state = {
    .is_press_action = true,
    .state = TD_NONE,
    .layer = 1,
    .kc = KC_NO
};

void set_tap_dance_layer(uint16_t kc, layer_names_t layer) {
  layer_tap_state.kc = kc;
  layer_tap_state.layer = layer;
}

td_state_t cur_dance (tap_dance_state_t *state) {
    if (state->count == 1) {
        return (state->interrupted || !state->pressed) ? TD_SINGLE_TAP : TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        return (state->interrupted || !state->pressed) ? TD_DOUBLE_TAP : TD_DOUBLE_HOLD;
    } else if (state->count == 3) {
        return (state->interrupted || !state->pressed) ? TD_TRIPLE_TAP : TD_TRIPLE_HOLD;
    } else { 
        return TD_UNKNOWN; 
    }
}

// Functions that control what our tap dance keys do

void layer_finished(tap_dance_state_t *state, void *user_data) {
    layer_tap_state.state = cur_dance(state);
    td_state_t tap_state = layer_tap_state.state;
    uint16_t kc = layer_tap_state.kc;
    layer_names_t layer = layer_tap_state.layer;
    switch (tap_state) {
        case TD_SINGLE_TAP:
            tap_code(kc);
            break;
        case TD_SINGLE_HOLD:
            layer_on((uint8_t) layer);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is((uint8_t) layer)) {
                // If already set, then switch it off
                layer_off((uint8_t) layer);
            } else {
                // If not already set, then switch the layer on
                layer_on((uint8_t) layer);
            }
            break;
        default:
            break;
    }
}

void layer_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer

    if (layer_tap_state.state == TD_SINGLE_HOLD) {
        layer_off((uint8_t) layer_tap_state.layer);
    }
    layer_tap_state.state = TD_NONE;
}