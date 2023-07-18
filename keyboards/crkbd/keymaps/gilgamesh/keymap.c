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
#include "features/select_word.h"
#include "features/layer_lock.h"
#include "features/achordion.h"

enum crkbd_layers {
    _DVARF_MAC,
    _TRON_MAC_BASE,
    _TRON_MAC_RED,
    _TRON_MAC_BLUE,
    _TRON_MAC_PURPLE,
    _DVARF_WIN,
    _NUM_MAC,
    _NUM_WIN,
    _NAV_MAC,
    _NAV_WIN,
    _SYM_MAC,
    _SYM_WIN,
    _EXT_MAC,
    _EXT_WIN,
    _MSE_MAC,
    _MSE_WIN,
    _FUN1_MAC,
    _FUN1_WIN,
    _FUN2_MAC,
    _FUN2_WIN,
};

#define NUM LT(_NUM_MAC,KC_DEL)
#define NAV LT(_NAV_MAC,KC_BSPC)
#define SYM LT(_SYM_MAC,KC_TAB)
#define EXT LT(_EXT_MAC,KC_ENT)
#define MSE MO(_MSE_MAC)
#define FUN1 MO(_FUN1_MAC)
#define FUN2 MO(_FUN2_MAC)

#define TRON_NUM LT(_NUM_MAC,KC_DEL)
#define TRON_NAV LT(_NAV_MAC,KC_BSPC)
#define TRON_SYM LT(_SYM_MAC,KC_TAB)
#define TRON_EXT LT(_EXT_MAC,KC_ENT)

// Left-hand home row mods
#define HCTL_Y LCTL_T(KC_Y)
#define HCMD_E LGUI_T(KC_E)
#define HOPT_I LALT_T(KC_I)
#define HSFT_A LSFT_T(KC_A)
#define HHYP_O KC_O
#define HMEH_U KC_U
#define HHYP_MINS HYPR_T(JP_MINS)
#define HMEH_DOT MEH_T(JP_DOT)
#define HSYM_C LT(_SYM_MAC,KC_C)


// Right-hand home row mods
#define HCTL_H RCTL_T(KC_H)
#define HCMD_T RGUI_T(KC_T)
#define HOPT_N RALT_T(KC_N)
#define HSFT_S RSFT_T(KC_S)
#define HHYP_D KC_D
#define HMEH_R KC_R
#define HHYP_B HYPR_T(KC_B)
#define HMEH_X MEH_T(KC_X)
#define HEXT_M LT(_EXT_MAC,KC_M)

//tron japanese laid over JIS kana

#define TJ_RA JP_O
#define TJ_RU JP_DOT
#define TJ_KO JP_B
#define TJ_HA JP_F
#define TJ_XYO S(JP_9)
#define TJ_KI JP_G
#define TJ_NO JP_K
#define TJ_KU JP_H
#define TJ_A JP_3
#define TJ_RE JP_SCLN
#define TJ_TA JP_Q
#define TJ_TO JP_S
#define TJ_KA JP_T
#define TJ_TE JP_W
#define TJ_MO JP_M
#define TJ_WO S(JP_0)
#define TJ_I JP_E
#define TJ_U JP_4
#define TJ_SHI JP_D
#define TJ_NN JP_Y
#define TJ_MA JP_J
#define TJ_RI JP_L
#define TJ_NI JP_I
#define TJ_SA JP_X
#define TJ_NA JP_U
#define TJ_SU JP_R
#define TJ_TSU JP_Z
#define TJ_DOUTEN S(JP_COMM)
#define TJ_KUTEN S(JP_DOT)
#define TJ_XTSU S(JP_Z)
#define TJ_HI JP_V
#define TJ_SO JP_C
#define TJ_NAKAGURO S(JP_SLSH)
#define TJ_XYA S(JP_7)
#define TJ_HO JP_MINS
#define TJ_E JP_5
#define TJ_KE JP_COLN
#define TJ_ME JP_SLSH
#define TJ_MU JP_RBRC
#define TJ_RO JP_UNDS
#define TJ_NU JP_1
#define TJ_NE JP_COMM
#define TJ_XYU S(JP_8)
#define TJ_YO JP_9
#define TJ_FU JP_2
#define TJ_O JP_6
#define TJ_CHI JP_A
#define TJ_CHOUONNPU JP_YEN
#define TJ_MI JP_N
#define TJ_YA JP_7
#define TJ_XE S(JP_5)
#define TJ_XO S(JP_6)
#define TJ_SE JP_P
#define TJ_YU JP_8
#define TJ_HE JP_CIRC
#define TJ_WA JP_0
#define TJ_XI S(JP_E)
#define TJ_XA S(JP_3)
#define TJ_XU S(JP_4)


