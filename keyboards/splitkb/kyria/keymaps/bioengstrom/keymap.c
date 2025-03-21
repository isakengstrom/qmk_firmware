/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum layers {
    _QWERTY_BIO = 0,
    _COLEMAK_DH_BIO = 1,
    _NAV_BIO = 2,
    _SYM_BIO = 3,
    _NUM_BIO = 4,
    _NUMLOCK_BIO = 5,
    _FKEYS_BIO = 6,
    _RGB_BIO = 7,
    _CTRL_LAYER = 8
};

// Aliases for readability
#define QWR_BIO   DF(_QWERTY_BIO)
#define CMK_BIO   DF(_COLEMAK_DH_BIO)

#define NAV_QUO  LT(_NAV_BIO, SE_QUOT) // ' on press, navigation on hold for querty
#define NAV_O  LT(_NAV_BIO, SE_O) // O on press, navigation on hold for querty
#define NUM_DQU  LT(_NUM_BIO, SE_DQUO) // 2/" on press, nums and åäö on hold, for both querty and colemak dh

#define NAV_BIO  MO(_NAV_BIO)
#define SYM_BIO  MO(_SYM_BIO)
#define NUM_BIO  MO(_NUM_BIO)
#define NML_BIO  MO(_NUMLOCK_BIO)
#define FKY_BIO  MO(_FKEYS_BIO)
#define RGB_BIO  MO(_RGB_BIO)

#define CTL_ESC  MT(MOD_LCTL, KC_ESC)

// Left home row mods for both querty and colemak dh
#define CTL_A  MT(MOD_LCTL, SE_A) // A on press, control on hold

// Left home row mods for querty
#define SFT_S  MT(MOD_LSFT, SE_S) // S on press, shift layer on hold
#define ALT_D  MT(MOD_LALT, SE_D) // D on press, alt layer on hold
#define SYM_F  LT(_SYM_BIO, SE_F) // F on press, activate symbol layer on hold

// Left home row mods for colemak dh
#define SFT_R  MT(MOD_LSFT, SE_R) // R on press, shift layer on hold
#define ALT_S  MT(MOD_LALT, SE_S) // S on press, alt layer on hold
#define SYM_T  LT(_SYM_BIO, SE_T) // T on press, activate symbol layer on hold

// todo: fix paste "ctrl + V", as V has now been moved one space to the right
// todo: this is probably not working,as it should be activating the ctrl layer when ctrl is held, but how do I do that when there's already a modifier on CTL_ESC?
#define PASTE_MACRO LCTL(SE_V) // Acts as paste (i.e. qwerty ctrl + V)
#define PST_D LT(_CTRL_LAYER, SE_D) // D on press, paste on ctrl + press



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY_BIO
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |   ´    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LShift |A/Ctrl|S/Shft|D/LAlt|F/Sym |   G  |                              |   H  |   J  |   K  |   L  | '/Nav| "/NUM  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |Ctrl/Esc|   Z  |   X  |   C  |   V  |   B  |Numloc| FKeys|  |Colemk|  ?   |   N  |   M  | ,  ; | . :  | -  _ | +  ?   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | RGB  | LGUI | LAlt | Space| Enter|  | Del  | Bksp | AltGr| RGUI | Menu |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
[_QWERTY_BIO] = LAYOUT(
 KC_TAB  , SE_Q ,  SE_W   ,  SE_E  ,   SE_R ,   SE_T ,                                        SE_Y,   SE_U ,  SE_I ,   SE_O ,  SE_P , SE_ACUT,
 KC_LSFT , CTL_A,  SFT_S  ,  ALT_D ,   SYM_F,   SE_G ,                                        SE_H,   SE_J ,  SE_K ,   SE_L ,NAV_QUO, NUM_DQU,
 CTL_ESC , SE_Z ,  SE_X   ,  SE_C  ,   SE_V ,   SE_B , NML_BIO, FKY_BIO,     CMK_BIO,SE_QUES, SE_N,   SE_M ,SE_COMM, SE_DOT ,SE_MINS, SE_PLUS,
                            RGB_BIO, KC_LGUI, KC_LALT, KC_SPC , KC_ENT ,     KC_DEL ,KC_BSPC,SYM_BIO, KC_RGUI, KC_APP
),

