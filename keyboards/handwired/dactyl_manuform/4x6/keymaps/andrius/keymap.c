#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
enum {
    LAYER_QWERTY = 0,
    LAYER_ADJUST,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_RAISE_LOWER,
    LAYER_FN,
    LAYER_MOUSE,
    LAYER_MOUSE_ASSIST,
    LAYER_TEST,
};

// Custom keycodes
enum {
    KC_CUSTOM_RESET = SAFE_RANGE,
    KC_ROUND_POINTY,
    KC_CURLY_BRACKETS,
    KC_BLOCK_BRACKETS,
    KC_ROUND_BRACKETS,
    KC_POINT_BRACKETS,
};
#define KC_CRST KC_CUSTOM_RESET

#define KC_RP KC_ROUND_POINTY

#define KC_CBR KC_CURLY_BRACKETS
#define KC_BBR KC_BLOCK_BRACKETS
#define KC_RBR KC_ROUND_BRACKETS
#define KC_PBR KC_POINT_BRACKETS


#define C_LEFT C(KC_LEFT)
#define C_RIGHT C(KC_RIGHT)

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Fillers to make layering more clear

// Layer switches
#define QWERTY DF(LAYER_QWERTY)
#define MOUSE_A DF(LAYER_MOUSE_ASSIST)
#define LOWER MO(LAYER_LOWER)
#define RAISE MO(LAYER_RAISE)
#define RA_LO MO(LAYER_RAISE_LOWER)
#define FN MO(LAYER_FN)
#define MOUSE DF(LAYER_MOUSE)

#define TEST MO(LAYER_TEST)

// Switch to function layer when held, escape when tapped
#define AD_ESC LT(LAYER_ADJUST, KC_ESCAPE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * +-----------------------------------------+                  +-----------------------------------------+
 * | `    |   q  |   w  |   e  |   r  |   t  |                  |   y  |   u  |   i  |   o  |   p  | DEL  |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | ESC  |   a  |   s  |   d  |   f  |   g  |                  |   h  |   j  |   k  |   l  |   ;  |  '   |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |SHIFT |   z  |   x  |   c  |   v  |   b  |                  |   n  |   m  |   ,  |   .  |   /  |SHIFT |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |   -  |   +  |                                              | MOUSE|   \  |
 *               +-------------+-------------+                  +-------------+-------------+
 *                             |ETNER | BCSP |                  |SPACE | TAB  |
 *                             |------+------|                  |------+------|
 *                             | CTRL |LOWER |                  |RAISE | ALT  |
 *                             |------+------|                  |------+------|
 *                             | SHFT |SUPER |                  | FN   | META |
 *                             +-------------+                  +-------------+
 */

[LAYER_QWERTY] = LAYOUT(
     RAISE ,  KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_DEL,   \
    AD_ESC ,  KC_A,  KC_S,   KC_D,   KC_F,   KC_G,               KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,  \
    KC_LSFT,  KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,               KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,   \
                     KC_MINUS,KC_EQL,                                             MOUSE  ,KC_BSLS,                 \
                                    KC_ENT ,KC_BSPC ,             KC_SPC,  KC_TAB ,                                \
                                    KC_LCTL,  LOWER ,             RAISE ,  KC_LALT,                                \
                                    KC_LSFT,  TEST  ,              FN   ,  KC_LGUI                                 \
),

/* Base (lower)
 * +-----------------------------------------+                  +-----------------------------------------+
 * |      |   1  |   2  |   3  |   4  |   5  |                  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                  | left | down | up   | right|      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |   6  |   7  |   8  |   9  |   0  |                  |      |      |      |      |      |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              |      |      |
 *               +-------------+                                              +-------------+
 */
[LAYER_LOWER] = LAYOUT(
    _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,_______,  \
    _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,            KC_LEFT,KC_DOWN, KC_UP ,KC_RIGHT,_______,_______, \
    _______,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,            XXXXXXX,XXXXXXX,_______,_______,_______,_______,  \
                    XXXXXXX,XXXXXXX,                                            XXXXXXX,XXXXXXX,                   \
                                    MOUSE_A,_______,            _______,_______,                                   \
                                    _______,XXXXXXX,             RA_LO ,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),

/* Base (raise)
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |  !   |  ^   |  ~   |                  |      |  {   |  }   |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |  @   |  *   |  $   |  %   |  `   |                  |      |  (   |  )   |      |  :   | "    |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |  &   |  #   |  !   |                  |      |  [   |  ]   |  up  | right|      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              | left | down |
 *               +-------------+                                              +-------------+
 */