// super cmd tab
bool is_cmd_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t cmd_tab_timer = 0;     // we will be using them soon.


// super alt tab
bool is_alt_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t alt_tab_timer = 0;     // we will be using them soon.


enum custom_keycodes {
    GOOGL = SAFE_RANGE,
    GTRNS,
    DFINE,
    SELWORD,
    LLOCK,
    CMD_TAB,
    ALT_TAB,
    M_TRON,
    NOTTRONWIN,
    M_DVARF_MAC,
    M_NUM,
    M_SYM,
    M_NAV,
    M_EXT,
    TJ_GI,
    TJ_GE,
    TJ_GU,
    TJ_DI,
    TJ_DZI,
    TJ_VU,
    TJ_JI,
    TJ_ZU,
    TJ_DZU,
    TJ_BI,
    TJ_ZO,
    TJ_GO,
    TJ_BA,
    TJ_BO,
    TJ_DA,
    TJ_DO,
    TJ_GA,
    TJ_DE,
    TJ_BU,
    TJ_ZE,
    TJ_ZA,
    TJ_BE,
    TJ_PA,
    TJ_PI,
    TJ_PU,
    TJ_PE,
    TJ_PO,
    TJ_LKAGIKAKO,
    TJ_RKAGIKAKO,
    _KANA,
    _EISU,
};

// macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  {
    // achordion
    if (!process_achordion(keycode, record)) { return false; }
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
    // super alt tab
  case ALT_TAB:
    if (record->event.pressed) {
      if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
      }
      cmd_tab_timer = timer_read();
      register_code(KC_TAB);
    } else {
      unregister_code(KC_TAB);
    }
    break;
    // lang switching
  case _EISU:
    if (record->event.pressed) {
      tap_code(KC_LNG2);
    }
    else {
       layer_move(_DVARF_MAC);
    }
    break;
  case _KANA:
    if (record->event.pressed) {
       tap_code(KC_LNG1);
    }
    else {
       layer_move(_TRON_MAC_BASE);
    }
    break;
    // TJ_GI,
  case TJ_GI:
    if (record->event.pressed) {
      // when keycode TJ_GI is pressed
      SEND_STRING(SS_TAP(X_G));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_GE,
  case TJ_GE:
    if (record->event.pressed) {
      tap_code(KC_QUOT);
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_GU,
  case TJ_GU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_H));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_DZI,
  case TJ_DZI:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_A));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_VU,
  case TJ_VU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_4));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_JI,
  case TJ_JI:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_D));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_ZU,
  case TJ_ZU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_R));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_DZU,
  case TJ_DZU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Z));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_BI,
  case TJ_BI:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_V));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_ZO,
  case TJ_ZO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_C));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_GO,
  case TJ_GO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_B));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_BA,
  case TJ_BA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_BO,
  case TJ_BO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINS));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_DA,
  case TJ_DA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Q));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_DO,
  case TJ_DO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_S));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_GA,
  case TJ_GA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_T));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_DE,
  case TJ_DE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_W));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_BU,
  case TJ_BU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_2));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_ZE,
  case TJ_ZE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_P));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;
    // TJ_ZA,
  case TJ_ZA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_X));
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;

    // TJ_BE,
  case TJ_BE:
    if (record->event.pressed) {
      tap_code(KC_EQL);
      tap_code(KC_LBRC);
    } else {
      //
    }
    break;

    // TJ_PA,
  case TJ_PA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F));
      tap_code(KC_RBRC);
    } else {
      //
    }
    break;
    // TJ_PI,
  case TJ_PI:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_V));
      tap_code(KC_RBRC);
    } else {
      //
    }
    break;
    // TJ_PU,
  case TJ_PU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_2));
      tap_code(KC_RBRC);
    } else {
      //
    }
    break;
    // TJ_PE,
  case TJ_PE:
    if (record->event.pressed) {
      tap_code(KC_EQL);
      tap_code(KC_RBRC);
    } else {
      //
    }
    break;
    // TJ_PO,
  case TJ_PO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINS));
      tap_code(KC_RBRC);
    } else {
      //
    }
    break;
    // TJ_LKAGIKAKO,
  case TJ_LKAGIKAKO:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_RBRC) SS_UP(X_LSFT));
    } else {
      //
    }
    break;
    // TJ_RKAGIKAKO,
  case  TJ_RKAGIKAKO:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_NUHS) SS_UP(X_LSFT));
    } else {
      //
    }
    break;
    // other macros
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
};


