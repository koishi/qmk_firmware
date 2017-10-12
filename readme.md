# osx_jis_koishi ErgoDox EZ Keymap

# Build Setup

$ brew install teensy_loader_cli

$ brew tap osx-cross/avr

$ brew install dfu-programmer

$ brew install avr-gcc

$ brew install avr-libc

# Build Command

$ cd /Users/koishi/dev_private/qmk_firmware/keyboards/ergodox

$ make ergodox-ez-osx_jis_koishi

$ make teensy keymap=osx_jis_koishi

# Keymap

https://github.com/koishi/qmk_firmware/blob/master/keyboards/ergodox/keymaps/osx_jis_koishi/keymap.c
