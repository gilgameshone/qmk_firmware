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


enum crkbd_layers {
    _MAGICSTURDY,
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
    _EXT,
    _SYM,
    _FUN1,
    _FUN2,
};

#define NUM LT(_SYM_NUM,KC_BSPC)
#define NAV LT(_NAV_EXT,KC_ENT)
#define MSE MO(_MSE)
#define FUN1 MO(_FUN1)
#define FUN2 MO(_FUN2)


#define PASTE G(KC_V)

#define TRON_NUM LT(_SYM_NUM,KC_BSPC)
#define TRON_NAV MO(_NAV_EXT)


// magic sturdy Left-hand home row mods
#define HSCTL_D LCTL_T(KC_D)
#define HSCMD_R LGUI_T(KC_R)
#define HSOPT_T LALT_T(KC_T)
#define HSSFT_S LSFT_T(KC_S)


// magic sturdy Right-hand home row mods
#define HSCTL_N RCTL_T(KC_N)
#define HSCMD_E RGUI_T(KC_E)
#define HSOPT_A RALT_T(KC_A)
#define HSSFT_I RSFT_T(KC_I)




// TRON Left-hand home row mods // defunct
#define HCTL_TJ_TE TJ_TE
#define HCMD_TJ_KA TJ_KA
#define HOPT_TJ_TO TJ_TO
#define HSFT_TJ_TA TJ_TA


// TRON Right-hand home row mods // defunct
#define HCTL_TJ_I TJ_I
#define HCMD_TJ_U TJ_U
#define HOPT_TJ_SHI TJ_SHI
#define HSFT_TJ_NN TJ_NN



// This keymap uses Ikcelaks' Magic Sturdy layout for the base layer (see
// https://github.com/Ikcelaks/keyboard_layouts). I've also made some twists of
// my own. The "magic" is a key whose function depends on the last pressed key,
// implemented using the Alternate Repeat Key. This key is used to remove the
// top SFBs and type common n-grams.
//
// The following describes the functionality, where * is the magic key and @ the
// repeat key. For example, tapping A and then the magic key types "ao".
//
// SFB removal and common n-grams:
//
//     A * -> AO     L * -> LK      S * -> SK
//     C * -> CY     M * -> MENT    T * -> TMENT
//     D * -> DY     O * -> OA      U * -> UE
//     E * -> EU     P * -> PY      Y * -> YP
//     G * -> GY     Q * -> QUEN    spc * -> THE
//     I * -> ION    R * -> RL
//



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




// magic sturdy

#define C_MAGIC QK_AREP


// super cmd tab
bool is_cmd_tab_active = false; // ADD this near the beginning of keymap.c
uint16_t cmd_tab_timer = 0;     // we will be using them soon.

