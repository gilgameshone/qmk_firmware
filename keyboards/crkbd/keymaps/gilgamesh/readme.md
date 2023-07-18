![Gilgamesh keymap image](https://github.com/gilgameshone/gilgamesh-layout/blob/main/Gilgamesh-whole.drawio.png)

# Gilgamesh keymap
A 36-key keyboard layout on QMK firmware that uses 5-7 layers and does not use tap-hold keys. 
The keys are laid out on a 3x5 grid + 3 thumb keys per hand. It is optimised to be used on Mac machines expecting a JIS keyboard.

## BASE

The base layer uses [Dvarf](https://o-x-e-y.github.io/layouts/dvarf/index.html)<sup>[1]</sup> for the alpha arrangement. This can be swapped on the fly via FN2 layer. The shifted characters are above, accessed by `One Shot Shift`, with some changes to shifted JIS to better suit English prose. Numbers, symbols and navigation keys are in the Lower and Raise layers respectively. There are no dual function keys, such as tap-hold keys. 

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
| “ |   |   |   |   |   |   |   |   |   |   |
| ‘ | u | o | w | p |   | q | d | v | r | f |
|   |   |   |   |   |   |   |   |   |   |   |
| a | i | o | y | g |   | l | h | t | n | s |
| ; | : | ? |   |   |   |   |   |   |   |   |
| , | . | - | c | j |   | k | m | b | x | z |
|___|___|SYM|NUM|SPC|   |OSS|NAV|EXT|___|___|

### Modifier keys and layer keys

Modifier keys are on the same side as the layer key (`NAV` or `NUM`) on the home row, on every layer below Base. This reduces finger contortion when chording the  modifiers with other keys. To reduce chording even more, _nearly_ all modifiers are `One Shot`, meaning they are sticky. To use modifiers with alpha keys, simply release the layer key. `Hyper` and `Meh` keys are not real modifiers but chords of normal modifiers -- `Hyper` is every modifier key, and `Meh` is every key except shift. These are rarely used by existing keyboard shortcuts in any OS. `Hyper` is configured to call Alfred and `Meh` to call Rectangle, a window manager. Unfortunately these are not yet one shot. Infrequent layer keys are also available on the bottom row. `Shift` has a low priority here as its duplicatie `One Shot Shift` on the base layer is used for prose. The extra layer keys are below the modifier keys and can be toggled on.

## NUM

Lower contains a number pad that uses the typical number row keys (not the actual numpad keys). The `SYM` layer is prefered in favour of the shifted number keys. `XXX` indicates key held to access layer. Thumb keys here change to `Backspace` and `Delete`. Extra symbols for maths-type situations are added on 'wrong' hand, and `comma` and `dot` from `Base` are visible here too. The symbols can be shifted but the `SYM` layer should reduce little finger fatigue. `layer lock` keys are next to the main `MO` layer keys. `Mnu` sends focus to the menu bar. There is also a `Pause` key and a macro to rewind audio and return to main window. 

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|Mnu|   |   |Ldr|   |   | + | 7 | 8 | 9 | * |
|Sft|Opt|Cmd|Ctl|   |   | - | 4 | 5 | 6 | / |
| , | . |   |   |   |   | = | 1 | 2 | 3 | 0 |
|___|___|   |NUM|   |   | # | % | ~ |___|___|

## NAV

The Navigation layer includes navigation and copy and paste keys. The navigation keys are on the left side of the keyboard because the most frequently used arrow keys are down and right (for navigating directories and documents that typically start top left), placing them under stronger fingers on the home row. Copy and paste are also under stronger fingers. This layer also includes Mac screen screen options. `select word` here will highlight the word under the cursor and select it. Press again to highlight the ajacent word too. Hold shift and press `select word` to select an entire line. `word forward` will move the cursor right without selecting. The `leader key` gives access to another type of modifier, and is currently combined with homerow keys to give leader keys for Emacs: `C-x`, `C-c`, and `M-x`.  There are also tab switching buttons, `Tab Forward` and `Tab Backward`, and `Previous` and `Next`.

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|Und|Cut|Cpy|Pst|Rdo|   |   |Ldr|   |   |LLk| 
|←  |↑  |↓  |→  |SWd|   |SSS|Ctl|Cmd|Opt|Sft| 
|Hme|PgD|PgU|End|WdF|   |SSA|Prv|TBw|Tfw|Nxt|
|___|___|ESC|   |   |   |   |NAV|   |___|___|

## SYM

The Symbol layer is accessed momentarily by holding left then right thumb layer keys in succession. Characters here began as shifted versions of `NUM` but are slowly being optimised. This layer is vital for home row access to brackets. The remaining symbols are on the stuffed into the 'wrong' side of the layer. For Windows, `Zenkaku/Hankaku`, `Muhenkan`, `Henkan`, `Kana` and `Eisu` keys are here. 

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|ZHk|MHn|Hnk|Kan|   |   | ¥ | [ | ] | : | ^ |
|Sft|Opt|Cmd|Ctl|   |   | ; | ( | ) | & | ? |
|Eis|FN2|FN1|   |   |   | \|| { | } | @ | _ |
|___|___|SYM|   |   |   | ! | $ | ` |___|___|

## EXT

The Extend layer is to place miscellaneous keys on the home row, notably Play/Pause. 
It also features macro keys that use Alfred to either: Google a term, translate it, or search for the definition. There is also a macro to rewind the media player slightly. This layer also has `Launch Pad`, `Scroll Lock`, and `Pause`. `Super Command Tab` sends `Command` `Tab`, then holds `Command` and sends another `Tab` on repeat. `Exposé`, `Eject`, `Shifted Eisu` and `Enter` keys are here too. 

### Caps Word
The mostly useless Caps Lock key is relegated here, in favour of the smart QMK `Caps Word` that is enabled by pressing both home index finger keys on the Base layer (`Y` and `H`) and automatically turns off on space or other keypress. 

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|L2 |Eis|Kan|L1 |   |   |Lpd|Exp|   |   |Ejt| 
|Mut|VUp|VDn|Ply|RwB|   |SCL|Ctl|Cmd|Opt|Sft| 
|Clk|Dfe|Gtr|GoG|CmT|   |PSE|   |MSE|   |Ent|
|___|___|   |   |   |   |   |   |EXT|___|___|

## MSE

The rarely used Mouse layer has mouse direction keys, mouse wheel direction keys, and mouse buttons. The power, sleep, and wake keys are in a contorted position to avoid accidental press. `Rewind` and `Fast-forward` are in the same place as `Next` and `Previous` are in `EXT`.

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|   |BT2|BT2|BT3|   |   |PWR|   |   |   |App|
|MLT|MUP|MDN|MRT|   |   |SLP|Ctl|Cmd|Opt|Sft|
|WLT|WUP|WDN|WRT|   |   |WKE|RWD|MSE|   |FFD|
|___|___|   |   |   |   |   |   |   |___|___|

## FN1

Function keys are rarely used on Mac but here for prosperity. Base layer switch is in an contorted position to avoid accidental press. This layer also has `Print Screen` and `Num Lock`.

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|   |   |   |   |Dvf|   |PRS|F9 |F10|F11|F12|
|Sft|Opt|Cmd|Ctl|   |   |NUM|F5 | F6| F7| F8|
|   |FN2|   |   |   |   |   |F1 | F2| F3| F4|
|___|___|   |   |   |   |   |   |   |___|___|

## FN2

Who needs function keys up to 24? Absolutely nobody. `QMK Bootloader` and `QMK Reboot` are in contorted positions to avoid accidental press.

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|QBT|   |   |   |   |   |   |F21|F22|F23|F24|
|Sft|Opt|Cmd|Ctl|   |   |   |F17|F18|F19|F20|
|QRB|FN2|FN1|   |   |   |   |F13|F14|F15|F16|
|___|___|   |   |   |   |   |   |   |___|___|

QMK Bootloader can also be accessed via triple vertical combo of outer pinky keys, Reboot for QMK by triple vertical combo of the inner most index finger keys, and clear EEprom via triple vertical combo of index finger home positions. These make it easier to troubleshoot and flash each side.

### Notes

 - [1] Dvarf is an alpha key layout created by [o-x-e-y](https://o-x-e-y.github.io/) that is based on Dvorak.
 - This keymap takes inspiration from the great [Miryoku](https://github.com/manna-harbour/miryoku), the excellent [Seniply](https://stevep99.github.io/seniply/), and many others.
 - Tools that help me utilize this keymap are Emacs, Alfred, Rectangle, and Vimari.
 - [Gilgamesh keymap image with all layers separated](https://github.com/gilgameshone/gilgamesh-layout/blob/main/Gilgamesh-layers.drawio.png)
 - Updated to One Shot modifier implementation by [daliusd](https://blog.ffff.lt/posts/callum-layers/).
 - Added `layer lock` and `select word` from [Pascal Getreuer](https://getreuer.info/posts/keyboards/index.html).
 - Added Tron Japanese layer. Update readme TODO []