void matrix_scan_user(void) {
  // achordion
  achordion_task();
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



// combos

const uint16_t PROGMEM combo_capsword[] = {HCTL_Y, HCTL_H, COMBO_END};
const uint16_t PROGMEM combo_qkboot[] = {JP_QUOT, HSFT_A, JP_COMM, COMBO_END};
const uint16_t PROGMEM combo_qkreboot[] = {KC_P, KC_G, KC_J, COMBO_END};
const uint16_t PROGMEM combo_qkeeprom[] = {KC_W, HCTL_Y, KC_C, COMBO_END};
const uint16_t PROGMEM combo_mac[] = {HHYP_MINS, HCMD_E, HHYP_O, COMBO_END};
const uint16_t PROGMEM combo_win[] = {HMEH_DOT, HOPT_I, HMEH_U, COMBO_END};
const uint16_t PROGMEM combo_ret[] = {HOPT_I, HOPT_N, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {HHYP_O, HHYP_D, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {JP_QUOT, KC_F, COMBO_END};
const uint16_t PROGMEM combo_pause[] = {HMEH_U, HMEH_R, COMBO_END};
const uint16_t PROGMEM combo_lang1[] = {KC_F, HSFT_S, COMBO_END};
const uint16_t PROGMEM combo_dvarf[] = {JP_MINS, JP_DOT, COMBO_END};
const uint16_t PROGMEM combo_lang2[] = {JP_QUOT, HSFT_A, COMBO_END};
const uint16_t PROGMEM combo_tron[] = {HHYP_B, HMEH_X, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_capsword, CW_TOGG),
  COMBO(combo_qkboot, QK_BOOT),
  COMBO(combo_qkeeprom, EE_CLR),
  COMBO(combo_qkreboot, QK_RBT),
  COMBO(combo_ret, KC_ENT),
  COMBO(combo_tab, KC_TAB),
  COMBO(combo_esc, KC_ESC),
  COMBO(combo_mac, DF(_DVARF_MAC)),
  COMBO(combo_win, DF(_DVARF_WIN)),
  COMBO(combo_pause, KC_MPLY),
  COMBO(combo_lang1, KC_LNG1),
  COMBO(combo_dvarf, TO(_DVARF_MAC)),
  COMBO(combo_lang2, KC_LNG2),
  COMBO(combo_tron, TO(_TRON_MAC_BASE)),
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
const key_override_t ctl_del_bksp_override = ko_make_basic(MOD_MASK_CTRL, KC_BSPC, KC_DEL);
const key_override_t ctl_quo_scln_override = ko_make_basic(MOD_MASK_CTRL, JP_QUOT, C(JP_SCLN));
const key_override_t one_numpad_override = ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_P1);
const key_override_t two_numpad_override = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_P2);
const key_override_t three_numpad_override = ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_P3);
const key_override_t four_numpad_override = ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_P4);
const key_override_t five_numpad_override = ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_P5);
const key_override_t six_numpad_override = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_P6);
const key_override_t seven_numpad_override = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_P7);
const key_override_t eight_numpad_override = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_P8);
const key_override_t nine_numpad_override = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_P9);
const key_override_t zero_numpad_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_P0);
const key_override_t comm_semi_override = ko_make_basic(MOD_MASK_SHIFT, JP_COMM, JP_SCLN);
const key_override_t dot_coln_override = ko_make_basic(MOD_MASK_SHIFT, HMEH_DOT, JP_COLN);
const key_override_t min_ques_override = ko_make_basic(MOD_MASK_SHIFT, HHYP_MINS, JP_QUES);
const key_override_t lbrk_lsbk_override = ko_make_basic(MOD_MASK_SHIFT, JP_LPRN, JP_LABK);
const key_override_t rbrk_rsbk_override = ko_make_basic(MOD_MASK_SHIFT, JP_RPRN, JP_RABK);



