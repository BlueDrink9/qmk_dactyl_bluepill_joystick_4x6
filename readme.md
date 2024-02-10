# Dactyl ManuForm

![Imgur](https://i.imgur.com/7y0Vbydh.jpg)  
*Pair of Dactyl Manuform 4x6*

Forked from the [Dactyl](/keyboards/handwired/dactyl), the *Dactyl ManuForm* is a parameterized, handwired, split bodied, tented, concave key-well design that incorporates the thumb cluster from the [ManuForm](https://geekhack.org/index.php?topic=46015.0).

* Keyboard Maintainer: [Tom Short](https://github.com/tshort)
* Hardware Supported: Pro Micro, or clone of
* Hardware Availability: [Github](https://github.com/tshort/dactyl-keyboard)

## Variants

*Dactyl ManuForm's* are built in variations that cater for different row and column counts, and thumb clusters.  

As standard: 
- The finger keywell bottom row has 2 keys, 1 each in ring and middle columns
    - Exception to this rule is the `5x7` variant - that has two additional keys, per half, in this row
- The thumb cluster has 6 keys, arranged in a staggered 2 columns by 3 rows 

Variants are denoted as `RowCount`*x*`ColumnCount`*(_`Alteration`)*

### Row
| Count | Description |
| :---: | :---: |
| 4 | Three rows, typically for alphabet and some puncuation characters, with 2 key (finger keywell) bottom row |
| 5 | As *4 row* with number row above |
| 6 | As *5 row* with function row above |

### Column
| Count | Description |
| :---: | :---: |
| 5 | A column for each finger with additional column for first finger |  
| 6 | As *5 column* with additional pinky finger column |
| 7 | As *6 column* with either an additional first finger column (`5x7`) or additional pinky column (`6x7`) |  

### Alteration
| Code | Description |
| :---: | :---: |
| 5 | Thumb cluster replaced with five key thumb cluster of [Dactyl Manuform Mini](https://github.com/l4u/dactyl-manuform-mini-keyboard) | 
| 2_5 | Same as code *5* with two additional keys added to finger key-well bottom row |

## Case Files Generator

[Dactyl Generator](https://ryanis.cool/dactyl), created by [rianadon](https://github.com/rianadon), is a web based file generator that negates having to compose case files using programming languages, which was the matter when using the original *Dactyl* and *Dactyl ManuForm* GitHub repos, by instead compiling case files based on options and parameters configured in a web front end.

## Compile

Make example for this keyboard (after setting up your build environment) in the 5x6 variant:

    make handwired/my_dactyl

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Keymaps

### Default

The default functional layout, based on QWERTY, and every variant has this keymap; used as a starting point/template for custom keymaps and for debugging purposes when soldering key matrix to controller.

### VIA
Similar to *Default* but adds support for the [VIA](https://usevia.app/) keymap configurator. Layer count set to 4 to comply with VIA defaults, and remaps keys to accommodate this constraint, if applicable.

Variants with VIA support:
- 4x6
- 5x6_5
- 5x7

## Flashing


Flashing example for this keyboard:

    dfu-util -a -w 2 -d 1EAF:0003 -D .build/handwired_my_dactyl_default.bin

## Handedness configurations

See [Handedness](https://docs.qmk.fm/#/config_options?id=setting-handedness) documentation for more information on configuring handedness/master half.

## VIA Configuration 

Variants with a `via` keymap are VIA capable. 
Compile firmware, for [enabled variant](#via), with it's `via` keymap and flash board with this firmware file.
```
qmk compile -kb handwired/dactyl_manuform/4x6 -km via
```


## Bootloader

Enter the bootloader in 2 ways:

* **Physical reset button**: On the bluepill, hold the KEY0 button then press the NRST button.
* **Keycode in layout**: Hold 5, then press space
<!-- * **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard -->

The bootloader only persists briefly, so start the dfu flash asap (leaving ~1 second for MCU to reboot to bootloader).