enum custom_keycodes {
    GOOGL = SAFE_RANGE,
    GTRNS,
    DFINE,
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


// Tap Dance keycodes




// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_SINGLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum  {
  NAV_REP, // Our example key: `NAV` when held, `QK_REP` when tapped. Add additional keycodes for each tapdance.
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void nav_rep_finished(tap_dance_state_t *state, void *user_data);
void nav_rep_reset(tap_dance_state_t *state, void *user_data);



// macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) { 
    // lang switching
  case _EISU:
    if (record->event.pressed) {
      tap_code(KC_LNG2);
    }
    else {
      layer_move(_MAGICSTURDY);
    }
    return false;
  case _ROMAJI:
    if (record->event.pressed) {
      tap_code(KC_LNG1);
    }
    else {
      layer_move(_TRON_ROMAJI_BASE);
    }
    return false;
  case _KANA:
    if (record->event.pressed) {
      tap_code(KC_LNG1);
    }
    else {
      layer_move(_TRON_BASE);
    }
    return false;
    // TJ_GI,
  case TJ_GI:
    if (record->event.pressed) {
      // when keycode TJ_GI is pressed
      SEND_STRING(SS_TAP(X_G));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_GE,
  case TJ_GE:
    if (record->event.pressed) {
      tap_code(KC_QUOT);
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_GU,
  case TJ_GU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_H));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_DZI,
  case TJ_DZI:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_A));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_VU,
  case TJ_VU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_4));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_JI,
  case TJ_JI:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_D));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_ZU,
  case TJ_ZU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_R));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_DZU,
  case TJ_DZU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Z));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_BI,
  case TJ_BI:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_V));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_ZO,
  case TJ_ZO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_C));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_GO,
  case TJ_GO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_B));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_BA,
  case TJ_BA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_BO,
  case TJ_BO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINS));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_DA,
  case TJ_DA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Q));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_DO,
  case TJ_DO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_S));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_GA,
  case TJ_GA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_T));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_DE,
  case TJ_DE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_W));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_BU,
  case TJ_BU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_2));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_ZE,
  case TJ_ZE:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_P));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;
    // TJ_ZA,
  case TJ_ZA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_X));
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;

    // TJ_BE,
  case TJ_BE:
    if (record->event.pressed) {
      tap_code(KC_EQL);
      tap_code(KC_LBRC);
    } else {
      //
    }
    return false;

    // TJ_PA,
  case TJ_PA:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_F));
      tap_code(KC_RBRC);
    } else {
      //
    }
    return false;
    // TJ_PI,
  case TJ_PI:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_V));
      tap_code(KC_RBRC);
    } else {
      //
    }
    return false;
    // TJ_PU,
  case TJ_PU:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_2));
      tap_code(KC_RBRC);
    } else {
      //
    }
    return false;
    // TJ_PE,
  case TJ_PE:
    if (record->event.pressed) {
      tap_code(KC_EQL);
      tap_code(KC_RBRC);
    } else {
      //
    }
    return false;
    // TJ_PO,
  case TJ_PO:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINS));
      tap_code(KC_RBRC);
    } else {
      //
    }
    return false;
    // TJ_LKAGIKAKO,
  case TJ_LKAGIKAKO:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_RBRC) SS_UP(X_LSFT));
    } else {
      //
    }
    return false;
    // TJ_RKAGIKAKO,
  case  TJ_RKAGIKAKO:
    if (record->event.pressed) {
      SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_NUHS) SS_UP(X_LSFT));
    } else {
      //
    }
    return false;
        // tron romaji

  case TRJ_GI:
    if (record->event.pressed) {
      tap_code(KC_G);
      tap_code(KC_I);
    } else {
      //
    }
return false;
      case TRJ_GE:
    if (record->event.pressed) {
      tap_code(KC_G);
      tap_code(KC_E);
    } else {
      //
    }
return false;
      case TRJ_GU:
    if (record->event.pressed) {
      tap_code(KC_G);
      tap_code(KC_U);
    } else {
      //
    }
return false;
  case TRJ_DI:
    if (record->event.pressed) {
      tap_code(KC_D);
      tap_code(KC_I);
    } else {
      //
    }
return false;
      case TRJ_DZI:
    if (record->event.pressed) {
      tap_code(KC_D);
      tap_code(KC_Z);
      tap_code(KC_I);
    } else {
      //
    }
return false;
      case TRJ_VU:
    if (record->event.pressed) {
      tap_code(KC_V);
      tap_code(KC_U);
    } else {
      //
    }
return false;
      case TRJ_JI:
    if (record->event.pressed) {
      tap_code(KC_J);
      tap_code(KC_I);
    } else {
      //
    }
return false;
      case TRJ_ZU:
    if (record->event.pressed) {
      tap_code(KC_Z);
      tap_code(KC_U);
    } else {
      //
    }
return false;
    case TRJ_DZU:
    if (record->event.pressed) {
      tap_code(KC_D);
      tap_code(KC_Z);
      tap_code(KC_U);
    } else {
      //
    }
