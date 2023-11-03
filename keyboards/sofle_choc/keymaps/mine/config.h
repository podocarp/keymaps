/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

// Enabling this option changes the startup behavior to listen for an
// active USB communication to delegate which part is master and which
// is slave. With this option enabled and theres’s USB communication,
// then that half assumes it is the master, otherwise it assumes it
// is the slave.
//
// I've found this helps with some ProMicros where the slave does not boot
#define SPLIT_USB_DETECT
#define SPLIT_WPM_ENABLE
#define SPLIT_OLED_ENABLE


#define RGB_DISABLE_WHEN_USB_SUSPENDED     // turn off effects when suspended
#define SPLIT_TRANSPORT_MIRROR             // If LED_MATRIX_KEYPRESSES or LED_MATRIX_KEYRELEASES is enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100  // limits maximum brightness of LEDs (max 255). Higher may cause the controller to crash.

#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_RGB_TEST
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_TWINKLE

//#define DISABLE_RGB_MATRIX_ALPHAS_MODS
//#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
//#define DISABLE_RGB_MATRIX_BREATHING
//#define DISABLE_RGB_MATRIX_BAND_SAT
//#define DISABLE_RGB_MATRIX_BAND_VAL
//#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
//#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
//#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
//#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
//#define DISABLE_RGB_MATRIX_CYCLE_ALL
//#define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
//#define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
//#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
//#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
//#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
//#define DISABLE_RGB_MATRIX_DUAL_BEACON
//#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
//#define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
//#define DISABLE_RGB_MATRIX_RAINBOW_BEACON
//#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//#define DISABLE_RGB_MATRIX_RAINDROPS
//#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
//#define DISABLE_RGB_MATRIX_TYPING_HEATMAP
//#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
//#define DISABLE_RGB_MATRIX_SPLASH
//#define DISABLE_RGB_MATRIX_MULTISPLASH
//#define DISABLE_RGB_MATRIX_SOLID_SPLASH
//#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
//#define DISABLE_RGB_MATRIX_DUAL_BEACON
//#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
//#define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
//#define DISABLE_RGB_MATRIX_RAINBOW_BEACON
//#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//#define DISABLE_RGB_MATRIX_RAINDROPS
//#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
//#define DISABLE_RGB_MATRIX_TYPING_HEATMAP
//#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
//#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
//#define DISABLE_RGB_MATRIX_SPLASH
//#define DISABLE_RGB_MATRIX_MULTISPLASH
//#define DISABLE_RGB_MATRIX_SOLID_SPLASH
//#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH

#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
//#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN
//#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
//#undef ENABLE_RGB_MATRIX_MULTISPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH