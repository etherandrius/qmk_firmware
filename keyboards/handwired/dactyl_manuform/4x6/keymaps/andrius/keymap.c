#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
enum {
    LAYER_QWERTY = 0,
    LAYER_ADJUST,
    LAYER_NUMBER,
    LAYER_NAV,
    LAYER_SYMBOLS,
    LAYER_FN,
};

// Custom keycodes
enum {
    KC_CUSTOM_RESET = SAFE_RANGE,
};
#define KC_CRST KC_CUSTOM_RESET

#define C_LEFT C(KC_LEFT)
#define C_RIGHT C(KC_RIGHT)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Layer switches
#define QWERTY DF(LAYER_QWERTY)
#define NAV MO(LAYER_NAV)
#define SYM OSL(LAYER_SYMBOLS)
#define FN MO(LAYER_FN)
#define SHIFT OSM(MOD_LSFT)

// // Left-hand home row mods
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F CMD_T(KC_F)

// Right-hand home row mods
#define HOME_J CMD_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)

#define NUM_V LT(LAYER_NUMBER, KC_V)
#define NAV_A LT(LAYER_NAV, KC_A)

// Switch to function layer when held, escape when tapped
#define AD_ESC LT(LAYER_ADJUST, KC_ESCAPE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * +-----------------------------------------+                  +-----------------------------------------+
 * |      |   q  |   w  |   e  |   r  |   t  |                  |   y  |   u  |   i  |   o  |   p  |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | ESC  |a|NAV |s|ALT |d|CTL |f|CMD |   g  |                  |   h  |j|CMD |k|CTL |l|ALT |   ;  | ENTR |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |   z  |   x  |   c  |v|NUM |   b  |                  |   n  |   m  |      |      |      |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      | ALT  |                                              |      |      |
 *               +-------------+--------------------+    +--------------------+-------------+
 *                             |SHIFT |SPACE |      |    |      | BCSP | SYM  |
 *                             +--------------------+    +--------------------+
 */
[LAYER_QWERTY] = LAYOUT(
    XXXXXXX,  KC_Q,  KC_W,  KC_E,  KC_R,   KC_T,               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,XXXXXXX,   \
    AD_ESC , NAV_A,HOME_S,HOME_D,HOME_F,   KC_G,               KC_H, HOME_J, HOME_K, HOME_L,KC_SCLN, KC_ENT,   \
    XXXXXXX,  KC_Z ,  KC_X,  KC_C, NUM_V,   KC_B,               KC_N,   KC_M,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,   \
                     NAV ,KC_LALT,                                          XXXXXXX,XXXXXXX,                   \
                                      SHIFT, KC_SPC,            KC_BSPC,   SYM  ,                              \
                             OSL(LAYER_NAV),XXXXXXX,            XXXXXXX,OSL(LAYER_NUMBER),                     \
                                    XXXXXXX,XXXXXXX,              FN   ,  KC_RALT                              \
),

// can we make space and backspace be something else on hold ? How often do we actually hold space and backspace ?


/* Fake SHIFT
 * +-----------------------------------------+                  +-----------------------------------------+
 * |      | Q    | W    | E    | R    | T    |                  | Y    | U    | I    | O    | P    |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | ESC  | A    | S    | D    | F    | G    |                  | H    | J    | K    | L    |      | ENTR |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      | Z    | X    | C    | V    | B    |                  | N    | M    |      |      |      |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              |      |      |
 *               +-------------+                                              +-------------+
 */

/*
[LAYER_SHIFT] = LAYOUT(
    _______,S(KC_Q),S(KC_W),S(KC_E),S(KC_R),S(KC_T),           S(KC_Y),S(KC_U),   S(KC_I),  S(KC_O),   S(KC_P),_______,  \
    _______,S(KC_A),S(KC_S),S(KC_D),S(KC_F),S(KC_G),           S(KC_H),S(KC_J),   S(KC_K),  S(KC_L),S(KC_SCLN),_______,  \
    _______,S(KC_Z),S(KC_X),S(KC_C),S(KC_V),S(KC_B),           S(KC_N),S(KC_M),S(KC_COMM),S(KC_DOT),S(KC_SLSH),_______,  \
                   _______,_______,                                           _______,_______,                           \
                                    _______,_______,           _______,_______,                                          \
                                    _______,_______,           _______,_______,                                          \
                                    _______,_______,           _______,_______                                           \
),
*/

/* Navigation 
 * +-----------------------------------------+                  +-----------------------------------------+
 * |      |      |      |      |      |      |                  |      |CMD+[ |CMD+] |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  | left | down | up   | right|      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  | pgdw | whup | whdw | pgup |      |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              |      |      |
 *               +-------------+                                              +-------------+
 */
