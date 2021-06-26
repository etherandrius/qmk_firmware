#include QMK_KEYBOARD_H
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
/*
#define _QWERTY 0
#define _ADJUST 1
#define _NUMBER 2
#define _NAV 3
#define _SYMBOL 4
#define _FN 4
*/

enum {
    LAYER_QWERTY = 0,
    LAYER_ADJUST,
    LAYER_NUMBER,
    LAYER_NAV,
    LAYER_SYMBOLS,
    LAYER_FN,
};

enum custom_keycodes {
  BACKLIT = SAFE_RANGE,
  RGBRST
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

#define KC_XXXXX KC_NO
#define KC_GUIEI GUI_T(KC_LANG2)
#define KC_ALTKN ALT_T(KC_LANG1)

#define KC_FN MO(LAYER_FN)
#define KC_ADJUST MO(LAYER_ADJUST)
#define KC_SHIFT OSM(MOD_LSFT)
#define KC_SYM OSL(LAYER_SYMBOLS)

// // Left-hand home row mods
#define KC_HOME_S LALT_T(KC_S)
#define KC_HOME_D LCTL_T(KC_D)
#define KC_HOME_F CMD_T(KC_F)

// Right-hand home row mods
#define KC_HOME_J CMD_T(KC_J)
#define KC_HOME_K RCTL_T(KC_K)
#define KC_HOME_L LALT_T(KC_L)

#define KC_NUM_V LT(LAYER_NUMBER, KC_V)
#define KC_NAV_A LT(LAYER_NAV, KC_A)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_QWERTY] = LAYOUT_kc( \
      XXXXX,     Q,     W,     E,     R,     T,                      Y,     U,     I,     O,     P, XXXXX,\
      XXXXX, NAV_A,HOME_S,HOME_D,HOME_F,     G,                      H,HOME_J,HOME_K,HOME_L,   SCLN,XXXXX,\
      XXXXX,     Z,     X,     C, NUM_V,     B,                      N,     M,  ENT ,   TAB,   ESC ,XXXXX,\
                           ADJUST, SHIFT,   SPC,                   BSPC,   SYM, FN \
  ),

  [LAYER_NAV] = LAYOUT( \
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            XXXXXXX  ,G(KC_LBRC),G(KC_RBRC),XXXXXXX ,XXXXXXX,_______,  \
    _______,XXXXXXX,KC_LALT,KC_LCTL,KC_LCMD,XXXXXXX,            KC_LEFT  ,  KC_DOWN ,  KC_UP   ,KC_RIGHT,XXXXXXX,_______,  \
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            KC_PGDOWN,  KC_WH_U ,  KC_WH_D ,KC_PGUP ,XXXXXXX,_______,  \
                            _______,_______,_______,            _______  ,_______   ,_______ \
  ),

  [LAYER_SYMBOLS] = LAYOUT( \
    _______,S(KC_SLSH),KC_SLSH,S(KC_1),  S(KC_6),S(KC_GRV),         S(KC_QUOT),KC_LBRC,KC_RBRC,  S(KC_EQL),   KC_EQL ,_______,  \
    _______,S(KC_2),S(KC_8),   S(KC_4),  S(KC_5),  KC_GRV ,           KC_QUOT ,S(KC_9),S(KC_0),  KC_MINUS ,S(KC_SCLN),KC_TAB ,  \
    _______,XXXXXXX,S(KC_7),S(KC_COMM),S(KC_DOT),  S(KC_3),         S(KC_BSLS),KC_LCBR,KC_RCBR,S(KC_MINUS),  KC_BSLS ,_______,  \
                               _______,  KC_COMM,   KC_DOT,          _______  ,_______,_______ \
  ),


  [LAYER_NUMBER] = LAYOUT(
    _______,_______,_______,_______,_______,_______,            KC_PAST,KC_P7,KC_P8,KC_P9,S(KC_EQL),_______,   \
    _______,_______,_______,_______,_______,_______,            KC_PSLS,KC_P4,KC_P5,KC_P6,KC_MINUS,_______,   \
    _______,_______,_______,_______,_______,_______,            KC_DOT ,KC_P1,KC_P2,KC_P3,KC_EQL,_______,   \
                              _______,_______,_______,            _______,_______,KC_P0 \
  ),

  [LAYER_FN] = LAYOUT(
      _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,              KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11,   \
      _______, KC_F11, KC_F12,XXXXXXX,XXXXXXX,XXXXXXX,            KC_MUTE,KC_VOLD,KC_VOLU,KC_MPLY,XXXXXXX, KC_F12,   \
      _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            XXXXXXX,KC_BRID,KC_BRIU,KC_MPRV,KC_MNXT,_______,   \
                              _______,_______,_______,            _______,_______,_______ \
  ),

  [LAYER_ADJUST] = LAYOUT(
      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,\
      XXXXXXX,RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,XXXXXXX,                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,\
      XXXXXXX,RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,XXXXXXX,                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,\
                              _______,_______,_______,                _______,_______,_______ \
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    /* case RGB_MOD: */
    /*   #ifdef RGBLIGHT_ENABLE */
    /*     if (record->event.pressed) { */
    /*       rgblight_mode(RGB_current_mode); */
    /*       rgblight_step(); */
    /*       RGB_current_mode = rgblight_config.mode; */
    /*     } */
    /*   #endif */
    /*   return false; */
    /* case RGBRST: */
    /*   #ifdef RGBLIGHT_ENABLE */
    /*     if (record->event.pressed) { */
    /*       eeconfig_update_rgblight_default(); */
    /*       rgblight_enable(); */
    /*       RGB_current_mode = rgblight_config.mode; */
    /*     } */
    /*   #endif */
    /*   break; */
  }

  return true;
}
