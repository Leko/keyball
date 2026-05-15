/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

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

#include "quantum.h"

#define PRINT_SCREEN_COPY LSFT(LCTL(LCMD(KC_4)))
#define PRINT_SCREEN_FILE LALT(PRINT_SCREEN_COPY)
#define MV_WINDOW_3RD_L LALT(LCMD(KC_LEFT))
#define MV_WINDOW_3RD_C LALT(LCMD(KC_DOWN))
#define MV_WINDOW_3RD_R LALT(LCMD(KC_RIGHT))
#define MV_WINDOW_HARF_L LALT(KC_LEFT)
#define MV_WINDOW_HARF_R LALT(KC_RIGHT)
#define MV_WINDOW_MAX LALT(KC_UP)
#define HK_CHATGPT LALT(KC_SPC)

#define L_DEFAULT 0
#define L_SYMBOLS 1
#define L_SYSTEM 2
#define L_M_SCROLL 3

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  // [0] = LAYOUT_universal(
  //   KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                        KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_DEL   ,
  //   KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                        KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  , S(KC_7)  ,
  //   KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                        KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_INT1  ,
  //             KC_LALT,KC_LGUI,LCTL_T(KC_LNG2)     ,LT(1,KC_SPC),LT(3,KC_LNG1),                  KC_BSPC,LT(2,KC_ENT), RCTL_T(KC_LNG2),     KC_RALT  , KC_PSCR
  // ),
  [L_DEFAULT] = LAYOUT_universal(
    KC_TAB,          KC_Q, KC_W,       KC_E,    KC_R           , KC_T         ,                 /*|*/                       KC_Y,    KC_U,    KC_I,            KC_O,   KC_P,         KC_MINUS,
    LCTL_T(KC_ESC),  KC_A, KC_S,       KC_D,    KC_F           , KC_G         ,                 /*|*/                       KC_H,    KC_J,    KC_K,            KC_L,   KC_SEMICOLON, KC_QUOTE,
    LSFT_T(KC_LNG1), KC_Z, KC_X,       KC_C,    KC_V           , KC_B         ,                 /*|*/                       KC_N,    KC_M,    KC_COMMA,        KC_DOT, KC_SLASH,     MO(L_M_SCROLL),
                           HK_CHATGPT, XXXXXXX, LCMD_T(KC_LNG2), LT(L_SYMBOLS, KC_SPC), KC_SPC, /*|*/ KC_ENT, KC_BACKSPACE, _______, _______, MO(L_SYSTEM)
  ),
  // [1] = LAYOUT_universal(
  //   SSNP_FRE ,  KC_F1   , KC_F2    , KC_F3   , KC_F4    , KC_F5    ,                                         KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
  //   SSNP_VRT ,  _______ , _______  , KC_UP   , KC_ENT   , KC_DEL   ,                                         KC_PGUP  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_BTN3  , KC_F12   ,
  //   SSNP_HOR ,  _______ , KC_LEFT  , KC_DOWN , KC_RGHT  , KC_BSPC  ,                                         KC_PGDN  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,
  //                 _______  , _______ , _______  ,         _______  , _______  ,                   _______  , _______  , _______       , _______  , _______
  // ),
  [L_SYMBOLS] = LAYOUT_universal(
    KC_GRAVE, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),          /*|*/                  S(KC_6), S(KC_7), S(KC_8),     S(KC_9),         S(KC_0),          KC_EQUAL,
    KC_LCTL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             /*|*/                  XXXXXXX, XXXXXXX, KC_MINUS,    KC_LEFT_BRACKET, KC_RIGHT_BRACKET, KC_BACKSLASH,
    KC_LSFT,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,             /*|*/                  XXXXXXX, XXXXXXX, S(KC_COMMA), S(KC_DOT),       S(KC_SLASH),      _______,
                       _______, _______, _______, _______, _______, /*|*/ _______, KC_ESC, _______, _______, _______
  ),

  // [2] = LAYOUT_universal(
  //   _______  ,S(KC_QUOT), KC_7     , KC_8    , KC_9     , S(KC_8)  ,                                         S(KC_9)  , S(KC_1)  , S(KC_6)  , KC_LBRC  , S(KC_4)  , _______  ,
  //   _______  ,S(KC_SCLN), KC_4     , KC_5    , KC_6     , KC_RBRC  ,                                         KC_NUHS  , KC_MINS  , S(KC_EQL), S(KC_3)  , KC_QUOT  , S(KC_2)  ,
  //   _______  ,S(KC_MINS), KC_1     , KC_2    , KC_3     ,S(KC_RBRC),                                        S(KC_NUHS),S(KC_INT1), KC_EQL   ,S(KC_LBRC),S(KC_SLSH),S(KC_INT3),
  //                 KC_0     , KC_DOT  , _______  ,         _______  , _______  ,                   KC_DEL   , _______  , _______       , _______  , _______
  // ),
  [L_SYSTEM] = LAYOUT_universal(
    XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX, XXXXXXX,               /*|*/                   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KBC_RST,
    XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX, XXXXXXX,               /*|*/                   CPI_I1K, CPI_I100, SCRL_DVI, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX,           XXXXXXX, XXXXXXX,               /*|*/                   CPI_D1K, CPI_D100, SCRL_DVD, XXXXXXX, XXXXXXX, KBC_SAVE,
                      PRINT_SCREEN_COPY, PRINT_SCREEN_FILE, XXXXXXX, XXXXXXX, LCMD(KC_SPC), /*|*/ XXXXXXX, XXXXXXX, _______, _______,  _______
  ),

  // [3] = LAYOUT_universal(
  //   RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                        RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
  //   RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,                                        RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
  //   RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
  //                 QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
  // ),
  [L_M_SCROLL] = LAYOUT_universal(
    _______, _______, _______, _______, _______, _______,          /*|*/                   RGB_M_P,          RGB_M_B,          RGB_M_R,         RGB_M_SW, RGB_M_SN, RGB_M_K,
    _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          /*|*/                   MV_WINDOW_3RD_L,  MV_WINDOW_3RD_C,  MV_WINDOW_3RD_R, KC_UP,    _______,  KC_SYSTEM_SLEEP,
    _______, KC_MRWD, KC_MPRV, KC_MPLY, KC_MNXT, KC_MFFD,          /*|*/                   MV_WINDOW_HARF_L, MV_WINDOW_HARF_R, KC_LEFT,         KC_DOWN,  KC_RIGHT, _______,
                      RGB_TOG, RGB_MOD, _______, _______, _______, /*|*/ KC_BTN1, KC_BTN2, _______,          _______,          _______
  ),
  // KBC_RST	0x5DA5	Keyball設定のリセット
  // KBC_SAVE	0x5DA6	現在のKeyball設定をEEPROMに保存します
  // CPI_I100	0x5DA7	CPIを100増加させます(最大:12000)
  // CPI_D100	0x5DA8	CPIを100減少させます(最小:100)
  // CPI_I1K	0x5DA9	CPIを1000増加させます(最大:12000)
  // CPI_D1K	0x5DAA	CPIを1000減少させます(最小:100)
  // SCRL_TO	0x5DAB	タップごとにスクロールモードのON/OFFを切り替えます
  // SCRL_MO	0x5DAC	キーを押している間、スクロールモードになります
  // SCRL_DVI	0x5DAD	スクロール除数を１つ上げます(max D7 = 1/128)←最もスクロール遅い
  // SCRL_DVD	0x5DAE	スクロール除数を１つ下げます(min D0 = 1/1)←最もスクロール速い
  [AUTO_MOUSE_DEFAULT_LAYER] = LAYOUT_universal(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          /*|*/                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          /*|*/                   XXXXXXX, XXXXXXX, KC_BTN1, XXXXXXX, KC_BTN2, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          /*|*/                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                      XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, /*|*/ XXXXXXX, XXXXXXX, _______, _______, _______
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    // keyball_set_scroll_mode(get_highest_layer(state) == 3);
    switch(get_highest_layer(remove_auto_mouse_layer(state, true))) {
      case 3:
        // Auto enable scroll mode when the highest layer is 3
        // remove_auto_mouse_target must be called to adjust state *before* setting enable
        state = remove_auto_mouse_layer(state, false);
        set_auto_mouse_enable(false);
        keyball_set_scroll_mode(true);
        break;
      default:
        set_auto_mouse_enable(true);
        keyball_set_scroll_mode(false);
        break;
    }
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

void pointing_device_init_user(void) {
  set_auto_mouse_layer(AUTO_MOUSE_DEFAULT_LAYER); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
  // set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}
