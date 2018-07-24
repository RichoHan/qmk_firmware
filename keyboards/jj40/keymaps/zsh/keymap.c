#include QMK_KEYBOARD_H


#define _QWERTY 0
#define KC_DOUBLE_ZERO  1
#define MACRO_GST 2
#define MACRO_GBA 3
#define MACRO_GLGGA 4
#define MACRO_CODE 5
#define MACRO_XDG 6
#define MACRO_COMPOSE_PS 7
#define MACRO_COMPOSE_STOP 8
#define MACRO_COMPOSE_RM 9
#define MACRO_COMPOSE_UP 10

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT_2U_space( \
      KC_F4, KC_F8, KC_F12, MACRO_CODE,  MACRO_COMPOSE_RM,   KC_PGUP,   KC_PGDOWN,  KC_KP_MINUS,    KC_NO,   KC_KP_PLUS, KC_NO,   KC_KP_ENTER, \
      KC_F3, KC_F7, KC_F11, MACRO_GLGGA, MACRO_COMPOSE_UP,   KC_HOME,   KC_END,     KC_KP_ASTERISK, KC_KP_9, KC_KP_6,    KC_KP_3, KC_KP_DOT, \
      KC_F2, KC_F5, KC_F10, MACRO_GBA,   MACRO_COMPOSE_STOP, KC_INSERT, KC_DELETE,  KC_KP_SLASH,    KC_KP_8, KC_KP_5,    KC_KP_2, KC_KP_0 , \
      KC_F1, KC_F5, KC_F9,  MACRO_GST,   MACRO_COMPOSE_PS,   MACRO_XDG,             KC_NUMLOCK,     KC_KP_7, KC_KP_4,    KC_KP_1, KC_DOUBLE_ZERO \
    )
};

// Loop
void matrix_scan_user(void) {
  // Empty
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case KC_DOUBLE_ZERO:
        SEND_STRING("00");
        return false;
      case MACRO_GST:
        SEND_STRING("gst"SS_TAP(X_ENTER));
        return false;
      case MACRO_GBA:
        SEND_STRING("gba"SS_TAP(X_ENTER));
        return false;
      case MACRO_GLGGA:
        SEND_STRING("glgga"SS_TAP(X_ENTER));
        return false;
      case MACRO_CODE:
        SEND_STRING("code ."SS_TAP(X_ENTER));
        return false;
      case MACRO_XDG:
        SEND_STRING("xdg-open ."SS_TAP(X_ENTER));
        return false;
      case MACRO_COMPOSE_PS:
        SEND_STRING("docker-compose ps"SS_TAP(X_ENTER));
        return false;
      case MACRO_COMPOSE_STOP:
        SEND_STRING("docker-compose stop"SS_TAP(X_ENTER));
        return false;
      case MACRO_COMPOSE_UP:
        SEND_STRING("docker-compose up --force-recreate -d"SS_TAP(X_ENTER));
        return false;
      case MACRO_COMPOSE_RM:
        SEND_STRING("docker-compose rm"SS_TAP(X_ENTER));
        return false;
    }
  }
  return true;
};