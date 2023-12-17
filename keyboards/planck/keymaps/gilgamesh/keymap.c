/* Copyright 2015-2021 Jack Humbert
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


#include "keymap_japanese.h"
#include "sendstring_japanese.h"

#ifdef AUDIO_ENABLE
#include "muse.h"
#endif

enum planck_layers {
    _DVARF,
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST,
    _TRON_BASE,
    _TRON_RED,
    _TRON_BLUE,
    _TRON_PURPLE,
    _TRON_ROMAJI_BASE,
    _TRON_ROMAJI_RED,
    _TRON_ROMAJI_BLUE,
    _TRON_ROMAJI_PURPLE,
    _SYM_NUM,
    _NAV_EXT,
    _SYM,
    _FUN1,
    _FUN2,
};


#define NUM LT(_SYM_NUM,KC_DEL)
#define NAV LT(_NAV_EXT,KC_BSPC)
#define SYM LT(_SYM,KC_TAB)
#define EXT KC_ENT
#define FUN1 MO(_FUN1)
#define FUN2 MO(_FUN2)

#define PASTE G(KC_V)

#define TRON_NUM LT(_SYM_NUM,KC_DEL)
#define TRON_NAV LT(_NAV_EXT,KC_BSPC)
#define TRON_SYM LT(_SYM,KC_TAB)
#define TRON_EXT KC_ENT

// Left-hand home row mods
#define HCTL_Y LCTL_T(KC_Y)
#define HCMD_E LGUI_T(KC_E)
#define HOPT_I LALT_T(KC_I)
#define HSFT_A LSFT_T(KC_A)
#define HHYP_MINS HYPR_T(JP_MINS)
#define HMEH_DOT MEH_T(JP_DOT)

// Right-hand home row mods
#define HCTL_H RCTL_T(KC_H)
#define HCMD_T RGUI_T(KC_T)
#define HOPT_N RALT_T(KC_N)
#define HSFT_S RSFT_T(KC_S)
#define HHYP_B HYPR_T(KC_B)
#define HMEH_X MEH_T(KC_X)


// TRON Left-hand home row mods
#define HCTL_TJ_TE TJ_TE
#define HCMD_TJ_KA TJ_KA
#define HOPT_TJ_TO TJ_TO
#define HSFT_TJ_TA TJ_TA


// TRON Right-hand home row mods
#define HCTL_TJ_I TJ_I
#define HCMD_TJ_U TJ_U
#define HOPT_TJ_SHI TJ_SHI
#define HSFT_TJ_NN TJ_NN


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


//tron japanese laid over JIS romaji


#define TRJ_A JP_A
#define TRJ_I JP_I
#define TRJ_U JP_U
#define TRJ_E JP_E
#define TRJ_O JP_O
#define TRJ_LKAGIKAKO JP_LBRC
#define TRJ_RKAGIKAKO JP_RBRC
#define TRJ_DOUTEN JP_COMM
#define TRJ_KUTEN JP_DOT
#define TRJ_NAKAGURO JP_SLSH
#define TRJ_CHOUONNPU JP_MINS



// super cmd tab
bool is_cmd_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t cmd_tab_timer = 0;     // we will be using them soon.


enum custom_keycodes {
    GOOGL = SAFE_RANGE,
    GTRNS,
    DFINE,
    CMD_TAB,
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
    _ROMAJI,
    TRJ_GI,
    TRJ_GE,
    TRJ_GU,
    TRJ_DI,
    TRJ_DZI,
    TRJ_VU,
    TRJ_JI,
    TRJ_ZU,
    TRJ_DZU,
    TRJ_BI,
    TRJ_ZO,
    TRJ_GO,
    TRJ_BA,
    TRJ_BO,
    TRJ_DA,
    TRJ_DO,
    TRJ_GA,
    TRJ_DE,
    TRJ_BU,
    TRJ_ZE,
    TRJ_ZA,
    TRJ_BE,
    TRJ_PA,
    TRJ_PI,
    TRJ_PU,
    TRJ_PE,
    TRJ_PO,
TRJ_RA,
TRJ_RU,
TRJ_KO,
TRJ_HA,
TRJ_XYO,
TRJ_KI,
TRJ_NO,
TRJ_KU,
TRJ_RE,
TRJ_TA,
TRJ_TO,
TRJ_KA,
TRJ_TE,
TRJ_MO,
TRJ_WO,
TRJ_SHI,
TRJ_NN,
TRJ_MA,
TRJ_RI,
TRJ_NI,
TRJ_SA,
TRJ_NA,
TRJ_SU,
TRJ_TSU,
TRJ_XTSU,
TRJ_HI,
TRJ_SO,
TRJ_XYA,
TRJ_HO,
TRJ_KE,
TRJ_ME,
TRJ_MU,
TRJ_RO,
TRJ_NU,
TRJ_NE,
TRJ_XYU,
TRJ_YO,
TRJ_FU,
TRJ_CHI,
TRJ_MI,
TRJ_YA,
TRJ_XE,
TRJ_XO,
TRJ_SE,
TRJ_YU,
TRJ_HE,
TRJ_WA,
TRJ_XI,
TRJ_XA,
TRJ_XU,

};


// macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // rolling home row modifier cancellation
  switch (keycode) {
  case HCTL_H:
    /*
      This piece of code nullifies the effect of Right Shift when tapping
      the RCTL_T(KC_H) key.
      This helps rolling over RCTL_T(KC_H) and RCMD_T(KC_T)
      to obtain the intended "h" instead of "cmd+h" hide.
      Consequently, cmd+h can only be obtained by tapping LCMD_E(KC_H)
      and holding LSFT_T(KC_S) (which is the left Shift mod tap).
    */

    /*
      Detect the tap.
      We're only interested in overriding the tap behavior
      z in a certain cicumstance. The hold behavior can stay the same.
    */
    if (record->event.pressed && record->tap.count > 0) {
      // Detect right Command
      if (get_mods() & MOD_BIT(KC_RGUI)) {
        // temporarily disable right Command
        // so that we can send KC_T and KC_H
        // without Command on.
        unregister_mods(MOD_BIT(KC_RGUI));
        tap_code(KC_T);
        tap_code(KC_H);
        // restore the mod state
        add_mods(MOD_BIT(KC_RGUI));
        // to prevent QMK from processing RCTL_T(KC_N) as usual in our special case
        return false;
      }
    }
    /*else process RCTL_T(KC_H) as usual.*/
    return true;
  }
  switch (keycode) {
  case HCTL_Y:
    if (record->event.pressed && record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_LGUI)) {
        unregister_mods(MOD_BIT(KC_LGUI));
        tap_code(KC_E);
        tap_code(KC_Y);
        add_mods(MOD_BIT(KC_LGUI));
        return false;
      }
    }
    return true;
  }
  switch (keycode) {
  case LALT_T(JP_LPRN):
    if (record->tap.count && record->event.pressed) {
      tap_code16(JP_LPRN);
      return false;
    }
    break;
  }
  // disable rolling on mute key with OPT
  switch (keycode) {
  case MT(MOD_RSFT,KC_MUTE):
    if (record->event.pressed && record->tap.count > 0) {
      if (get_mods() & MOD_BIT(KC_RALT)) {
        unregister_mods(MOD_BIT(KC_RALT));
        tap_code(KC_MUTE);
        add_mods(MOD_BIT(KC_RALT));
        return false;
      }
    }
    return true;
  }
  switch (keycode) {
  case LALT_T(JP_LPRN):
    if (record->tap.count && record->event.pressed) {
      tap_code16(JP_LPRN);
      return false;
    }
    break;
  }
  switch (keycode) {
  case LGUI_T(JP_RPRN):
    if (record->tap.count && record->event.pressed) {
      tap_code16(JP_RPRN);
      return false;
    }
    break;
  }
  switch (keycode) {
  case LSFT_T(JP_AMPR):
    if (record->tap.count && record->event.pressed) {
      tap_code16(JP_AMPR);
      return false;
    }
    break;
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
    // lang switching
  case _EISU:
    if (record->event.pressed) {
      tap_code(KC_LNG2);
    }
    else {
      layer_move(_DVARF);
    }
    break;
  case _ROMAJI:
    if (record->event.pressed) {
      tap_code(KC_LNG1);
    }
    else {
      layer_move(_TRON_ROMAJI_BASE);
    }
    break;
  case _KANA:
    if (record->event.pressed) {
      tap_code(KC_LNG1);
    }
    else {
      layer_move(_TRON_BASE);
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
    // tron romaji

  case TRJ_GI:
    if (record->event.pressed) {
      tap_code(KC_G);
      tap_code(KC_I);
    } else {
      //
    }
break;
      case TRJ_GE:
    if (record->event.pressed) {
      tap_code(KC_G);
      tap_code(KC_E);
    } else {
      //
    }
break;
      case TRJ_GU:
    if (record->event.pressed) {
      tap_code(KC_G);
      tap_code(KC_U);
    } else {
      //
    }
break;
  case TRJ_DI:
    if (record->event.pressed) {
      tap_code(KC_D);
      tap_code(KC_I);
    } else {
      //
    }
break;
      case TRJ_DZI:
    if (record->event.pressed) {
      tap_code(KC_D);
      tap_code(KC_Z);
      tap_code(KC_I);
    } else {
      //
    }
break;
      case TRJ_VU:
    if (record->event.pressed) {
      tap_code(KC_V);
      tap_code(KC_U);
    } else {
      //
    }
break;
      case TRJ_JI:
    if (record->event.pressed) {
      tap_code(KC_J);
      tap_code(KC_I);
    } else {
      //
    }
break;
      case TRJ_ZU:
    if (record->event.pressed) {
      tap_code(KC_Z);
      tap_code(KC_U);
    } else {
      //
    }
break;
    case TRJ_DZU:
    if (record->event.pressed) {
      tap_code(KC_D);
      tap_code(KC_Z);
      tap_code(KC_U);
    } else {
      //
    }
break;
      case TRJ_BI:
    if (record->event.pressed) {
      tap_code(KC_B);
      tap_code(KC_I);
    } else {
      //
    }
break;
      case TRJ_ZO:
    if (record->event.pressed) {
      tap_code(KC_Z);
      tap_code(KC_O);
    } else {
      //
    }
break;
      case TRJ_GO:
    if (record->event.pressed) {
      tap_code(KC_G);
      tap_code(KC_O);
    } else {
      //
    }
    break;
      case TRJ_BA:
    if (record->event.pressed) {
      tap_code(KC_B);
      tap_code(KC_A);
    } else {
      //
    }
    break;
      case TRJ_BO:
    if (record->event.pressed) {
      tap_code(KC_B);
      tap_code(KC_O);
    } else {
      //
    }
    break;
      case TRJ_DA:
    if (record->event.pressed) {
      tap_code(KC_D);
      tap_code(KC_A);
    } else {
      //
    }
    break;
      case TRJ_DO:
    if (record->event.pressed) {
      tap_code(KC_D);
      tap_code(KC_O);
    } else {
      //
    }
break;
      case TRJ_GA:
    if (record->event.pressed) {
      tap_code(KC_G);
      tap_code(KC_A);
    } else {
      //
    }
    break;
      case TRJ_DE:
    if (record->event.pressed) {
      tap_code(KC_D);
      tap_code(KC_E);
    } else {
      //
    }
    break;
      case TRJ_BU:
    if (record->event.pressed) {
      tap_code(KC_B);
      tap_code(KC_U);
    } else {
      //
    }
    break;
          case TRJ_ZE:
    if (record->event.pressed) {
      tap_code(KC_Z);
      tap_code(KC_E);
    } else {
      //
    }
break;
      case TRJ_ZA:
    if (record->event.pressed) {
      tap_code(KC_Z);
      tap_code(KC_A);
    } else {
      //
    }
    break;
      case TRJ_BE:
    if (record->event.pressed) {
      tap_code(KC_B);
      tap_code(KC_E);
    } else {
      //
    }
    break;
          case TRJ_PA:
    if (record->event.pressed) {
      tap_code(KC_P);
      tap_code(KC_A);
    } else {
      //
    }
    break;
          case TRJ_PI:
    if (record->event.pressed) {
      tap_code(KC_P);
      tap_code(KC_I);
    } else {
      //
    }
    break;
          case TRJ_PU:
    if (record->event.pressed) {
      tap_code(KC_P);
      tap_code(KC_U);
    } else {
      //
    }
    break;
          case TRJ_PE:
    if (record->event.pressed) {
      tap_code(KC_P);
      tap_code(KC_E);
    } else {
      //
    }
    break;
          case TRJ_PO:
    if (record->event.pressed) {
      tap_code(KC_P);
      tap_code(KC_O);
    } else {
      //
    }
    break;
          case TRJ_RA:
    if (record->event.pressed) {
      tap_code(KC_R);
      tap_code(KC_A);
    } else {
      //
    }
    break;
      case TRJ_RU:
    if (record->event.pressed) {
      tap_code(KC_R);
      tap_code(KC_U);
    } else {
      //
    }
break;
          case TRJ_KO:
    if (record->event.pressed) {
      tap_code(KC_K);
      tap_code(KC_O);
    } else {
      //
    }
    break;
      case TRJ_HA:
    if (record->event.pressed) {
      tap_code(KC_H);
      tap_code(KC_A);
    } else {
      //
    }
    break;
      case TRJ_XYO:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_Y);
      tap_code(KC_O);
    } else {
      //
    }
    break;
      case TRJ_KI:
    if (record->event.pressed) {
      tap_code(KC_K);
      tap_code(KC_I);
    } else {
      //
    }
    break;
      case TRJ_NO:
    if (record->event.pressed) {
      tap_code(KC_N);
      tap_code(KC_O);
    } else {
      //
    }
    break;
          case TRJ_KU:
    if (record->event.pressed) {
      tap_code(KC_K);
      tap_code(KC_U);
    } else {
      //
    }
    break;
          case TRJ_RE:
    if (record->event.pressed) {
      tap_code(KC_R);
      tap_code(KC_E);
    } else {
      //
    }
    break;
          case TRJ_TA:
    if (record->event.pressed) {
      tap_code(KC_T);
      tap_code(KC_A);
    } else {
      //
    }
    break;
          case TRJ_TO:
    if (record->event.pressed) {
      tap_code(KC_T);
      tap_code(KC_O);
    } else {
      //
    }
    break;
          case TRJ_KA:
    if (record->event.pressed) {
      tap_code(KC_K);
      tap_code(KC_A);
    } else {
      //
    }
    break;
          case TRJ_TE:
    if (record->event.pressed) {
      tap_code(KC_T);
      tap_code(KC_E);
    } else {
      //
    }
    break;
          case TRJ_MO:
    if (record->event.pressed) {
      tap_code(KC_M);
      tap_code(KC_O);
    } else {
      //
    }
    break;
          case TRJ_WO:
    if (record->event.pressed) {
      tap_code(KC_W);
      tap_code(KC_O);
    } else {
      //
    }
    break;
          case TRJ_SHI:
    if (record->event.pressed) {
      tap_code(KC_S);
      tap_code(KC_H);
      tap_code(KC_I);
    } else {
      //
    }
    break;
          case TRJ_NN:
    if (record->event.pressed) {
      tap_code(KC_N);
      tap_code(KC_N);
    } else {
      //
    }
    break;
          case TRJ_MA:
    if (record->event.pressed) {
      tap_code(KC_M);
      tap_code(KC_A);
    } else {
      //
    }
    break;
          case TRJ_RI:
    if (record->event.pressed) {
      tap_code(KC_R);
      tap_code(KC_I);
    } else {
      //
    }
    break;
          case TRJ_NI:
    if (record->event.pressed) {
      tap_code(KC_N);
      tap_code(KC_I);
    } else {
      //
    }
    break;
          case TRJ_SA:
    if (record->event.pressed) {
      tap_code(KC_S);
      tap_code(KC_A);
    } else {
      //
    }
    break;
          case TRJ_SU:
    if (record->event.pressed) {
      tap_code(KC_S);
      tap_code(KC_U);
    } else {
      //
    }
    break;
          case TRJ_TSU:
    if (record->event.pressed) {
      tap_code(KC_T);
      tap_code(KC_S);
      tap_code(KC_U);
    } else {
      //
    }
    break;
     case TRJ_XTSU:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_T);
      tap_code(KC_S);
      tap_code(KC_U);
    } else {
      //
    }
    break;
          case TRJ_HI:
    if (record->event.pressed) {
      tap_code(KC_H);
      tap_code(KC_I);
    } else {
      //
    }
    break;
              case TRJ_SO:
    if (record->event.pressed) {
      tap_code(KC_S);
      tap_code(KC_O);
    } else {
      //
    }
    break;
              case TRJ_XYA:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_Y);
      tap_code(KC_A);
    } else {
      //
    }
    break;
          case TRJ_HO:
    if (record->event.pressed) {
      tap_code(KC_H);
      tap_code(KC_O);
    } else {
      //
    }
    break;
          case TRJ_KE:
    if (record->event.pressed) {
      tap_code(KC_K);
      tap_code(KC_E);
    } else {
      //
    }
    break;
          case TRJ_ME:
    if (record->event.pressed) {
      tap_code(KC_M);
      tap_code(KC_E);
    } else {
      //
    }
    break;
