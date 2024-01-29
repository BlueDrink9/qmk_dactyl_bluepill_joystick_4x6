/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* split config */
// USB cable goes into left
#define MASTER_LEFT

// Only actually need these for visual state display
// #define SPLIT_LAYER_STATE_ENABLE
// #define SPLIT_MODS_ENABLE

// #define SPLIT_POINTING_ENABLE

#define FORCED_SYNC_THROTTLE_MS 100
#define SPLIT_MAX_CONNECTION_ERRORS 10
// #define SERIAL_USART_TX_PIN A2 
// Because A2 is tx2, not tx1
#define SERIAL_USART_DRIVER SD2


/* mouse config */
#define MOUSEKEY_INTERVAL    20
#define MOUSEKEY_DELAY       0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED   7
#define MOUSEKEY_WHEEL_DELAY 0

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* Enables This makes it easier for fast typists to use dual-function keys */
#define PERMISSIVE_HOLD


// Joystick setup
#define JOYSTICK_BUTTON_COUNT 1
#define JOY_BUTTON_PIN B5
// #define JOY_BUTTON_KEY JS_0
#define JOY_BUTTON_KEY KC_X
// Min 0, max 6: X, Y, Z, Rx, Ry, Rz
#define JOYSTICK_AXIS_COUNT 2
#define JOYXPIN B0
#define JOYYPIN B1
// Min 8, max 16
#define JOYSTICK_AXIS_RESOLUTION 12
#define JOYSTICK_AXIS_MAX 4095
#define ANALOG_JOYSTICK_CLICK_PIN A0


// #define DEBUG_MATRIX_SCAN_RATE

// #define DEBOUNCE 10

// #define TAPPING_TOGGLE 2
