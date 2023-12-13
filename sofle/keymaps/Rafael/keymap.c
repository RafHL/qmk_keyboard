
 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
    {1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
    {35+15, 5, hsv},\
      {35+22, 3, hsv},\
      {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
    {10, 2, hsv}, \
        {20, 2, hsv}, \
        {30, 2, hsv}, \
      {35+ 10, 2, hsv}, \
      {35+ 20, 2, hsv}, \
      {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)  \
    {33, 4, hsv}, \
      {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
    {7, 4, hsv}, \
      {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv)  \
    {25, 2, hsv}, \
      {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv)   \
    {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
        {1, 6, hsv}, \
    {35+1, 6, hsv}, \
        {7, 4, hsv}, \
      {35+ 7, 4, hsv}, \
        {25, 2, hsv}, \
      {35+ 25, 2, hsv}


enum sofle_layers {
    _BASE = 0,
    _QWERTY,
    _RAISE,
    _NUMPAD,
    _ADJUST
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    RGBRST
    //KC_COLEMAK,
    //KC_COLEMAKDH,
    //KC_LOWER,
    //KC_RAISE,
    //KC_ADJUST,
    //KC_D_MUTE
};

#define LCT_tESC CTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| MUTE  |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE |RAISE | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
    [_BASE] = LAYOUT(
      //,------------------------------------------------.                    ,---------------------------------------------------.
     TO(_QWERTY), KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
      //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
      KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
      //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
      LCT_tESC, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, CTL_T(KC_QUOT),
      //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
LSFT_T(KC_EQL), KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,  KC_MUTE,KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_PERC),
      //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
MO(_RAISE), MO(_NUMPAD), ALT_T(KC_TILD), KC_SPC,  TO(_RAISE),          TO(_NUMPAD), KC_ENT,  GUI_T(KC_BSLS), MO(_NUMPAD), MO(_RAISE)
      //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    ),

    [_QWERTY] = LAYOUT(
      //,------------------------------------------------.                    ,---------------------------------------------------.
      TO(_BASE), KC_1,KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
      //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
      KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
      //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
      KC_LCTL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
      KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,  KC_MUTE,KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
      //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_ENT,          KC_ESC, KC_ENT,  KC_RALT, KC_RGUI, KC_RCTL
      //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    ),

    [_RAISE] = LAYOUT(
      //,------------------------------------------------.                    ,---------------------------------------------------.
      QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT,
      //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
       KC_TAB,   KC_F1,   KC_F2,   KC_F3,   KC_F4, TO(_ADJUST),               KC_CIRC, KC_PIPE, KC_AMPR, KC_LPRN, KC_RPRN, KC_BSPC,
      //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
     LCT_tESC,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_LGUI,                   KC_EQL,  KC_PLUS, KC_ASTR, KC_LBRC, KC_RBRC, CTL_T(KC_QUOT),
      //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
LSFT_T(KC_AT),   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_CAPS, KC_TRNS, KC_TRNS, KC_EXLM, KC_MINS, KC_SLSH, KC_ESC,  KC_DEL,  RSFT_T(KC_TILD),
      //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
KC_TRNS, KC_TRNS, ALT_T(KC_TILD), LT(_NUMPAD,KC_SPC), TO(_NUMPAD),      TO(_BASE), LT(_BASE,KC_ENT), GUI_T(KC_BSLS), KC_TRNS, KC_TRNS
      //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    ),

    [_NUMPAD] = LAYOUT(
      //,------------------------------------------------.                    ,---------------------------------------------------.
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
         KC_0,    KC_LPRN,  KC_1,  KC_2,  KC_3,    KC_RPRN,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_DEL, KC_BSPC,
      //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
     LCT_tESC,    KC_LBRC,  KC_4,  KC_5,  KC_6,    KC_RBRC,                      KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TILD, CTL_T(KC_PSCR),
      //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  LSFT_T(KC_EQL), KC_LCBR,  KC_7,  KC_8,  KC_9,    KC_RCBR, KC_TRNS, KC_TRNS,    KC_UNDS, KC_MINS, KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_BSLS),
      //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                  KC_TRNS, KC_TRNS, ALT_T(KC_X), KC_SPC, TO(_BASE),     TO(_RAISE), KC_ENT, GUI_T(KC_BSLS), KC_TRNS, KC_TRNS
      //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
    ),

  [_ADJUST] = LAYOUT(
      //,------------------------------------------------.                    ,---------------------------------------------------.
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
        RGBRST,  QK_BOOT, KC_F15, KC_WH_L, KC_WH_R, KC_LCTL,                      KC_RCTL, KC_MS_BTN1, KC_MS_U, KC_MS_BTN2, KC_F14, KC_MS_BTN3,
      //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_WH_U, KC_MS_BTN5,                  KC_VOLU, KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLD, KC_MUTE,
      //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_WH_D, KC_MS_BTN4,  KC_TRNS, KC_TRNS, KC_F15, KC_MPRV, KC_MPLY, KC_MNXT, KC_ACL0, KC_ACL1,
      //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                  KC_TRNS, KC_TRNS, KC_LALT, KC_ACL1, TO(_BASE),  TO(_NUMPAD), KC_ENT, KC_ACL0, KC_ACL1, KC_ACL2
      //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
  )
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_RED)

);
const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_PINK)
);

// _NUM,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_num_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_BLUE)

    );
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_PURPLE)
);

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_INDICATORS(HSV_ORANGE),
    SET_UNDERGLOW(HSV_ORANGE),
    SET_NUMPAD(HSV_BLUE),
    {7, 4, HSV_ORANGE},
    {25, 2, HSV_ORANGE},
    {35+6, 4, HSV_ORANGE},
    {35+25, 2, HSV_ORANGE}
);
// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_GREEN),
    SET_NUMROW(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

    layer_qwerty_lights,
    layer_num_lights,// overrides layer 1
    layer_symbol_lights,
    layer_command_lights,
    layer_numpad_lights,
    layer_switcher_lights,  // Overrides other layers
    layer_colemakdh_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERTY));
    rgblight_set_layer_state(7, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_COLEMAKDH));


    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(5, layer_state_cmp(state, _SWITCH));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
