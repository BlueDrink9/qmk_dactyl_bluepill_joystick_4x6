#include QMK_KEYBOARD_H
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

int16_t joyXMid = ANALOG_JOYSTICK_AXIS_MAX/2;
int16_t joyYMid = ANALOG_JOYSTICK_AXIS_MAX/2;

// Custom tapping terms
// uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // case SFT_T(KC_SPC):
//         //     return TAPPING_TERM + 1250;
//         // case LT(1, KC_GRV):
//         //     return 130;
//         default:
//             return TAPPING_TERM;
//     }
// }

// enum tap_dance_actions_enum {
//       TD_LAYER_TOGGLE
// };

enum custom_keycodes {
  NEWLINE_AFTER = SAFE_RANGE,
  PASTE_UP,
  CUT_EOL,
  SELECT_LINE,
  YANK_EOL,
  NEWLINE_UP,
  PASTE_REPLACE,
};

enum tap_dance_codes {
  TD_ESC_GRAVE,
  TD_SNAKE_CASE,
  TD_VIM_GG,
  TD_VISUAL_V,
  TD_BOF_EOF,
  TD_VOLDOWN_MUTE,
  TD_PAUSEPLAY,
};


enum layer_names {
    QWERTY,
    COLEMAK,
    // GAMING,
    NUMBERS,
    SPECIAL,
    VIM,
    VIM_SHIFTED,
    VIM_VISUAL,
    SNAKE_CASE,
};