/*
 * Base Layer: COLEMAK_DH_BIO
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  |   '  |   ´    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LShift |A/Ctrl|R/Shft|S/LAlt|T/Sym |   G  |                              |   M  |   N  |   E  |   I  | O/Nav| "/NUM  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |Ctrl/Esc|   Z  |   X  |   C  |   D  |   V  |Numloc| FKeys|  |QWERTY|  ?   |   K  |   H  | ,  ; | . :  | -  _ | +  ?   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | RGB  | LGUI | LAlt | Space| Enter|  | Del  | Bksp | AltGr| RGUI | Menu |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
[_COLEMAK_DH_BIO] = LAYOUT(
 KC_TAB  , SE_Q ,  SE_W   ,  SE_F  ,   SE_P ,   SE_B ,                                        SE_J,   SE_L ,  SE_U ,   SE_Y ,  SE_P , SE_ACUT,
 KC_LSFT , CTL_A,  SFT_R  ,  ALT_S ,   SYM_T,   SE_G ,                                        SE_M,   SE_N ,  SE_E ,   SE_I , NAV_O , NUM_DQU,
 CTL_ESC , SE_Z ,  SE_X   ,  SE_C  ,   PST_D,   SE_V , NML_BIO, FKY_BIO,     QWR_BIO,SE_QUES, SE_K,   SE_H ,SE_COMM, SE_DOT ,SE_MINS, SE_PLUS,
                            RGB_BIO, KC_LGUI, KC_LALT, KC_SPC , KC_ENT ,     KC_DEL ,KC_BSPC,SYM_BIO, KC_RGUI, KC_APP
),

/*
 * Nav Layer: Media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              | PgUp | Home |   ↑  | End  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | PgDn |  ←   |   ↓  |   →  |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_NAV_BIO] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                     KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


 /*
  * SYMBOLS
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      |  @   |  £   |  $   |  €   |                              |   @  |  $   |   ~  |  /   |  \   |   |    |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |   #  |  {   |  [   |  ]   |  }   |   &    |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |   ^  |  <   |  (   |  )   |  >   |   =    |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_SYM_BIO] = LAYOUT(
       _______, _______ ,  SE_AT, SE_PND , SE_DLR, SE_EURO,                                       SE_AT , SE_DLR , SE_TILD, SE_SLSH, SE_BSLS, SE_PIPE,
       _______, _______, _______, _______, _______, _______,                                     SE_HASH, SE_LCBR, SE_LBRC, SE_RBRC, SE_RCBR, SE_AMPR,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, SE_CIRC, SE_LABK, SE_LPRN, SE_RPRN, SE_RABK, SE_EQL ,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),

/*
  * Number Row & åäö
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |   1  |   2  |   3  |  4   |   5  |                              |  6   |   7  |   8  |   9  |   0  |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |  å   |   ä  |   ö  |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_NUM_BIO] = LAYOUT(
       _______,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                                      KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , _______,
       _______, _______, _______, _______, _______, _______,                                     _______, SE_ARNG, SE_ADIA, SE_ODIA, _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),

/*
  * Num Lock
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      |      |      |      |      |                              |      |   7  |   8  |   9  |      |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |   4  |   5  |   6  |      |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |   1  |   2  |   3  |      |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |   0  |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_NUMLOCK_BIO] = LAYOUT(
       _______, _______, _______, _______, _______, _______,                                     _______, KC_7  , KC_8 , KC_9 , _______, _______,
       _______, _______, _______, _______, _______, _______,                                     _______, KC_4  , KC_5 , KC_6 , _______, _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1  , KC_2 , KC_3 , _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, KC_0, _______, _______
     ),

/*
  * Function Keys
  *
  * ,-------------------------------------------.                              ,-------------------------------------------.
  * |        |      |      |      |      |      |                              |      |  F7  |  F8  |  F9  | F10  |        |
  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
  * |        |      |      |      |      |      |                              |      |  F4  |  F5  |  F6  | F11  |        |
  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
  * |        |      |      |      |      |      |      |      |  |      |      |      |  F1  |  F2  |  F3  | F12  |        |
  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        |      |      |      |      |      |  |      |      |      |      |      |
  *                        `----------------------------------'  `----------------------------------'
  */
     [_FKEYS_BIO] = LAYOUT(
       _______, _______, _______, _______, _______, _______,                                     _______, KC_F7  , KC_F8 , KC_F9 , KC_F10 , _______,
       _______, _______, _______, _______, _______, _______,                                     _______, KC_F4  , KC_F5 , KC_F6 , KC_F11 , _______,
       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1  , KC_F2 , KC_F3 , KC_F12 , _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),

