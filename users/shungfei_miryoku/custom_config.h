// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define MIDI_ADVANCED

#define MIRYOKU_ALTERNATIVES_OSUMANIA \
KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
KC_A,              KC_R,              KC_S,              KC_T,              KC_G,              KC_M,              KC_N,              KC_E,              KC_I,              KC_O,              \
KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,           \
U_NP,              U_NP,              KC_ESC,            KC_SPC,            KC_TAB,            KC_ENT,            KC_SPC,           KC_DEL,            U_NP,              U_NP

#define IRIS_ALTERNATIVES_TAP_CUSTOMDH \
TD(U_TD_U_BASE), KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                      KC_6,   KC_7,  KC_8,    KC_9,   KC_0,    TD(U_TD_U_BASE),\
KC_LBRC,         KC_Q,   KC_W,   KC_F,   KC_P,   KC_B,                      KC_J,   KC_L,  KC_U,    KC_Y,   KC_QUOT, KC_RBRC, \
KC_SCLN,         KC_A,   KC_R,   KC_S,   KC_T,   KC_G,                      KC_M,   KC_N,  KC_E,    KC_I,   KC_O,    KC_EQL, \
KC_GRV,          KC_Z,   KC_X,   KC_C,   KC_D,   KC_V,   KC_MPLY,  KC_MUTE, KC_K,   KC_H,  KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, \
                                         KC_ESC, KC_SPC, KC_TAB,   KC_ENT,  KC_SPC, KC_DEL

#define IRIS_ALTERNATIVES_MIDI \
TD(U_TD_U_BASE), MI_Ds3,   MI_F3,   MI_G3,   MI_A3,   MI_B3,                       KC_6,    KC_7,  KC_8,    KC_9,   KC_0,    TD(U_TD_U_BASE),\
MI_Gs2,          MI_As2,   MI_C3,   MI_D3,   MI_E3,   MI_Fs3,                      KC_J,    KC_L,  KC_U,    KC_Y,   KC_QUOT, KC_RBRC, \
MI_Ds2,          MI_F2,    MI_G2,   MI_A2,   MI_B2,   MI_Cs3,                      KC_M,    KC_N,  KC_E,    KC_I,   KC_O,    KC_EQL, \
MI_As1,          MI_C2,    MI_D2,   MI_E2,   MI_Fs2,  MI_Gs2,  KC_MPLY,   KC_MUTE, KC_K,    KC_H,  KC_COMM, KC_DOT, KC_SLSH, KC_BSLS, \
                                             MI_TRSD, MI_TRSU, MI_SUST,   KC_ENT,  MI_OCTD, MI_OCTU

// Modified miryoku with unused keys and rotary encoders
#define MIRYOKU_MAPPING(\
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29,\
     N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39\
)\
LAYOUT(\
TD(U_TD_U_BASE), KC_1, KC_2, KC_3, KC_4, KC_5,                      KC_6, KC_7, KC_8, KC_9, KC_0, TD(U_TD_U_BASE),\
KC_TAB,     K00,  K01,  K02,  K03,  K04,                       K05,  K06,  K07,  K08,  K09,  KC_RALT,\
KC_LCTL,    K10,  K11,  K12,  K13,  K14,                       K15,  K16,  K17,  K18,  K19,  KC_F3,\
KC_LSFT,    K20,  K21,  K22,  K23,  K24,  KC_MPLY,   KC_MUTE,  K25,  K26,  K27,  K28,  K29,  KC_RSFT,\
                              K32,  K33,  K34,                 K35,  K36,  K37\
)

#define IRIS_MAPPING(\
K38, K39, K40, K41, K42, K43,                 K44, K45, K46, K47, K48, K49,\
K50, K00, K01, K02, K03, K04,                 K05, K06, K07, K08,  K09,  K51,\
K52, K10, K11, K12, K13, K14,                 K15, K16, K17, K18,  K19,  K53,\
K54, K20, K21, K22, K23, K24, K55,       K56, K25, K26, K27,  K28,  K29,  K57,\
                    K32, K33, K34,       K35, K36, K37\
)\
LAYOUT(\
K38, K39, K40, K41, K42, K43,                 K44, K45, K46, K47, K48, K49,\
K50, K00, K01, K02, K03, K04,                 K05, K06, K07, K08,  K09,  K51,\
K52, K10, K11, K12, K13, K14,                 K15, K16, K17, K18,  K19,  K53,\
K54, K20, K21, K22, K23, K24, K55,       K56, K25, K26, K27,  K28,  K29,  K57,\
                    K32, K33, K34,       K35, K36, K37\
)

#if !defined(MIRYOKU_LAYER_EXTRA)
  #if !defined (MIRYOKU_LAYERS_FLIP)
    #if defined (MIRYOKU_EXTRA_CUSTOMDH)
      #define MIRYOKU_LAYER_EXTRA IRIS_ALTERNATIVES_TAP_CUSTOMDH
      #define MIRYOKU_LAYERMAPPING_EXTRA IRIS_MAPPING
    #elif defined (MIRYOKU_EXTRA_MIDI)
      #define MIRYOKU_LAYER_EXTRA IRIS_ALTERNATIVES_MIDI
      #define MIRYOKU_LAYERMAPPING_EXTRA IRIS_MAPPING
    #endif
  #endif
#endif

#if !defined(MIRYOKU_LAYER_TAP)
  #if !defined (MIRYOKU_LAYERS_FLIP)
    #if defined (MIRYOKU_TAP_OSUMANIA)
      #define MIRYOKU_LAYER_TAP MIRYOKU_ALTERNATIVES_OSUMANIA
    #endif
  #endif
#endif

#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(EXTRA,  "Extra") \
MIRYOKU_X(TAP,    "Tap") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Mouse") \
MIRYOKU_X(MEDIA,  "Media") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun")

#undef TAPPING_TERM
#define TAPPING_TERM 100
#define PERMISSIVE_HOLD
#define ACHORDION_STREAK

// Squeezing some extra space

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

#define NO_ACTION_ONESHOT


#undef RGB_MATRIX_FRAMEBUFFER_EFFECTS

#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
// #undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #undef ENABLE_RGB_MATRIX_CYCLE_ALL
// #undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
// #undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS

// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#undef ENABLE_RGB_MATRIX_TYPING_HEATMAP
#undef ENABLE_RGB_MATRIX_DIGITAL_RAIN

// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_MULTISPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
