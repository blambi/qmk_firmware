#include "pad20.h"
#include "action_layer.h"
#include "eeconfig.h"


#define ____ KC_TRNS
#define TRNS KC_TRNS

#define DEF 0
#define HDN 1
#define ARW 2
#define OVR 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* 0: Default */
[DEF] = KEYMAP(
  KC_FN0, KC_PSLS, KC_PAST, KC_PMNS, \
  KC_P7,  KC_P8,   KC_P9,   KC_PPLS, \
  KC_P4,  KC_P5,   KC_P6,   KC_PEQL, \
  KC_P1,  KC_P2,   KC_P3,   KC_BSPC, \
  KC_P0,  KC_PCMM, KC_PDOT, KC_PENT  \
),
/* 1: Qwer - Aka left side */
[HDN] = KEYMAP(
  KC_FN0,  KC_1,    KC_2,   KC_3, \
  KC_Q,    KC_W,    KC_E,   KC_R, \
  KC_A,    KC_S,    KC_D,   KC_F, \
  KC_Z,    KC_X,    KC_C,   KC_SPC, \
  KC_LSFT, KC_LALT, KC_TAB, KC_SPC  \
),
/* 2: Arrow map */
[ARW] = KEYMAP(
  KC_FN0,   KC_END,  KC_PGUP,  KC_ESC,  \
  KC_BSPC,  KC_UP,   KC_PGDN,  KC_WH_U, \
  KC_LEFT,  KC_DOWN, KC_RIGHT, KC_WH_D, \
  KC_RSFT,  KC_Z,    KC_X,     KC_SPC,  \
  KC_RCTRL, KC_LALT, KC_TAB,   KC_ENTER \
),
/* 3: Fn Overlay */
[OVR] = KEYMAP(
  ____, KC_FN1, KC_FN2, KC_FN3, \
  ____, ____,   ____,   ____,   \
  ____, ____,   ____,   ____,   \
  ____, ____,   ____,   ____,   \
  ____, ____,   ____,    ____  \
)
};


const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_TAP_KEY(OVR, KC_NUMLOCK),
    [1] = ACTION_LAYER_SET(HDN, ON_PRESS),
    [2] = ACTION_LAYER_SET(ARW, ON_PRESS),
    [3] = ACTION_LAYER_SET(DEF, ON_PRESS),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE;
};


bool process_record_user (uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
  case KC_FN1:
      if (record->event.pressed) {
        //PORTC |= (1 << 6); // PC6 goes high
        PIN_SET(PORTC, 6);
        PIN_CLEAR(PORTD, 4);
      }
      break;
  case KC_FN2:
      if (record->event.pressed) {
          /*PORTC &= ~(1 << 6); // PC6 goes high 
            PORTD |= (1<<4);*/
        PIN_SET(PORTD, 4);
        PIN_CLEAR(PORTC, 6);
      }
      break;
  case KC_FN3:
      if (record->event.pressed) {
        //PORTD &= ~(1 << 4); // PC6 goes high
        PIN_CLEAR(PORTC, 6);
        PIN_CLEAR(PORTD, 4);
      }
      break;
  }
  return true;
}