case TRJ_MU:
    if (record->event.pressed) {
      tap_code(KC_M);
      tap_code(KC_U);
    } else {
      //
    }
    break;
case TRJ_RO:
    if (record->event.pressed) {
      tap_code(KC_R);
      tap_code(KC_O);
    } else {
      //
    }
    break;
case TRJ_NU:
    if (record->event.pressed) {
      tap_code(KC_N);
      tap_code(KC_U);
    } else {
      //
    }
    break;
case TRJ_NE:
    if (record->event.pressed) {
      tap_code(KC_N);
      tap_code(KC_E);
    } else {
      //
    }
    break;
case TRJ_XYU:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_Y);
            tap_code(KC_U);
    } else {
      //
    }
    break;
case TRJ_YO:
    if (record->event.pressed) {
      tap_code(KC_Y);
      tap_code(KC_O);
    } else {
      //
    }
    break;
case TRJ_FU:
    if (record->event.pressed) {
      tap_code(KC_F);
      tap_code(KC_U);
    } else {
      //
    }
    break;
case TRJ_CHI:
    if (record->event.pressed) {
      tap_code(KC_C);
      tap_code(KC_H);
            tap_code(KC_I);
    } else {
      //
    }
    break;
case TRJ_MI:
    if (record->event.pressed) {
      tap_code(KC_M);
      tap_code(KC_I);
    } else {
      //
    }
    break;
    case TRJ_YA:
    if (record->event.pressed) {
      tap_code(KC_Y);
      tap_code(KC_A);
    } else {
      //
    }
    break;