//    static const char PROGMEM qmk_logo[] = {
//        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
//        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
//        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
//    };
    static const char PROGMEM my_logo[] = {
        // 'A6B962B1-084E-48F3-85E5-3969A76A54CA', 128x32px
        // Yae + Black and White Mages
        0x00, 0xfc, 0xfb, 0xff, 0xfe, 0xfc, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xe0, 0xe0, 0xc0, 0xc0, 0xc0,
        0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xd0, 0xf0, 0xe0, 0xe0, 0xc0, 0x80, 0x80, 0xb0, 0xf0, 0xe0,
        0xe0, 0xe0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf0, 0xf8,
        0xfe, 0xfe, 0xfe, 0x1f, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x60, 0x70, 0x70, 0x70,
        0x78, 0x78, 0x78, 0x7e, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xef, 0xef, 0x9f, 0x7e, 0x00, 0x00,
        0x00, 0x01, 0x03, 0x9f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xfc, 0xfc, 0xfc, 0xfc, 0xf0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xf8,
        0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf3, 0xff, 0xdb, 0x5b, 0xe7, 0xf7, 0xef, 0xef,
        0xdf, 0xff, 0xbf, 0x9f, 0x9f, 0x9f, 0xbf, 0xff, 0xff, 0xff, 0xff, 0x7e, 0x3c, 0x78, 0xe0, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x01, 0x01, 0x81, 0x01, 0x01, 0x77, 0x07, 0x07, 0x07, 0xef, 0xef, 0x0f, 0x0f, 0x0f, 0x1f,
        0x1f, 0x1f, 0xf9, 0x70, 0x60, 0xe0, 0x00, 0x00, 0x00, 0x07, 0x08, 0x08, 0x10, 0x00, 0x00, 0xf6,
        0x80, 0x80, 0xf0, 0xf8, 0xf0, 0xf0, 0x01, 0xe7, 0xe7, 0xff, 0x7f, 0x7f, 0x0f, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xfe, 0xfc, 0xff, 0xff, 0xfe, 0xfc, 0xf9,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xee, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7b, 0xff, 0xff,
        0xdf, 0xef, 0xff, 0x6f, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xde, 0xff, 0xff, 0xff, 0x6f, 0x03, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x70, 0x77, 0x77, 0x8e, 0xfe, 0xfe, 0xf8, 0x98, 0x98, 0x88, 0x0e, 0x0e, 0xf6, 0xf6, 0xf6, 0xf6,
        0xfe, 0xfe, 0xfe, 0xf7, 0xf7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x66, 0x77, 0x07, 0x07, 0x01,
        0xc9, 0xc9, 0xe9, 0xf8, 0xf8, 0xf8, 0xf9, 0xf9, 0xf9, 0xf7, 0x89, 0x89, 0xfe, 0xf8, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x07, 0x07,
        0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x07, 0x0f, 0x1f, 0x1f, 0x1f, 0x3f, 0x3f, 0x7f, 0x7f,
        0xff, 0xfe, 0xfd, 0xf3, 0x63, 0x07, 0x0f, 0x0f, 0x6f, 0x6f, 0x77, 0x77, 0x7f, 0x7f, 0x7d, 0x7f,
        0x3f, 0x3f, 0x1f, 0x1f, 0x0f, 0x06, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x80, 0xff, 0xff, 0xf8, 0xf7, 0xf7, 0xef, 0x99, 0x99, 0x99, 0xf8, 0xf8, 0xe7, 0x9f, 0x9f, 0x7f,
        0x7f, 0x7f, 0x9f, 0xe1, 0xe1, 0x80, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x17, 0x00, 0x00, 0x78,
        0x10, 0x10, 0x60, 0x0e, 0x0f, 0x0f, 0x07, 0x7f, 0x7f, 0x1f, 0x0f, 0x7f, 0x7f, 0x1f, 0x00, 0x00
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

static void oled_print_status(void) {
    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base  "), false);
            break;
        case _QWERTY:
            oled_write_P(PSTR("Qwerty"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise "), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Numpad"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust"), false);
            break;

        default:
            oled_write_P(PSTR("Dafuq "), false);
    }

    oled_write_P(PSTR(" - Rafe's Sofle"), false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_0;
    }
    return rotation;
}

void oled_render_capslock(void) {
    // capslock From ajarov
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.caps_lock ? PSTR("CAPS LOCK, BISH") : PSTR("               "), false);
}

char keylog_str[24];
char     my_key_name = ' ';
uint8_t  my_last_row;
uint8_t  my_last_col;
uint16_t my_last_keycode;

void oled_render_keylog(void) {
    // Update keylog
    snprintf(
        keylog_str, sizeof(keylog_str), "%dx%d k%2d: %c\n",
        my_last_row, my_last_col, my_last_keycode, my_key_name
    );
    oled_write_ln(keylog_str, false);
}


bool oled_task_user(void) {
    if (is_keyboard_master()) {
        if (is_keyboard_left()) {
            oled_render_capslock();
            oled_render_keylog();
            oled_print_status();
        } else {
            oled_print_status();
            oled_render_keylog();
            oled_render_capslock();
        }
    } else {
        render_logo();
    }
    return false;
}

#endif

char keylog_str[24];
static const char PROGMEM code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    my_last_row = record->event.key.row;
    my_last_col = record->event.key.col;
    my_last_keycode = keycode & 0xff;

    if (keycode < 60)
        my_key_name = pgm_read_byte(&code_to_name[keycode]);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _COLEMAK:
            case _QWERTY:
            case _COLEMAKDH:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
            break;
        case _RAISE:
        case _LOWER:
                if (clockwise) {
                    tap_code(KC_DOWN);
                } else {
                    tap_code(KC_UP);
                }
            break;
        default:
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
            break;
        }
    }
    return true;
}

#endif
