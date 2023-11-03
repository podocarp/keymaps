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
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_EQL, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_BSPC, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, KC_MPLY, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_QUOT, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(1), MO(2), SC_SENT, KC_BSLS, KC_LBRC, KC_RBRC),
	[1] = LAYOUT(KC_PSCR, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_NO, KC_F12, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_LCBR, KC_RCBR, KC_PIPE, KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LT, KC_GT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, MO(3), KC_NO, KC_NO, KC_NO, KC_NO),
	[2] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_PGUP, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_END, KC_PGDN, KC_NO, KC_NO, KC_NO, KC_PLUS, KC_NO, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_COLN, KC_DEL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BTN1, KC_BTN2, KC_BTN3, KC_BTN4, KC_QUES, KC_DQUO, KC_NO, KC_NO, KC_NO, KC_NO, MO(3), KC_TRNS, KC_TRNS, KC_PIPE, KC_LCBR, KC_RCBR),
	[3] = LAYOUT(KC_NO, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, KC_NO, KC_P7, KC_P8, KC_P9, KC_PPLS, KC_NO, KC_NO, QK_BOOT, RGB_VAD, RGB_VAI, RGB_SAD, RGB_SAI, KC_NO, KC_P4, KC_P5, KC_P6, KC_PCMM, KC_NO, KC_NO, EE_CLR, RGB_SPD, RGB_SPI, KC_NO, KC_NO, KC_NO, KC_P1, KC_P2, KC_P3, KC_PEQL, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, KC_NO, KC_NO, KC_P0, KC_PDOT, KC_PENT, KC_NUM, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO)
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_status(void) {
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("Settings\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

// WPM-responsive animation stuff here
#define IDLE_FRAMES 5
#define IDLE_SPEED 40 // below this wpm value your animation will idle

// #define PREP_FRAMES 1 // uncomment if >1

#define TAP_FRAMES 2
#define TAP_SPEED 60 // above this wpm value typing animation to triggere

#define ANIM_FRAME_DURATION 200 // how long each frame lasts in ms
// #define SLEEP_TIMER 60000 // should sleep after this period of 0 wpm, needs fixing
#define ANIM_SIZE 636 // number of bytes in array, minimize for adequate firmware size, max is 1024

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
// uint8_t current_prep_frame = 0; // uncomment if PREP_FRAMES >1
uint8_t current_tap_frame = 0;

// Images credit j-inc(/James Incandenza) and pixelbenny. Credit to obosob for initial animation approach.
bool oled_task_user(void) {
    if (!is_keyboard_master()) {
    } else {
        oled_set_cursor(0, 6);
        oled_write_P(PSTR("WPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), '0'), false);
        oled_write_P(PSTR("\n"), false);
        render_status();
    }

    return false;
}

#endif
