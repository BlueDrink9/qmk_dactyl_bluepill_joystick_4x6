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

#define USB_SUSPEND_WAKEUP_DELAY 0


/* split config */
// Use these if I decide to solder-specify handedness - which I probably
// should do tbh
// #define SPLIT_HAND_PIN B7
// #define    SPLIT_HAND_PIN_LOW_IS_LEFT
// USB cable goes into left
#define MASTER_LEFT

// Only actually need these for visual state display
// #define SPLIT_LAYER_STATE_ENABLE
// #define SPLIT_MODS_ENABLE

// #define SPLIT_POINTING_ENABLE
// #define POINTING_DEVICE_LEFT

#define FORCED_SYNC_THROTTLE_MS 100
#define SPLIT_MAX_CONNECTION_ERRORS 10
// #define SERIAL_USART_TX_PIN A2 
// Because A2 is tx2, not tx1
#define SERIAL_USART_DRIVER SD2


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
#define JOYSTICK_AXIS_MAX 4095
#define ANALOG_JOYSTICK_AXIS_MAX 4095
// Lower makes movement faster
#define ANALOG_JOYSTICK_SPEED_REGULATOR 20
#define ANALOG_JOYSTICK_SPEED_MAX 2
#define ANALOG_JOYSTICK_CLICK_PIN A0


#define GRAVE_ESC_CTRL_OVERRIDE

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000 
