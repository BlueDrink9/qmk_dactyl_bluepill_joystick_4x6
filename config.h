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

// Only actually need these for visual state display
// #define SPLIT_LAYER_STATE_ENABLE
// #define SPLIT_MODS_ENABLE

// Enables left pointer even when right is master
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_LEFT

#define SERIAL_USART_DRIVER SD3
#define SERIAL_DEBUG

// Joystick setup
#define ANALOG_JOYSTICK_X_AXIS_PIN B0
#define ANALOG_JOYSTICK_Y_AXIS_PIN B1
#define ANALOG_JOYSTICK_AXIS_MAX 1024
// Small dead zone to prevent mouse drift?
#define ANALOG_JOYSTICK_AXIS_MIN 0
// Lower makes movement faster
#define ANALOG_JOYSTICK_SPEED_REGULATOR 20
#define ANALOG_JOYSTICK_SPEED_MAX 2
// Sets ranges to be considered movement automatically.
#define ANALOG_JOYSTICK_AUTO_AXIS
// Use custom weights for lever positions for smooth accelleration and fine adjustment.
#define ANALOG_JOYSTICK_WEIGHTS { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 8 , 9 , 10 , 11 , 12 , 13 , 14 , 15 , 16 , 17 , 18 , 19 , 20 , 21 , 22 , 23 , 24 , 25 , 26 , 28 , 29 , 30 , 31 , 32 , 33 , 34 , 35 , 36 , 37 , 38 , 39 , 40 , 41 , 42 , 43 , 44 , 45 , 46 , 47 , 48 , 49 , 50 , 51 , 52 , 53 , 54 , 55 , 56 , 57 , 58 , 59 , 60 , 61 , 62 , 63 , 65 , 66 , 67 , 68 , 69 , 70 , 71 , 72 , 73 , 74 , 75 , 76 , 77 , 78 , 79 , 80 , 81 , 82 , 83 , 84 , 85 , 86 , 87 , 88 , 89 , 90 , 91 , 92 , 93 , 94 , 95 , 96 , 97 , 98 , 99 , 100 }
// Cut off movement while joystick returns to start position.
#define ANALOG_JOYSTICK_CUTOFF

// Deadzones in percent
#define ANALOG_JOYSTICK_X_AXIS_DEADZONE 3;
#define ANALOG_JOYSTICK_Y_AXIS_DEADZONE 3;

// Docs say I can move this to info.json but compiler complains
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 3000 

#define PERMISSIVE_HOLD_PER_KEY

#define GRAVE_ESC_CTRL_OVERRIDE
#define COMBO_TERM 100  // default 50

#define INDICATOR_LED_PIN_RIGHT A2
#define INDICATOR_LED_PIN_LEFT A3
#define INDICATOR_LED_CHANNEL_RIGHT 3
#define INDICATOR_LED_CHANNEL_LEFT 4
#define INDICATOR_LED_PWM &PWMD2


// #define BACKLIGHT_PIN A3
// #define BACKLIGHT_PINS { A2, A3 }
// #define BACKLIGHT_BREATHING
// #define BACKLIGHT_ON_STATE 0
// #define BACKLIGHT_DEFAULT_BREATHING true

/* Miryoku */
#define BILATERAL_COMBINATIONS_LIMIT_CHORD_TO_N_KEYS 4 /* GUI, Alt, Ctrl, Shift */
#define BILATERAL_COMBINATIONS_DELAY_MODS_THAT_MATCH MOD_MASK_GUI
#define BILATERAL_COMBINATIONS_DELAY_MATCHED_MODS_BY 120  /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_CROSSOVER_AFTER 80   /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_SAMESIDED_AFTER 500 /* ms */
// Don't allow home row mods while in the middle off typing
#define BILATERAL_COMBINATIONS_TYPING_STREAK_TIMEOUT 160  /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_MODMASK (~MOD_MASK_SHIFT)
