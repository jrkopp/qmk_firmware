#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "process_tap_dance.h"
#include "jk_layers.h"

typedef enum {
  TD_ESC_MED, 
  TD_SPACE_NAV, 
  TD_TAB_SYM, 
  TD_BSPC_SYM, 
  TD_ENT_MS, 
  TD_DEL_MED
} tap_dances_t;

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
    layer_names_t layer;
    uint16_t kc;
} td_layer_t;

void layer_finished(tap_dance_state_t *state, void *user_data);
void layer_reset(tap_dance_state_t *state, void *user_data);

void set_tap_dance_layer(uint16_t kc, layer_names_t layer);