[LAYER_RAISE] = LAYOUT(
    _______,XXXXXXX,XXXXXXX,S(KC_1),S(KC_6),S(KC_GRV),          XXXXXXX,KC_LCBR,KC_RCBR,XXXXXXX,XXXXXXX,XXXXXXX,  \
    _______,S(KC_2),S(KC_8),S(KC_4),S(KC_5),KC_GRV ,            XXXXXXX,S(KC_9),S(KC_0),XXXXXXX,S(KC_SCLN),S(KC_QUOT),  \
    _______,XXXXXXX,XXXXXXX,S(KC_7),S(KC_3),S(KC_1),            XXXXXXX,KC_LBRC,KC_RBRC,KC_UP ,KC_RIGHT,_______,  \
                    XXXXXXX,_______,                                            KC_LEFT,KC_DOWN,                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______, RA_LO ,            XXXXXXX,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),

/* Base (mosue assist)
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      | del  | tabl | up   | tabr | pgup |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      | bspc | left | down | right| pgdw |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              |      |      |
 *               +-------------+                                              +-------------+
 */
[LAYER_MOUSE_ASSIST] = LAYOUT(
    _______,KC_DEL ,C(KC_J),KC_UP  ,C(KC_K) ,KC_PGUP,           XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,   \
    _______,KC_BSPC,KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDOWN,         XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,   \
    _______,C(KC_Z),C(KC_X),C(KC_C),C(KC_V) ,XXXXXXX,           XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,   \
                    XXXXXXX,XXXXXXX,                                            XXXXXXX,XXXXXXX,                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,QWERTY ,            _______,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),

/* Base (raise_lower)
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  | HOME | C_L  | C_R  | END  |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              |      |      |
 *               +-------------+                                              +-------------+
 */
[LAYER_RAISE_LOWER] = LAYOUT(
    _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,   \
    _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,            KC_HOME, C_LEFT,C_RIGHT, KC_END,XXXXXXX,XXXXXXX,   \
    _______,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,   \
                    XXXXXXX,XXXXXXX,                                            XXXXXXX,XXXXXXX,                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,XXXXXXX,            XXXXXXX,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),

/* Base (fn)
 * +-----------------------------------------+                  +-----------------------------------------+
 * |      |  f1  |  f2  |  f3  |  f4  |  f5  |                  |  f6  |  f7  |  f8  |  f9  | f10  | f11  |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |  !   |  @   |  #   |  $   |  %   |                  | MUTE | VOL- | VOL+ | MUTE |      | f12  |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |  ^   |  &   |  *   |  (   |  )   |                  |      | BRI- | BRI+ |      |      |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              |      |      |
 *               +-------------+                                              +-------------+
 */
[LAYER_FN] = LAYOUT(
    _______,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,              KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11,   \
    _______,S(KC_1),S(KC_2),S(KC_3),S(KC_4),S(KC_5),            KC_MUTE,KC_VOLD,KC_VOLU,KC_MUTE,XXXXXXX, KC_F12,   \
    _______,S(KC_6),S(KC_7),S(KC_8),S(KC_9),S(KC_0),            XXXXXXX,KC_BRID,KC_BRIU,XXXXXXX,XXXXXXX,_______,   \
                    XXXXXXX,XXXXXXX,                                            XXXXXXX,XXXXXXX,                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            XXXXXXX,_______                                    \
),

/* Base (test)
 * +-----------------------------------------+                  +-----------------------------------------+
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              |      |      |
 *               +-------------+                                              +-------------+
 */