return false;
      case TRJ_BI:
    if (record->event.pressed) {
      tap_code(KC_B);
      tap_code(KC_I);
    } else {
      //
    }
return false;
      case TRJ_ZO:
    if (record->event.pressed) {
      tap_code(KC_Z);
      tap_code(KC_O);
    } else {
      //
    }
return false;
      case TRJ_GO:
    if (record->event.pressed) {
      tap_code(KC_G);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
      case TRJ_BA:
    if (record->event.pressed) {
      tap_code(KC_B);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
      case TRJ_BO:
    if (record->event.pressed) {
      tap_code(KC_B);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
      case TRJ_DA:
    if (record->event.pressed) {
      tap_code(KC_D);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
      case TRJ_DO:
    if (record->event.pressed) {
      tap_code(KC_D);
      tap_code(KC_O);
    } else {
      //
    }
return false;
      case TRJ_GA:
    if (record->event.pressed) {
      tap_code(KC_G);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
      case TRJ_DE:
    if (record->event.pressed) {
      tap_code(KC_D);
      tap_code(KC_E);
    } else {
      //
    }
    return false;
      case TRJ_BU:
    if (record->event.pressed) {
      tap_code(KC_B);
      tap_code(KC_U);
    } else {
      //
    }
    return false;
          case TRJ_ZE:
    if (record->event.pressed) {
      tap_code(KC_Z);
      tap_code(KC_E);
    } else {
      //
    }
return false;
      case TRJ_ZA:
    if (record->event.pressed) {
      tap_code(KC_Z);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
      case TRJ_BE:
    if (record->event.pressed) {
      tap_code(KC_B);
      tap_code(KC_E);
    } else {
      //
    }
    return false;
          case TRJ_PA:
    if (record->event.pressed) {
      tap_code(KC_P);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
          case TRJ_PI:
    if (record->event.pressed) {
      tap_code(KC_P);
      tap_code(KC_I);
    } else {
      //
    }
    return false;
          case TRJ_PU:
    if (record->event.pressed) {
      tap_code(KC_P);
      tap_code(KC_U);
    } else {
      //
    }
    return false;
          case TRJ_PE:
    if (record->event.pressed) {
      tap_code(KC_P);
      tap_code(KC_E);
    } else {
      //
    }
    return false;
          case TRJ_PO:
    if (record->event.pressed) {
      tap_code(KC_P);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
          case TRJ_RA:
    if (record->event.pressed) {
      tap_code(KC_R);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
      case TRJ_RU:
    if (record->event.pressed) {
      tap_code(KC_R);
      tap_code(KC_U);
    } else {
      //
    }
return false;
          case TRJ_KO:
    if (record->event.pressed) {
      tap_code(KC_K);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
      case TRJ_HA:
    if (record->event.pressed) {
      tap_code(KC_H);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
      case TRJ_XYO:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_Y);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
      case TRJ_KI:
    if (record->event.pressed) {
      tap_code(KC_K);
      tap_code(KC_I);
    } else {
      //
    }
    return false;
      case TRJ_NO:
    if (record->event.pressed) {
      tap_code(KC_N);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
          case TRJ_KU:
    if (record->event.pressed) {
      tap_code(KC_K);
      tap_code(KC_U);
    } else {
      //
    }
    return false;
          case TRJ_RE:
    if (record->event.pressed) {
      tap_code(KC_R);
      tap_code(KC_E);
    } else {
      //
    }
    return false;
          case TRJ_TA:
    if (record->event.pressed) {
      tap_code(KC_T);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
          case TRJ_TO:
    if (record->event.pressed) {
      tap_code(KC_T);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
          case TRJ_KA:
    if (record->event.pressed) {
      tap_code(KC_K);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
          case TRJ_TE:
    if (record->event.pressed) {
      tap_code(KC_T);
      tap_code(KC_E);
    } else {
      //
    }
    return false;
          case TRJ_MO:
    if (record->event.pressed) {
      tap_code(KC_M);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
          case TRJ_WO:
    if (record->event.pressed) {
      tap_code(KC_W);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
          case TRJ_SHI:
    if (record->event.pressed) {
      tap_code(KC_S);
      tap_code(KC_H);
      tap_code(KC_I);
    } else {
      //
    }
    return false;
          case TRJ_NN:
    if (record->event.pressed) {
      tap_code(KC_N);
      tap_code(KC_N);
    } else {
      //
    }
    return false;
          case TRJ_MA:
    if (record->event.pressed) {
      tap_code(KC_M);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
          case TRJ_RI:
    if (record->event.pressed) {
      tap_code(KC_R);
      tap_code(KC_I);
    } else {
      //
    }
    return false;
          case TRJ_NI:
    if (record->event.pressed) {
      tap_code(KC_N);
      tap_code(KC_I);
    } else {
      //
    }
    return false;
          case TRJ_SA:
    if (record->event.pressed) {
      tap_code(KC_S);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
          case TRJ_SU:
    if (record->event.pressed) {
      tap_code(KC_S);
      tap_code(KC_U);
    } else {
      //
    }
    return false;
          case TRJ_TSU:
    if (record->event.pressed) {
      tap_code(KC_T);
      tap_code(KC_S);
      tap_code(KC_U);
    } else {
      //
    }
    return false;
     case TRJ_XTSU:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_T);
      tap_code(KC_S);
      tap_code(KC_U);
    } else {
      //
    }
    return false;
          case TRJ_HI:
    if (record->event.pressed) {
      tap_code(KC_H);
      tap_code(KC_I);
    } else {
      //
    }
    return false;
              case TRJ_SO:
    if (record->event.pressed) {
      tap_code(KC_S);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
              case TRJ_XYA:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_Y);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
          case TRJ_HO:
    if (record->event.pressed) {
      tap_code(KC_H);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
          case TRJ_KE:
    if (record->event.pressed) {
      tap_code(KC_K);
      tap_code(KC_E);
    } else {
      //
    }
    return false;
          case TRJ_ME:
    if (record->event.pressed) {
      tap_code(KC_M);
      tap_code(KC_E);
    } else {
      //
    }
    return false;
case TRJ_MU:
    if (record->event.pressed) {
      tap_code(KC_M);
      tap_code(KC_U);
    } else {
      //
    }
    return false;
case TRJ_RO:
    if (record->event.pressed) {
      tap_code(KC_R);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
case TRJ_NU:
    if (record->event.pressed) {
      tap_code(KC_N);
      tap_code(KC_U);
    } else {
      //
    }
    return false;
case TRJ_NE:
    if (record->event.pressed) {
      tap_code(KC_N);
      tap_code(KC_E);
    } else {
      //
    }
    return false;
case TRJ_XYU:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_Y);
            tap_code(KC_U);
    } else {
      //
    }
    return false;
case TRJ_YO:
    if (record->event.pressed) {
      tap_code(KC_Y);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
case TRJ_FU:
    if (record->event.pressed) {
      tap_code(KC_F);
      tap_code(KC_U);
    } else {
      //
    }
    return false;
case TRJ_CHI:
    if (record->event.pressed) {
      tap_code(KC_C);
      tap_code(KC_H);
            tap_code(KC_I);
    } else {
      //
    }
    return false;
case TRJ_MI:
    if (record->event.pressed) {
      tap_code(KC_M);
      tap_code(KC_I);
    } else {
      //
    }
    return false;
    case TRJ_YA:
    if (record->event.pressed) {
      tap_code(KC_Y);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
case TRJ_XE:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_E);
    } else {
      //
    }
    return false;
case TRJ_XO:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_O);
    } else {
      //
    }
    return false;
    case TRJ_SE:
    if (record->event.pressed) {
      tap_code(KC_S);
      tap_code(KC_E);
    } else {
      //
    }
    return false;
case TRJ_YU:
    if (record->event.pressed) {
      tap_code(KC_Y);
      tap_code(KC_U);
    } else {
      //
    }
    return false;
    case TRJ_HE:
    if (record->event.pressed) {
      tap_code(KC_H);
      tap_code(KC_E);
    } else {
      //
    }
    return false;
    case TRJ_WA:
    if (record->event.pressed) {
      tap_code(KC_W);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
case TRJ_XI:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_I);
    } else {
      //
    }
    return false;
case TRJ_XA:
    if (record->event.pressed) {
      tap_code(KC_X);
      tap_code(KC_A);
    } else {
      //
    }
    return false;
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
    return false;
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
    return false;
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
    return false;
  }
  return true;
}







// combos

const uint16_t PROGMEM combo_capsword[] = {KC_SPC, OSM(MOD_LSFT), COMBO_END};
const uint16_t PROGMEM combo_qkboot[] = {KC_X, HSSFT_S, KC_V, COMBO_END};
const uint16_t PROGMEM combo_qkreboot[] = {KC_P, KC_Y, KC_W, COMBO_END};
const uint16_t PROGMEM combo_qkeeprom[] = {KC_C, HSCTL_D, KC_G, COMBO_END};
const uint16_t PROGMEM combo_fun1[] = {KC_SPC, NUM, COMBO_END};
const uint16_t PROGMEM combo_del[] = {OSM(MOD_LSFT), NAV, COMBO_END};


combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_capsword, CW_TOGG),
  COMBO(combo_qkboot, QK_BOOT),
  COMBO(combo_qkeeprom, EE_CLR),
  COMBO(combo_qkreboot, QK_RBT),
  COMBO(combo_fun1, MO(_FUN1)),
  COMBO(combo_del, KC_DEL),
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
const key_override_t comm_quo_override = ko_make_basic(MOD_MASK_SHIFT, JP_COMM, JP_QUOT);
const key_override_t dot_dquo_override = ko_make_basic(MOD_MASK_SHIFT, JP_DOT, JP_DQUO);
const key_override_t min_ques_override = ko_make_basic(MOD_MASK_SHIFT, JP_MINS, JP_QUES);


const key_override_t **key_overrides = (const key_override_t *[]){
    &comm_quo_override,
    &dot_dquo_override,
    &min_ques_override,
    NULL
};



// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAGICSTURDY] = LAYOUT_split_3x5_3(
        KC_X,     KC_M,    KC_L,    KC_C,    KC_P,                        KC_B,  KC_NUBS,    KC_U,    KC_O,    KC_Q,
        HSSFT_S,  HSOPT_T, HSCMD_R, HSCTL_D, KC_Y,                        KC_F,  HSCTL_N, HSCMD_E, HSOPT_A, HSSFT_I,
        KC_V,     KC_K,    KC_J,    KC_G,    KC_W,                        KC_Z,     KC_H, JP_COMM, JP_DOT,  JP_MINS,
        QK_REP,     NUM,  KC_SPC, OSM(MOD_LSFT),   NAV,  TD(NAV_REP)
  ),
  [_TRON_BASE] = LAYOUT_split_3x5_3(
        TJ_RA,   TJ_RU,   TJ_KO,   TJ_HA,  TJ_XYO,                        TJ_KI,   TJ_NO,   TJ_KU,    TJ_A,   TJ_RE,
        TJ_TA,   TJ_TO,   TJ_KA,   TJ_TE,   TJ_MO,                        TJ_WO,    TJ_I,    TJ_U,  TJ_SHI,   TJ_NN,
        TJ_MA,   TJ_RI,   TJ_NI,   TJ_SA,   TJ_NA,                        TJ_SU,  TJ_TSU,TJ_DOUTEN,TJ_KUTEN,TJ_XTSU,
                            _______,  TRON_NUM,  MO(_TRON_RED), MO(_TRON_BLUE),TRON_NAV,  _______
                         ),
  [_TRON_BLUE] = LAYOUT_split_3x5_3(
        TJ_BI,   TJ_ZO,   TJ_GO,  TJ_BA,    TJ_BO,                         TJ_E,   TJ_KE,   TJ_ME,   TJ_MU,  TJ_RO,
        TJ_DA,   TJ_DO,   TJ_GA,  TJ_DE,    TJ_BU,                         TJ_O,  TJ_CHI,TJ_CHOUONNPU,TJ_MI,  TJ_YA,
        TJ_XE,   TJ_XO,    TJ_ZE,  TJ_ZA,   TJ_BE,                        TJ_WA,   TJ_XI,   TJ_XA, _______,   TJ_XU,
                            _______,  _______, MO(_TRON_PURPLE),    _______, _______, _______
                                    ),
  [_TRON_RED] = LAYOUT_split_3x5_3(
        TJ_HI,   TJ_SO,TJ_NAKAGURO,TJ_XYA,  TJ_HO,                        TJ_GI,   TJ_GE,  TJ_GU,  _______, _______,
        TJ_NU,   TJ_NE,  TJ_XYU,   TJ_YO,   TJ_FU,                         TJ_O,  TJ_DZI,  TJ_VU,    TJ_JI, _______,
        TJ_XE,   TJ_XO,   TJ_SE,   TJ_YU,   TJ_HE,                        TJ_ZU,  TJ_DZU,TJ_LKAGIKAKO,TJ_RKAGIKAKO, TJ_XU,
                            _______,  _______, _______,    MO(_TRON_PURPLE), _______, _______
                                    ),
  [_TRON_PURPLE] = LAYOUT_split_3x5_3(
      TJ_PI,   _______, _______, TJ_PA,  TJ_PO,                         _______, _______, _______, _______, _______,
      _______, _______, _______, _______, TJ_PU,                         KC_SPC, C(JP_J), C(JP_K), C(JP_L), C(JP_SCLN),
      _______, _______, _______, _______, TJ_PE,                        _______, KC_ENT, _______, _______, _______,
                            _______,  _______,  _______,            _______, _______, _______
                                    ),
  [_TRON_ROMAJI_BASE] = LAYOUT_split_3x5_3(
        TRJ_RA, TRJ_RU, TRJ_KO, TRJ_HA, TRJ_XYO,                     TRJ_KI,  TRJ_NO,  TRJ_KU,  TRJ_A,  TRJ_RE,
        TRJ_TA, TRJ_TO, TRJ_KA, TRJ_TE,  TRJ_MO,                     TRJ_WO,   TRJ_I,  TRJ_U, TRJ_SHI,  TRJ_NN,
        TRJ_MA,   TRJ_RI,   TRJ_NI,   TRJ_SA,   TRJ_NA,              TRJ_SU, TRJ_TSU,TRJ_DOUTEN,TRJ_KUTEN,TRJ_XTSU,
                   _______,  TRON_NUM,  MO(_TRON_ROMAJI_RED), MO(_TRON_ROMAJI_BLUE),TRON_NAV,  _______
                                           ),
  [_TRON_ROMAJI_BLUE] = LAYOUT_split_3x5_3(
        TRJ_BI, TRJ_ZO, TRJ_GO, TRJ_BA, TRJ_BO,                      TRJ_E,   TRJ_KE,   TRJ_ME,  TRJ_MU,   TRJ_RO,
        TRJ_DA, TRJ_DO, TRJ_GA, TRJ_DE, TRJ_BU,                      TRJ_O,  TRJ_CHI,TRJ_CHOUONNPU,TRJ_MI, TRJ_YA,
        TRJ_XE, TRJ_XO, TRJ_ZE, TRJ_ZA, TRJ_BE,                     TRJ_WA,   TRJ_XI,   TRJ_XA, _______,   TRJ_XU,
                   _______,  _______, MO(_TRON_ROMAJI_PURPLE),    _______, _______, _______
                                           ),
  [_TRON_ROMAJI_RED] = LAYOUT_split_3x5_3(
       TRJ_HI, TRJ_SO,TRJ_NAKAGURO,TRJ_XYA, TRJ_HO,                 TRJ_GI,   TRJ_GE,  TRJ_GU,  _______, _______,
       TRJ_NU, TRJ_NE, TRJ_XYU, TRJ_YO,  TRJ_FU,                     TRJ_O,  TRJ_DZI,  TRJ_VU,   TRJ_JI, _______,
       TRJ_XE, TRJ_XO,  TRJ_SE, TRJ_YU,  TRJ_HE,                    TRJ_ZU,  TRJ_DZU,TRJ_LKAGIKAKO,TRJ_RKAGIKAKO, TRJ_XU,
                         _______,  _______, _______,   MO(_TRON_ROMAJI_PURPLE), _______, _______
                                           ),
  [_TRON_ROMAJI_PURPLE] = LAYOUT_split_3x5_3(
        TRJ_PI,  _______, _______, TRJ_PA,  TRJ_PO,                    _______, _______, _______, _______, _______,
        _______, _______, _______, _______, TRJ_PU,                     KC_SPC, C(JP_J), C(JP_K), C(JP_L), C(JP_SCLN),
        _______, _______, _______, _______, TRJ_PE,                    _______, KC_ENT, _______, _______, _______,
                               _______,  _______,  _______, _______, _______, _______
   ),
  [_SYM_NUM] = LAYOUT_split_3x5_3(
      JP_QUES, JP_LBRC, JP_RBRC, JP_COLN, C(KC_F2),              JP_PLUS,  KC_7, KC_8, KC_9, JP_ASTR,
      JP_AMPR, JP_LPRN, JP_RPRN, JP_SCLN, JP_AT,                 JP_MINS,  KC_4, KC_5, KC_6, JP_SLSH,
      JP_DQUO, JP_QUOT, JP_UNDS, JP_EXLM, JP_PIPE,                JP_EQL,  KC_1, KC_2, KC_3,    KC_0,
                                  _______,  NUM,  _______,     KC_ENT,  OSL(_SYM), _______
                              ),
  [_NAV_EXT] = LAYOUT_split_3x5_3(
      G(KC_Z), G(KC_X), G(KC_C), PASTE,   LSG(KC_Z),              _______,    _______,   _EISU,   _KANA, _ROMAJI,
      KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, KC_TAB,                 KC_DEL,     KC_RCTL, KC_RGUI, KC_RALT, KC_RSFT,
      KC_HOME, KC_PGUP, KC_PGDN, KC_END,  KC_INS,                 HYPR(KC_B), KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE,
      _______,     KC_ESC, OSL(_EXT),  _______, NAV,  _______
                              ),
  [_EXT] = LAYOUT_split_3x5_3(
      MEH(KC_X), MEH(KC_M), MEH(KC_L), S(LAG(KC_V)),  MEH(KC_P),         LSG(KC_5), _______, _______, _______, _______,
      MEH(KC_S), MEH(KC_T), MEH(KC_R),     MEH(KC_D), HYPR(KC_Y),           _______, _______, _______, _______, _______,
      MEH(KC_V), MEH(KC_K), MEH(KC_J),     MEH(KC_G),  MEH(KC_W),           _______,   GOOGL,   GTRNS,   DFINE, JP_CAPS,
                                  _______,     _______, _______,  MEH(KC_SPC), _______,  _______
                              ),
  [_SYM] = LAYOUT_split_3x5_3(
      JP_ZKHK, JP_MHEN, JP_HENK, JP_KANA, _______,                      LSA(JP_8), JP_HASH, JP_LABK, JP_RABK,   JP_CIRC,
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL, JP_BSLS,                      JP_TILD,   JP_PERC, JP_LCBR, JP_RCBR,    JP_GRV,
      JP_EISU,    FUN2,    FUN1,  KC_LPAD, KC_SCRL,                     KC_NUHS,    JP_YEN,  JP_DLR, A(JP_3), LSA(JP_2),
                                XXXXXXX, XXXXXXX, XXXXXXX,   _______, _______, _______
                              ),
  [_FUN1] = LAYOUT_split_3x5_3(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_PSCR,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
      KC_LSFT, KC_LOPT, KC_LCMD, KC_LCTL, XXXXXXX,                    KC_NUM,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_MAGICSTURDY),          KC_PAUS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                               ),
  [_FUN2] = LAYOUT_split_3x5_3(
     S(KC_F21), S(KC_F22), S(KC_F23), S(KC_F24), S(KC_F10),          XXXXXXX,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
     S(KC_F17), S(KC_F18), S(KC_F19), S(KC_F20), S(KC_F11),          XXXXXXX,  KC_F17,  KC_F18,  KC_F19,  KC_F20,
     S(KC_F13), S(KC_F14), S(KC_F15), S(KC_F16), S(KC_F12),          XXXXXXX,  KC_F13,  KC_F14,  KC_F15,  KC_F16,
                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
                               )
};


// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    }
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t nav_rep_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void nav_rep_finished(tap_dance_state_t *state, void *user_data) {
    nav_rep_tap_state.state = cur_dance(state);
    switch (nav_rep_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code16(QK_REP);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_NAV_EXT);
            break;
        default:
            break;
    }
}

void nav_rep_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (nav_rep_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_NAV_EXT);
    }
    nav_rep_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [NAV_REP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_rep_finished, nav_rep_reset)
};

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case KC_C: return KC_O;
        case KC_P: return KC_E;
        case KC_G: return KC_Y;
    }

    return KC_TRNS;
}


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM:
            return TAPPING_TERM - 80;
        case NAV:
            return TAPPING_TERM - 80;
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case NUM:
    // Immediately select the hold action when another key is tapped.
    return true;
  case NAV:
    return true;
  default :
    // Do not select the hold action when another key is tapped.
    return false;
  }
  return true;
}




