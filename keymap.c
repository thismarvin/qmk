#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _WORKMAN 0
#define _QWERTY 1
#define _GAMING 2
#define _NUMPAD 3
#define _LOWER 4
#define _RAISE 5
#define _EXTEND 6
#define _ADJUST 16

// TODO
// - Emoji Macro Layer!

enum custom_keycodes {
  WORKMAN = SAFE_RANGE,
  QWERTY,
  GAMING,
  NUMPAD,
  LOWER,
  RAISE,
  EXTEND,
  ADJUST,

  M_DESKL,
  M_DESKR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* WORKMAN
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  |   ;  |Delete|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Extend|   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   M  |   C  |   V  |   K  |   L  |   ,  |   .  |   /  |RS/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |      |Lower |Space | Bksp |Raise |      | Alt  |  GUI | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_WORKMAN] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_DEL, \
  EXTEND,  KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT, \
  KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, LOWER,   KC_SPC,  KC_BSPC, RAISE,   XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL \
),

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RS/Ent|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |      |Lower |Space | Bksp |Raise |      | Alt  |  GUI | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL, \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SFTENT , \
  KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, LOWER,   KC_SPC,  KC_BSPC, RAISE,   XXXXXXX, KC_RALT, KC_RGUI, KC_RCTL \
),

/* GAMING
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Entr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  Up  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |      |Lower |Space | Bksp |Raise |   /  | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_GAMING] = LAYOUT( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_QUOT, \
  XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT, \
  KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX, LOWER,   KC_SPC,  KC_BSPC, RAISE,   KC_SLSH, KC_LEFT, KC_DOWN, KC_RGHT \
),

/* NUMPAD
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |   $  |      |   /  |   *  |   -  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   %  |   7  |   8  |   9  |   +  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   ^  |   4  |   5  |   6  |   +  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   =  |   1  |   2  |   3  |Enter | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Adjust|      | Space|   0  |   0  |   .  |Enter | Bksp |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] =  LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DLR,  XXXXXXX, KC_SLSH, KC_ASTR, KC_MINS,  KC_BSPC, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PERC, KC_7,    KC_8,    KC_9,    KC_PLUS, KC_BSPC, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CIRC, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_BSPC, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_EQL,  KC_1,    KC_2,    KC_3,    KC_ENT,  KC_BSPC, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ADJUST,  XXXXXXX, KC_SPC,  KC_0,    KC_0,    KC_DOT,  KC_ENT,  KC_BSPC \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Home |   (  |   )  | End  |      |   {  |   }  |   _  |   =  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   [  |   ]  |   -  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | DESKL|      | DESKR|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, _______, KC_HOME, KC_LPRN, KC_RPRN, KC_END,  _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_EQL,  KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_MINS, KC_PLUS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, M_DESKL, _______, M_DESKR \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Home |   (  |   )  | End  |      |   {  |   }  |   _  |   =  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   [  |   ]  |   -  |   +  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______, _______, KC_HOME, KC_LPRN, KC_RPRN, KC_END,  _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_EQL,  KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_MINS, KC_PLUS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Extend
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  F5  |      |      |PgDwn | PgUp |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Enter |      | Left | Down |  Up  |Right |      | Esc  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |C-Bksp|      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_EXTEND] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_F5,   _______, _______,    KC_PGDN, KC_PGUP, _______, _______, _______, \
  _______, _______, _______, _______, KC_ENT,  _______, KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT, _______, KC_ESC, \
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,\
  _______, _______, _______, _______, _______, _______, C(KC_BSPC), _______, _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Caps | WORK |QWERTY| GAME |NUMPAD|      |      |      |      |      |      | Reset|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Sleep|      | Wake |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_CAPS, WORKMAN, QWERTY,  GAMING,  NUMPAD,  _______, _______, _______, _______, _______, _______, RESET, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_SLEP, _______, KC_WAKE, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
)

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WORKMAN:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_WORKMAN);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_GAMING);
      }
      return false;
      break;
    case NUMPAD:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_NUMPAD);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case EXTEND:
      if (record->event.pressed) {
        layer_on(_EXTEND);
      } else {
        layer_off(_EXTEND);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;

    case M_DESKL:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LCTL) SS_TAP(X_LEFT) SS_UP(X_LCTL) SS_UP(X_LGUI));
      }
      break;
    case M_DESKR:
      if (record->event.pressed) {
          SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LCTL) SS_TAP(X_RIGHT) SS_UP(X_LCTL) SS_UP(X_LGUI));
      }
      break;
  }
  return true;
}

/* Template
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
/* [_Template] =  LAYOUT( \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \ */
/* ) */
