#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _NUMPAD 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  NUMPAD
};

bool caps_lock_on = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    LOWER,            RAISE,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, KC_LALT, KC_ENT,                    KC_SPC,  KC_LBRC, KC_RBRC
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMPAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  _______, _______, _______, _______, _______,                            _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, _______, _______, _______, _______, _______,                            _______, KC_P4,   KC_P5,   KC_P6,   KC_PEQL, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_RCTL, _______, _______, _______, _______, _______, LOWER,            RAISE,   _______, KC_P1,   KC_P2,   KC_P3,   KC_PCMM, KC_APP,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_RGUI, KC_RALT, KC_SPC,                    KC_ENT,  KC_P0,   KC_PDOT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     NUMPAD,  _______, _______, _______, _______, _______,                            _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  _______, KC_UP,   _______, _______, _______,                            _______, KC_INS,  KC_HOME, KC_PGUP, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, G(KC_LEFT), G(KC_RGHT),                      _______, KC_DEL,  KC_END,  KC_PGDN, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_RCTL, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, KC_APP,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_RGUI, KC_RALT, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     NUMPAD,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              _______, _______, _______, _______, KC_MINS, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,                             _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                             _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  _______,          _______, _______, _______, _______, _______, _______, KC_APP,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_RGUI, KC_RALT, _______,                   _______,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, NUMPAD,  _______, _______, _______, _______,                            _______, RGB_TOG, RGB_MOD, RGB_RMOD,_______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_BRIU, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            KC_BRID, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_MUTE, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, KC_VOLD,  KC_VOLU
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool numpad_led_state = host_keyboard_led_state().num_lock;
    bool scroll_led_state = host_keyboard_led_state().scroll_lock;
    bool caps_led_state = host_keyboard_led_state().caps_lock;
    switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
          if(IS_LAYER_ON(_NUMPAD)){
              layer_off(_NUMPAD);
          } else {
              layer_on(_NUMPAD);
          }
      }
    case KC_NUM:
      if (record->event.pressed) {
        if (!numpad_led_state) {
            rgblight_sethsv (HSV_TEAL);
        } else {
            rgblight_sethsv (HSV_BLUE);
        }
      }
      return true;
      break;
    case KC_SCRL:
      if (record->event.pressed) {
        if (!scroll_led_state) {
            rgblight_sethsv (HSV_PINK);
        } else {
            rgblight_sethsv (HSV_PURPLE);
        }
      }
      return true;
      break;
    case KC_CAPS:
      if (record->event.pressed) {
        if (!caps_led_state) {
            rgblight_sethsv (HSV_ORANGE);
        } else {
            rgblight_sethsv (HSV_RED);
        }
      }
      return true;
      break;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    bool numpad_led_state = host_keyboard_led_state().num_lock;
    bool caps_led_state = host_keyboard_led_state().caps_lock;
    switch (get_highest_layer(state)) {
    case _NUMPAD:
        if (numpad_led_state) {
            rgblight_sethsv (HSV_TEAL);
        } else {
            rgblight_sethsv (HSV_BLUE);
        }
        break;
    default: //  for any other layers, or the default layer
        if (caps_led_state) {
            rgblight_sethsv (HSV_ORANGE);
        } else {
            rgblight_sethsv (HSV_RED);
        }
        break;
    }
  return state;
}
