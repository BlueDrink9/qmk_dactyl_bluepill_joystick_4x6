keymap_folder = keymaps/default
layer_drawing = $(keymap_folder)/keymap.mine.pdf
firmware_file = ~/src/qmk_firmware/.build/handwired_my_dactyl_default.bin
vial_firmware_file = ~/src/vial-qmk/.build/handwired_my_dactyl_vial.bin

all: compile

compile:
	qmk compile handwired/my_dactyl:default

flash:
	dfu-util -a 2 -w -d 1EAF:0003 -D $(firmware_file)

flash_vial:
	dfu-util -a -w 2 -d 1EAF:0003 -D $(vial_firmware_file)

clean:
	qmk clean -a

clean_json: info_clean.json

# Draw layers using keymap-drawer
draw: $(layer_drawing)

$(layer_drawing): $(keymap_folder)/keymap_drawer.yaml info_clean.json
	keymap draw $< -j  $(word 2,$^) >| $@.svg
	inkscape --export-pdf=$@ $@.svg

$(keymap_folder)/keymap.json: $(keymap_folder)/keymap.c
	qmk c2json $< >| $@

$(keymap_folder)/keymap_drawer.yaml: $(keymap_folder)/keymap.json
	keymap parse -q $< >| $@

info_clean.json: info.json
	hjson -j $< >| $@

.PHONY: all compile flash flash_vial clean draw clean_json