// OLED STUFF

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_0;
    } else {
        return rotation;
    }
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
  DISPLAY_LAYER_NAME(_SYM, "SYM");
  DISPLAY_LAYER_NAME(_EXT, "EXT");
  DISPLAY_LAYER_NAME(_NAV_EXT, "NAV EXT");
  DISPLAY_LAYER_NAME(_SYM_NUM, "SYM NUM");
  DISPLAY_LAYER_NAME(_MAGICSTURDY, "MAGIC STURDY");
  DISPLAY_LAYER_NAME(_TRON_BASE, "TRON BASE");
  DISPLAY_LAYER_NAME(_TRON_BLUE, "TRON BLUE");
  DISPLAY_LAYER_NAME(_TRON_RED, "TRON RED");
  DISPLAY_LAYER_NAME(_TRON_PURPLE, "TRON PURPLE");
  DISPLAY_LAYER_NAME(_TRON_ROMAJI_BASE, "TRON ROMAJI BASE");
  DISPLAY_LAYER_NAME(_TRON_ROMAJI_BLUE, "TRON ROMAJI BLUE");
  DISPLAY_LAYER_NAME(_TRON_ROMAJI_RED, "TRON ROMAJI RED");
  DISPLAY_LAYER_NAME(_TRON_ROMAJI_PURPLE, "TRON ROMAJI PURPLE");
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


void render_keylock_status(led_t led_state) {
    oled_write_P(PSTR("Lock:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_ln_P(PSTR("S"), led_state.scroll_lock);
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
    render_keylock_status(host_keyboard_led_state());
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
