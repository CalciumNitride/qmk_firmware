/* Copyright 2020 CalciumNitride
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

#define CTLDT  CTL_T(KC_PDOT)
#define RAISE  MO(_RAISE)
#define RAIESC LT(_RAISE, KC_ESC)
#define LOWF11 LT(_LOWER, KC_F11)
#define KC_JAT KC_LBRC
#define KC_NO  _______
#define SFTESC SFT_T(KC_ESC)
#define SFTTAB RSFT_T(KC_TAB)
#define ALTF3  ALT_T(KC_F3)
#define CTLSHT LCTL(KC_LSFT)
#define M_TGT  CTL_T(KC_LEFT) // comand_targetting
#define M_INV    KC_BSPC // window_inventory
#define M_PINV   RSFT(KC_BSPC) // window_pet inventory
#define M_W_SD RCTL(KC_UP) // window_stardust
#define M_W_EW RCTL(KC_PPLS) // window_ego weapons
#define M_AMA  RCTL(KC_BSLS) // comand_automatic atack
#define M_W_CD RCTL(KC_DOWN) // window_crafting diary
#define M_W_P  RSFT(KC_LEFT) // window_pet
#define M_TEC  RSFT(KC_T) // window_technique
#define RSF_1  RSFT(KC_1)


// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _RAISE,
    _LOWER,
    _SKILL2
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL,
    SLOT2,
    SLOT3,
    SLOT4,
    SLOTR,
    SLOTR4,
    TAB_5,
    FW5231,
    FW3152,
    FW,
    WASD,
    WYVERN,
    BPET,
    ALTO,
    RPET,
    GTEW,
    HOLLOW,
    CHORUS,
    PET_8,
    OD,
    PET_CtS,
    PET_AN
};

//petkey's num
int WVnum = 0;
int BPETnum = 1;
int ALTOnum = 1;
int ODnum = 1;
int RPETnum = 1;
int DVCnum = 1;
int CtSnum = 0;
int ANnum = 0;

//active slot
int active_slot = 0;
int active_skill_window = 0;

//led settings
#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // 設定を保存せずに RGB を有効にします
  rgblight_sethsv_noeeprom(HSV_ORANGE);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
//,-------------------------------------------------------------------------------.
     FW5231,   KC_R,  KC_F4,   KC_W,  KC_F3,        KC_F5,  TAB_5,  KC_UP,KC_DOWN, \
//|--------|-------|-------|-------|-------|--------------\-------\-------\-------.
    SFTTAB,  RAISE,   KC_A,   KC_S,   KC_D,   KC_F1, KC_F6,   GTEW,KC_PSLS,KC_PAST, \
//|-------|-------|-------|-------|-------|--------\------\-------\-------\------.
             SLOTR,  M_TGT, KC_F2,   KC_G,  KC_SLSH,  KC_F7, KC_F10,KC_PDOT, \
//|-------+-------\------+-------+--------\--------+-------+-------+-------+------.
   _______,    SFTESC    ,  SLOT3,  SLOT4 , WYVERN,  LOWF11 \
//|-------------------------------------------------------------------------------.
),

    [_RAISE] = LAYOUT(
//,-------------------------------------------------------------------------------.
    _______,FW   ,  PET_8,     OD,  RSF_1,      _______,   KC_G,   KC_H, KC_BSPC, \
//|--------|-------|-------|-------|-------|--------------\-------\-------\-------.
      WASD,KC_TRNS, KC_DOT,   KC_Q,   KC_E,  M_AMA ,_______,   KC_Q,   KC_R,   KC_S, \
//|-------|-------|-------|-------|-------|--------\-------\-------\-------\------.
           KC_TRNS,KC_TRNS,  KC_T,  KC_SPC, PET_CtS,_______,   KC_Z,   KC_1, \
//|-------+-------\------+-------+--------\--------+-------+-------+-------+------.
   KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS,   ALTO,KC_TRNS \
//|-------------------------------------------------------------------------------.
),
    [_LOWER] = LAYOUT(
//,-------------------------------------------------------------------------------.
    _______,M_W_CD ,S(KC_P),S(KC_X),S(KC_Y),       S(KC_M),S(KC_N),M_W_SD ,S(KC_Q), \
//|--------|-------|-------|-------|-------|--------------\-------\-------\-------.
   _______,KC_TRNS,S(KC_O),KC_PPLS,M_W_EW ,M_PINV  ,M_INV   ,S(KC_C),S(KC_F),KC_RBRC, \
//|-------|-------|-------|-------|-------|--------\------\-------\-------\------.
        KC_TRNS,S(KC_SPC),M_TEC,   M_W_P, S(KC_L),KC_RO  ,S(KC_RO),KC_BSLS, \
//|-------+-------\------+-------+--------\--------+-------+-------+-------+------.
   KC_TRNS,KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS \
//|-
),
    [_SKILL2] = LAYOUT(
//,-------------------------------------------------------------------------------.
     FW3152,   BPET,   RPET,   KC_W,  KC_F8,        KC_F5,  TAB_5,  KC_TRNS,KC_TRNS, \
//|--------|-------|-------|-------|-------|--------------\-------\-------\-------.
    SFTTAB, KC_ESC,   KC_A,   KC_S,   KC_D,  PET_AN, KC_F6,  KC_F9,KC_TRNS,KC_TRNS, \
//|-------|-------|-------|-------|-------|--------\------\-------\-------\------.
            SLOTR4, CTLSHT, KC_F9,   KC_G,  KC_TRNS,  KC_F7, KC_F10,KC_TRNS, \
//|-------+-------\------+-------+--------\--------+-------+-------+-------+------.
   _______,    SFTESC    ,  SLOT3,  SLOT4 , WYVERN,  LOWF11 \
//|-------------------------------------------------------------------------------.
)
};

uint16_t key_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case SLOT2:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_X));
                active_slot = 2;
            } else {
                // when keycode is released
                SEND_STRING(SS_TAP(X_Z));
                active_slot = 1;
            }
            break;
        case SLOT3:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_C) SS_TAP(X_PGDN));
                active_slot = 3;
                active_skill_window = 7;
                
            } else {
                // when keycode is released
                SEND_STRING(SS_TAP(X_Z) SS_TAP(X_PGUP));
                active_slot = 1;
                active_skill_window = 1;
            }
            break;
        case SLOT4:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_V) SS_TAP(X_DEL));
                layer_on(_SKILL2);
                active_slot = 4;
                active_skill_window = 4;
            } else {
                // when keycode is released
                layer_off(_SKILL2);
                SEND_STRING(SS_TAP(X_Z) SS_TAP(X_PGUP));
                active_slot = 1;
                active_skill_window = 1;
            }
                break;
        case SLOTR:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING("fz" SS_TAP(X_PGDN));
                active_skill_window = 7;
                active_slot = 1;
            } else {
                // when keycode is released
                SEND_STRING("fz" SS_TAP(X_PGUP));
                active_skill_window = 1;
                active_slot = 1;
                
            }
            break;
        case SLOTR4:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING("fv" SS_TAP(X_PGDN));
                active_slot = 4;
            } else {
                // when keycode is released
                SEND_STRING("f" SS_TAP(X_PGUP));
                if(active_slot == 1) {
                    SEND_STRING("z");
                }
            }
            break;
        case TAB_5:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_HOME));
            } else {
                // when keycode is released
                SEND_STRING(SS_TAP(X_PGUP));
            }
            break;
        case FW5231:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_F12) SS_DELAY(150) "5231");
            } else {
                // when keycode is released
            }
            break;
        case FW3152:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_F12) SS_DELAY(150) "3152");
            } else {
                // when keycode is released
            }
            break;
        case FW:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_F12));
            } else {
                // when keycode is released
            }
            break;
        case WYVERN:
            if (record->event.pressed) {
                // when keycode is pressed
                key_timer = timer_read();
                register_code(KC_LALT);

            } else {
                // when keycode is released
                unregister_code(KC_LALT);
                if(timer_elapsed(key_timer)<TAPPING_TERM){
                    if     (WVnum==0){SEND_STRING(SS_TAP(X_P0));}
                    else if(WVnum==1){SEND_STRING(SS_TAP(X_P1));}
                    else if(WVnum==2){SEND_STRING(SS_TAP(X_P2));}
                    else if(WVnum==3){SEND_STRING(SS_TAP(X_P3));}
                    else if(WVnum==4){SEND_STRING(SS_TAP(X_P4));}
                    else if(WVnum==5){SEND_STRING(SS_TAP(X_P5));}
                    else if(WVnum==6){SEND_STRING(SS_TAP(X_P6));}
                    else if(WVnum==7){SEND_STRING(SS_TAP(X_P7));}
                    else if(WVnum==8){SEND_STRING(SS_TAP(X_P8));}
                    else if(WVnum==9){SEND_STRING(SS_TAP(X_P9)); WVnum = -1;}
                    WVnum ++;
                }
            }
            break;
        case WASD:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING("WASD");
            } else {
                // when keycode is released
            }
            break;
        case BPET:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_M));
                if     (BPETnum==1){SEND_STRING(SS_TAP(X_1));}
                else if(BPETnum==2){SEND_STRING(SS_TAP(X_2));}
                else if(BPETnum==3){SEND_STRING(SS_TAP(X_3));}
                else if(BPETnum==4){SEND_STRING(SS_TAP(X_4));}
                else if(BPETnum==4){SEND_STRING(SS_TAP(X_5));}
                else if(BPETnum==4){SEND_STRING(SS_TAP(X_6));}
                else if(BPETnum==4){SEND_STRING(SS_TAP(X_7));}
                else if(BPETnum==4){SEND_STRING(SS_TAP(X_8));}
                else if(BPETnum==4){SEND_STRING(SS_TAP(X_9));}
                else if(BPETnum==5){SEND_STRING(SS_TAP(X_0)); BPETnum = 0;}
                BPETnum ++;
                SEND_STRING(SS_TAP(X_V));
            } else {
                // when keycode is released
                SEND_STRING(SS_DELAY(200) SS_TAP(X_PMNS));
            }
            break;
        case ALTO:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_N));
                if     (ALTOnum==1){SEND_STRING(SS_TAP(X_1));}
                else if(ALTOnum==2){SEND_STRING(SS_TAP(X_2));}
                else if(ALTOnum==3){SEND_STRING(SS_TAP(X_3));}
                else if(ALTOnum==4){SEND_STRING(SS_TAP(X_4));}
                else if(ALTOnum==5){SEND_STRING(SS_TAP(X_5));}
                else if(ALTOnum==6){SEND_STRING(SS_TAP(X_6)); ALTOnum = 0;}
                ALTOnum ++;
                SEND_STRING(SS_TAP(X_Z));
            } else {
                // when keycode is released
                SEND_STRING(SS_DELAY(200) SS_TAP(X_PMNS));
            }
            break;
        case RPET:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_B));
                if     (RPETnum==1){SEND_STRING(SS_TAP(X_2));}
                else if(RPETnum==2){SEND_STRING(SS_TAP(X_3));}
                else if(RPETnum==3){SEND_STRING(SS_TAP(X_4));}
                else if(RPETnum==4){SEND_STRING(SS_TAP(X_5));}
                else if(RPETnum==5){SEND_STRING(SS_TAP(X_6));}
                else if(RPETnum==6){SEND_STRING(SS_TAP(X_7));}
                else if(RPETnum==7){SEND_STRING(SS_TAP(X_8));}
                else if(RPETnum==8){SEND_STRING(SS_TAP(X_9));}
                else if(RPETnum==9){SEND_STRING(SS_TAP(X_0));}
                else if(RPETnum==10){SEND_STRING(SS_TAP(X_MINS)); RPETnum = 0;}
                RPETnum ++;
                SEND_STRING(SS_TAP(X_V));
            } else {
                // when keycode is released
                SEND_STRING(SS_DELAY(200) SS_TAP(X_PMNS));
            }
            break;
        case GTEW:
            // golden time and elemental wave
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_HOME)  SS_TAP(X_I) SS_DELAY(320) SS_TAP(X_O) SS_TAP(X_PGUP));
            } else {
                // when keycode is released
            }
            break;
        case HOLLOW:
            if (record->event.pressed) {
                // when keycode is pressed

            } else {
                // when keycode is released
            }
            break;
        case CHORUS:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_P) SS_DELAY(500) SS_TAP(X_L) SS_DELAY(200) SS_TAP(X_N));
            } else {
                // when keycode is released
            }
            break;
        case PET_8:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_COMM));
                if     (DVCnum==1){SEND_STRING(SS_TAP(X_1));}
                else if(DVCnum==2){SEND_STRING(SS_TAP(X_2));}
                else if(DVCnum==3){SEND_STRING(SS_TAP(X_3));}
                else if(DVCnum==4){SEND_STRING(SS_TAP(X_4));}
                else if(DVCnum==5){SEND_STRING(SS_TAP(X_5));}
                else if(DVCnum==6){SEND_STRING(SS_TAP(X_6));}
                else if(DVCnum==7){SEND_STRING(SS_TAP(X_7));}
                else if(DVCnum==8){SEND_STRING(SS_TAP(X_8));}
                else if(DVCnum==9){SEND_STRING(SS_TAP(X_9));}
                else if(DVCnum==10){SEND_STRING(SS_TAP(X_0));}
                else   {SEND_STRING(SS_TAP(X_MINS)); DVCnum = 0;}
                DVCnum ++;
                SEND_STRING(SS_TAP(X_Z));
   
            } else {
                // when keycode is released
            }
            break;
        case OD:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_X));
                if     (ODnum==1){SEND_STRING(SS_TAP(X_1));}
                else if(ODnum==2){SEND_STRING(SS_TAP(X_2));}                
                else if(ODnum==3){SEND_STRING(SS_TAP(X_3)); ODnum = 0;}
                ODnum ++;
                SEND_STRING(SS_TAP(X_Z) SS_DELAY(200) SS_RSFT("1") );
            } else {
                // when keycode is released
                SEND_STRING(SS_DELAY(50) SS_TAP(X_Q));     // skill
            }
            break;
        case PET_CtS:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_N));
                if     (CtSnum==0){SEND_STRING(SS_TAP(X_7));}
                else if(CtSnum==1){SEND_STRING(SS_TAP(X_8));}
                else if(CtSnum==2){SEND_STRING(SS_TAP(X_9)); CtSnum = -1;}
                CtSnum ++;
                SEND_STRING(SS_TAP(X_Z));
                SEND_STRING(SS_DELAY(50) SS_RSFT("1"));
            } else {
                // when keycode is released
                SEND_STRING(SS_DELAY(200) SS_TAP(X_PMNS));
            }
            break;
        case PET_AN:
            if (record->event.pressed) {
                // when keycode is pressed
                SEND_STRING(SS_TAP(X_X));
                if     (ANnum==0){SEND_STRING(SS_TAP(X_MINS));}
                else if(ANnum==1){SEND_STRING(SS_TAP(X_0));}
                else if(ANnum==2){SEND_STRING(SS_TAP(X_9));}
                else if(ANnum==3){SEND_STRING(SS_TAP(X_8)); ANnum = -1;}
                ANnum ++;
                SEND_STRING(SS_TAP(X_V));
            } else {
                // when keycode is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
*/
