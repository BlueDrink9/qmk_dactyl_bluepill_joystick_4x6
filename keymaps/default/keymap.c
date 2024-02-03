#include QMK_KEYBOARD_H
#include "analog.h"
// #include "quantum.h"
#include "print.h"
#include "joystick.h"

int16_t joyXMid = JOYSTICK_AXIS_MAX/2;
int16_t joyYMid = JOYSTICK_AXIS_MAX/2;

void scan_joystick_button(void);

// enum tap_dance_actions_enum {
//       TD_LAYER_TOGGLE
// };

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  NEWLINE_AFTER,
  PASTE_UP,
  CUT_EOL,
  SELECT_LINE,
  YANK_EOL,
  NEWLINE_UP,
  PASTE_REPLACE,
};

enum layer_names {
    BASE,
    COLEMAK,
    GAMING,
    NUMBERS,
    SPECIAL,
    VIM,
    VIM_SHIFTED,
    VIM_VISUAL,
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
    ),

  [VIM] = LAYOUT(
DM_REC2, DM_RSTP,   DM_PLY1, DM_PLY2,   KC_END,       KC_TRNS,       KC_TRNS,        KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_HOME,    KC_TRNS,
KC_TRNS, DM_REC1, LCTL(KC_RIGHT),  KC_TRNS,   LCTL(KC_V),   TD(DANCE_9),   KC_DOWN,        KC_RIGHT, LCTL(KC_Z), LCTL(KC_C), KC_TRNS,    KC_TRNS,
KC_TRNS, KC_END,         KC_BACKSPACE,       KC_TRNS,   KC_TRNS,      LCTL(KC_X),    LCTL(KC_RIGHT), TO(BASE),    NEWLINE_AFTER, KC_TRNS, KC_TRNS,    KC_TRNS,
MO(VIM_SHIFTED),   KC_TRNS,        KC_DELETE,       KC_CUT, TD(DANCE_10), LCTL(KC_LEFT), KC_UP,          KC_TRNS,  KC_TRNS,    KC_TRNS,    LCTL(KC_F), MO(VIM_SHIFTED),

KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,

KC_TRNS, KC_TRNS, MO(VIM_SHIFTED),
KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [VIM_SHIFTED] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_END,     KC_TRNS,      KC_HOME, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, PASTE_UP, LCTL(KC_END), KC_TRNS, KC_TRNS, KC_TRNS,    YANK_EOL, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_END,  KC_TRNS,   KC_TRNS, KC_TRNS,    CUT_EOL,   KC_TRNS, KC_HOME, NEWLINE_UP, KC_TRNS,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_BACKSPACE, KC_TRNS, SELECT_LINE, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,

        KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [VIM_VISUAL] = LAYOUT(
  TO(VIM),   KC_TRNS, KC_TRNS,              KC_TRNS, LSFT(KC_END),  KC_TRNS,             LSFT(KC_HOME), KC_TRNS,        KC_TRNS,              KC_TRNS,     LSFT(KC_HOME), KC_TRNS,
  KC_TRNS,   KC_TRNS, LCTL(LSFT(KC_RIGHT)), KC_TRNS, PASTE_REPLACE, TD(DANCE_BOF_EOF),   LSFT(KC_DOWN), LSFT(KC_RIGHT), LCTRL(KC_Z),          LCTRL(KC_C), KC_TRNS,       KC_TRNS,
  KC_TRNS,   KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS,       LCTL(KC_X),          LSFT(KC_LEFT), KC_TRNS,        LCTL(LSFT(KC_RIGHT)), KC_TRNS,     KC_TRNS,       KC_TRNS,
    KC_TRNS, KC_TRNS, KC_BACKSPACE,         KC_TRNS, TO(VIM),       LCTL(LSFT(KC_LEFT)), LSFT(KC_UP),   KC_TRNS,        LSFT(KC_TAB),         KC_TAB,      KC_TRNS,       KC_TRNS,

      KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,

      KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS


)};

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_BOF_EOF,
  DANCE_12,
  DANCE_13,
};

