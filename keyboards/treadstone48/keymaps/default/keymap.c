#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "bootloader.h"
#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif
#include "../common/oled_helper.h"

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
enum layer_number {
  _BASE = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
  LOWER = SAFE_RANGE,
  RAISE,
  ADJUST,
  KANJI,
  RGBRST
};

enum tapdances{
  TD_SCCL = 0,
  TD_SLRO,
};

// Layer Mode aliases
#define KC_LOWER LOWER
#define KC_RAISE RAISE

#define KC______ KC_TRNS
#define KC_XXXXX KC_NO
#define KC_KANJI KANJI

#define KC_RST   RESET
#define KC_LRST  RGBRST
#define KC_LTOG  RGB_TOG
#define KC_LHUI  RGB_HUI
#define KC_LHUD  RGB_HUD
#define KC_LSAI  RGB_SAI
#define KC_LSAD  RGB_SAD
#define KC_LVAI  RGB_VAI
#define KC_LVAD  RGB_VAD
#define KC_LMOD  RGB_MOD
#define KC_KNRM  AG_NORM
#define KC_KSWP  AG_SWAP

#define KC_TBSF  LSFT_T(KC_TAB)
// #define KC_SPSF  LSFT_T(KC_SPC)
#define KC_ALAP  LALT_T(KC_APP)
#define KC_JEQL  LSFT(KC_MINS)

#define KC_SCCL  TD(TD_SCCL)
#define KC_SLRO  TD(TD_SLRO)

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_SCCL] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT),
  [TD_SLRO] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, KC_RO),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_BASE_kc( \
  //,------------------------------------------------------------------------------------------.
        ESC,     Q,     W,     E,     R,     T,     Y,     U,     I,     O,     P,         MINS,\
  //|------+------+------+------+------+------|------+------+------+------+------+-------------|
       TBSF,     A,     S,     D,     F,     G,     H,     J,     K,     L,  SCCL,          ENT,\
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|
       LSFT,     Z,     X,     C,     V,     B,     N,     M,  COMM,   DOT,  SLRO,    UP,       \
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|
      LCTRL,  LALT,  LGUI, LOWER,         BSPC,          SPC, RAISE,  ALAP,  LEFT,  DOWN,  RGHT,\
  //`------------------------------------------------------------------------------------------'
        DEL \
  // ExtraKey: Split backspace key or it is below the enter key.
  ),

  [_LOWER] = LAYOUT_BASE_kc( \
  //,------------------------------------------------------------------------------------------.
      _____,    F1,    F2,    F3,    F4,    F5,  MINS,   EQL,  LBRC,  RBRC,  BSLS,          DEL,\
  //|------+------+------+------+------+------|------+------+------+------+------+-------------|
      _____,    F6,    F7,    F8,    F9,   F10, XXXXX, XXXXX, XXXXX,  SCLN,  QUOT,        _____,\
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|
      _____,   F11,   F12, XXXXX, KANJI,   ENT, XXXXX, XXXXX,  COMM,   DOT,   GRV,  PGUP,       \
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|
      _____, _____, _____, _____,          DEL,        _____, _____, XXXXX,  HOME,  PGDN,   END,\
  //`------------------------------------------------------------------------------------------'
      XXXXX \
  // ExtraKey: Split backspace key or it is below the enter key.
  ),

  [_RAISE] = LAYOUT_BASE_kc( \
  //,------------------------------------------------------------------------------------------.
      _____,     1,     2,     3,     4,     5,     6,     7,     8,     9,     0,        XXXXX,\
  //|------+------+------+------+------+------|------+------+------+------+------+-------------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,     4,     5,     6,  QUOT,        _____,\
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|
      _____, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,     1,     2,     3,    RO, XXXXX,       \
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|
      _____, _____, _____, _____,        _____,        _____, _____,     0,   DOT,  COMM,  SLSH,\
  //`------------------------------------------------------------------------------------------'
      XXXXX \
  // ExtraKey: Split backspace key or it is below the enter key.
  ),

  [_ADJUST] = LAYOUT_BASE_kc( \
  //,------------------------------------------------------------------------------------------.
      XXXXX,   RST,  LRST,  KNRM,  KSWP, XXXXX, XXXXX,  WH_L,  WH_U,  HOME,  PGUP,        XXXXX,\
  //|------+------+------+------+------+------|------+------+------+------+------+-------------|
      XXXXX,  LTOG,  LHUI,  LSAI,  LVAI, XXXXX, XXXXX,  WH_R,  WH_D,   END,  PGDN,        XXXXX,\
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|
      _____,  LMOD,  LHUD,  LSAD,  LVAD, XXXXX, XXXXX, XXXXX,  BTN1,  BTN2, XXXXX,  MS_U,       \
  //|------+------+------+------+------+------|------+------+------+------+------+------+------|
      _____, _____, _____, _____,        XXXXX,        XXXXX, _____, XXXXX,  MS_L,  MS_D,  MS_R,\
  //`------------------------------------------------------------------------------------------'
      XXXXX \
  // ExtraKey: Split backspace key or it is below the enter key.
  )
};

