My QMK configs for corne and sofle.


I installed everything onto NB PC using:
```
$ cd Downloads/
$ mkdir qmk_firmware
$ cd qmk_firmware/
$ git clone https://github.com/qmk/qmk_firmware
$ git clone https://github.com/RafHL/qmk_keyboard
$ mv qmk_keyboard/crkbd/keymaps/Rafael/ qmk_firmware/keyboards/crkbd/keymaps/Rafael
$ python3 -m pip install --user qmk
$ qmk hello
$ sudo apt install dfu-programmer
$ make crkbd:Rafael:dfu-split-right
$ make crkbd:Rafael:dfu-split-left
```

For Pro Micro Sofle, use:
```
$ sudo apt install avrdude
$ make sofle:Rafael:avrdude-split-left
$ make sofle:Rafael:avrdude-split-right
```

If you want to use the default keymap, use sofle:default:...

In general, use <Keyboard>:<Keymap>:<bootloader>-split-<left or right>






For my future reference, QMK Doctor says:

```
Ψ QMK Doctor is checking your environment.
Ψ CLI version: 1.1.2
Ψ QMK home: /home/rafe/Documents/qmk_2023-12-09/qmk_firmware
Ψ Detected Linux (Manjaro Linux).
⚠ Missing or outdated udev rules for 'apm32-dfu' boards. Run 'sudo cp /home/rafe/Documents/qmk_2023-12-09/qmk_firmware/util/udev/50-qmk.rules /etc/udev/rules.d/'.
⚠ Missing or outdated udev rules for 'gd32v-dfu' boards. Run 'sudo cp /home/rafe/Documents/qmk_2023-12-09/qmk_firmware/util/udev/50-qmk.rules /etc/udev/rules.d/'.
⚠ Missing or outdated udev rules for 'wb32-dfu' boards. Run 'sudo cp /home/rafe/Documents/qmk_2023-12-09/qmk_firmware/util/udev/50-qmk.rules /etc/udev/rules.d/'.
⚠ Missing or outdated udev rules for 'usbtinyisp' boards. Run 'sudo cp /home/rafe/Documents/qmk_2023-12-09/qmk_firmware/util/udev/50-qmk.rules /etc/udev/rules.d/'.
Ψ Userspace enabled: False
Ψ Git branch: master
Ψ Repo version: 0.23.1
⚠ The official repository does not seem to be configured as git remote "upstream".
Ψ All dependencies are installed.
Ψ Found arm-none-eabi-gcc version 13.2.0
Ψ Found avr-gcc version 13.2.0
⚠ We do not recommend avr-gcc newer than 8. Downgrading to 8.x is recommended.
Ψ Found avrdude version 7.2
Ψ Found dfu-programmer version 1.0.0
Ψ Found dfu-util version 0.11
Ψ Submodules are up to date.
Ψ Submodule status:
Ψ - lib/chibios: 2023-04-15 13:48:04 +0000 --  (11edb16)
Ψ - lib/chibios-contrib: 2023-07-17 11:39:05 +0200 --  (da78eb3)
Ψ - lib/googletest: 2021-06-11 06:37:43 -0700 --  (e2239ee)
Ψ - lib/lufa: 2022-08-26 12:09:55 +1000 --  (549b973)
Ψ - lib/vusb: 2022-06-13 09:18:17 +1000 --  (819dbc1)
Ψ - lib/printf: 2022-06-29 23:59:58 +0300 --  (c2e3b4e)
Ψ - lib/pico-sdk: 2023-02-12 20:19:37 +0100 --  (a3398d8)
Ψ - lib/lvgl: 2022-04-11 04:44:53 -0600 --  (e19410f)
Ψ QMK is ready to go, but minor problems were found
```
