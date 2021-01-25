#include QMK_KEYBOARD_H
#define _____  KC_TRNS
#define __x__  KC_NO
#define xx_SPC MT(MOD_LSFT,KC_SPC)
#define xx_Z   MT(MOD_LSFT,KC_Z)

#define _SYM 1
#define _NAV 2
#define _PAD 3
#define _FUN 4
#define _GAM 5

/* Macros */
enum custom_keycodes {
  MC_MUTE = SAFE_RANGE,
  MC_SHOT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   * Base       ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
   *            │ q  │ w  │ f  │ p  │ b  │     │ j  │ l  │ u  │ y  │ ⌫  │
   *            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   *            │ a  │ r  │ s  │ t  │ g  │     │ m  │ n  │ e  │ i  │ o  │ 
   *            ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   *            │ z ⇧│ x  │ c  │ d  │ v  │     │ k  │ h  │ ,  │ .  │ ⇧  │
   *            └────┴────┴────┼────┴────┴─────┴────┴────┼────┴────┴────┘
   *            │ ⌃  │ ⌥  │ ⌘  │sym │   ␣  ⇧│   ␣   │nav │ pad│ m⁰ │ ↵  │
   *            └────┴────┴─── └────┴───────┴───────┴────┘ ───┴────┴────┘
   */
  [0] = LAYOUT_planck_2x2u(
    KC_Q,    KC_W,    KC_F,    KC_P,      KC_B, __x__,  __x__,  KC_J, KC_L,     KC_U,     KC_Y,    KC_BSPC,
    KC_A,    KC_R,    KC_S,    KC_T,      KC_G, __x__,  __x__,  KC_M, KC_N,     KC_E,     KC_I,    KC_O,
    xx_Z,    KC_X,    KC_C,    KC_D,      KC_V, __x__,  __x__,  KC_K, KC_H,     KC_COMM,  KC_DOT,  KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, OSL(_SYM), /**/  xx_SPC, KC_SPC, /**/  MO(_NAV), MO(_PAD), MC_MUTE, KC_ENT
  ),

  /*
   * ┌┄┄┄┄┐    Symbols (lower)
   * ┆sym ┆┄┐  ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
   * └┄┄┄┄┘ └› │ '  │ "  │ ^  │ ?  │ `  │ quo │ [  │ <  │ =  │ >  │ ]  │ brace
   *           ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   *           │ !  │ @  │ #  │ $  │ %  │ 123 │ {  │ (  │ :  │ )  │ }  │
   *           ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   *           │ \  │ ~  │ |  │ &  │ ;  │ etc │ /  │ *  │ -  │ +  │ _  │ math
   *           └────┴────┴────┼────┼────┘     └────┴────┴────┴────┴────┘
   *                          │ ▓▓ │     
   *                          └────┘
   */
  [_SYM] = LAYOUT_planck_2x2u(
    KC_QUOT, KC_DQUO, KC_CIRC, KC_QUES, KC_GRV,  __x__, __x__, KC_LBRC, KC_LT,    KC_EQL,  KC_GT,   KC_RBRC,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, __x__, __x__, KC_LCBR, KC_LPRN,  KC_COLN, KC_RPRN, KC_RCBR,
    KC_SCLN, KC_TILD, KC_PIPE, KC_AMPR, KC_BSLS, __x__, __x__, KC_PSLS, KC_PAST,  KC_PMNS, KC_PPLS, KC_UNDS,
    _____,   _____,   _____,   _____,   /**/     _____, _____, /**/     MO(_FUN), _____,   _____,   _____
  ),

