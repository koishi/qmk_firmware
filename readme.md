# osx_jis_koishi/osx_ansi_koishi ErgoDox EZ Keymap

## Build Setup

$ brew install teensy_loader_cli

$ brew tap osx-cross/avr

$ brew install dfu-programmer

$ brew install avr-gcc

$ brew install avr-libc

## Build Command

$ cd /Users/koishi/dev_private/qmk_firmware/

### JIS

$ make ergodox_ez:osx_jis_koishi

$ teensy_loader_cli -mmcu=atmega32u4 -w -v ergodox_ez_osx_jis_koishi.hex

### ANSI

$ make ergodox_ez:osx_ansi_koishi

$ teensy_loader_cli -mmcu=atmega32u4 -w -v ergodox_ez_osx_ansi_koishi.hex

> If using Karabiner-Elements, will quit

## Keymap

### JIS

https://github.com/koishi/qmk_firmware/blob/master/keyboards/ergodox_ez/keymaps/osx_jis_koishi/keymap.c

### ANSI

https://github.com/koishi/qmk_firmware/blob/master/keyboards/ergodox_ez/keymaps/osx_ansi_koishi/keymap.c