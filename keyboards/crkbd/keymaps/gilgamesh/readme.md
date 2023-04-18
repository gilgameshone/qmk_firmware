# Gilgamesh keymap
A 36-key keyboard layout on QMK firmware that uses 5-7 layers and does not use tap-hold keys.
The keys are laid out on a 3x5 grid + 3 thumb keys per hand. It is optimised to be used on Mac machines expecting a JIS keyboard. 

## BASE

The base layer uses Dvarf<sup>[1](https://o-x-e-y.github.io/layouts/dvarf/index.html)</sup> for the alpha arrangement, but can be swapped via FN2 layer.
The shifted characters are above, accessed by One Shot Shift. 
Numbers, symbols and navigation keys are in the Lower and Raise layers respectively.
There are no dual function keys, such as tap-hold keys.

|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|
|---|---|---|---|---|---|---|---|---|---|---|
| “ |   |   |   |   |   |   |   |   |   |   |
| ‘ | u | o | w | p |   | q | d | v | r | f |
|   |   |   |   |   |   |   |   |   |   |   |
| a | i | o | y | g |   | l | h | t | n | s |
| < | > | ~ |   |   |   |   |   |   |   |   |
| , | . | - | c | j |   | k | m | b | x | z |
|•••|•••|TAB|LWR|SPC|   |OSS|RSE|RET|•••|•••|

### Modifier keys

Modifier keys are on the same side as the layer key (RSE or LWR) on the home row, on every layer below Base. This reduces finger contortion when chording with modifiers. Hyper and Meh keys are not real modifiers but chords of normal modifiers -- Hyper is every modifier key, and Meh is every key except shift. These are rarely used by existing keyboard shortcuts in any OS. Hyper calls Alfred and Meh calls Rectangle, a window manager. Infrequent layer keys are also available on the bottom row.

## LWR

Lower contains a number pad that uses the typical number row keys. The shifted versions are above. Some shifted keys have been modified from normal JIS to reduce redundancy. XXX indicates key held to access layer.

|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|
|---|---|---|---|---|---|---|---|---|---|---|
|   |   |   |   |   |   | ; | ^ | ( | ) | : |
|   |Meh|Hyp|   |   |   | + | 7 | 8 | 9 | * |
|   |   |   |   |   |   | = | $ | % | & | ? |
|Sft|Opt|Cmd|Ctl|   |   | - | 4 | 5 | 6 | / |
|   |   |   |   |   |   | \|| ! | @ | # | _ |
|   |FN2|FN1|SYM|   |   | ¥ | 1 | 2 | 3 | 0 |
|•••|•••|...|XXX|...|   |DEL|SYM|BkS|•••|•••|

## SYM

The Symbol layer is accessed via either both thumb layer keys in succession or a layer thumb key and and index finger key.
Most characters are simply the shifted versions, more easily accessed from the thumbs rather than the pinky finger shift. 
This layer is vital for home row access to brackets.

|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|
|---|---|---|---|---|---|---|---|---|---|---|
|   |Meh|Hyp|   |   |   | ; | [ | ] | ^ | : |
|Sft|Opt|Cmd|Ctl|   |   | = | ( | ) | @ | ? |
|   |FN2|FN1|XXX|   |   | \|| { | } | ` | _ |
|•••|•••|...|XXX|...|•••|...|XXX|...|•••|•••|


## RSE

The Raise layer includes navigation, copy and paste, and some redundant square brackets.
Here, we also have Grave Escape -- ESC on press, tilde when shifted, and grave mark with Command key held.
The navigation keys are on the left side of the keyboard because the most frequently used arrow keys are down and right (for navigating directories and documents that start top left), placing them under stronger fingers on the home row. Copy and paste are also under stronger fingers.

|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|
|---|---|---|---|---|---|---|---|---|---|---|
|Undo|Cut |Copy|Pste|Redo|| |   |Hyp|Meh|   | 
|←  |↑  |↓  |→︎  | [ |   |   |Ctl|Cmd|Opt|Sft| 
|Home|PgDn|PgUp|End | ] | | |EXT|MSE|   |   |
|•••|•••| ` |EXT|SPC|   |...|XXX|...|•••|•••|
|   |   |ESC|   |   |   |   |   |   |   |   |
|   |   |~  |   |   |   |   |   |   |   |   |

## EXT

The Extend layer is to place miscellaneous keys on the home row, notably Play/Pause. 
It also features macro keys that use Alfred to either: Google a term, translate it, or search for the definition.

### Caps Word
The mostly useless Caps Lock key is relegated here, in favour of the smart QMK Caps Word that is enabled by pressing both home index finger keys (`Y` and `H`) and automatically turns off on space or other keypress. 

|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|
|---|---|---|---|---|---|---|---|---|---|---|
|Caps|L2en|L1jp||   |   |   |   |Hyp|Meh|   | 
|Mute|VolUp|VolDn|Play| | | |Ctl|Cmd|Opt|Sft| 
|    |Dfine|Gtrns|GooGL|| | |XXX|MSE|   |   |
|•••|•••|...|XXX|...|•••|...|XXX|...|•••|•••|

## MSE

The rarely used Mouse layer has mouse direction keys, mouse wheel direction keys, mouse buttons, and Mac print screen options. The power, sleep, and wake keys are in a contorted position to avoid accidental press. 

|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|
|---|---|---|---|---|---|---|---|---|---|---|
|   |BT2|BT2|BT3|SRCBLK||PWR|   |Hyp|Meh|   |
|MLT|MUP|MDN|MRT|SRCSEL||SLP|Ctl|Cmd|Opt|Sft|
|WLT|WUP|WDN|WRT|SRC|   |WKE|EXT|XXX|   |   |
|•••|•••|...|...|...|•••|...|XXX|...|•••|•••|

## FN1

Function keys are rarely used on Mac but here for prosperity. Base layer switches and One Shot Toggle keys are in contorted positions to avoid accidental press.

|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|
|---|---|---|---|---|---|---|---|---|---|---|
|   |Meh|Hyp|   |Dvarf|    |PRS|F9 |F10|F11|F12|
|Sft|Opt|Cmd|Ctl|Dvorak|   |SCL|F5 | F6| F7| F8|
|OSTOGG|FN2|XXX|SYM|Qwerty||PSE|F1 | F2| F3| F4|
|•••|•••|...|XXX|...|•••|...|...|...|•••|•••|

## FN2

Who need function keys up to 24? absolutely nobody. QMK Bootloader and QMK Reboot are in contorted positions to avoid accidental press.

|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|•••|
|---|---|---|---|---|---|---|---|---|---|---|
|QBT|Meh|Hyp|   |   |   |   |F21|F22|F23|F24|
|Sft|Opt|Cmd|Ctl|   |   |INS|F17|F18|F19|F20|
|QRB|XXX|FN1|SYM|   |   |   |F13|F14|F15|F16|
|•••|•••|...|XXX|...|•••|...|...|...|•••|•••|

[1] Dvarf is an alpha key layout created by o-x-e-y, that is based on Dvorak.
[x] DONE Fix shift override
[ ] TODO Finish whole keymap below

### Whole keymap

|•••|...|•••|...|•••|...|•••|...|•••|...|•••|...|•••|...|•••|...|•••|...|•••|...|•••|...|•••|
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|QBT| " |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | ' | ⎌ |   | U |   |   | O  |   |   | W  |   |   | P |   |   |   |   |   |   |   |   |   |   |   |   |   |
|CPS|   |   |L2EN|  |  |L1JP   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