const key_override_t **key_overrides = (const key_override_t *[]){
    &quots_quotd_override,
    &ctl_del_bksp_override,
    &ctl_quo_scln_override,
    &one_numpad_override,
    &two_numpad_override,
    &three_numpad_override,
    &four_numpad_override,
    &five_numpad_override,
    &six_numpad_override,
    &seven_numpad_override,
    &eight_numpad_override,
    &nine_numpad_override,
    &zero_numpad_override,
    &comm_semi_override,
    &dot_coln_override,
    &lbrk_lsbk_override,
    &rbrk_rsbk_override,
    &min_ques_override,
    NULL
};

// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVARF_MAC] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      JP_QUOT,  HMEH_U,  HHYP_O,    KC_W,    KC_P,                         KC_Q,    KC_V,  HHYP_D,  HMEH_R,    KC_F,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       HSFT_A,  HOPT_I,  HCMD_E,  HCTL_Y,    KC_G,                         KC_L,  HCTL_H,  HCMD_T,  HOPT_N,  HSFT_S,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      JP_COMM,HMEH_DOT,HHYP_MINS, HSYM_C,    KC_J,                         KC_K,  HEXT_M,  HHYP_B,  HMEH_X,    KC_Z,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  SYM,     NUM,  KC_SPC,OSM(MOD_LSFT),   NAV,  EXT
                             //`--------------------------'  `--------------------------'
                                    ),
  [_TRON_MAC_BASE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
        TJ_RA,   TJ_RU,   TJ_KO,   TJ_HA,  TJ_XYO,                        TJ_KI,   TJ_NO,   TJ_KU,    TJ_A,   TJ_RE,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        TJ_TA,   TJ_TO,   TJ_KA,   TJ_TE,   TJ_MO,                        TJ_WO,    TJ_I,    TJ_U,  TJ_SHI,   TJ_NN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        TJ_MA,   TJ_RI,   TJ_NI,   TJ_SA,   TJ_NA,                        TJ_SU,  TJ_TSU,TJ_DOUTEN,TJ_KUTEN,TJ_XTSU,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
        TRON_SYM,  TRON_NUM,  MO(_TRON_MAC_RED), MO(_TRON_MAC_BLUE),TRON_NAV, TRON_EXT
                             //`--------------------------'  `--------------------------'
                         ),
  [_TRON_MAC_BLUE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
        TJ_BI,   TJ_ZO,   TJ_GO,  TJ_BA,    TJ_BO,                         TJ_E,   TJ_KE,   TJ_ME,   TJ_MU,  TJ_RO,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        TJ_DA,   TJ_DO,   TJ_GA,  TJ_DE,    TJ_BU,                         TJ_O,  TJ_CHI,TJ_CHOUONNPU,TJ_MI,  TJ_YA,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        TJ_XE,   TJ_XO,    TJ_ZE,  TJ_ZA,   TJ_BE,                        TJ_WA,   TJ_XI,   TJ_XA, _______,   TJ_XU,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                       _______,  _______, MO(_TRON_MAC_PURPLE),    _______, _______, _______
                             //`--------------------------'  `--------------------------'
                                    ),
  [_TRON_MAC_RED] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
        TJ_HI,   TJ_SO,TJ_NAKAGURO,TJ_XYA,  TJ_HO,                        TJ_GI,   TJ_GE,  TJ_GU,  _______, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        TJ_NU,   TJ_NE,  TJ_XYU,   TJ_YO,   TJ_FU,                         TJ_O,  TJ_DZI,  TJ_VU,    TJ_JI, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        TJ_XE,   TJ_XO,   TJ_SE,   TJ_YU,   TJ_HE,                        TJ_ZU,  TJ_DZU,TJ_LKAGIKAKO,TJ_RKAGIKAKO, TJ_XU,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                               _______,  _______, _______,    MO(_TRON_MAC_PURPLE), _______, _______
                             //`--------------------------'  `--------------------------'
                                    ),
  [_TRON_MAC_PURPLE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      TJ_PI,   _______, _______, TJ_PA,  TJ_PO,                         _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, TJ_PU,                         KC_SPC, C(JP_J), C(JP_K), KC_ENT, _______,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______, TJ_PE,                        _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  _______,  _______,  _______, _______, _______, _______
                             //`--------------------------'  `--------------------------'
                                    ),
  [_DVARF_WIN] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      JP_QUOT,  HMEH_U,  HHYP_O,    KC_W,    KC_P,                         KC_Q,    KC_V,  HHYP_D,  HMEH_R,    KC_F,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       HSFT_A,  HOPT_I,  HCMD_E,  HCTL_Y,    KC_G,                         KC_L,  HCTL_H,  HCMD_T,  HOPT_N,  HSFT_S,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      JP_COMM,HMEH_DOT,HHYP_MINS, LT(_SYM_WIN,KC_C),    KC_J,         KC_K,  LT(_EXT_WIN,KC_M),  HHYP_B,  HMEH_X,    KC_Z,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
   LT(_SYM_WIN,KC_TAB),     LT(_NUM_WIN,KC_DEL),  KC_SPC,OSM(MOD_LSFT),   LT(_NAV_WIN,KC_BSPC),  LT(_EXT_WIN,KC_ENT)
                             //`--------------------------'  `--------------------------'
                                ),
  [_NUM_MAC] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
    C(KC_F2), KC_LNG2, KC_LNG1, TO(_TRON_MAC_BASE), _______,            JP_PLUS,    KC_7,    KC_8,    KC_9, JP_ASTR,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL, _______,                      JP_MINS,    KC_4,    KC_5,    KC_6, JP_SLSH,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     _______, _______, _______, _______ ,_______,                       JP_EQL,    KC_1,    KC_2,    KC_3,    KC_0,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 TO(_DVARF_MAC),  NUM, TO(_DVARF_MAC), JP_HASH, JP_PERC, JP_TILD
                             //`--------------------------'  `--------------------------'
                              ),
  [_NUM_WIN] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
     A(KC_F2),  KC_MEH, KC_HYPR, QK_LEAD, _______,                      JP_PLUS,    KC_7,    KC_8,    KC_9, JP_ASTR,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL, _______,                      JP_MINS,    KC_4,    KC_5,    KC_6, JP_SLSH,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      _______, _______, _______, _______ ,_______,                       JP_EQL,    KC_1,    KC_2,    KC_3,    KC_0,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 TO(_DVARF_WIN), XXXXXXX, TO(_DVARF_WIN), JP_HASH, JP_PERC, JP_TILD
                             //`--------------------------'  `--------------------------'
                              ),
  [_NAV_MAC] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      G(KC_Z), G(KC_X), G(KC_C), G(KC_V),LSG(KC_Z),                    XXXXXXX,  QK_LEAD, KC_HYPR,  KC_MEH,   LLOCK,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, SELWORD,                    LSG(KC_5), KC_RCTL, KC_RCMD, KC_ROPT, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_HOME, KC_PGUP, KC_PGDN,  KC_END,A(KC_RGHT),                   LSG(KC_3), KC_MPRV,S(C(KC_TAB)),C(KC_TAB),KC_MNXT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 KC_ESC,   TO(_DVARF_MAC), TO(_DVARF_MAC), TO(_DVARF_MAC), NAV, TO(_DVARF_MAC)
                             //`--------------------------'  `--------------------------'
                              ),
      [_NAV_WIN] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_Y),                    XXXXXXX,  QK_LEAD, KC_HYPR,  KC_MEH,   LLOCK,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, SELWORD,                    LSG(KC_S), KC_RCTL, KC_RCMD, KC_ROPT, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_HOME, KC_PGUP, KC_PGDN,  KC_END,A(KC_RGHT),                   G(KC_PSCR), KC_MPRV,S(C(KC_TAB)),C(KC_TAB),KC_MNXT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 KC_ESC,   TO(_DVARF_WIN), TO(_DVARF_WIN), TO(_DVARF_WIN), XXXXXXX, TO(_DVARF_WIN)
                             //`--------------------------'  `--------------------------'
                              ),
  [_SYM_MAC] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      JP_ZKHK, JP_MHEN, JP_HENK, JP_KANA, XXXXXXX,                       JP_YEN, JP_LBRC, JP_RBRC, JP_COLN, JP_CIRC,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL, JP_BSLS,                      JP_SCLN, JP_LPRN, JP_RPRN, JP_AMPR, JP_QUES,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      JP_EISU,    FUN2,    FUN1, XXXXXXX, XXXXXXX,                      JP_PIPE, JP_LCBR, JP_RCBR,   JP_AT, JP_UNDS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, TO(_DVARF_MAC), TO(_DVARF_MAC),   JP_EXLM, JP_DLR, JP_GRV
                             //`--------------------------'  `--------------------------'
                              ),
      [_SYM_WIN] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      JP_ZKHK, JP_MHEN, JP_HENK, JP_KANA, XXXXXXX,                       JP_YEN, JP_LBRC, JP_RBRC, JP_COLN, JP_CIRC,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL, JP_BSLS,                      JP_SCLN, JP_LPRN, JP_RPRN, JP_AMPR, JP_QUES,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      JP_EISU, MO(_FUN2_WIN), MO(_FUN1_WIN), XXXXXXX, XXXXXXX,          JP_PIPE, JP_LCBR, JP_RCBR,   JP_AT, JP_UNDS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX, TO(_DVARF_MAC), TO(_DVARF_MAC),   JP_EXLM, JP_DLR, JP_GRV
                             //`--------------------------'  `--------------------------'
                              ),
  [_EXT_MAC] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
     KC_LNG2, _EISU, _KANA,KC_LNG1 , XXXXXXX,    KC_LPAD, KC_MCTL, XXXXXXX, XXXXXXX, KC_EJCT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_MUTE, KC_VOLU, KC_VOLD, KC_MPLY,HYPR(KC_B),                    KC_PAUS, KC_RCTL, KC_RCMD, KC_ROPT, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      JP_CAPS,   DFINE,   GTRNS,   GOOGL, CMD_TAB,                      KC_SCRL, XXXXXXX,     MSE, XXXXXXX, KC_PENT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 TO(_DVARF_MAC), TO(_DVARF_MAC), TO(_DVARF_MAC),    TO(_DVARF_MAC), TO(_DVARF_MAC), XXXXXXX
                             //`--------------------------'  `--------------------------'
      // afred macro - hyper-B is back 2 seconds in iina when used in emacs
                              ),
      [_EXT_WIN] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_CAPS, KC_LNG2, KC_LNG1, ALT_TAB, XXXXXXX,                      KC_ASST, KC_MCTL, XXXXXXX, XXXXXXX, KC_CPNL,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_MUTE, KC_VOLU, KC_VOLD, KC_MPLY,HYPR(KC_B),                    KC_PAUS, KC_RCTL, KC_RCMD, KC_ROPT, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      JP_CAPS,   DFINE,   GTRNS,   GOOGL, XXXXXXX,                      KC_SCRL, XXXXXXX, MO(_MSE_WIN), XXXXXXX, KC_PENT,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
            TO(_DVARF_WIN), TO(_DVARF_WIN), TO(_DVARF_WIN),    TO(_DVARF_WIN), TO(_DVARF_WIN), XXXXXXX
                             //`--------------------------'  `--------------------------'
                              ),
  [_MSE_MAC] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, KC_BTN2, KC_BTN1, KC_BTN3, XXXXXXX,                      KC_PWR, XXXXXXX,  XXXXXXX, XXXXXXX,  KC_APP,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, XXXXXXX,                     KC_SLEP,  KC_RCTL, KC_RCMD, KC_ROPT, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX,                     KC_WAKE,  KC_MRWD, XXXXXXX, XXXXXXX, KC_MFFD,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 TO(_DVARF_MAC), TO(_DVARF_MAC), TO(_DVARF_MAC),    TO(_DVARF_MAC), TO(_DVARF_MAC), TO(_DVARF_MAC)
                             //`--------------------------'  `--------------------------'
                              ),
      [_MSE_WIN] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, KC_BTN2, KC_BTN1, KC_BTN3, XXXXXXX,                      KC_PWR, XXXXXXX,  XXXXXXX, XXXXXXX,  KC_APP,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, XXXXXXX,                     KC_SLEP,  KC_RCTL, KC_RCMD, KC_ROPT, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX,                     KC_WAKE,  KC_MRWD, XXXXXXX, XXXXXXX, KC_MFFD,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
            TO(_DVARF_WIN), TO(_DVARF_WIN), TO(_DVARF_WIN),    TO(_DVARF_WIN), TO(_DVARF_WIN), TO(_DVARF_WIN)
                             //`--------------------------'  `--------------------------'
                              ),
  [_FUN1_MAC] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,DF(_DVARF_MAC),                    KC_PSCR,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL,DF(_DVARF_WIN),                 KC_NUM,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 TO(_DVARF_MAC), TO(_DVARF_MAC), TO(_DVARF_MAC),    TO(_DVARF_MAC), TO(_DVARF_MAC), TO(_DVARF_MAC)
                             //`--------------------------'  `--------------------------'
                               ),
      [_FUN1_WIN] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,DF(_DVARF_MAC),                    KC_PSCR,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL,DF(_DVARF_WIN),                 KC_NUM,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
             TO(_DVARF_WIN), TO(_DVARF_WIN), TO(_DVARF_WIN),    TO(_DVARF_WIN), TO(_DVARF_WIN), TO(_DVARF_WIN)
                             //`--------------------------'  `--------------------------'
                               ),
  [_FUN2_MAC] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL, XXXXXXX,                      XXXXXXX,  KC_F17,  KC_F18,  KC_F19,  KC_F20,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       QK_RBT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_F13,  KC_F14,  KC_F15,  KC_F16,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 TO(_DVARF_MAC), TO(_DVARF_MAC), TO(_DVARF_MAC),    TO(_DVARF_MAC), TO(_DVARF_MAC), TO(_DVARF_MAC)
                             //`--------------------------'  `--------------------------'
                               ),
      [_FUN2_WIN] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL, XXXXXXX,                      XXXXXXX,  KC_F17,  KC_F18,  KC_F19,  KC_F20,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       QK_RBT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_F13,  KC_F14,  KC_F15,  KC_F16,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
              TO(_DVARF_WIN), TO(_DVARF_WIN), TO(_DVARF_WIN),    TO(_DVARF_WIN), TO(_DVARF_WIN), TO(_DVARF_WIN)
                             //`--------------------------'  `--------------------------'
                               )
};

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  return achordion_opposite_hands(tap_hold_record, other_record);
}



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
  DISPLAY_LAYER_NAME(_FUN2_MAC, "FUN 2 MAC");
  DISPLAY_LAYER_NAME(_FUN1_MAC, "FUN 1 MAC");
  DISPLAY_LAYER_NAME(_MSE_MAC, "MSE MAC");
  DISPLAY_LAYER_NAME(_EXT_MAC, "EXT MAC");
  DISPLAY_LAYER_NAME(_SYM_MAC, "SYM MAC");
  DISPLAY_LAYER_NAME(_NAV_MAC, "NAV MAC");
  DISPLAY_LAYER_NAME(_NUM_MAC, "NUM MAC");
  DISPLAY_LAYER_NAME(_DVARF_MAC, "DVARF MAC");
  DISPLAY_LAYER_NAME(_FUN2_WIN, "FUN 2 WIN");
  DISPLAY_LAYER_NAME(_FUN1_WIN, "FUN 1 WIN");
  DISPLAY_LAYER_NAME(_MSE_WIN, "MSE WIN");
  DISPLAY_LAYER_NAME(_EXT_WIN, "EXT WIN");
  DISPLAY_LAYER_NAME(_SYM_WIN, "SYM WIN");
  DISPLAY_LAYER_NAME(_NAV_WIN, "NAV WIN");
  DISPLAY_LAYER_NAME(_NUM_WIN, "NUM WIN");
  DISPLAY_LAYER_NAME(_DVARF_WIN, "DVARF WIN");
  DISPLAY_LAYER_NAME(_TRON_MAC_BASE, "TRON MAC BASE");
  DISPLAY_LAYER_NAME(_TRON_MAC_BLUE, "TRON MAC BLUE");
  DISPLAY_LAYER_NAME(_TRON_MAC_RED, "TRON MAC RED");
  DISPLAY_LAYER_NAME(_TRON_MAC_PURPLE, "TRON MAC PURPLE");
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
