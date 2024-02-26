qmk_dir = $(HOME)/src/qmk_firmware
keyboard_name = my_dactyl
# Name of folder/subfolder within qmk_firmware/keyboards
keyboard_dir = handwired/$(keyboard_name)
keymap_name = default

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

keymap_folder = keymaps/$(keymap_name)
layer_drawing = $(keymap_folder)/keymap.mine.pdf
firmware_file = $(qmk_dir)/.build/$(subst /,_,$(keyboard_dir))_$(keymap_name).bin
vial_firmware_file = $(qmk_dir)/.build/handwired_$(keyboard_name)_vial.bin
board_link = $(qmk_dir)/keyboards/$(keyboard_dir)

all: compile

compile:
	qmk compile -kb $(keyboard_dir) -km $(keymap_name)

flash:
	dfu-util -a 2 -w -d 1EAF:0003 -D $(firmware_file)

flash_vial:
	dfu-util -a -w 2 -d 1EAF:0003 -D $(vial_firmware_file)

clean:
	qmk clean -a

clean_json: info_clean.json

# Draw layers using keymap-drawer
draw: $(layer_drawing)

link:
	if [ -L "$(board_link)" ]; then rm $(board_link); fi
	sudo ln -s $(mkfile_dir) $(board_link)

$(layer_drawing): $(keymap_folder)/keymap_drawer.yaml info_clean.json
	keymap draw $< -j  $(word 2,$^) >| $@.svg
	inkscape --export-pdf=$@ $@.svg
	rm $(keymap_folder)/keymap.json 

$(keymap_folder)/keymap.json: $(keymap_folder)/keymap.c
	qmk c2json $< >| $@

$(keymap_folder)/keymap_drawer.yaml: $(keymap_folder)/keymap.json
	keymap parse -q $< >| $@

info_clean.json: info.json
	hjson -j $< >| $@

.PHONY: all compile flash flash_vial clean draw clean_json