// XXX DON'T FORGET TO INCLUDE A PATH TO QK_BOOTLOADER
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWERTY] = LAYOUT(
QK_GRAVE_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5,    KC_6, KC_7, KC_8, KC_9, KC_0, KC_EQL,
KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,    KC_Y, KC_U, KC_I, KC_O, KC_P, TD(TD_SNAKE_CASE),
KC_BSPC, KC_A, MT(KC_LALT, KC_S), MT(KC_LWIN, KC_D), MT(KC_LCTL, KC_F), KC_G,    KC_H, MT(KC_RCTL, KC_J), MT(KC_RWIN, KC_K), MT(KC_RALT, KC_L), KC_SEMICOLON, KC_QUOT,
LSFT_T(KC_LEFT_BRACKET), KC_Z, KC_X, KC_C, LT(VIM,KC_V), KC_B,     KC_N, LT(VIM,KC_M), KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_RIGHT_BRACKET),

    // Left cluster has joystick in top right position.
    KC_SPC, MT(KC_RALT, KC_ENTER), KC_MS_BTN1,       KC_APP,   TT(NUMBERS),      KC_RIGHT_SHIFT,
    // Temporary bootloader key on layer 0 so I don't forget to include one while debugging
    KC_BACKSPACE, KC_DEL,   TT(SPECIAL),      QK_BOOT, TT(SPECIAL), KC_ENTER
),

    [COLEMAK] = LAYOUT(
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS,
KC_TRNS, KC_Q,    KC_W,    KC_F,    KC_P,          KC_G,    KC_J,    KC_L,          KC_U,    KC_Y,    KC_SEMICOLON, KC_TRNS,
KC_TRNS, KC_A, MT(KC_LALT, KC_R), MT(KC_LWIN, KC_S), MT(KC_LCTL, KC_T), KC_D,    KC_H, MT(KC_RCTL, KC_N), MT(KC_RWIN, KC_E), MT(KC_RALT, KC_I), KC_O, KC_TRNS,
KC_TRNS, KC_Z,    KC_X,    KC_C,    LT(VIM, KC_V), KC_B,    KC_K,    LT(VIM, KC_M), KC_COMM, KC_DOT,  KC_SLSH,      KC_TRNS,

KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [NUMBERS] = LAYOUT(

KC_ESCAPE, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
KC_TRNS,   KC_GRAVE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINUS, KC_EQL, KC_F12,
KC_TRNS,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_TRNS,

KC_TRNS, KC_TRNS, KC_MS_BTN2,       KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
),

  [VIM] = LAYOUT(
DM_REC2, DM_RSTP,   DM_PLY1, DM_PLY2,   KC_END,       KC_TRNS,       KC_TRNS,        KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_HOME,    KC_TRNS,
KC_TRNS, DM_REC1, LCTL(KC_RIGHT),  KC_TRNS,   LCTL(KC_V),   TD(TD_VIM_GG),   KC_DOWN,        KC_RIGHT, LCTL(KC_Z), LCTL(KC_C), KC_TRNS,    KC_TRNS,
KC_TRNS, KC_END,         KC_BACKSPACE,       KC_TRNS,   KC_TRNS,      LCTL(KC_X),    LCTL(KC_RIGHT), TG(VIM),    NEWLINE_AFTER, KC_TRNS, KC_TRNS,    KC_TRNS,
MO(VIM_SHIFTED),   KC_TRNS,        KC_DELETE,       KC_CUT, TD(TD_VISUAL_V), LCTL(KC_LEFT), KC_UP,          KC_TRNS,  KC_TRNS,    KC_TRNS,    LCTL(KC_F), MO(VIM_SHIFTED),

KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, MO(VIM_SHIFTED),
KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [VIM_SHIFTED] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_END,     KC_TRNS,      KC_HOME, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, PASTE_UP, LCTL(KC_END), KC_TRNS, KC_TRNS, KC_TRNS,    YANK_EOL, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_END,  KC_TRNS,   KC_TRNS, KC_TRNS,    CUT_EOL,   KC_TRNS, KC_HOME, NEWLINE_UP, KC_TRNS,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_BACKSPACE, KC_TRNS, SELECT_LINE, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,

KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [VIM_VISUAL] = LAYOUT(
  TG(VIM_VISUAL),   KC_TRNS, KC_TRNS,              KC_TRNS, LSFT(KC_END),  KC_TRNS,             LSFT(KC_HOME), KC_TRNS,        KC_TRNS,              KC_TRNS,     LSFT(KC_HOME), KC_TRNS,
  KC_TRNS,   KC_TRNS, LCTL(LSFT(KC_RIGHT)), KC_TRNS, PASTE_REPLACE, TD(TD_BOF_EOF),   LSFT(KC_DOWN), LSFT(KC_RIGHT), LCTL(KC_Z),          LCTL(KC_C), KC_TRNS,       KC_TRNS,
  KC_TRNS,   KC_TRNS, KC_TRNS,              KC_TRNS, KC_TRNS,       LCTL(KC_X),          LSFT(KC_LEFT), KC_TRNS,        LCTL(LSFT(KC_RIGHT)), KC_TRNS,     KC_TRNS,       KC_TRNS,
    KC_TRNS, KC_TRNS, KC_BACKSPACE,         KC_TRNS, TG(VIM_VISUAL),       LCTL(LSFT(KC_LEFT)), LSFT(KC_UP),   KC_TRNS,        LSFT(KC_TAB),         KC_TAB,      KC_TRNS,       KC_TRNS,

KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
  ),


  [SPECIAL] = LAYOUT(
    TO(QWERTY), TO(QWERTY), TO(COLEMAK),       KC_TRNS,    KC_TRNS,      KC_SYSTEM_SLEEP,       QK_BOOT,         KC_TRNS,       KC_TRNS,    KC_TRNS,        KC_PRINT_SCREEN, KC_SYRQ,
    KC_TRNS,         KC_TRNS, KC_MS_WH_LEFT, KC_MS_UP,   KC_MS_WH_RIGHT, KC_TRNS,       KC_TRNS, KC_HOME, KC_UP,   KC_END, KC_TRNS,    KC_TRNS,
    KC_CAPS_LOCK,     KC_TRNS, KC_MS_LEFT,    KC_MS_DOWN, KC_MS_RIGHT,    KC_MS_WH_UP,   KC_PGUP,  KC_LEFT,    KC_DOWN, KC_RIGHT,    KC_TRNS,    KC_TRNS,
    QK_BOOT,         KC_TRNS, KC_MS_BTN2,     KC_MS_BTN3, KC_MS_BTN1,   KC_MS_WH_DOWN,     KC_PGDN,  KC_TRNS,       KC_TRNS,    KC_UP,          KC_TRNS,    KC_TRNS,

  TD(TD_PAUSEPLAY), KC_AUDIO_VOL_UP,     KC_MS_BTN3,       KC_PGUP, KC_MS_BTN2, KC_MS_BTN1,
  KC_MEDIA_PREV_TRACK, TD(TD_VOLDOWN_MUTE), KC_TRNS,       KC_PGDN, KC_TRNS, KC_MS_BTN3
  ),

  [SNAKE_CASE] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_SPC,
    KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,

KC_UNDS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, TG(SNAKE_CASE),
KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS


)};

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
    // Set mid based on current resting position
    if ((joyXMid != analogReadPin(ANALOG_JOYSTICK_X_AXIS_PIN))|
          (joyYMid != analogReadPin(ANALOG_JOYSTICK_Y_AXIS_PIN))) {
        joyXMid = analogReadPin(ANALOG_JOYSTICK_X_AXIS_PIN);
        joyYMid = analogReadPin(ANALOG_JOYSTICK_Y_AXIS_PIN);
    }
}

joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    JOYSTICK_AXIS_IN(ANALOG_JOYSTICK_X_AXIS_PIN, ANALOG_JOYSTICK_AXIS_MAX, ANALOG_JOYSTICK_AXIS_MAX/2, 0), // X, Low(L) ~ High(R)
    JOYSTICK_AXIS_IN(ANALOG_JOYSTICK_Y_AXIS_PIN, ANALOG_JOYSTICK_AXIS_MAX, ANALOG_JOYSTICK_AXIS_MAX/2, 0), // Y, Low(U) ~ High(D)
};

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


void tap_dance_pair_on_hold(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;

    if(state->count == 3) {
        tap_code16(pair->kc2);
        tap_code16(pair->kc2);
        tap_code16(pair->kc2);
    }
    if(state->count > 3) {
        tap_code16(pair->kc1);
    }
}

void tap_dance_pair_hold_finished(tap_dance_state_t *state, void *user_data) {
  tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;
  switch (dance_step(state)) {
    case SINGLE_HOLD: register_code16(pair->kc2); break;
    default: register_code16(pair->kc1); break;
  }
}

void tap_dance_pair_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;
    switch (dance_step(state)) {
      case SINGLE_HOLD: unregister_code16(pair->kc2); break;
      case SINGLE_TAP: wait_ms(TAP_CODE_DELAY); unregister_code16(pair->kc1); break;
      default: unregister_code16(pair->kc1); break;
    }
}

#define ACTION_TAP_DANCE_HOLD(kc1, kc2) \
    { .fn = {tap_dance_pair_on_hold, tap_dance_pair_hold_finished, tap_dance_pair_hold_reset, NULL}, .user_data = (void *)&((tap_dance_pair_t){kc1, kc2}), }


void on_td_esc_grave(tap_dance_state_t *state, void *user_data);
void td_esc_grave_finished(tap_dance_state_t *state, void *user_data);
void td_esc_grave_reset(tap_dance_state_t *state, void *user_data);

void on_td_esc_grave(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
        tap_code16(KC_ESCAPE);
    }
    if(state->count > 3) {
        tap_code16(KC_ESCAPE);
    }
}

void td_esc_grave_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[TD_ESC_GRAVE].step = dance_step(state);
    switch (dance_state[TD_ESC_GRAVE].step) {
        case SINGLE_TAP: register_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: register_code16(KC_ESCAPE); register_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: register_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ESCAPE); register_code16(KC_ESCAPE);
    }
}

void td_esc_grave_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TD_ESC_GRAVE].step) {
        case SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_TAP: unregister_code16(KC_ESCAPE); break;
        case DOUBLE_HOLD: unregister_code16(KC_GRAVE); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ESCAPE); break;
    }
    dance_state[TD_ESC_GRAVE].step = 0;
}

void on_td_snake_case(tap_dance_state_t *state, void *user_data);
void td_snake_case_finished(tap_dance_state_t *state, void *user_data);
void td_snake_case_reset(tap_dance_state_t *state, void *user_data);

void on_td_snake_case(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
        tap_code16(KC_MINUS);
    }
    if(state->count > 3) {
        tap_code16(KC_MINUS);
    }
}

void td_snake_case_finished(tap_dance_state_t *state, void *user_data) {
  // Change layer if double tapped and held
    dance_state[TD_SNAKE_CASE].step = dance_step(state);
    switch (dance_state[TD_SNAKE_CASE].step) {
        case SINGLE_TAP: register_code16(KC_MINUS); break;
        case DOUBLE_TAP: register_code16(KC_MINUS); register_code16(KC_MINUS); break;
        case DOUBLE_HOLD: layer_move(SNAKE_CASE); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MINUS); register_code16(KC_MINUS);
    }
}

void td_snake_case_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TD_SNAKE_CASE].step) {
        case SINGLE_TAP: unregister_code16(KC_MINUS); break;
        case DOUBLE_TAP: unregister_code16(KC_MINUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MINUS); break;
    }
    dance_state[TD_SNAKE_CASE].step = 0;
}

void on_td_vim_gg(tap_dance_state_t *state, void *user_data);
void td_vim_gg_finished(tap_dance_state_t *state, void *user_data);
void td_vim_gg_reset(tap_dance_state_t *state, void *user_data);

void on_td_vim_gg(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_HOME));
        tap_code16(LCTL(KC_HOME));
        tap_code16(LCTL(KC_HOME));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_HOME));
    }
}