/*
 * Keyboard RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |                              | TOG  | SAI  | HUI  | VAI  | MOD  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      | SAD  | HUD  | VAD  | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RGB_BIO] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                    _______, _______, _______, _______,  _______, _______,
      _______, _______, _______, _______, _______, _______,                                    RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI,  RGB_MOD, _______,
      _______, _______, _______, _______, _______, _______,_______, _______, _______, _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______,
                                 _______, _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),

    /*
     * Ctrl layer
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |      |      |      |Paste |      |      |      |  |      |      |      |      |      |      |      |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_CTRL_LAYER] = LAYOUT(
        _______, _______, _______, _______ ,   _______, _______,                                    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______ ,   _______, _______,                                    _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,PASTE_MACRO, _______,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                   _______,    _______, _______,_______, _______, _______, _______, _______, _______, _______
    ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */


#ifdef OLED_ENABLE
/* 	Note for rendering images on Oled screens.
*	Screens are setup in horizontal rows, 8 pixels high, they render left to right.
*	Unless told otherwise they will keep going to the right until running out of space on that row and will then wrap down to the next row.
*	If you run over the end of the bottom row it will loop back to the start of the top row.
*	Using oled_set_cursor(X,Y) we can set position of where to start rendering.
*	X is the position from the left spaced in character spacing (default is 6px wide per character), starting at 0 for the start of the row.
*	Y is the position from the top row, starting at 0 for the top row.
*	128x32 size Oleds have 4 rows, 128px wide and 8px high, identified from row 0 being the top row and row 3 at the bottom.
*	They are 21.3 characters wide, with 0 being the left most and 20 being the start of the last character.
*	If you try render a 32px x 32px picture it will draw the first 32px wide, then the next 32px wide section next to it, not under it.
*	To correct for this the image needs to be broken up into segments, each segment being what is to be rendered on that line.
*	Breaking the image into segments is easy as each vertical row of 8px in the column is a byte. Represented in the image file as a hexidecimal value.
*	This translates to a binary digit rendered vertically in our Oled column http://cactus.io/resources/toolbox/decimal-binary-octal-hexadecimal-conversion
*	Data for each row of our Oled is then X amount of hexidecimal value's where X is how many pixels wide the image is we are trying to render.
*	Putting these chunks sequentially inside a const char allows us to pull them out easily.
*	Setup is <char_name>[<total number of chunks>][<how many pixels wide each chunk is>]
*	If rendering single image only then total number of chunks is simply how many lines, if animation is lines x images
*	Note, while logo_example[4][32] is 4 lines of image each 32px wide, when we call them back the counter starts at 0 and goes to 3, not 1 to 4
*	Once we have our image broken up we need to render it line by line, for our 32x32px example we want to
*	Set cursor to the desired X position on Y = 0 row, render the [0] chunk
*	Set cursor to the desired X position on Y = 1 row, render the [1] chunk
*	Set cursor to the desired X position on Y = 2 row, render the [2] chunk
*	Set cursor to the desired X position on Y = 3 row, render the [3] chunk
*	To avoid doing this manually, especially if rendering multiple images we can setup a loop we can feed the images into.
*
*	// Loop to create line by line rendering for Horizontal display
*	// Input is oled_render_image(how many rows tall, how many pixels wide, what to render, X pos, Y pos, Frame offset)
*	void oled_render_image(int lines, int px, const char render_line[][px], int X_pos, int Y_pos, int frame) {
*	for (uint8_t i = 0; i < lines; i++){
*            oled_set_cursor(X_pos, Y_pos + i);
*			oled_write_raw_P(render_line[i + frame], px);
*		}
*	}
*
*	oled_render_image(4, 32, my_logo, 15, 0, 0, 0, 0);
* 	This would draw the my_logo image, 32x32px in size, on the far right of the screen.
*	Note : 128x32 screens only have 4 rows high, if you were try render at 15,1 as the first row of the image
*	would be on the second row of the screen and the last row would wrap around and be on the first row.
*   Note : The Frame offset is used to select different images in the array. Eg. Sit1 is 0,1,2 in the array and Sit2 is 3,4,5.
*	If we want to render Sit2 we offset the counter by 3 to get 3,4,5.
*/
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }


/* KEYBOARD PET START */

/* settings */
#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 30

/* advanced settings */
#define LUNA_FRAME_DURATION 230 // how long each frame lasts in ms
#define LUNA_SIZE 32 // number of bytes in array. This is how many pixels wide your image is. max is 1024 but would apply if line wrapping and not segmeting image and on 128x64 size screen, 512 is max on 128x32.

/* Setup Variables */
uint8_t current_frame = 0;
bool isSneaking = false;
bool isJumping = false;
bool showedJump = true;
int jump_height = 0;

// Loop to create line by line rendering for Horizontal display
// Input is oled_render_image(how many rows tall, how many pixels wide, what to render, X pos, Y pos, Frame offset)
void oled_render_image(int lines, int px, const char render_line[][px], int X_pos, int Y_pos, int frame) {
for (uint8_t i = 0; i < lines; i++){
        oled_set_cursor(X_pos, Y_pos + i);
		oled_write_raw_P(render_line[i + frame], px);
	}
}

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y, int LOGO_X, int LOGO_Y) {

	/* setup some variables & timers */
	static uint8_t prev_wpm = 0;
	static uint32_t tap_timer = 0; // WPM and mod triggered
	if (get_current_wpm() > prev_wpm || get_mods()) { tap_timer = timer_read32(); }
	prev_wpm = get_current_wpm();

	// Elapsed time between key presses
	uint32_t keystroke = timer_elapsed32(tap_timer);
	static uint16_t anim_timer = 0;

    /* Sit - 32x24px */
    static const char PROGMEM sit[6][LUNA_SIZE] = {
        /* 'sit1' */
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
		0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x68, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
		0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        /* 'sit2' */
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c,
		0x02, 0x05, 0x02, 0x24, 0x04, 0x04, 0x02, 0xa9, 0x1e, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{   0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x90, 0x08, 0x18, 0x60, 0x10, 0x08, 0x04, 0x03, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x0e, 0x82, 0x7c, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		{   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x0c, 0x10, 0x10, 0x20, 0x20, 0x20, 0x28,
        0x3e, 0x1c, 0x20, 0x20, 0x3e, 0x0f, 0x11, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* Walk - 32x24px */
    static const char PROGMEM walk[6][LUNA_SIZE] = {
        /* 'walk1' */
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x90, 0x90, 0x90, 0xa0, 0xc0, 0x80, 0x80,
		0x80, 0x70, 0x08, 0x14, 0x08, 0x90, 0x10, 0x10, 0x08, 0xa4, 0x78, 0x80, 0x00, 0x00, 0x00, 0x00},
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0xfc, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
		0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x18, 0xea, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00},
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x03,
		0x06, 0x18, 0x20, 0x20, 0x3c, 0x0c, 0x12, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		/* 'walk2' */
        {   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x20, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00,
		0x00, 0xe0, 0x10, 0x28, 0x10, 0x20, 0x20, 0x20, 0x10, 0x48, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0xf8, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
		0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x10, 0x30, 0xd5, 0x20, 0x1f, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e,
		0x02, 0x1c, 0x14, 0x08, 0x10, 0x20, 0x2c, 0x32, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* Run - 32x24px */
    static const char PROGMEM run[6][LUNA_SIZE] = {
        /* 'run1' */
        {    0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x08, 0x08, 0xc8, 0xb0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
		0x80, 0x40, 0x40, 0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0xc4, 0xa4, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x58, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x09, 0x04, 0x04, 0x04, 0x04, 0x02, 0x03, 0x02, 0x01, 0x01,
		0x02, 0x02, 0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00},
         /* 'run2' */
        {    0x00, 0x00, 0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
		0x80, 0x80, 0x78, 0x28, 0x08, 0x10, 0x20, 0x30, 0x08, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x10, 0xb0, 0x50, 0x55, 0x20, 0x1f, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37,
		0x02, 0x1e, 0x20, 0x20, 0x18, 0x0c, 0x14, 0x1e, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* Bark - 32x24px */
    static const char PROGMEM bark[6][LUNA_SIZE] = {
        /* 'bark1' */
        {    0x00, 0xc0, 0x20, 0x10, 0xd0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
		0x3c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x80, 0xc8, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
		0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        /* 'bark2' */
        {    0x00, 0xe0, 0x10, 0x10, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x40,
		0x40, 0x2c, 0x14, 0x04, 0x08, 0x90, 0x18, 0x04, 0x08, 0xb0, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x03, 0x04, 0x08, 0x10, 0x11, 0xf9, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x48, 0x28, 0x2a, 0x10, 0x0f, 0x20, 0x4a, 0x09, 0x10},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x0c, 0x10, 0x20, 0x28, 0x37, 0x02, 0x02,
		0x04, 0x08, 0x10, 0x26, 0x2b, 0x32, 0x04, 0x05, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* Sneak - 32x24px */
    static const char PROGMEM sneak[6][LUNA_SIZE] = {
        /* 'sneak1' */
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0xc0, 0x40, 0x40, 0x80, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x1e, 0x21, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x04,
		0x04, 0x04, 0x03, 0x01, 0x00, 0x00, 0x09, 0x01, 0x80, 0x80, 0xab, 0x04, 0xf8, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1c, 0x20, 0x20, 0x3c, 0x0f, 0x11, 0x1f, 0x02, 0x06,
		0x18, 0x20, 0x20, 0x38, 0x08, 0x10, 0x18, 0x04, 0x04, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00},
        /* 'sneak2' */
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0xe0, 0xa0, 0x20, 0x40, 0x80, 0xc0, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x3e, 0x41, 0xf0, 0x04, 0x02, 0x02, 0x02, 0x03, 0x02, 0x02, 0x02, 0x04,
		0x04, 0x02, 0x01, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x40, 0x55, 0x82, 0x7c, 0x00, 0x00, 0x00},
        {    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x20, 0x30, 0x0c, 0x02, 0x05, 0x09, 0x12, 0x1e, 0x04,
		0x18, 0x10, 0x08, 0x10, 0x20, 0x28, 0x34, 0x06, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00}
    };

    /* animation */
    void animate_luna(void) {

	    //// Render QMK Logo, has been placed inside Luna code due to OLED Flicker
	    //oled_render_image(4, 32, qmk_logo, LOGO_X, LOGO_Y, 0);

		/* jump */
        if (isJumping || !showedJump) {

            // Is jumping, clear the bottom line and tell animation to render 1 line up
            oled_set_cursor(LUNA_X,LUNA_Y +3);
            oled_write("     ", false);
			jump_height = 1;
            showedJump = true;
        } else {

            // Not jumping, clears the top row and tells animation to render bottom 3 rows
            oled_set_cursor(LUNA_X,LUNA_Y);
            oled_write("     ", false);
			jump_height = 0;
        }

        /* switch frame */
        // current_frame = (current_frame + <number of lines per image>) % <lines x how many frames>;
		current_frame = (current_frame + 3) % 6;

        /* current status */
        if(host_keyboard_led_state().caps_lock) {
            oled_render_image(3, LUNA_SIZE, bark, LUNA_X, LUNA_Y + 1, current_frame);

        } else if(isSneaking) {
			oled_render_image(3, LUNA_SIZE, sneak, LUNA_X, LUNA_Y + 1 - jump_height, current_frame);

        } else if(prev_wpm <= MIN_WALK_SPEED) {
			oled_render_image(3, LUNA_SIZE, sit, LUNA_X, LUNA_Y + 1, current_frame);

        } else if(prev_wpm <= MIN_RUN_SPEED) {
			oled_render_image(3, LUNA_SIZE, walk, LUNA_X, LUNA_Y + 1 - jump_height, current_frame);

        } else {
			oled_render_image(3, LUNA_SIZE, run, LUNA_X, LUNA_Y + 1 - jump_height, current_frame);

        }
    }

	if (keystroke > OLED_TIMEOUT) { oled_off(); }
	else if (timer_elapsed(anim_timer) > (LUNA_FRAME_DURATION - (prev_wpm/2))) {
		anim_timer = timer_read();
		animate_luna();
	}
}

/* KEYBOARD PET END */


bool oled_task_user(void) {

    if (is_keyboard_master()) {
		/* KEYBOARD PET START */
    	render_luna(1,1,15,0); // (luna X pos, luna Y pos, QMK X pos, QMK Y pos) note that Luna is 4 lines tall Y settings must be 0 on 128x32 display
    	/* KEYBOARD PET END */

		/* wpm counter */
        oled_set_cursor(2,6); // sets position where "wpm" will be displayed
        oled_write("WPM -", false);

        uint8_t n = get_current_wpm();
        char wpm_str[4];
        oled_set_cursor(8,6); // sets position where WPM counter will be displayed
        wpm_str[3] = '\0';
        wpm_str[2] = '0' + n % 10;
        wpm_str[1] = '0' + ( n /= 10) % 10;
        wpm_str[0] = '0' + n / 10;
        oled_write(wpm_str, false);

		// clear upper right screen half
		oled_set_cursor(7,0);
        oled_write_P(PSTR("\n"), false);
		// clear upper right screen half
		oled_set_cursor(7,1);
        oled_write_P(PSTR("\n"), false);
        // Host Keyboard Layer Status
       	oled_set_cursor(7,2); // sets position where "Layer" will be displayed
        oled_write_P(PSTR("Layer:\n"), false);

        // Host Keyboard Layer Status
       	oled_set_cursor(7,3); // sets position where layer name will be displayed
        switch (get_highest_layer(layer_state)) {
            case _QWERTY_BIO:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _COLEMAK_DH_BIO:
                oled_write_P(PSTR("COLEMAK DH\n"), false);
                break;
            case _NAV_BIO:
                oled_write_P(PSTR("Navigation\n"), false);
                break;
            case _SYM_BIO:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case _NUM_BIO:
                oled_write_P(PSTR("Numbers/Swe\n"), false);
                break;
            case _NUMLOCK_BIO:
                oled_write_P(PSTR("Num Lock\n"), false);
                break;
            case _FKEYS_BIO:
                oled_write_P(PSTR("F-Keys\n"), false);
                break;
            case _RGB_BIO:
                oled_write_P(PSTR("RGB\n"), false);
                break;
            case _CTRL_LAYER:
                oled_write_P(PSTR("CTRL Extra\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

    } else {
		oled_set_cursor(2,2); // sets position where text will be displayed
        oled_write("Ebb & Flow", false);
        oled_set_cursor(6,6); // sets position where text will be displayed
        oled_write("(:", false);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
        /* KEYBOARD PET STATUS END */
	}
	return true;
}

#endif
/*
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),


///*
// * Base Layer: QWERTY
// *
// * ,-------------------------------------------.                              ,-------------------------------------------.
// * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
// * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
// * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
// * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
// * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
// * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
// *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
// *                        |      |      | Enter|      |      |  |      |      |      |      |      |
// *                        `----------------------------------'  `----------------------------------'
// */
//    [_QWERTY] = LAYOUT(
//     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                        KC_Y,   KC_U ,  KC_I ,   KC_O ,  KC_P , KC_BSPC,
//     CTL_ESC , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                        KC_H,   KC_J ,  KC_K ,   KC_L ,KC_SCLN,CTL_QUOT,
//     KC_LSFT , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_LBRC,KC_CAPS,     FKEYS  , KC_RBRC, KC_N,   KC_M ,KC_COMM, KC_DOT ,KC_SLSH, KC_RSFT,
//                                ADJUST , KC_LGUI, ALT_ENT, KC_SPC , NAV   ,     SYM    , KC_SPC ,KC_RALT, KC_RGUI, KC_APP
//    ),