#define L_BASE _BASE
#define L_LOWER (1<<_LOWER)
#define L_RAISE (1<<_RAISE)
#define L_ADJUST (1<<_ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_RAISE|L_LOWER)

#ifdef SSD1306OLED
typedef struct {
  uint8_t state;
  char name[8];
}LAYER_DISPLAY_NAME;

#define LAYER_DISPLAY_MAX 5
const LAYER_DISPLAY_NAME layer_display_name[LAYER_DISPLAY_MAX] = {
  {L_BASE, "Base"},
  {L_BASE + 1, "Base"},
  {L_LOWER, "Lower"},
  {L_RAISE, "Raise"},
  {L_ADJUST_TRI, "Adjust"}
};

static inline const char* get_leyer_status(void) {

  for (uint8_t i = 0; i < LAYER_DISPLAY_MAX; ++i) {
    if (layer_state == 0 && layer_display_name[i].state == default_layer_state) {

      return layer_display_name[i].name;
    } else if (layer_state != 0 && layer_display_name[i].state == layer_state) {

      return layer_display_name[i].name;
    }
  }

  return "?";
}

static char layer_status_buf[24] = "Layer state ready.\n";
static inline void update_keymap_status(void) {

  snprintf(layer_status_buf, sizeof(layer_status_buf) - 1, "OS:%s Layer:%s\n",
    keymap_config.swap_lalt_lgui? "win" : "mac", get_leyer_status());
}

static inline void render_keymap_status(struct CharacterMatrix *matrix) {

  matrix_write(matrix, layer_status_buf);
}

#define UPDATE_KEYMAP_STATUS() update_keymap_status()
#define RENDER_KEYMAP_STATUS(a) render_keymap_status(a)

#else

#define UPDATE_KEYMAP_STATUS()
#define RENDER_KEYMAP_STATUS(a)

#endif

static inline void update_change_layer(bool pressed, uint8_t layer1, uint8_t layer2, uint8_t layer3) {

  pressed ? layer_on(layer1) : layer_off(layer1);
  IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2) ? layer_on(layer3) : layer_off(layer3);
}

int RGB_current_mode;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  UPDATE_KEY_STATUS(keycode, record);

  bool result = false;
  switch (keycode) {
    case LOWER:
      update_change_layer(record->event.pressed, _LOWER, _RAISE, _ADJUST);
      break;
    case RAISE:
      update_change_layer(record->event.pressed, _RAISE, _LOWER, _ADJUST);
        break;
    case KANJI:
      if (record->event.pressed) {
        if (keymap_config.swap_lalt_lgui == false) {
          register_code(KC_LANG2);
        } else {
          SEND_STRING(SS_LALT("`"));
        }
      } else {
        unregister_code(KC_LANG2);
      }
      break;
    #ifdef RGBLIGHT_ENABLE
      case RGB_MOD:
          if (record->event.pressed) {
            rgblight_mode(RGB_current_mode);
            rgblight_step();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
      case RGBRST:
          if (record->event.pressed) {
            eeconfig_update_rgblight_default();
            rgblight_enable();
            RGB_current_mode = rgblight_config.mode;
          }
        break;
    #endif
    default:
      result = true;
      break;
  }

  UPDATE_KEYMAP_STATUS();
  return result;
}

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
  #ifdef SSD1306OLED
    iota_gfx_init(!has_usb()); // turns on the display
  #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void matrix_scan_user(void) {
  iota_gfx_task();  // this is what updates the display continuously
}

static inline void matrix_update(struct CharacterMatrix *dest,
                          const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

static inline void render_status(struct CharacterMatrix *matrix) {

  UPDATE_LED_STATUS();
  RENDER_LED_STATUS(matrix);
  RENDER_KEYMAP_STATUS(matrix);
  UPDATE_LOCK_STATUS();
  RENDER_LOCK_STATUS(matrix);
  RENDER_KEY_STATUS(matrix);
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;

  #if DEBUG_TO_SCREEN
    if (debug_enable) {
      return;
    }
  #endif

  matrix_clear(&matrix);
  if (is_master) {
    render_status(&matrix);
  }

  matrix_update(&display, &matrix);
}

#endif
