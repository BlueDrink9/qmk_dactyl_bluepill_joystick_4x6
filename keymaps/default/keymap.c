#include QMK_KEYBOARD_H
#include "analog.h"
// #include "quantum.h"
#include "print.h"
#include "joystick.h"

#define TAPPING_TERM 200

int16_t joyXMid = JOYSTICK_AXIS_MAX/2;
int16_t joyYMid = JOYSTICK_AXIS_MAX/2;

void scan_joystick_button(void);

// enum tap_dance_actions_enum {
//       TD_LAYER_TOGGLE
// };

enum layer_names {
    BASE,
    COLEMAK,
    GAMING,
    NUMBERS,
    SPECIAL,
    VIM,
};

// DON'T FORGET TO INCLUDE A PATH TO QK_BOOTLOADER
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT(
KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,    KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINUS,
KC_BSPC, KC_A, MT(KC_LALT, KC_S), MT(KC_LWIN, KC_D), MT(KC_LCTL, KC_F), KC_G,    KC_H, MT(KC_RCTL, KC_J), MT(KC_RWIN, KC_K), MT(KC_RALT, KC_L), KC_SEMICOLON, KC_QUOT,
LSFT_T(KC_LEFT_BRACKET), KC_Z, KC_X, KC_C, LT(VIM,KC_V), KC_B,     KC_N, LT(VIM,KC_M), KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_RIGHT_BRACKET),

KC_MS_LEFT, TT(SPECIAL), TT(NUMBERS),
KC_DEL,     KC_SPACE,    KC_BACKSPACE,

        // Temporary bootloader key so I don't forget to include one
QK_BOOTLOADER,         KC_SPC, KC_APP, 
LALT_T(KC_RALT), KC_RIGHT_SHIFT, KC_ENTER
),

    [COLEMAK] = LAYOUT(
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,
KC_TRNS, KC_Q,    KC_W,    KC_F,    KC_P,          KC_G,    KC_J,    KC_L,          KC_U,    KC_Y,    KC_SEMICOLON, KC_TRNS,
KC_TRNS, KC_A, MT(KC_LALT, KC_R), MT(KC_LWIN, KC_S), MT(KC_LCTL, KC_T), KC_D,    KC_H, MT(KC_RCTL, KC_N), MT(KC_RWIN, KC_E), MT(KC_RALT, KC_I), KC_O, KC_TRNS,
KC_TRNS, KC_Z,    KC_X,    KC_C,    LT(VIM, KC_V), KC_B,    KC_K,    LT(VIM, KC_M), KC_COMM, KC_DOT,  KC_SLSH,      KC_TRNS,

KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,

KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS
)


};

// void dance_layer_toggle(qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     tap_code(KC_5);
//   } else if (state->count == 2) {
//     // Double tap, toggle layer
//     layer_invert(YOUR_LAYER);
//   }
// }

// qk_tap_dance_action_t tap_dance_actions[] = {
//   [TD_LAYER_TOGGLE_LETTERS] = ACTION_TAP_DANCE_FN(dance_layer_toggle)
// };

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
}


void keyboard_pre_init_user(void) {
    // Joystick setup
    setPinInputHigh(JOY_BUTTON_PIN);
    // Set mid based on current resting position
    // if ((joyXMid != analogReadPin(JOYXPIN))|(joyYMid != analogReadPin(JOYYPIN))) {
    //     joyXMid = analogReadPin(JOYXPIN);
    //     joyYMid = analogReadPin(JOYYPIN);
    // }
}

void matrix_init_user(){
}

void matrix_scan_user(void) {
    scan_joystick_button();
};

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_IN(JOYXPIN, JOYSTICK_AXIS_MAX, JOYSTICK_AXIS_MAX/2, 0), // X, Low(L) ~ High(R)
    JOYSTICK_AXIS_IN(JOYYPIN, JOYSTICK_AXIS_MAX, JOYSTICK_AXIS_MAX/2, 0), // Y, Low(U) ~ High(D)
};

static uint8_t direct_pin_state = 0; // Store last state

void scan_joystick_button(){
    uint8_t current_state = readPin(JOY_BUTTON_PIN);
    // Check for state change from high to low (button press)
    if (direct_pin_state && !current_state) {
        // Button was high, now low: Key press
        register_code(JOY_BUTTON_KEY);
    } else if (!direct_pin_state && current_state) {
        // Button was low, now high: Key release
        unregister_code(JOY_BUTTON_KEY);
    }
    // Update last state
    direct_pin_state = current_state;
}