[LAYER_NAV] = LAYOUT(
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            XXXXXXX  ,G(KC_LBRC),G(KC_RBRC),XXXXXXX ,XXXXXXX,_______,  \
    _______,XXXXXXX,KC_LALT,KC_LCTL,KC_LCMD,XXXXXXX,            KC_LEFT  ,  KC_DOWN ,  KC_UP   ,KC_RIGHT,XXXXXXX,_______,  \
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            KC_PGDOWN,  KC_WH_U ,  KC_WH_D ,KC_PGUP ,XXXXXXX,_______,  \
                    _______,_______,                                            XXXXXXX,XXXXXXX,                           \
                                    _______,_______,            _______,_______,                                           \
                                    _______,XXXXXXX,            _______,_______,                                           \
                                    _______,_______,            _______,_______                                            \
),

/* Symbol   
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |  ?   |  /   |  !   |  ^   |  ~   |                  |  "   |  [   |  ]   |  +   |   =  |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |  @   |  *   |  $   |  %   |  `   |                  |  '   |  (   |  )   |  -   |   :  | TAB  |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |  &   |  <   |  >   |  #   |                  |  |   |  {   |  }   |  _   |   \  |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              |      |      |
 *               +-------------+--------------------+    +--------------------+-------------+
 *                             |   ,  |  .   |      |    |      |      |  NAV |
 *                             +--------------------+    +--------------------+
 */
[LAYER_SYMBOLS] = LAYOUT(
    _______,S(KC_SLSH),KC_SLSH,S(KC_1),  S(KC_6),S(KC_GRV),         S(KC_QUOT),KC_LBRC,KC_RBRC,  S(KC_EQL),   KC_EQL ,_______,  \
    _______,S(KC_2),S(KC_8),   S(KC_4),  S(KC_5),  KC_GRV ,           KC_QUOT ,S(KC_9),S(KC_0),  KC_MINUS ,S(KC_SCLN),KC_TAB ,  \
    _______,XXXXXXX,S(KC_7),S(KC_COMM),S(KC_DOT),  S(KC_3),         S(KC_BSLS),KC_LCBR,KC_RCBR,S(KC_MINUS),  KC_BSLS ,_______,  \
                    XXXXXXX,XXXXXXX,                                            KC_TAB,XXXXXXX,                                 \
                                    KC_COMM, KC_DOT,            _______,NAV,                                                    \
                                    _______,_______,            XXXXXXX,_______,                                                \
                                    _______,_______,            _______,_______                                                 \
),

/* Function and media controls
 * +-----------------------------------------+                  +-----------------------------------------+
 * |      |  f1  |  f2  |  f3  |  f4  |  f5  |                  |  f6  |  f7  |  f8  |  f9  | f10  | f11  |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  | MUTE | VOL- | VOL+ | PLAY |      | f12  |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  |      | BRI- | BRI+ |      |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              | PREV | NEXT |
 *               +-------------+                                              +-------------+
 */
[LAYER_FN] = LAYOUT(
    _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,              KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11,   \
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            KC_MUTE,KC_VOLD,KC_VOLU,KC_MPLY,XXXXXXX, KC_F12,   \
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            XXXXXXX,KC_BRID,KC_BRIU,XXXXXXX,XXXXXXX,_______,   \
                    XXXXXXX,XXXXXXX,                                            KC_MPRV,KC_MNXT,                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),

/* Base (esc)
   Number layer and reset
 */
[LAYER_NUMBER] = LAYOUT(
    _______,_______,_______,_______,_______,_______,            _______,KC_7,KC_8,KC_9,_______,_______,   \
    _______,_______,_______,_______,_______,_______,            _______,KC_4,KC_5,KC_6,_______,_______,   \
    _______,_______,_______,_______,_______,_______,            _______,KC_1,KC_2,KC_3,_______,_______,   \
                    _______,_______,                                         KC_0,_______,                \
                                    _______,_______,            _______,_______,                          \
                                    _______,XXXXXXX,            XXXXXXX,_______,                          \
                                    _______,_______,            _______,_______                           \
),


/* Base (esc)
   Number layer and reset
 */
[LAYER_ADJUST] = LAYOUT(
    _______,_______,_______,_______,_______,_______,            _______,XXXXXXX,XXXXXXX,XXXXXXX,_______,KC_CRST,   \
    _______,_______,_______,_______,_______,_______,            _______,XXXXXXX,XXXXXXX,XXXXXXX,_______,KC_CRST,   \
    _______,_______,_______,_______,_______,_______,            _______,XXXXXXX,XXXXXXX,XXXXXXX,_______,KC_CRST,   \
                    _______,_______,                                         XXXXXXX,_______,                      \
                                    _______,_______,            _______,_______,                                   \
                                    _______,XXXXXXX,            XXXXXXX,_______,                                   \
                                    _______,_______,            _______,_______                                    \
)
};


void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == KC_CUSTOM_RESET && record->event.pressed) {
        // Send enter then reset the keyboard, so the flash script can proceed
        register_code(KC_ENTER);
        reset_keyboard();
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* case LALT_T(KC_A): */
        /*     return TAPPING_TERM + 150; */
        /* case LALT_T(KC_SCLN): */
        /*     return TAPPING_TERM + 150; */
        default:
            return TAPPING_TERM;
    }
}
