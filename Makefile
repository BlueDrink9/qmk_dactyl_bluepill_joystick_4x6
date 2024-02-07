all:
	qmk compile #  handwired/my_dactyl:default

flash:
	dfu-util -a 2 -d 1EAF:0003 -D ~/src/qmk_firmware/.build/handwired_my_dactyl_default.bin

flash_vial:
	dfu-util -a 2 -d 1EAF:0003 -D ~/src/vial-qmk/.build/handwired_my_dactyl_vial.bin

clean:
	qmk clean -a
