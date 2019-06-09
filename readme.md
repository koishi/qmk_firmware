# koishi Customize Keyboard Keymaps

## Build Setup

$ brew install teensy_loader_cli

$ brew tap osx-cross/avr

$ brew install dfu-programmer

$ brew install avr-gcc@7

$ echo 'export PATH="/usr/local/opt/avr-gcc@7/bin:$PATH"' >> ~/.bash_profile

or

$ brew tap osx-cross/avr

$ brew tap PX4/homebrew-px4

$ brew update

$ brew install avr-gcc@8

$ brew link --force avr-gcc@8

$ brew install dfu-programmer

$ brew install dfu-util

$ brew install gcc-arm-none-eabi

$ brew install avrdude

## Build Command

$ cd /Users/koishi/dev_private/qmk_firmware/

### ErgoDox EZ JIS

$ make ergodox_ez:osx_jis_koishi

$ teensy_loader_cli -mmcu=atmega32u4 -w -v ergodox_ez_osx_jis_koishi.hex

### ErgoDox EZ ANSI

$ make ergodox_ez:osx_ansi_koishi

$ teensy_loader_cli -mmcu=atmega32u4 -w -v ergodox_ez_osx_ansi_koishi.hex

> If using Karabiner-Elements, will quit

### ErgoDash

$ make ergodash/rev2:koishi:avrdude

### Rhymestone

$ make rhymestone:koishi:avrdude

### Planck

$ make planck/rev6:koishi:dfu-util

## Keymap

### ErgoDox EZ JIS

https://github.com/koishi/qmk_firmware/blob/master/keyboards/ergodox_ez/keymaps/osx_jis_koishi/keymap.c

### ErgoDox EZ ANSI

https://github.com/koishi/qmk_firmware/blob/master/keyboards/ergodox_ez/keymaps/osx_ansi_koishi/keymap.c

### ErgoDash

https://github.com/koishi/qmk_firmware/blob/master/keyboards/ergodash/rev2/keymaps/koishi/keymap.c

### Rhymestone

https://github.com/koishi/qmk_firmware/blob/master/keyboards/rhymestone/keymaps/koishi/keymap.c

### Planck

https://github.com/koishi/qmk_firmware/blob/master/keyboards/planck/keymaps/koishi/keymap.c