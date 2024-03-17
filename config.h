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
// If I need to use one half without the other, this might still be
// useful. (Matrix handedness only works when both are connected)
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define SPLIT_HAND_MATRIX_GRID_LOW_IS_LEFT

// Enables left pointer even when right is master
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_LEFT

#define SERIAL_USART_DRIVER SD3

// #define SERIAL_DEBUG

// Joystick setup
#define ANALOG_JOYSTICK_X_AXIS_PIN B0
#define ANALOG_JOYSTICK_Y_AXIS_PIN B1
#define ANALOG_JOYSTICK_AXIS_MAX 1024
// Small dead zone to prevent mouse drift?
#define ANALOG_JOYSTICK_AXIS_MIN 0
// Lower makes movement faster
// Set to 1 to avoid interfering with weights.
#define ANALOG_JOYSTICK_SPEED_REGULATOR 1
#define ANALOG_JOYSTICK_SPEED_MAX 1
// Sets ranges to be considered movement automatically.
// #define ANALOG_JOYSTICK_AUTO_AXIS

// Use custom weights for lever positions for smooth accelleration and fine adjustment.
// Generated with JSON.stringify(Array.from(Array(101).keys()).map(x =>
// Math.max(Math.ceil((((0.88*x/100-0.35)**3+0.020)/0.982*100)), 0)))
// then the following macro within the pasted output:
// "+dri}ds"ds];s/,0/,1/g
#define ANALOG_JOYSTICK_WEIGHTS {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,8,8,9,9,9,10,10,11,11,12,12,13,14,14,15,16,16,17,18 }
// Cut off movement while joystick returns to start position.
#define ANALOG_JOYSTICK_CUTOFF

// Deadzones in percent
#define ANALOG_JOYSTICK_X_AXIS_DEADZONE 7
#define ANALOG_JOYSTICK_Y_AXIS_DEADZONE 6
#define MOUSE_EXTENDED_REPORT

// Docs say I can move this to info.json but compiler complains
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000 

#define PERMISSIVE_HOLD_PER_KEY

#define GRAVE_ESC_CTRL_OVERRIDE
#define COMBO_TERM 100  // default 50

#define BREATHING_LED_PWM &PWMD2
#define N_BREATHING_PINS 2
#define BREATHING_LED_PIN_RIGHT A2
#define BREATHING_LED_PIN_LEFT A3
#define BREATHING_PINS { BREATHING_LED_PIN_LEFT, BREATHING_LED_PIN_RIGHT }; 
#define BREATHING_LED_CHANNEL_RIGHT 2
#define BREATHING_LED_CHANNEL_LEFT 3

/* Miryoku */
#define BILATERAL_COMBINATIONS_LIMIT_CHORD_TO_N_KEYS 4 /* GUI, Alt, Ctrl, Shift */
#define BILATERAL_COMBINATIONS_DELAY_MODS_THAT_MATCH MOD_MASK_GUI
#define BILATERAL_COMBINATIONS_DELAY_MATCHED_MODS_BY 120  /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_CROSSOVER_AFTER 80   /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_SAMESIDED_AFTER 500 /* ms */
// Don't allow home row mods while in the middle off typing
#define BILATERAL_COMBINATIONS_TYPING_STREAK_TIMEOUT 160  /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_MODMASK (~MOD_MASK_SHIFT)