[LAYER_TEST] = LAYOUT(
    _______,RGB_TOG,XXXXXXX,XXXXXXX,XXXXXXX ,XXXXXXX,           XXXXXXX,KC_CBR ,KC_CBR ,XXXXXXX,XXXXXXX,XXXXXXX,   \
    _______,RGB_HUI,RGB_SAI,RGB_VAI,RGB_MOD ,XXXXXXX,           XXXXXXX,KC_RBR ,KC_RBR ,XXXXXXX,XXXXXXX,XXXXXXX,   \
    _______,RGB_HUD,RGB_SAD,RGB_VAD,RGB_RMOD,XXXXXXX,           XXXXXXX,KC_BBR ,KC_BBR ,XXXXXXX,XXXXXXX,XXXXXXX,   \
                    XXXXXXX,XXXXXXX,                                            KC_PBR ,KC_PBR ,                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,XXXXXXX,            _______,_______                                    \
),

/* Base (mouse)
 * +-----------------------------------------+                  +-----------------------------------------+
 * |QWERTY|      |      |      |      |      |                  |      |      |      |      | WH U | WH U |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |QWERTY|      |      |      |      |      |                  | LEFT | DOWN | UP   |RIGHT | WH D | WH D |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |QWERTY|      |      |      |      |      |                  |      |      |      | UP   |RIGHT |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              | LEFT | DOWN |
 *               +-------------+                                              +-------------+
 */
[LAYER_MOUSE] = LAYOUT(
    _______,_______,_______,_______,_______,_______,           _______,_______,_______,_______,KC_WH_D,KC_WH_D,   \
    QWERTY ,_______,_______,_______,_______,_______,           KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,KC_WH_U,KC_WH_U,   \
    _______,_______,_______,_______,_______,_______,           XXXXXXX,XXXXXXX,XXXXXXX,KC_MS_U,KC_MS_R,QWERTY ,   \
                    _______,_______,                                            KC_MS_L,KC_MS_D,                  \
                                    _______,_______,            KC_BTN1,KC_BTN2,                                  \
                                    _______,_______,            _______,_______,                                  \
                                    _______,_______,            _______,_______                                   \
),

[LAYER_ADJUST] = LAYOUT(
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,KC_CRST,   \
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,KC_CRST,   \
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,KC_CRST,   \
                    _______,_______,                                            _______,_______,                   \
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
    switch (keycode) {
        case KC_CUSTOM_RESET:
            if (record->event.pressed) {
                // Send enter then reset the keyboard, so the flash script can proceed
                register_code(KC_ENTER);
                reset_keyboard();
            }
        // do not have return false here; (after the reset thing)
        
        // fixing raise lower layer.
        // currnet problem if press lower, press raise, release lower then we are in later lower rather than raise

        // below macros for double braces 
        case KC_CURLY_BRACKETS:
            if (record->event.pressed) {
				register_code(KC_LSHIFT); // shift down
                tap_code(KC_LBRACKET); // {
                tap_code(KC_RBRACKET); // }
				unregister_code(KC_LSHIFT); // shift up

                tap_code(KC_LEFT); // <-
            }
            return false;
        case KC_BLOCK_BRACKETS:
            if (record->event.pressed) {
                tap_code(KC_LBRACKET); // [
                tap_code(KC_RBRACKET); // ]

                tap_code(KC_LEFT); // <-
            }
            return false;
        case KC_ROUND_BRACKETS:
            if (record->event.pressed) {
				register_code(KC_LSHIFT); // shift down
                tap_code(KC_9); // (
                tap_code(KC_0); // )
				unregister_code(KC_LSHIFT); // shift up

                tap_code(KC_LEFT); // <-
            }
            return false;
        case KC_POINT_BRACKETS:
            if (record->event.pressed) {
				register_code(KC_LSHIFT); // shift down
                tap_code(KC_COMMA); // <
                tap_code(KC_DOT); // >
				unregister_code(KC_LSHIFT); // shift up

                tap_code(KC_LEFT); // <-
            }
            return false;
    }
    return true;
}
