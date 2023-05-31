/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2022 Gilgamesh @gilgamesh_one@mastodon.world

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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_japanese.h"
#include "sendstring_japanese.h"
#include "features/flow.h"
#include "features/select_word.h"
#include "features/layer_lock.h"

enum crkbd_layers {
    _DVARF,
    _DVORAK,
    _QWERTY,
    _NUM,
    _NAV,
    _SYM,
    _EXT,
    _MSE,
    _FUN1,
    _FUN2,
};

#define NUM MO(_NUM)
#define NAV MO(_NAV)
#define SYM MO(_SYM)
#define EXT MO(_EXT)
#define MSE MO(_MSE)
#define FUN1 MO(_FUN1)
#define FUN2 MO(_FUN2)

// super cmd tab
bool is_cmd_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t cmd_tab_timer = 0;     // we will be using them soon.


enum custom_keycodes {
    GOOGL = SAFE_RANGE,
    GTRNS,
    DFINE,
    OS_FUN2,
    SELWORD,
    LLOCK,
    CMD_TAB,
};

// flow STUFF
// flow_config should correspond to following format:
// * layer keycode
// * modifier keycode
const uint16_t flow_config[FLOW_COUNT][2] = {
    {NUM, KC_LSFT},
    {NUM, KC_LOPT},
    {NUM, KC_LCMD},
    {NUM, KC_LCTL},
    {NAV, KC_RSFT},
    {NAV, KC_ROPT},
    {NAV, KC_RCMD},
    {NAV, KC_RCTL},
};

const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {OS_FUN2, _FUN2},
};

// macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    {
    // flow
        if (!update_flow(keycode, record->event.pressed, record->event.key))
            return false;
    }
    // select word
    {
      if (!process_select_word(keycode, record, SELWORD)) { return false;}
    }
    // layer lock
    {
      if (!process_layer_lock(keycode, record, LLOCK)) { return false; }
    }
    // super cmd tab
    {
      switch (keycode) { // This will do most of the grunt work with the keycodes.
      case CMD_TAB:
        if (record->event.pressed) {
          if (!is_cmd_tab_active) {
            is_cmd_tab_active = true;
            register_code(KC_LCMD);
          }
          cmd_tab_timer = timer_read();
          register_code(KC_TAB);
        } else {
          unregister_code(KC_TAB);
        }
        break;
      }
    }
    // macro
    switch (keycode) {
    case GOOGL:
      if (record->event.pressed) {
        // when keycode GOOGL is pressed
        SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_C)
                    SS_UP(X_LCMD));  // command C
        SEND_STRING(SS_DOWN(X_LCMD) SS_DOWN(X_LCTL) SS_DOWN(X_LSFT)
                    SS_DOWN(X_LOPT) SS_TAP(X_SPC) SS_UP(X_LOPT)
                    SS_UP(X_LSFT) SS_UP(X_LCTL)
                    SS_UP(X_LCMD));  // open alfred
        wait_ms(50);
        SEND_STRING(SS_TAP(X_G) SS_TAP(X_SPC));  // tap G
        SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_V) SS_UP(X_LCMD)
                    SS_TAP(X_ENT));  // command V + enter
      } else {
        // when keycode GOOGL is released
      }
      break;
    case GTRNS:
      if (record->event.pressed) {
        // when keycode GTRNS is pressed
        SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_C)
                    SS_UP(X_LCMD));  // command C
        SEND_STRING(SS_DOWN(X_LCMD) SS_DOWN(X_LCTL) SS_DOWN(X_LSFT)
                    SS_DOWN(X_LOPT) SS_TAP(X_SPC) SS_UP(X_LOPT)
                    SS_UP(X_LSFT) SS_UP(X_LCTL)
                    SS_UP(X_LCMD));  // open alfred
        wait_ms(50);
        SEND_STRING(SS_TAP(X_T) SS_TAP(X_SPC));  // tap T
        SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_V) SS_UP(X_LCMD)
                    SS_TAP(X_ENT));  // command V + enter
      } else {
        // when keycode GTRNS is released
      }
      break;
    case DFINE:
      if (record->event.pressed) {
        // when keycode DFINE is pressed
        SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_C)
                    SS_UP(X_LCMD));  // command C
        SEND_STRING(SS_DOWN(X_LCMD) SS_DOWN(X_LCTL) SS_DOWN(X_LSFT)
                    SS_DOWN(X_LOPT) SS_TAP(X_SPC) SS_UP(X_LOPT)
                    SS_UP(X_LSFT) SS_UP(X_LCTL)
                    SS_UP(X_LCMD));  // open alfred
        wait_ms(200);
        SEND_STRING(SS_TAP(X_D) SS_TAP(X_SPC));  // tap D
        SEND_STRING(SS_DOWN(X_LCMD) SS_TAP(X_V)
                    SS_UP(X_LCMD));  // command V
        wait_ms(200);                     // wait
        SEND_STRING(SS_TAP(X_ENT));      // enter
      } else {
        // when keycode DFINE is released
      }
      break;

    }
    return true;
}