void td_vim_gg_finished(tap_dance_state_t *state, void *user_data) {
  // ctrl+home (BoF) on g or gg, EoF on G
    dance_state[TD_VIM_GG].step = dance_step(state);
    switch (dance_state[TD_VIM_GG].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_HOME)); break;
        case SINGLE_HOLD: register_code16(LCTL(KC_END)); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_HOME)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_HOME)); register_code16(LCTL(KC_HOME));
    }
}

void td_vim_gg_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TD_VIM_GG].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_HOME)); break;
        case SINGLE_HOLD: unregister_code16(LCTL(KC_END)); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_HOME)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_HOME)); break;
    }
    dance_state[TD_VIM_GG].step = 0;
}

void td_visual_v_finished(tap_dance_state_t *state, void *user_data);
void td_visual_v_reset(tap_dance_state_t *state, void *user_data);

void td_visual_v_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[TD_VISUAL_V].step = dance_step(state);
    switch (dance_state[TD_VISUAL_V].step) {
        case SINGLE_TAP: layer_move(VIM_VISUAL); break;
        case SINGLE_HOLD: register_code16(KC_V); break;
        case DOUBLE_TAP: layer_move(VIM_VISUAL); break;
        case DOUBLE_SINGLE_TAP: layer_move(VIM_VISUAL); break;
    }
}

void td_visual_v_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TD_VISUAL_V].step) {
        case SINGLE_HOLD: unregister_code16(KC_V); break;
    }
    dance_state[TD_VISUAL_V].step = 0;
}
void on_td_bof_eof(tap_dance_state_t *state, void *user_data);
void td_bof_eof_finished(tap_dance_state_t *state, void *user_data);
void td_bof_eof_reset(tap_dance_state_t *state, void *user_data);

void on_td_bof_eof(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(LSFT(KC_HOME)));
        tap_code16(LCTL(LSFT(KC_HOME)));
        tap_code16(LCTL(LSFT(KC_HOME)));
    }
    if(state->count > 3) {
        tap_code16(LCTL(LSFT(KC_HOME)));
    }
}

void td_bof_eof_finished(tap_dance_state_t *state, void *user_data) {
  // ctrl+shift+home if gg, end if hold g 
    dance_state[TD_VIM_GG].step = dance_step(state);
    switch (dance_state[TD_VIM_GG].step) {
        case SINGLE_TAP: register_code16(LCTL(LSFT(KC_HOME))); break;
        case SINGLE_HOLD: register_code16(LCTL(LSFT(KC_END))); break;
        case DOUBLE_TAP: register_code16(LCTL(LSFT(KC_HOME))); register_code16(LCTL(LSFT(KC_HOME))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(LSFT(KC_HOME))); register_code16(LCTL(LSFT(KC_HOME)));
    }
}

void td_bof_eof_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[TD_VIM_GG].step) {
        case SINGLE_TAP: unregister_code16(LCTL(LSFT(KC_HOME))); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LSFT(KC_END))); break;
        case DOUBLE_TAP: unregister_code16(LCTL(LSFT(KC_HOME))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(LSFT(KC_HOME))); break;
    }
    dance_state[TD_VIM_GG].step = 0;
}

// void on_td_voldown_mute(tap_dance_state_t *state, void *user_data);
// void td_voldown_mute_finished(tap_dance_state_t *state, void *user_data);
// void td_voldown_mute_reset(tap_dance_state_t *state, void *user_data);

// void on_td_voldown_mute(tap_dance_state_t *state, void *user_data) {
//     if(state->count == 3) {
//         tap_code16(KC_AUDIO_VOL_DOWN);
//         tap_code16(KC_AUDIO_VOL_DOWN);
//         tap_code16(KC_AUDIO_VOL_DOWN);
//     }
//     if(state->count > 3) {
//         tap_code16(KC_AUDIO_VOL_DOWN);
//     }
// }

// void td_voldown_mute_finished(tap_dance_state_t *state, void *user_data) {
//   // Vol down if tapped/double tapped, mute if held
//     dance_state[TD_VOLDOWN_MUTE].step = dance_step(state);
//     switch (dance_state[TD_VOLDOWN_MUTE].step) {
//         case SINGLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
//         case SINGLE_HOLD: register_code16(KC_AUDIO_MUTE); break;
//         case DOUBLE_TAP: register_code16(KC_AUDIO_VOL_DOWN); break;
//         case DOUBLE_HOLD: register_code16(KC_AUDIO_VOL_DOWN); break;
//         case DOUBLE_SINGLE_TAP: tap_code16(KC_AUDIO_VOL_DOWN); register_code16(KC_AUDIO_VOL_DOWN);
//     }
// }

