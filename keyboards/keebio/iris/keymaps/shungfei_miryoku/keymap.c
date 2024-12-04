// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

// Rotary encoder code
// Most is copied from https://docs.splitkb.com/hc/en-us/articles/360010513760-How-can-I-use-a-rotary-encoder
#include QMK_KEYBOARD_H
#include "manna-harbour_miryoku.h"

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
#if defined MIRYOKU_LAYERS_FLIP
    if (index == 1) {
        // Right encoder
#else
    if (index == 0) {
        // Left encoder
#endif
        if (layer_state_is(U_BASE) | layer_state_is(U_BUTTON) | layer_state_is(U_EXTRA)) {
            // Browser tabbing
            if (clockwise) {
                tap_code16(C(KC_TAB));
            } else {
                tap_code16(S(C(KC_TAB)));
            }
        } else if (layer_state_is(U_SYM)) {
            // Scroll search results
            if (clockwise) {
                tap_code(KC_F3);
            } else {
                tap_code16(S(KC_F3));
            }
        } else if (layer_state_is(U_NUM) | layer_state_is(U_TAP)) {
            // Window switching. Could also use ALT+ESC
            if (clockwise) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                tap_code16(KC_TAB);
            } else {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                tap_code16(S(KC_TAB));
            }
        } else if (layer_state_is(U_FUN)) {
            // Brightness
            if (clockwise) {
                tap_code(KC_BRIU);
            } else {
                tap_code(KC_BRID);
            }
        }
#if defined MIRYOKU_LAYERS_FLIP
    } else if (index == 0) {
        // Left encoder
#else
    } else if (index == 1) {
        // Right encoder
#endif
        if (layer_state_is(U_BASE) | layer_state_is(U_BUTTON) | layer_state_is(U_EXTRA)) {
            // Scrolling
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        } else if (layer_state_is(U_MEDIA) | layer_state_is(U_TAP)) {
            // Volume control
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (layer_state_is(U_NAV)) {
            // Up/down and (CTRL) left/right arrow keys
            if (get_mods() & MOD_BIT(KC_LCTL)) {
                // Holding CTRL
                if (clockwise) {
                    tap_code(KC_RGHT);
                } else {
                    tap_code(KC_LEFT);
                }
            } else {
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
            }
        } else if (layer_state_is(U_MOUSE)) {
            // Redo/undo
            if (clockwise) {
                tap_code16(U_RDO);
            } else {
                tap_code16(U_UND);
            }
        }
    }
    return false;
}

// For rotary encoder window switching
void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 750) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}