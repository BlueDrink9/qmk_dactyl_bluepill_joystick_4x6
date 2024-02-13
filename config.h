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

/* General feel settings */

/* split config */
// If soldered
// #define    SPLIT_HAND_PIN_LOW_IS_LEFT
// Matrix with missing slot
// #define SPLIT_HAND_MATRIX_GRID_LOW_IS_RIGHT
// USB cable goes into left
// #define MASTER_LEFT
#define MASTER_RIGHT

// Only actually need these for visual state display
// #define SPLIT_LAYER_STATE_ENABLE
// #define SPLIT_MODS_ENABLE

// If right is master, enables left pointing device
// #define SPLIT_POINTING_ENABLE
// #define POINTING_DEVICE_LEFT

// Only got second half working with
// speed 2 + bitbang. USART half
// duplex didn't work.
#define SELECT_SOFT_SERIAL_SPEED 2
// #define SPLIT_MAX_CONNECTION_ERRORS 50
// #define SPLIT_CONNECTION_CHECK_TIMEOUT 2000
// #define FORCED_SYNC_THROTTLE_MS 1
#define SERIAL_DEBUG
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 3500

#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 5000


// // Joystick setup
#define JOYSTICK_BUTTON_COUNT 0
// #define JOY_BUTTON_PIN B5
// // #define JOY_BUTTON_KEY JS_0
// #define JOY_BUTTON_KEY KC_X
// Min 0, max 6: X, Y, Z, Rx, Ry, Rz
#define JOYSTICK_AXIS_COUNT 2
#define ANALOG_JOYSTICK_X_AXIS_PIN B0
#define ANALOG_JOYSTICK_Y_AXIS_PIN B1
// Min 8, max 16
#define JOYSTICK_AXIS_RESOLUTION 12
#define ANALOG_JOYSTICK_AXIS_MAX 4095
// Small dead zone of 10% to prevent mouse drift
#define ANALOG_JOYSTICK_AXIS_MIN 400
// Lower makes movement faster
#define ANALOG_JOYSTICK_SPEED_REGULATOR 20
#define ANALOG_JOYSTICK_SPEED_MAX 2
// #define ANALOG_JOYSTICK_CLICK_PIN A0
// Sets ranges to be considered movement automatically.
#define ANALOG_JOYSTICK_AUTO_AXIS
// Use custom weights for lever positions for smooth accelleration and fine adjustment.
#define ANALOG_JOYSTICK_WEIGHTS
// Cut off movement when joystick returns to start position.
#define ANALOG_JOYSTICK_CUTOFF

// Docs say I can move this to info.json but compiler complains
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000 

#define GRAVE_ESC_CTRL_OVERRIDE