case TRJ_XE:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_E);
    } else {
      //
    }
    break;
case TRJ_XO:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_O);
    } else {
      //
    }
    break;
    case TRJ_SE:
    if (record->event.pressed) {
      tap_code(KC_S);
      tap_code(KC_E);
    } else {
      //
    }
    break;
case TRJ_YU:
    if (record->event.pressed) {
      tap_code(KC_Y);
      tap_code(KC_U);
    } else {
      //
    }
    break;
    case TRJ_HE:
    if (record->event.pressed) {
      tap_code(KC_H);
      tap_code(KC_E);
    } else {
      //
    }
    break;
    case TRJ_WA:
    if (record->event.pressed) {
      tap_code(KC_W);
      tap_code(KC_A);
    } else {
      //
    }
    break;
case TRJ_XI:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_I);
    } else {
      //
    }
    break;
case TRJ_XA:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_A);
    } else {
      //
    }
    break;
    case TRJ_XU:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_U);
    } else {
      //
    }
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
  // super cmd tab - The very important timer.
  if (is_cmd_tab_active) {
    if (timer_elapsed(cmd_tab_timer) > 500) {
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
const uint16_t PROGMEM combo_ret[] = {KC_C, KC_M, COMBO_END};
const uint16_t PROGMEM combo_pause[] = {KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM combo_sym[] = {NUM, KC_SPC, COMBO_END};
const uint16_t PROGMEM combo_ext[] = {NAV, OSM(MOD_LSFT), COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_capsword, CW_TOGG),
  COMBO(combo_qkboot, QK_BOOT),
  COMBO(combo_qkeeprom, EE_CLR),
  COMBO(combo_qkreboot, QK_RBT),
  COMBO(combo_ret, KC_ENT),
  COMBO(combo_pause, KC_MPLY),
  COMBO(combo_sym, SYM),
  COMBO(combo_ext, EXT),
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
//const key_override_t paste_override = ko_make_basic(MOD_MASK_SHIFT, PASTE, (S(A(G(KC_V)))));
//const key_override_t comm_semi_override = ko_make_basic(MOD_MASK_SHIFT, JP_COMM, JP_SCLN);
//const key_override_t dot_coln_override = ko_make_basic(MOD_MASK_SHIFT, HMEH_DOT, JP_COLN);
//const key_override_t min_ques_override = ko_make_basic(MOD_MASK_SHIFT, HHYP_MINS, JP_QUES);
//const key_override_t lbrk_lsbk_override = ko_make_basic(MOD_MASK_SHIFT, JP_LPRN, JP_LABK);
//const key_override_t rbrk_rsbk_override = ko_make_basic(MOD_MASK_SHIFT, JP_RPRN, JP_RABK);
//const key_override_t hidden_files_mac_override = ko_make_basic(MOD_MASK_SG, HMEH_DOT, JP_RABK);
//const key_override_t kana_romaji_override = ko_make_basic(MOD_MASK_SHIFT, _KANA, _ROMAJI);



const key_override_t **key_overrides = (const key_override_t *[]){
    &quots_quotd_override,
    &ctl_del_bksp_override,
    //  &paste_override,
    // &comm_semi_override,
    // &dot_coln_override,
    // &lbrk_lsbk_override,
    // &rbrk_rsbk_override,
    // &min_ques_override,
    // &hidden_files_mac_override,
    // &kana_romaji_override,
    NULL
};

// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVARF] = LAYOUT_planck_grid(
                                JP_QUOT,    KC_U,    KC_O,    KC_W,    KC_P, RGB_TOG, RGB_SAI,  KC_Q,    KC_V,    KC_D,    KC_R,    KC_F,
                                HSFT_A,  HOPT_I,  HCMD_E,  HCTL_Y,    KC_G, RGB_MOD, RGB_VAI,   KC_L,  HCTL_H,  HCMD_T,  HOPT_N,  HSFT_S,
                                JP_COMM,HMEH_DOT,HHYP_MINS,   KC_C,    KC_J, RGB_HUI, RGB_SPI,   KC_K,    KC_M,  HHYP_B,  HMEH_X,    KC_Z,
                                XXXXXXX, XXXXXXX,    SYM,     NUM,  KC_SPC,XXXXXXX, XXXXXXX,OSM(MOD_LSFT),   NAV,  EXT,  XXXXXXX, XXXXXXX
                                ),
  [_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    JP_SCLN, JP_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    JP_COMM, JP_DOT,  JP_SLSH, KC_ENT ,
    MO(_ADJUST), KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER),   KC_SPC,  KC_SPC,  MO(_RAISE),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
                                   ),
  [_RAISE] = LAYOUT_planck_grid(
    JP_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   JP_MINS, JP_EQL,  JP_LBRC, JP_RBRC, JP_BSLS,
    KC_INT4, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_INT6,
    KC_INT5, KC_INT1, KC_INT2, KC_INT3, KC_LNG1, _______, _______, KC_LNG2, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),
  [_LOWER] = LAYOUT_planck_grid(
    JP_TILD, JP_EXLM, JP_AT,   JP_HASH, JP_DLR,  JP_PERC, JP_CIRC, JP_AMPR,    JP_ASTR,    JP_LPRN, JP_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   JP_UNDS,    JP_PLUS,    JP_LCBR, JP_RCBR, JP_PIPE,
    KC_INT4, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  KC_INT6,
    KC_INT5, KC_INT1, KC_INT2, KC_INT3, KC_LNG1, _______, _______, KC_LNG2,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),
  [_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DF(_QWERTY),DF(_DVARF), _______,_______,  _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
                                 ),
  [_TRON_BASE] = LAYOUT_planck_grid(
                                    TJ_RA,   TJ_RU,   TJ_KO,   TJ_HA,  TJ_XYO,    XXXXXXX,XXXXXXX,                    TJ_KI,   TJ_NO,   TJ_KU,    TJ_A,   TJ_RE,
                                    HSFT_TJ_TA, HOPT_TJ_TO, HCMD_TJ_KA, HCTL_TJ_TE, TJ_MO,   XXXXXXX,XXXXXXX,          TJ_WO, HCTL_TJ_I, HCMD_TJ_U, HOPT_TJ_SHI, HSFT_TJ_NN,
                                    TJ_MA,   TJ_RI,   TJ_NI,   TJ_SA,   TJ_NA, XXXXXXX,XXXXXXX,                       TJ_SU,  TJ_TSU,TJ_DOUTEN,TJ_KUTEN,TJ_XTSU,
                                    XXXXXXX,XXXXXXX,    TRON_SYM,  TRON_NUM,  MO(_TRON_RED),XXXXXXX,XXXXXXX, MO(_TRON_BLUE),TRON_NAV, TRON_EXT,XXXXXXX,XXXXXXX
                                    ),
  [_TRON_BLUE] = LAYOUT_planck_grid(
                                    TJ_BI,   TJ_ZO,   TJ_GO,  TJ_BA,    TJ_BO,     XXXXXXX,XXXXXXX,                    TJ_E,   TJ_KE,   TJ_ME,   TJ_MU,  TJ_RO,
                                    TJ_DA,   TJ_DO,   TJ_GA,  TJ_DE,    TJ_BU,     XXXXXXX,XXXXXXX,                    TJ_O,  TJ_CHI,TJ_CHOUONNPU,TJ_MI,  TJ_YA,
                                    TJ_XE,   TJ_XO,    TJ_ZE,  TJ_ZA,   TJ_BE,      XXXXXXX,XXXXXXX,                  TJ_WA,   TJ_XI,   TJ_XA, _______,   TJ_XU,
                                    XXXXXXX,XXXXXXX,                  _______,  _______, MO(_TRON_PURPLE),XXXXXXX,XXXXXXX,    _______, _______, _______,XXXXXXX,XXXXXXX
                                    ),
  [_TRON_RED] = LAYOUT_planck_grid(
                                   TJ_HI,   TJ_SO,TJ_NAKAGURO,TJ_XYA,  TJ_HO,  XXXXXXX,XXXXXXX,                      TJ_GI,   TJ_GE,  TJ_GU,  _______, _______,
                                   TJ_NU,   TJ_NE,  TJ_XYU,   TJ_YO,   TJ_FU,  XXXXXXX,XXXXXXX,                       TJ_O,  TJ_DZI,  TJ_VU,    TJ_JI, _______,
                                   TJ_XE,   TJ_XO,   TJ_SE,   TJ_YU,   TJ_HE,  XXXXXXX,XXXXXXX,                      TJ_ZU,  TJ_DZU,TJ_LKAGIKAKO,TJ_RKAGIKAKO, TJ_XU,
                                   XXXXXXX,XXXXXXX,                          _______,  _______, _______,  XXXXXXX,XXXXXXX,  MO(_TRON_PURPLE), _______, _______,XXXXXXX,XXXXXXX
                                   ),
  [_TRON_PURPLE] = LAYOUT_planck_grid(
                                      TJ_PI,   _______, _______, TJ_PA,  TJ_PO,       XXXXXXX,XXXXXXX,                  _______, _______, _______, _______, _______,
                                      _______, _______, _______, _______, TJ_PU,     XXXXXXX,XXXXXXX,                    KC_SPC, C(JP_J), C(JP_K), C(JP_L), C(JP_SCLN),
                                      _______, _______, _______, _______, TJ_PE,     XXXXXXX,XXXXXXX,                   _______, KC_ENT, _______, _______, _______,
                                      XXXXXXX,XXXXXXX,                       _______,  _______,  _______,XXXXXXX,XXXXXXX, _______, _______, _______,XXXXXXX,XXXXXXX
                                      ),
  [_TRON_ROMAJI_BASE] = LAYOUT_planck_grid(
                                    TRJ_RA,   TRJ_RU,   TRJ_KO,   TRJ_HA,  TRJ_XYO,    XXXXXXX,XXXXXXX,                    TRJ_KI,   TRJ_NO,   TRJ_KU,    TRJ_A,   TRJ_RE,
                                    TRJ_TA, TRJ_TO, TRJ_KA, TRJ_TE, TRJ_MO,   XXXXXXX,XXXXXXX,          TRJ_WO, TRJ_I, TRJ_U, TRJ_SHI, TRJ_NN,
                                    TRJ_MA,   TRJ_RI,   TRJ_NI,   TRJ_SA,   TRJ_NA, XXXXXXX,XXXXXXX,                       TRJ_SU,  TRJ_TSU,TRJ_DOUTEN,TRJ_KUTEN,TRJ_XTSU,
                                    XXXXXXX,XXXXXXX,    TRON_SYM,  TRON_NUM,  MO(_TRON_ROMAJI_RED),XXXXXXX,XXXXXXX, MO(_TRON_ROMAJI_BLUE),TRON_NAV, TRON_EXT,XXXXXXX,XXXXXXX
                                    ),
  [_TRON_ROMAJI_BLUE] = LAYOUT_planck_grid(
                                    TRJ_BI,   TRJ_ZO,   TRJ_GO,  TRJ_BA,    TRJ_BO,     XXXXXXX,XXXXXXX,                    TRJ_E,   TRJ_KE,   TRJ_ME,   TRJ_MU,  TRJ_RO,
                                    TRJ_DA,   TRJ_DO,   TRJ_GA,  TRJ_DE,    TRJ_BU,     XXXXXXX,XXXXXXX,                    TRJ_O,  TRJ_CHI,TRJ_CHOUONNPU,TRJ_MI,  TRJ_YA,
                                    TRJ_XE,   TRJ_XO,    TRJ_ZE,  TRJ_ZA,   TRJ_BE,      XXXXXXX,XXXXXXX,                  TRJ_WA,   TRJ_XI,   TRJ_XA, _______,   TRJ_XU,
                                    XXXXXXX,XXXXXXX,                  _______,  _______, MO(_TRON_ROMAJI_PURPLE),XXXXXXX,XXXXXXX,    _______, _______, _______,XXXXXXX,XXXXXXX
                                    ),
  [_TRON_ROMAJI_RED] = LAYOUT_planck_grid(
                                   TRJ_HI,   TRJ_SO,TRJ_NAKAGURO,TRJ_XYA,  TRJ_HO,  XXXXXXX,XXXXXXX,                      TRJ_GI,   TRJ_GE,  TRJ_GU,  _______, _______,
                                   TRJ_NU,   TRJ_NE,  TRJ_XYU,   TRJ_YO,   TRJ_FU,  XXXXXXX,XXXXXXX,                       TRJ_O,  TRJ_DZI,  TRJ_VU,    TRJ_JI, _______,
                                   TRJ_XE,   TRJ_XO,   TRJ_SE,   TRJ_YU,   TRJ_HE,  XXXXXXX,XXXXXXX,                      TRJ_ZU,  TRJ_DZU,TRJ_LKAGIKAKO,TRJ_RKAGIKAKO, TRJ_XU,
                                   XXXXXXX,XXXXXXX,                          _______,  _______, _______,  XXXXXXX,XXXXXXX,  MO(_TRON_ROMAJI_PURPLE), _______, _______,XXXXXXX,XXXXXXX
                                   ),
  [_TRON_ROMAJI_PURPLE] = LAYOUT_planck_grid(
                                      TRJ_PI,   _______, _______, TRJ_PA,  TRJ_PO,       XXXXXXX,XXXXXXX,                  _______, _______, _______, _______, _______,
                                      _______, _______, _______, _______, TRJ_PU,     XXXXXXX,XXXXXXX,                    KC_SPC, C(JP_J), C(JP_K), C(JP_L), C(JP_SCLN),
                                      _______, _______, _______, _______, TRJ_PE,     XXXXXXX,XXXXXXX,                   _______, KC_ENT, _______, _______, _______,
                                      XXXXXXX,XXXXXXX,                       _______,  _______,  _______,XXXXXXX,XXXXXXX, _______, _______, _______,XXXXXXX,XXXXXXX
                                      ),

  [_SYM_NUM] = LAYOUT_planck_grid(
                                  JP_AT, JP_LBRC, JP_RBRC, JP_COLN, _______,     XXXXXXX,XXXXXXX,                 JP_PLUS,    KC_7,    KC_8,    KC_9, JP_ASTR,
                                  LSFT_T(JP_AMPR), LALT_T(JP_LPRN), LGUI_T(JP_RPRN), MT(MOD_LCTL,JP_SCLN), _______,XXXXXXX,XXXXXXX,JP_MINS,KC_4,KC_5,    KC_6, JP_SLSH,
                                  _______, _______, JP_UNDS, JP_EXLM , JP_PIPE,    XXXXXXX,XXXXXXX,                   JP_EQL,    KC_1,    KC_2,    KC_3,    KC_0,
                                  XXXXXXX,XXXXXXX,                  _______,  NUM,  _______, XXXXXXX,XXXXXXX,    KC_ENT,  OSL(_SYM), _______,XXXXXXX,XXXXXXX
                                  ),

  [_NAV_EXT] = LAYOUT_planck_grid(
                                  G(KC_Z), G(KC_X), G(KC_C), PASTE,LSG(KC_Z),       XXXXXXX,XXXXXXX,            LSG(KC_5),  CMD_TAB,  _EISU, _KANA,   _______,
                                  KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, KC_TAB, XXXXXXX,XXXXXXX,HYPR(KC_B), MT(MOD_RCTL,KC_MPLY), MT(MOD_RGUI,KC_VOLD), MT(MOD_RALT,KC_VOLU), MT(MOD_RSFT,KC_MUTE),
                                  KC_HOME, KC_PGUP, KC_PGDN,  KC_END,   KC_ESC,   XXXXXXX,XXXXXXX,                  C(KC_F2),   GOOGL,   GTRNS,   DFINE, JP_CAPS,
                                  XXXXXXX,XXXXXXX,    _______,     KC_ESC, KC_TAB, XXXXXXX,XXXXXXX, _______, NAV,  _______,XXXXXXX,XXXXXXX
                                  ),
  [_SYM] = LAYOUT_planck_grid(
                              JP_ZKHK, JP_MHEN, JP_HENK, JP_KANA, XXXXXXX,       XXXXXXX,XXXXXXX,               _______, JP_HASH, JP_LABK, JP_RABK, JP_CIRC,
                              KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL, JP_BSLS,       XXXXXXX,XXXXXXX,               JP_TILD, JP_PERC, JP_LCBR, JP_RCBR,  JP_GRV,
                              JP_EISU,    FUN2,    FUN1, XXXXXXX, XXXXXXX,      XXXXXXX,XXXXXXX,                _______,  JP_YEN,  JP_DLR, _______, _______,
                              XXXXXXX,XXXXXXX,             XXXXXXX, TO(_DVARF), TO(_DVARF), XXXXXXX,XXXXXXX,  _______, _______, _______,XXXXXXX,XXXXXXX
                              ),

  [_FUN1] = LAYOUT_planck_grid(
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,DF(_DVARF),   XXXXXXX,XXXXXXX,                 KC_PSCR,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
                               KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL,DF(_QWERTY),   XXXXXXX,XXXXXXX,               KC_NUM,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,XXXXXXX,                XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
                               XXXXXXX,XXXXXXX,                TO(_DVARF), TO(_DVARF), TO(_DVARF), XXXXXXX,XXXXXXX,   TO(_DVARF), TO(_DVARF), TO(_DVARF),XXXXXXX,XXXXXXX
                               ),
  [_FUN2] = LAYOUT_planck_grid(
                               QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,XXXXXXX,                 XXXXXXX,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
                               KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL, XXXXXXX,    XXXXXXX,XXXXXXX,                 XXXXXXX,  KC_F17,  KC_F18,  KC_F19,  KC_F20,
                               QK_RBT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,XXXXXXX,                 XXXXXXX,  KC_F13,  KC_F14,  KC_F15,  KC_F16,
                               XXXXXXX,XXXXXXX,                   TO(_DVARF), TO(_DVARF), TO(_DVARF),  XXXXXXX,XXXXXXX,    TO(_DVARF), TO(_DVARF), TO(_DVARF),XXXXXXX,XXXXXXX
                               )
};
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NAV:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
    switch (keycode) {
        case NUM:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