// void dance_layer_toggle(tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     tap_code(KC_5);
//   } else if (state->count == 2) {
//     // Double tap, toggle layer
//     layer_invert(YOUR_LAYER);
//   }
// }

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
#endif
}

bool handle_macro_presses(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    handle_macro_presses(keycode, record);
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
    if ((joyXMid != analogReadPin(JOYXPIN))|(joyYMid != analogReadPin(JOYYPIN))) {
        joyXMid = analogReadPin(JOYXPIN);
        joyYMid = analogReadPin(JOYYPIN);
    }
}

void matrix_init_user(){
}

void matrix_scan_user(void) {
    // scan_joystick_button();
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

bool handle_macro_presses(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NEWLINE_AFTER:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_END) SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case PASTE_UP:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_HOME) SS_DELAY(100) SS_LCTL(SS_TAP(X_V)) SS_DELAY(100) SS_TAP(X_ENTER));
    }
    break;
    case CUT_EOL:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_DELAY(100) SS_LCTL(SS_TAP(X_X)));
    }
    break;
    case SELECT_LINE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_HOME) SS_DELAY(100) SS_LSFT(SS_TAP(X_END)));
    }
    break;
    case YANK_EOL:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_END)) SS_DELAY(100) SS_LCTL(SS_TAP(X_C)));
    }
    break;
    case NEWLINE_UP:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_HOME) SS_DELAY(100) SS_TAP(X_ENTER) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case PASTE_REPLACE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_DELETE) SS_DELAY(100) SS_LCTL(SS_TAP(X_V)));
    }
    break;

  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[14];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: register_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: unregister_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[0].step = 0;
}
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: layer_move(4); break;
        case DOUBLE_TAP: layer_move(4); break;
        case DOUBLE_HOLD: layer_move(1); break;
        case DOUBLE_SINGLE_TAP: layer_move(4); break;
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_MINUS);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_MINUS); break;
        case DOUBLE_TAP: register_code16(KC_MINUS); register_code16(KC_MINUS); break;
        case DOUBLE_HOLD: layer_move(8); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case DOUBLE_TAP: unregister_code16(KC_MINUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
        tap_code16(KC_LCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_LCBR);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_LCBR); break;
        case SINGLE_HOLD: layer_on(9); break;
        case DOUBLE_TAP: register_code16(KC_LCBR); register_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LCBR); register_code16(KC_LCBR);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_LCBR); break;
        case SINGLE_HOLD: layer_off(9); break;
        case DOUBLE_TAP: unregister_code16(KC_LCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LCBR); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RCBR);
        tap_code16(KC_RCBR);
        tap_code16(KC_RCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_RCBR);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_RCBR); break;
        case SINGLE_HOLD: register_code16(KC_RALT); break;
        case DOUBLE_TAP: register_code16(KC_RCBR); register_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RCBR); register_code16(KC_RCBR);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_RCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_RALT); break;
        case DOUBLE_TAP: unregister_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RCBR); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PGUP);
        tap_code16(KC_PGUP);
        tap_code16(KC_PGUP);
    }
    if(state->count > 3) {
        tap_code16(KC_PGUP);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_PGUP); break;
        case SINGLE_HOLD: register_code16(KC_RALT); break;
        case DOUBLE_TAP: register_code16(KC_PGUP); break;
        case DOUBLE_HOLD: register_code16(KC_PGUP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PGUP); register_code16(KC_PGUP);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_PGUP); break;
        case SINGLE_HOLD: unregister_code16(KC_RALT); break;
        case DOUBLE_TAP: unregister_code16(KC_PGUP); break;
        case DOUBLE_HOLD: unregister_code16(KC_PGUP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PGUP); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PGDN);
        tap_code16(KC_PGDN);
        tap_code16(KC_PGDN);
    }
    if(state->count > 3) {
        tap_code16(KC_PGDN);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_PGDN); break;
        case SINGLE_HOLD: layer_on(7); break;
        case DOUBLE_TAP: register_code16(KC_PGDN); break;
        case DOUBLE_HOLD: register_code16(KC_PGDN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PGDN); register_code16(KC_PGDN);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_PGDN); break;
        case SINGLE_HOLD: layer_off(7); break;
        case DOUBLE_TAP: unregister_code16(KC_PGDN); break;
        case DOUBLE_HOLD: unregister_code16(KC_PGDN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PGDN); break;
    }
    dance_state[6].step = 0;
}
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: layer_move(4); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: layer_move(4); break;
        case DOUBLE_HOLD: layer_move(2); break;
        case DOUBLE_SINGLE_TAP: layer_move(4); break;
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
    }
    dance_state[7].step = 0;
}
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_HOLD: layer_move(0); break;
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
    }
    dance_state[8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_HOME));
        tap_code16(LCTL(KC_HOME));
        tap_code16(LCTL(KC_HOME));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_HOME));
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_HOME)); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_END)); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_HOME)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_HOME)); register_code16(LCTL(KC_HOME));
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_HOME)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_END)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_HOME)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_HOME)); break;
    }
    dance_state[9].step = 0;
}
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: layer_move(6); break;
        case SINGLE_HOLD: register_code16(KC_V); break;
        case DOUBLE_TAP: layer_move(6); break;
        case DOUBLE_SINGLE_TAP: layer_move(6); break;
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_HOLD: unregister_code16(KC_V); break;
    }
    dance_state[10].step = 0;
}
void on_dance_bof_eof(tap_dance_state_t *state, void *user_data);
void dance_bof_eof_finished(tap_dance_state_t *state, void *user_data);
void dance_bof_eof_reset(tap_dance_state_t *state, void *user_data);

