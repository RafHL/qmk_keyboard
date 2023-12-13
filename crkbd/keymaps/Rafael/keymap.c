#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum corne_layers {
    _BASE = 0,
    _RAISE,
    _QWERTY,
    _NUMPAD,
    _ADJUST
};

enum custom_keycodes {
  BASE = SAFE_RANGE,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define LCT_tESC CTL_T(KC_ESC)
#define layout_base \
LAYOUT( \
  /*,-----------------------------------------------------.                    ,-----------------------------------------------------. */ \
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, \
  /*|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */ \
     LCT_tESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, CTL_T(KC_QUOT),\
  /*|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------| */ \
LSFT_T(KC_EQL),   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, RSFT_T(KC_PERC),\
  /*|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------| */ \
                               ALT_T(KC_TILD), KC_SPC, TO(_RAISE),       TO(_NUMPAD), KC_ENT, GUI_T(KC_BSLS) \
                                      /*`--------------------------'  `--------------------------' */ \
  )

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = layout_base,

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,   KC_F1,   KC_F2,   KC_F3,   KC_F4, TO(_ADJUST),          KC_CIRC, KC_PIPE, KC_AMPR, KC_LPRN, KC_RPRN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LCT_tESC,   KC_F5,   KC_F6,   KC_F7,   KC_F8, KC_LGUI,                      KC_EQL,  KC_PLUS, KC_ASTR, KC_LBRC, KC_RBRC, CTL_T(KC_QUOT),\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
LSFT_T(KC_AT),   KC_F9,  KC_F10,  KC_F11,  KC_F12, KC_CAPS,                      KC_EXLM, KC_MINS, KC_SLSH, KC_ESC,  KC_DEL,  RSFT_T(KC_TILD),\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                  ALT_T(KC_TILD), LT(_NUMPAD,KC_SPC), TO(_NUMPAD),      TO(_QWERTY), LT(_QWERTY,KC_ENT), GUI_T(KC_BSLS) \
                                      //`--------------------------'  `--------------------------'
  ),

  [_QWERTY] = layout_base,

  [_NUMPAD] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_0,    KC_LPRN,  KC_1,  KC_2,  KC_3,    KC_RPRN,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  KC_DEL, KC_BSPC,\
  //|--------+-----------+----+--------+--------+---------|                    |--------+--------+--------+--------+--------+--------|
     LCT_tESC,    KC_LBRC,  KC_4,  KC_5,  KC_6,    KC_RBRC,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_TILD, CTL_T(KC_PSCR),\
  //|--------+-----------+----+--------+--------+---------|                    |--------+--------+--------+--------+--------+--------|
  LSFT_T(KC_EQL), KC_LCBR,  KC_7,  KC_8,  KC_9,    KC_RCBR,                      KC_UNDS, KC_MINS, KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_BSLS),\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              ALT_T(KC_X), KC_SPC, TO(_QWERTY),     TO(_RAISE), KC_ENT, GUI_T(KC_BSLS) \
                                      //`--------------------------'  `--------------------------'
    ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RGBRST, QK_BOOT, KC_F15, KC_WH_L, KC_WH_R, KC_LCTL,                      KC_RCTL, KC_MS_BTN1, KC_MS_U, KC_MS_BTN2, KC_F14, KC_MS_BTN3,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_WH_U, KC_MS_BTN5,                  KC_VOLU, KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLD, KC_MUTE,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, KC_WH_D, KC_MS_BTN4,                  KC_F15, KC_MPRV, KC_MPLY, KC_MNXT, KC_ACL0, KC_ACL1,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                      KC_LALT, KC_ACL1, TO(_QWERTY),  TO(_NUMPAD), KC_ENT, KC_ACL2\
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void matrix_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_get_mode();
#endif
}

//OLED_ENABLE OLED update loop, make sure to add #define OLED_ENABLE in config.h
#ifdef OLED_ENABLE

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

    oled_write_P(PSTR(" - Rafe's Corne"), false);
}


void oled_render_logo(void) {
//    static const char PROGMEM crkbd_logo[] = {
//        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
//        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
//        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
//        0};
//    oled_write_P(crkbd_logo, false);
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

// Modified from xyverz
char keylog_str[24];
static const char PROGMEM code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};
char     my_key_name = ' ';
uint8_t  my_last_row;
uint8_t  my_last_col;
uint16_t my_last_keycode;

void set_keylog(uint16_t keycode, keyrecord_t *record) {
    my_last_row = record->event.key.row;
    my_last_col = record->event.key.col;
    my_last_keycode = keycode & 0xff;

    if (keycode < 60)
        my_key_name = pgm_read_byte(&code_to_name[keycode]);
}

void oled_render_keylog(void) {
    // Update keylog
    snprintf(
        keylog_str, sizeof(keylog_str), "%dx%d k%2d: %c\n",
        my_last_row, my_last_col, my_last_keycode, my_key_name
    );
    oled_write_ln(keylog_str, false);
}

void oled_render_capslock(void) {
    // capslock From ajarov
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.caps_lock ? PSTR("CAPS LOCK, BISH") : PSTR("               "), false);
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
        oled_render_logo();
    }
    return false;
}

#endif//OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
  }

  switch (keycode) {
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          //RGB_current_mode = rgblight_config.mode;
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          //RGB_current_mode = rgblight_config.mode;
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      break;
  }
  return true;
}