  /*
   * ┌┄┄┄┄┐    Navigation (raise)
   * ┆nav ┆┄┐  ┌────┬────┬────┬────┬────┐     ┌────┎━━━━┯━━━━┯━━━━┓────┐
   * └┄┄┄┄┘ └› │ ⎋  │ ,  │ .  │ :  │ -  │     │pg↑ ┃home│ ▲  │end ┃ ⌃  │
   *           ├────┼────┼────┼────┼────┤     ├────┃────┼────┼────┃────┤
   *           │ 1  │ 2  │ 3  │ 4  │ 5  │     │pg↓ ┃ ◀  │ ▼  │ ▶  ┃ ↵  │
   *           ├────┼────┼────┼────┼────┤     ├────┗━━━━┷━━━━┷━━━━┛────┤
   *           │ 6  │ 7  │ 8  │ 9  │ 0  │     │    │ ⌃⌫ │ ⌫  │ ↹  │    │
   *           └────┴────┴────┴────┴────┘     └────┼────┼────┴────┴────┘
   *                                               │ ▓▓ │
   *                                               └────┘
   */
  [_NAV] = LAYOUT_planck_2x2u(
    KC_ESC,  KC_COMM, KC_DOT, KC_COLN,  KC_MINS, __x__, __x__, KC_PGUP, KC_HOME,    KC_UP,   KC_END,  KC_LCTL,
    KC_1,    KC_2,    KC_3,   KC_4,     KC_5,    __x__, __x__, KC_PGDN, KC_LEFT,    KC_DOWN, KC_RGHT, KC_ENT,
    KC_6,    KC_7,    KC_8,   KC_9,     KC_0,    __x__, __x__, KC_ESC,  C(KC_BSPC), KC_BSPC, KC_TAB,  __x__,
    _____,   _____,   _____,  MO(_FUN), /**/     _____, _____, /**/     _____,      _____,   _____,   _____
  ),

  /*
   * ┌┄┄┄┄┐    Numpad and macros
   * ┆pad ┆┄┐  ┌────┬────┬────┬────┬────┐     ┌────┏━━━━┯━━━━┯━━━━┓────┐
   * └┄┄┄┄┘ └› │    │    │ .  │    │    │     │ :  ┃ 1  │ 2  │ 3  ┃ /  │
   *           ├────┼────┼────┼────┼────┤     ├────┃────┼────┼────┃────┤
   *           │bck │hom │caps│cmbt│    │     │ -  ┃ 4  │ 5  │ 6  ┃ +  │
   *           ├────┼────┼────┼────┼────┤     ├────┃────┼────┼────┃────┤
   *           │    │    │    │    │ m¹ │     │ 0  ┃ 7  │ 8  │ 9  ┃ *  │
   *           └────┴────┴────┴────┴────┘     └────┗━━━━┷━━━━┷━━━━┛────┘
   *                                                    │ ▓▓ │     _gam
   *                                                    └────┘
   */
  [_PAD] = LAYOUT_planck_2x2u(
    __x__,       __x__,       KC_DOT,  __x__,   __x__,   __x__, __x__, KC_COLN, KC_1,  KC_2,  KC_3,  KC_PSLS,
    KC_WWW_BACK, KC_WWW_HOME, KC_CAPS, CMB_TOG, __x__,   __x__, __x__, KC_PMNS, KC_4,  KC_5,  KC_6,  KC_PPLS,
    __x__,       __x__,       __x__,   __x__,   MC_SHOT, __x__, __x__, KC_0,    KC_7,  KC_8,  KC_9,  KC_PAST,
    _____,       _____,       _____,   _____,   /**/     _____, _____, /**/     _____, _____, _____, DF(_GAM)
  ),

  /*
   * ┌┄┄┄┄┐    Function
   * ┆sym ┆    ┌────┌────┬────┐────┬────┐     ┌────┬────┬────┬────┬────┐
   * └┄┄┬┄┘    │rset│f₁₁ │f₁₂ │rmb │lmb │     │ w↑ │play│ △  │next│vol⁺│
   *    +┄┄›   ┌────┼────┼────┼────┬────┐     ├────┼────┼────┼────┼────┤
   * ┌┄┄┴┄┐    │ f₁ │ f₂ │ f₃ │ f₄ │ f₅ │     │ w↓ │ ◁  │ ▽  │ ▷  │vol⁻│
   * ┆nav ┆    ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   * └┄┄┄┄┘    │ f₆ │ f₇ │ f₈ │ f₉ │f₁₀ │     │    │    │rgb │scr⁻│scr⁺│
   *           └────┴────┴────┼────┼────┘     └────┼────┼────┴────┴────┘
   *                          │ ▓▓ │               │ ▓▓ │    media controls &
   *                          └────┘               └────┘          mouse keys
   */
  [_FUN] = LAYOUT_planck_2x2u(
    RESET, KC_F11, KC_F12, KC_MS_BTN2, KC_MS_BTN1, __x__, __x__, KC_WH_U, KC_MPLY, KC_MS_U, KC_MNXT, KC_VOLU,
    KC_F1, KC_F2,  KC_F3,  KC_F4,      KC_F5,      __x__, __x__, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_VOLD,
    KC_F6, KC_F7,  KC_F8,  KC_F9,      KC_F10,     __x__, __x__, __x__,   __x__,   RGB_TOG, KC_BRID, KC_BRIU,
    _____, _____,  _____,  _____,      /**/        _____, _____, /**/     _____,   _____,   _____,   _____
  ),