void matrix_scan_user(void) {
  // flow
  flow_matrix_scan();
  // layer lock
  layer_lock_task();
  // super cmd tab - The very important timer.
  if (is_cmd_tab_active) {
    if (timer_elapsed(cmd_tab_timer) > 300) {
      unregister_code(KC_LCMD);
      is_cmd_tab_active = false;
    }
  }
}

// leader
void leader_start_user(void) {
  // Do something when the leader key is pressed
}
void leader_end_user(void) {
  if (leader_sequence_one_key(KC_H)) {
    // Leader, h => emacs C-x
    tap_code16(LCTL(KC_X));
  } else if (leader_sequence_one_key(KC_T)) {
    // Leader, t => emacs C-c
    tap_code16(LCTL(KC_C));
  } else if (leader_sequence_one_key(KC_N)) {
    // Leader, n => emacs M-x
    tap_code16(LALT(KC_X));
  }
}

// combos

const uint16_t PROGMEM combo_capsword[] = {KC_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_qkboot[] = {JP_QUOT, KC_A, JP_COMM, COMBO_END};
const uint16_t PROGMEM combo_qkreboot[] = {KC_P, KC_G, KC_J, COMBO_END};
const uint16_t PROGMEM combo_qkeeprom[] = {KC_W, KC_Y, KC_C, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_capsword, CW_TOGG),
  COMBO(combo_qkboot, QK_BOOT),
  COMBO(combo_qkeeprom, EE_CLR),
  COMBO(combo_qkreboot, QK_RBT),
};

// caps word

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case JP_UNDS:
        case JP_MINS:
        case JP_AMPR:
          return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// key overides
// SHIFT + ' = "
const key_override_t quots_quotd_override = ko_make_basic(MOD_MASK_SHIFT, JP_QUOT, JP_DQUO);

const key_override_t **key_overrides = (const key_override_t *[]){
    &quots_quotd_override,
    NULL
};

// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVARF] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      JP_QUOT,    KC_U,    KC_O,    KC_W,    KC_P,                         KC_Q,    KC_V,    KC_D,    KC_R,    KC_F,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_A,    KC_I,    KC_E,    KC_Y,    KC_G,                         KC_L,    KC_H,    KC_T,    KC_N,    KC_S,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      JP_COMM,  JP_DOT, JP_MINS,    KC_C,    KC_J,                         KC_K,    KC_M,    KC_B,   KC_X,    KC_Z,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_TAB,     NUM,  KC_SPC,OSM(MOD_LSFT),   NAV,  KC_ENT
                             //`--------------------------'  `--------------------------'
  ),
  [_DVORAK] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      JP_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_MINS,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_TAB,   NUM,  KC_SPC,      KC_LSFT,     NAV,  KC_ENT
                             //`--------------------------'  `--------------------------'
  ),
  [_QWERTY] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_TAB,   NUM,  KC_SPC,      KC_LSFT,     NAV,  KC_ENT
                             //`--------------------------'  `--------------------------'
  ),
  [_NUM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
     C(KC_F2),  KC_MEH, KC_HYPR, QK_LEAD, JP_TILD,                      JP_PLUS,    KC_7,    KC_8,    KC_9, JP_ASTR,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL, JP_PERC,                      JP_MINS,    KC_4,    KC_5,    KC_6, JP_SLSH,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_TRNS, KC_TRNS,HYPR(KC_B),KC_MPLY,JP_HASH,                       JP_EQL,    KC_1,    KC_2,    KC_3,    KC_0,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 LLOCK,     NUM, XXXXXXX,    KC_BSPC,     SYM,  KC_DEL
                             //`--------------------------'  `--------------------------'
  ),
  [_NAV] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      G(KC_Z), G(KC_X), G(KC_C), G(KC_V),LSG(KC_Z),                    CMD_TAB,  QK_LEAD, KC_HYPR,  KC_MEH, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, SELWORD,                    LSG(KC_5), KC_RCTL, KC_RCMD, KC_ROPT, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_HOME, KC_PGUP, KC_PGDN,  KC_END,A(KC_RGHT),                   LSG(KC_3),XXXXXXX,S(C(KC_TAB)),C(KC_TAB),XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 KC_ESC,   EXT,   KC_SPC,      XXXXXXX,     NAV, LLOCK
                             //`--------------------------'  `--------------------------'
  ),
  [_SYM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX,  KC_MEH,  KC_HYPR, XXXXXXX, JP_GRV,                       JP_YEN, JP_LBRC, JP_RBRC, JP_COLN, JP_CIRC,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL,  JP_DLR,                      JP_SCLN, JP_LPRN, JP_RPRN, JP_AMPR, JP_QUES,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, OS_FUN2,    FUN1, XXXXXXX, JP_EXLM,                      JP_PIPE, JP_LCBR, JP_RCBR,   JP_AT, JP_UNDS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 LLOCK, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  `--------------------------'
  ),
  [_EXT] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_CAPS, KC_LNG2, KC_LNG1, KC_MPRV, KC_MNXT,                      KC_LPAD, KC_MCTL, KC_HYPR,  KC_MEH, KC_EJCT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_MUTE, KC_VOLU, KC_VOLD, KC_MPLY,HYPR(KC_B),                    KC_PAUS, KC_RCTL, KC_RCMD, KC_ROPT, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_MRWD,   DFINE,   GTRNS,   GOOGL, KC_MFFD,                      KC_SCRL,     EXT,     MSE, XXXXXXX, KC_PENT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, LLOCK
                             //`--------------------------'  `--------------------------'
      // afred macro - hyper-B is back 2 seconds in iina when used in emacs
  ),
  [_MSE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, KC_BTN2, KC_BTN1, KC_BTN3, XXXXXXX,                      KC_PWR, XXXXXXX,  KC_HYPR,  KC_MEH, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, XXXXXXX,                     KC_SLEP,  KC_RCTL, KC_RCMD, KC_ROPT, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX,                     KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  `--------------------------'
  ),
  [_FUN1] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX,  KC_MEH, KC_HYPR, XXXXXXX,DF(_DVARF),                    KC_PSCR,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL,DF(_DVORAK),                    KC_NUM,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,DF(_QWERTY),                   XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  `--------------------------'
  ),
  [_FUN2] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      QK_BOOT,  KC_MEH, KC_HYPR, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL, XXXXXXX,                      XXXXXXX,  KC_F17,  KC_F18,  KC_F19,  KC_F20,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       QK_RBT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_F13,  KC_F14,  KC_F15,  KC_F16,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                             //`--------------------------'  `--------------------------'
  )
};



// OLED STUFF

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define DISPLAY_LAYER_NAME(LAYER_NAME, LAYER_STRING) \
  if(get_highest_layer(layer_state|default_layer_state) == LAYER_NAME) { \
      oled_write_ln_P(PSTR(LAYER_STRING), false); \
      return;\
  }\


void oled_render_layer_state(void) {
  // if caps word is enabled, show
  if(is_caps_word_on()) {
      oled_write_ln_P(PSTR("CAPS WORD"), false);
      return;
  }
  DISPLAY_LAYER_NAME(_FUN2, "FUN 2");
  DISPLAY_LAYER_NAME(_FUN1, "FUN 1");
  DISPLAY_LAYER_NAME(_MSE, "MSE");
  DISPLAY_LAYER_NAME(_EXT, "EXT");
  DISPLAY_LAYER_NAME(_SYM, "SYM");
  DISPLAY_LAYER_NAME(_NAV, "NAV");
  DISPLAY_LAYER_NAME(_NUM, "NUM");
  DISPLAY_LAYER_NAME(_DVARF, "DVARF");
  DISPLAY_LAYER_NAME(_DVORAK, "DVORAK");
  DISPLAY_LAYER_NAME(_QWERTY, "QWERTY");
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void oled_render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("N "), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR("C "), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    oled_write_ln_P(PSTR("S "), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}

void oled_render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("Shift"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Option\n"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("Command"), (modifiers & MOD_MASK_GUI));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Control\n"), (modifiers & MOD_MASK_CTRL));
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_render_status_main(void) {
    /* Show Keyboard Layout  */
    oled_render_layer_state();
    oled_render_mod_status(get_mods());
    oled_render_keylock_status(host_keyboard_leds());
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_status_main();
    } else {
        oled_render_logo();
    }
    return false;
}


#endif // OLED_ENABLE