void on_dance_bof_eof(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(LSFT(KC_HOME)));
        tap_code16(LCTL(LSFT(KC_HOME)));
        tap_code16(LCTL(LSFT(KC_HOME)));
    }
    if(state->count > 3) {
        tap_code16(LCTL(LSFT(KC_HOME)));
    }
}

void dance_bof_eof_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(LCTL(LSFT(KC_HOME))); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_END))); break;
        case DOUBLE_TAP: register_code16(LCTL(LSFT(KC_HOME))); register_code16(LCTL(LSFT(KC_HOME))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(LSFT(KC_HOME))); register_code16(LCTL(LSFT(KC_HOME)));
    }
}

void dance_bof_eof_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(LCTL(LSFT(KC_HOME))); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_END))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(LSFT(KC_HOME))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(LSFT(KC_HOME))); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_AUDIO_VOL_DOWN);
        tap_code16(KC_AUDIO_VOL_DOWN);
        tap_code16(KC_AUDIO_VOL_DOWN);
    }
    if(state->count > 3) {
        tap_code16(KC_AUDIO_VOL_DOWN);
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
        case SINGLE_HOLD: register_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_HOLD: register_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_AUDIO_VOL_DOWN); register_code16(KC_AUDIO_VOL_DOWN);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case SINGLE_HOLD: unregister_code16(KC_AUDIO_MUTE); break;
        case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_HOLD: unregister_code16(KC_AUDIO_VOL_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
    }
    dance_state[12].step = 0;
}
void on_dance_13(tap_dance_state_t *state, void *user_data);
void dance_13_finished(tap_dance_state_t *state, void *user_data);
void dance_13_reset(tap_dance_state_t *state, void *user_data);

void on_dance_13(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
    if(state->count > 3) {
        tap_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_13_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_HOLD: register_code16(KC_MEDIA_STOP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
    }
}

void dance_13_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
        case SINGLE_HOLD: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
        case DOUBLE_HOLD: unregister_code16(KC_MEDIA_STOP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
    }
    dance_state[13].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_10_finished, dance_10_reset),
        [DANCE_BOF_EOF] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_bof_eof, dance_bof_eof_finished, dance_bof_eof_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
};