  /*
   * ┌┄┄┄┄┐    Gaming mode
   * ┆gam ┆┄┐  ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
   * └┄┄┄┄┘ └› │ ↹  │ q  │ w  │ e  │ r  │     │ t  │ y  │ u  │ ▲  │ ⎋  │
   *           ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   *           │ ⇧  │ a  │ s  │ d  │ f  │     │ g  │ h  │ ◀  │ ▼  │ ▶  │
   *           ├────┼────┼────┼────┼────┤     ├────┼────┼────┼────┼────┤
   *           │ ^  │ 1  │ 2  │ 3  │ 4  │     │ 5  │ 6  │    │    │ ↵  │
   *           ├────┴────┴────┴────┴────┘─────└────┴────┴────┴────┴────┤
   *           │ z  │ x  │ c  │ v  │   ␣   │  ⌘    │ b  │ n  │ m  │exit│
   *           └────┴────┴─── └────┴───────┴───────┴────┘ ───┴────┴──●─┘
   *                             press to return to the base layer ──┘
   */
  [_GAM] = LAYOUT_planck_2x2u(
      KC_TAB,  KC_Q, KC_W, KC_E, KC_R, __x__,  __x__,   KC_T, KC_Y, KC_U,    KC_UP,   KC_ESC,
      KC_LSFT, KC_A, KC_S, KC_D, KC_F, __x__,  __x__,   KC_G, KC_H, KC_LEFT, KC_DOWN, KC_RGHT,
      KC_LCTL, KC_1, KC_2, KC_3, KC_4, __x__,  __x__,   KC_5, KC_6, __x__,   __x__,   KC_ENT,
      KC_Z,    KC_X, KC_C, KC_V, /**/  KC_SPC, KC_LALT, /**/  KC_B, KC_N,    KC_M,    DF(0)
  ),

  /* Reserved */
  [6] = LAYOUT_planck_2x2u(
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, _____,
    _____, _____, _____, _____, _____, _____, _____, _____, _____, _____
  )
};

/*
 *                                 Chords
 *  ┌────┬────┬────┬────┬────┐     ┌────┬────┬────┬────┬────┐
 *  │ z  │ x  │ c  │ d  │ v  │     │ k  │ h  │ ,  │ .  │    │
 *  └────┴────┴──┆─┴──┆─┴────┘     └┆───┴┆───┴┆───┴───┆┴────┘
 *               └  ⌃ ┘             └ '  ┴ ⌃  ┘       ┆
 *                                       └ ⌫ ┄┄┄┄┄┄┄┄┄┘
 */
enum combos { CM_0, CM_1, CM_2, CM_3, CM_4, CM_5 };

const uint16_t PROGMEM combo_0[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_1[] = {KC_H, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_2[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_3[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM combo_4[] = {KC_8, KC_9, COMBO_END};
const uint16_t PROGMEM combo_5[] = {KC_K, KC_H, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CM_0] = COMBO(combo_0, KC_ENT),
  [CM_1] = COMBO(combo_1, C(KC_BSPC)),
  [CM_2] = COMBO(combo_2, KC_LCTL),
  [CM_3] = COMBO(combo_3, KC_LCTL),
  [CM_4] = COMBO(combo_4, KC_LCTL),
  [CM_5] = COMBO(combo_5, KC_QUOT)
};

// https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#ignore-mod-tap-interrupt
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MT(MOD_LCTL,KC_Q):
    case MT(MOD_LSFT,KC_Z):
    case MT(MOD_RSFT,KC_QUOT):
    case MT(MOD_LSFT,KC_6):
      return true;
    default:
      return false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MC_MUTE:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_LALT("a")));
        }
        break;
    case MC_SHOT:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_LCTL(SS_LALT("4"))));
        }
        break;
    }
    return true;
};
