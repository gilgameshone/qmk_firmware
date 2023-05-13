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
| < | > |   |   |   |   |   |   |   |   |   |
| , | . | - | c | j |   | k | m | b | x | z |
|___|___|TAB|LWR|SPC|   |OSS|RSE|RET|___|___|

### Modifier keys and layer keys

Modifier keys are on the same side as the layer key (`RSE` or `LWR`) on the home row, on every layer below Base. This reduces finger contortion when chording the  modifiers with other keys. To reduce chording even more, _nearly_ all modifiers are `One Shot`, meaning they are sticky. To use modifiers with alpha keys, simply release the layer key. `Hyper` and `Meh` keys are not real modifiers but chords of normal modifiers -- `Hyper` is every modifier key, and `Meh` is every key except shift. These are rarely used by existing keyboard shortcuts in any OS. `Hyper` is configured to call Alfred and `Meh` to call Rectangle, a window manager. Unfortunately these are not yet one shot. Infrequent layer keys are also available on the bottom row. `Shift` has a low priority here as its duplicatie `One Shot Shift` on the base layer is used for prose. The extra layer keys are below the modifier keys and can be toggled on.

## LWR

Lower contains a number pad that uses the typical number row keys (not the actual numpad keys). The shifted keys have been modified from normal JIS to reduce redundancy. `XXX` indicates key held to access layer. Thumb keys here change to `Backspace` and `Delete`. Extra symbols for maths-type situations are added on 'wrong' hand, and `comma` and `dot` from `Base` are visible here too. The symbols can be shifted but the `SYM` layer should reduce little finger fatigue. `layer lock` keys are next to the main `MO` layer keys.

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|   |Meh|Hyp|   | ~ |   | + | 7 | 8 | 9 | * |
|Sft|Opt|Cmd|Ctl| % |   | - | 4 | 5 | 6 | / |
| , | . |   |SYM| # |   | ¥ | 1 | 2 | 3 | 0 |
|___|___|LLk|XXX|...|   |BkS|SYM|DEL|___|___|

## SYM

The Symbol layer is accessed momentarily by holding left then right thumb layer keys in succession or by toggle with the left thumb layer key and an index finger key. Most characters are simply the shifted versions, more easily accessed from the thumbs rather than the pinky finger shift. This layer is vital for home row access to brackets. The remaining symbols are on the 'wrong' side of the layer.

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|   |Meh|Hyp|   | ` |   | ; | [ | ] | ^ | : |
|Sft|Opt|Cmd|Ctl| $ |   | = | ( | ) | & | ? |
|   |FN2|FN1|XXX| ! |   | \|| { | } | @ | _ |
|___|___|LLk|XXX|...|   |...|XXX|...|___|___|


## RSE

The Raise layer includes navigation and copy and paste keys. The navigation keys are on the left side of the keyboard because the most frequently used arrow keys are down and right (for navigating directories and documents that typically start top left), placing them under stronger fingers on the home row. Copy and paste are also under stronger fingers. This layer also includes Mac screen screen options. `select word` here will highlight the word under the cursor and select it. Press again to highlight the ajacent word too. Hold shift and press `select word` to select an entire line.

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|Undo|Cut |Copy|Pste|Redo||SSB|   |Hyp|Meh|   | 
|←   |↑   |↓   |→   |SlWd  ||SSS|Ctl|Cmd|Opt|Sft| 
|Home|PgDn|PgUp|End |   ||SSA|EXT|MSE|   |   |
|___|___|ESC|EXT|SPC|   |...|XXX|LLk|___|___|

## EXT

The Extend layer is to place miscellaneous keys on the home row, notably Play/Pause. It is accessed like `SYM` but mirrored. 
It also features macro keys that use Alfred to either: Google a term, translate it, or search for the definition.

### Caps Word
The mostly useless Caps Lock key is relegated here, in favour of the smart QMK `Caps Word` that is enabled by pressing both home index finger keys on the Base layer (`Y` and `H`) and automatically turns off on space or other keypress. This layer also has `Insert`, `Scroll Lock`, and `Pause`.

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|Caps|L2en|L1jp||   |   |INS|   |Hyp|Meh|   | 
|Mute|VolUp|VolDn|Play|| |SCL|Ctl|Cmd|Opt|Sft| 
|    |Dfine|Gtrns|GooGL|||PSE|XXX|MSE|   |   |
|___|___|...|XXX|...|   |...|XXX|LLk|___|___|

## MSE

The rarely used Mouse layer has mouse direction keys, mouse wheel direction keys, and mouse buttons. The power, sleep, and wake keys are in a contorted position to avoid accidental press. 

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|   |BT2|BT2|BT3|   |   |PWR|   |Hyp|Meh|   |
|MLT|MUP|MDN|MRT|   |   |SLP|Ctl|Cmd|Opt|Sft|
|WLT|WUP|WDN|WRT|   |   |WKE|EXT|XXX|   |   |
|___|___|...|...|...|   |...|XXX|...|___|___|

## FN1

Function keys are rarely used on Mac but here for prosperity. Base layer switches and One Shot Toggle keys are in contorted positions to avoid accidental press. This layer also has `Print Screen` and `Num Lock`.

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|   |Meh|Hyp|   |Dvarf|    |PRS|F9 |F10|F11|F12|
|Sft|Opt|Cmd|Ctl|Dvorak|   |NUM|F5 | F6| F7| F8|
|OSTOGG|FN2|XXX|SYM|Qwerty||   |F1 | F2| F3| F4|
|___|___|...|XXX|...|   |...|...|...|___|___|

## FN2

Who needs function keys up to 24? Absolutely nobody. `QMK Bootloader` and `QMK Reboot` are in contorted positions to avoid accidental press.

|   |   |   |   |   |   |   |   |   |   |   |
|---|---|---|---|---|---|---|---|---|---|---|
|QBT|Meh|Hyp|   |   |   |   |F21|F22|F23|F24|
|Sft|Opt|Cmd|Ctl|   |   |   |F17|F18|F19|F20|
|QRB|XXX|FN1|SYM|   |   |   |F13|F14|F15|F16|
|___|___|...|XXX|...|   |...|...|...|___|___|

### Notes

 - [1] Dvarf is an alpha key layout created by o-x-e-y that is based on Dvorak.
 - This keymap takes inspiration from the great [Miryoku](https://github.com/manna-harbour/miryoku), the excellent [Seniply](https://stevep99.github.io/seniply/), and many others.
 - Tools that help me utilize this keymap are Emacs, Alfred, Rectangle, and Vimari.
 - [Gilgamesh keymap image with all layers separated](https://github.com/gilgameshone/gilgamesh-layout/blob/main/Gilgamesh-layers.drawio.png)
 - Updated to One Shot modifier implementation by daliusd<sup>[4](https://blog.ffff.lt/posts/callum-layers/).
 - Reversed Delete and Backspace
 - Added `layer lock` and `select word` from [Pascal Getreuer](https://getreuer.info/posts/keyboards/index.html).
