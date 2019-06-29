/* * * * * * * * * * * * * * * * * * * * * *
 * semoog's keymap for Gray Studio Space65 *
 * * * * * * * * * * * * * * * * * * * * * */

#include QMK_KEYBOARD_H

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *  You can use _______ in place for KC_TRNS (transparent)   *
 *  Or you can use XXXXXXX for KC_NO (NOOP)                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Each layer gets a name for readability.
#define _DEFAULT 0
#define _WINSM 1
#define _WINMOD 2
#define _WINSPACEMOD 3
#define _MAC 4
#define _MACMOD 5
#define _MACSPACEMOD 6

// Shortcuts.
enum keycodes {
  LLALT = LALT(KC_LEFT),
  RLALT = LALT(KC_RIGHT),
  LCTRL = LCTL(KC_LEFT),
  RCTRL = LCTL(KC_RIGHT),
  MACSPACEMOD = LT(_MACSPACEMOD,KC_SPC),
  WINSPACEMOD = LT(_WINSPACEMOD,KC_SPC),
  GRAVE_MODS = (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT)),
  TO_WIN,
  TO_WINSM,
  TO_MAC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_DEFAULT] = LAYOUT( \
          KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,    KC_BSPC,    KC_BSPC,   KC_GRV,  \
          KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,    KC_RBRC,   KC_BSLS,    KC_DEL,             \
          KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,    KC_ENT,                KC_PGUP,            \
          KC_LSFT,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_LSFT,   KC_UP,      KC_PGDN,            \
          KC_LCTL,   KC_LGUI, KC_LALT,          KC_SPC,           KC_SPC,           KC_SPC,           KC_LGUI, MO(_WINMOD),KC_LEFT,   KC_DOWN,    KC_RGHT),

  /* Win */

	[_WINSM] = LAYOUT( \
          _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______,   _______, \
          _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______,            \
          _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,               _______,            \
          _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______,            \
          _______,   _______, _______,          WINSPACEMOD,      WINSPACEMOD,      WINSPACEMOD,      _______, _______,    _______,   _______,    _______),

	[_WINMOD] = LAYOUT( \
          RESET,     TG(_WINSM),TO(_MAC),_______,_______,_______, _______, _______, _______, _______, _______, KC_SLCK,    KC_PAUS,   _______,    _______,   _______, \
          _______,   _______, KC_UP,   _______, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, RGB_HUI,    RGB_HUD,   _______,    RGB_TOG,            \
          _______,   KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, RGB_M_K, _______, RGB_VAI, RGB_VAD,    _______,               RGB_MOD,            \
          _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY,    _______,   KC_VOLU,    RGB_RMOD,           \
          _______,   _______, _______,          _______,          _______,          _______,          _______, _______,    KC_MPRV,   KC_VOLD,    KC_MNXT),

  [_WINSPACEMOD] = LAYOUT( \
          _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______,   _______, \
          _______,   KC_LEFT, KC_UP,   KC_RIGHT,_______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______,            \
          _______,   LCTRL,   KC_DOWN, RCTRL,   _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,    _______,               _______,            \
          _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   KC__VOLUP,  _______,            \
          _______,   _______, _______,          _______,          _______,          _______,          _______, _______,    _______,   KC__VOLDOWN,_______),


  /* Mac */

	[_MAC] = LAYOUT( \
          KC_GRV,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______,   KC__MUTE,\
          _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______,            \
          KC_ESC,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,               _______,            \
          KC_LSPO,   KC_LSPO, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    KC_RSPC,   _______,    _______,            \
          _______,   KC_LALT, KC_LGUI,          MACSPACEMOD,      MACSPACEMOD,      MACSPACEMOD,      KC_RGUI, MO(_MACMOD),_______,   _______,    _______),

	[_MACMOD] = LAYOUT( \
          _______,   _______, TG(_MAC),_______, _______, _______, _______, _______, _______, _______, _______, KC_SLCK,    _______,   _______,    _______,   _______, \
          _______,   _______, KC_UP,   _______, _______, _______, _______, _______, _______, RGB_SPI, RGB_SPD, RGB_HUI,    RGB_HUD,   _______,    RGB_TOG,            \
          _______,   KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, RGB_M_K, _______, RGB_VAI, RGB_VAD,    _______,               RGB_MOD,            \
          _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY,    _______,   KC__VOLUP,  RGB_RMOD,           \
          _______,   _______, _______,          _______,          _______,          _______,          _______, _______,    KC_MRWD,   KC__VOLDOWN,KC_MFFD),

	[_MACSPACEMOD] = LAYOUT( \
          _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______,   _______, \
          _______,   KC_LEFT, KC_UP,   KC_RIGHT,_______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______,            \
          _______,   LLALT,   KC_DOWN, RLALT,   _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, _______,    _______,               _______,            \
          _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   KC__VOLUP,  _______,            \
          _______,   _______, _______,          _______,          _______,          _______,          _______, _______,    _______,   KC__VOLDOWN,_______)
};

/* uint32_t layer_state_set_user(uint32_t state) { */
/*   switch (biton32(state)) { */
/*     case _WINSM: */
/*     case _WINMOD: */
/*     case _WINSPACEMOD: */
/*       rgblight_setrgb (0x00,  0x00, 0xFF); */
/*       break; */
/*     case _MAC: */
/*     case _MACMOD: */
/*     case _MACSPACEMOD: */
/*       rgblight_setrgb (0xFF,  0x00, 0x00); */
/*       break; */
/*     default: //  for any other layers, or the default layer */
/*       break; */
/*   } */
/*   return state; */
/* } */

void matrix_init_user(void) {

}

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*     case TO_WIN: { */
/*       /\* eeconfig_update_default_layer(1UL << _WIN); *\/ */
/*       /\* default_layer_set(1UL << _WIN); *\/ */
/*       return false; */
/*     } */

/*     case TO_MAC: { */
/*       /\* eeconfig_update_default_layer(1UL << _MAC); *\/ */
/*       /\* default_layer_set(1UL << _MAC); *\/ */
/*       return false; */
/*     } */

/*     default: { */
/*       return true; */
/*     } */
/*   } */
/* } */

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
