#include "keymap_common.h"

/* The default Atreus layout. First layer is normal keys, second
   (momentary fn layer) is numbers, most punctuation, and
   arrows. Third (modal, persistent) layer is function keys and other
   rarely-used keys. */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: mostly letters */
  KEYMAP(KC_Q, KC_W, KC_E, KC_R, KC_T,                           KC_Y, KC_U, KC_I, KC_O, KC_P, \
         KC_A, KC_S, KC_D, KC_F, KC_G,                           KC_H, KC_J, KC_K, KC_L, KC_SCLN, \
         KC_Z, KC_X, KC_C, KC_V, KC_B,                           KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, \
         KC_TAB, KC_NO, KC_NO, KC_LGUI, KC_LSFT, KC_FN4, KC_FN5, KC_SPC, KC_FN0, KC_FN6, KC_NO, KC_BSLS),
  /* 1: quotes, hyphen, equals */
  KEYMAP(KC_GRAVE, KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO, KC_NO, KC_NO, KC_MINS, KC_EQUAL, \
         KC_HOME, KC_UP, KC_END, KC_PGUP, KC_BSPC,               KC_BSPC, KC_NO, KC_NO, KC_NO, KC_QUOT, \
         KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_NO,             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
         KC_TAB, KC_NO, KC_NO, KC_LGUI, KC_LSFT, KC_FN4, KC_FN5, KC_NO, KC_FN0, KC_NO, KC_NO, KC_NO),
  /* 2: arrows and function keys */
  LAYER_TWO,
  /* 3: punctuation and numbers */
  KEYMAP(KC_1, KC_2, KC_3, KC_4, KC_5,                           KC_6, KC_7, KC_8, KC_9, KC_0, \
         KC_HOME, KC_UP, KC_END, KC_PGUP, KC_BSPC,               KC_BSPC, KC_NO, KC_NO, KC_LBRC, KC_RBRC, \
         KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_NO,             KC_NO, KC_NO, KC_NO, KC_DOT, KC_NO, \
         KC_FN1, KC_NO, KC_NO, KC_LGUI, KC_LSFT, KC_FN4, KC_FN5, KC_SPC, KC_NO, KC_FN6, KC_NO, KC_NO),
};

const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
  [1] = ACTION_LAYER_ON(2, 1),  // switch to layer 2
  [2] = ACTION_LAYER_OFF(2, 1),  // switch back to layer 0
  [3] = ACTION_FUNCTION(BOOTLOADER),
  [4] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ESC),  // hold L-CTRL, tap ESC
  [5] = ACTION_MODS_TAP_KEY(MOD_LALT, KC_ENT),  // hold L-ALT, tap ENTER
  [6] = ACTION_LAYER_MOMENTARY(3),  // to FnB overlay
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}
