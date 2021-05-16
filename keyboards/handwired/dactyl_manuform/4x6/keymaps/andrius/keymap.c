#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Layers
enum {
    LAYER_QWERTY = 0,
    LAYER_ADJUST,
    LAYER_LOWER,
    NEW_LAYER_LOWER,
    LAYER_RAISE,
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
#define LOWER MO(LAYER_LOWER)
#define NEW_LOWER MO(NEW_LAYER_LOWER)
#define RAISE OSL(LAYER_RAISE)
#define FN MO(LAYER_FN)
#define SHIFT OSM(MOD_LSFT)


// Switch to function layer when held, escape when tapped
#define AD_ESC LT(LAYER_ADJUST, KC_ESCAPE)

/* #define R_L OSL(LAYER_RAISE, MO(NEW_LAYER_LOWER)) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * +-----------------------------------------+                  +-----------------------------------------+
 * |      |   q  |   w  |   e  |   r  |   t  |                  |   y  |   u  |   i  |   o  |   p  |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | ESC  |   a  |   s  |   d  |   f  |   g  |                  |   h  |   j  |   k  |   l  |   ;  | ENTR |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |   z  |   x  |   c  |   v  |   b  |                  |   n  |   m  |   ,  |   .  |   /  |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               | Lower| ALT  |                                              |      |   \  |
 *               +-------------+-------------+                  +-------------+-------------+
 *                             |SHIFT |SPACE |                  | BCSP |Raise |
 *                             |------+------|                  |------+------|
 *                             | CTRL |      |                  |      | GUI  |
 *                             |------+------|                  |------+------|
 *                             |      |      |                  | FN   |      |
 *                             +-------------+                  +-------------+
 */
[LAYER_QWERTY] = LAYOUT(
     RAISE ,  KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_DEL,   \
    AD_ESC ,  KC_A,  KC_S,   KC_D,   KC_F,   KC_G,               KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_ENT,  \
    KC_LSFT,  KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,               KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,   \
                NEW_LOWER,KC_LALT,                                            KC_RCTL,KC_BSLS,                 \
                                      SHIFT, KC_SPC,            KC_BSPC,  RAISE ,                                \
                                    KC_LCTL,XXXXXXX,            XXXXXXX,  KC_RGUI,                                \
                                      LOWER,XXXXXXX,              FN   ,  KC_RALT                                 \
),

/* Base (new lower)
 * +-----------------------------------------+                  +-----------------------------------------+
 * |      |      |      |      |      |      |                  |      |CMD+[ |CMD+] |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  | left | down | up   | right|      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                  |      |      |      |      |      |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              |      |      |
 *               +-------------+                                              +-------------+
 */
[NEW_LAYER_LOWER] = LAYOUT(
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            XXXXXXX,G(KC_LBRC),G(KC_RBRC),XXXXXXX,XXXXXXX,_______,  \
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            KC_LEFT,KC_DOWN, KC_UP ,KC_RIGHT,XXXXXXX,_______, \
    _______,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,            XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,_______,  \
                    _______,XXXXXXX,                                            XXXXXXX,XXXXXXX,                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,XXXXXXX,            _______,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),

/* Base (new raise)
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |  !   |  ^   |  ~   |                  |  "   |  [   |  ]   |  +   |   =  |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * | TAB  |  @   |  *   |  $   |  %   |  `   |                  |  '   |  (   |  )   |  -   |   :  | TAB  |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |      |      |  &   |  #   |      |                  |      |  {   |  }   |  _   |      |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              |  <   |  >   |
 *               +-------------+-------------+                  +-------------+-------------+
 *                             |      |      |                  |      |Lower |
 *                             +------+------+                  +------+------+
 */
[LAYER_RAISE] = LAYOUT(
    _______,XXXXXXX,XXXXXXX,S(KC_1),S(KC_6),S(KC_GRV),          S(KC_QUOT),KC_LBRC,KC_RBRC,S(KC_EQL),KC_EQL,KC_CAPS,  \
    KC_TAB,S(KC_2),S(KC_8),S(KC_4),S(KC_5),KC_GRV ,            KC_QUOT,S(KC_9),S(KC_0),KC_MINUS,S(KC_SCLN),KC_TAB,  \
    _______,XXXXXXX,XXXXXXX,S(KC_7),S(KC_3),XXXXXXX,            XXXXXXX,KC_LCBR,KC_RCBR,S(KC_MINUS),XXXXXXX,_______,  \
                    XXXXXXX,XXXXXXX,                                            S(KC_COMM),S(KC_DOT),                   \
                                    _______,_______,            _______,NEW_LOWER,                                   \
                                    _______,_______,            XXXXXXX,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),

/* Base (lower)
 * +-----------------------------------------+                  +-----------------------------------------+
 * |      |      |      |      |      |      |                  |      |CMD+[ |CMD+] |      |      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   4  |   5  |                  | left | down | up   | right|      |      |
 * |------+------+------+------+------+------|                  |------+------+------+------+------+------|
 * |      |   6  |   7  |   8  |   9  |   0  |                  |      |      |      |      |      |      |
 * +------+------+------+------+-------------+                  +-------------+------+------+------+------+
 *               |      |      |                                              |      |      |
 *               +-------------+                                              +-------------+
 */
[LAYER_LOWER] = LAYOUT(
    _______,_______,_______,_______,_______,_______,            _______,G(KC_LBRC),G(KC_RBRC),_______,_______,_______,  \
    _______,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,            KC_LEFT,KC_DOWN, KC_UP ,KC_RIGHT,_______,_______, \
    _______,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,            _______,_______,_______,_______,_______,_______,  \
                    XXXXXXX,XXXXXXX,                                            XXXXXXX,XXXXXXX,                   \
                                    _______,_______,            _______,_______,                                   \
                                    _______,XXXXXXX,            _______,_______,                                   \
                                    _______,_______,            _______,_______                                    \
),

/* Base (fn)
   Function and media controls
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
[LAYER_ADJUST] = LAYOUT(
    _______,_______,_______,_______,_______,_______,            _______,KC_7,KC_8,KC_9,_______,KC_CRST,   \
    _______,_______,_______,_______,_______,_______,            _______,KC_4,KC_5,KC_6,_______,KC_CRST,   \
    _______,_______,_______,_______,_______,_______,            _______,KC_1,KC_2,KC_3,_______,KC_CRST,   \
                    _______,_______,                                         KC_0,_______,                \
                                    _______,_______,            _______,_______,                          \
                                    _______,XXXXXXX,            XXXXXXX,_______,                          \
                                    _______,_______,            _______,_______                           \
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