// void td_voldown_mute_reset(tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     switch (dance_state[TD_VOLDOWN_MUTE].step) {
//         case SINGLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
//         case SINGLE_HOLD: unregister_code16(KC_AUDIO_MUTE); break;
//         case DOUBLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
//         case DOUBLE_HOLD: unregister_code16(KC_AUDIO_VOL_DOWN); break;
//         case DOUBLE_SINGLE_TAP: unregister_code16(KC_AUDIO_VOL_DOWN); break;
//     }
//     dance_state[TD_VOLDOWN_MUTE].step = 0;
// }

// void on_td_pauseplay(tap_dance_state_t *state, void *user_data);
// void td_pauseplay_finished(tap_dance_state_t *state, void *user_data);
// void td_pauseplay_reset(tap_dance_state_t *state, void *user_data);

// void on_td_pauseplay(tap_dance_state_t *state, void *user_data) {
//     if(state->count == 3) {
//         tap_code16(KC_MEDIA_PLAY_PAUSE);
//         tap_code16(KC_MEDIA_PLAY_PAUSE);
//         tap_code16(KC_MEDIA_PLAY_PAUSE);
//     }
//     if(state->count > 3) {
//         tap_code16(KC_MEDIA_PLAY_PAUSE);
//     }
// }

// void td_pauseplay_finished(tap_dance_state_t *state, void *user_data) {
//   // pauseplay if tapped, skip if held
//     dance_state[TD_PAUSEPLAY].step = dance_step(state);
//     switch (dance_state[TD_PAUSEPLAY].step) {
//         case SINGLE_TAP: register_code16(KC_MEDIA_PLAY_PAUSE); break;
//         case SINGLE_HOLD: register_code16(KC_MEDIA_NEXT_TRACK); break;
//         case DOUBLE_TAP: register_code16(KC_MEDIA_NEXT_TRACK); break;
//         case DOUBLE_HOLD: register_code16(KC_MEDIA_STOP); break;
//         case DOUBLE_SINGLE_TAP: tap_code16(KC_MEDIA_PLAY_PAUSE); register_code16(KC_MEDIA_PLAY_PAUSE);
//     }
// }

// void td_pauseplay_reset(tap_dance_state_t *state, void *user_data) {
//     wait_ms(10);
//     switch (dance_state[TD_PAUSEPLAY].step) {
//         case SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
//         case SINGLE_HOLD: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
//         case DOUBLE_TAP: unregister_code16(KC_MEDIA_NEXT_TRACK); break;
//         case DOUBLE_HOLD: unregister_code16(KC_MEDIA_STOP); break;
//         case DOUBLE_SINGLE_TAP: unregister_code16(KC_MEDIA_PLAY_PAUSE); break;
//     }
//     dance_state[TD_PAUSEPLAY].step = 0;
// }

/* Vial handles TD differently
tap_dance_action_t tap_dance_actions[] = {
        [TD_ESC_GRAVE] = ACTION_TAP_DANCE_FN_ADVANCED(on_td_esc_grave, td_esc_grave_finished, td_esc_grave_reset),
        [TD_SNAKE_CASE] = ACTION_TAP_DANCE_FN_ADVANCED(on_td_snake_case, td_snake_case_finished, td_snake_case_reset),
        [TD_VIM_GG] = ACTION_TAP_DANCE_FN_ADVANCED(on_td_vim_gg, td_vim_gg_finished, td_vim_gg_reset),
        [TD_VISUAL_V] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_visual_v_finished, td_visual_v_reset),
        [TD_BOF_EOF] = ACTION_TAP_DANCE_FN_ADVANCED(on_td_bof_eof, td_bof_eof_finished, td_bof_eof_reset),
        // [TD_VOLDOWN_MUTE] = ACTION_TAP_DANCE_FN_ADVANCED(on_td_voldown_mute, td_voldown_mute_finished, td_voldown_mute_reset),
        // [TD_PAUSEPLAY] = ACTION_TAP_DANCE_FN_ADVANCED(on_td_pauseplay, td_pauseplay_finished, td_pauseplay_reset),
        [TD_VOLDOWN_MUTE] = ACTION_TAP_DANCE_HOLD(KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE),
        [TD_PAUSEPLAY] = ACTION_TAP_DANCE_HOLD(KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK),
};
*/

// Send delete with shift+bs
const key_override_t override_shift_bs_del = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// // This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
//     &override_shift_bs_del,
//     NULL // Null terminate the array of overrides!
// };
