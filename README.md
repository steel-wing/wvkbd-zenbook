# wvkbd-zenbook - a suckless onscreen keyboard for the Asus Zenbook Duo

This is a slightly modified version of the default wvkbd `deskintl` layout, which aims to bring a similar visual and functional typing experience
to the Asus Zenbook Duo on Linux as is had by default on Windows.

<img title="screenshot" alt="A screenshot of an on-screen keyboard" src="/contrib/screenshot-2025-10-12_18-28-45.png">

## Features

 - Typing, modifier locking, layout switching
 - Positive visual feedback on key presses
 - Custom layouts and underlying keymaps
 - On-the-fly layout and keymap switching
 - Custom color schemes
 - Proper font drawing
 - Intuitive layouts
 - International layouts (cyrillic, arabic, persian, greek, georgian)
 - Support for 'Copy' keys which are not on the keymap
 - Emoji support
 - Compose key for character variants (e.g. diacritics)
 - Show/hide keyboard on signals (SIGUSR1 = hide, SIGUSR2 = show, SIGRTMIN = toggle)
 - Automatic portrait/landscape detection and subsequent layout switching

There are some areas that still need work:

 - An on screen touchpad would be incredible, but will likely require incredible amounts of work
 - Make sure the virtual input method in wayland is working as best as it can
 - Support for input method protocol in wayland, ability to respond to text
   fields

## Install

You'll need the following developer packages

 - cairo
 - pango
 - wayland-client
 - xkbcommon

You also need [scdoc](https://git.sr.ht/~sircmpwn/scdoc/) to generate the documentation.

The default set of layouts is called `zenbook`, which groups various layouts aimed at mobile devices
and also attempts to accommodate various international users. Run `make`. The resulting binary is called `wvkbd-zenbook`.

## Usage

Run `wvkbd-zenbook -L 600`. Choose a different number for a different height value.

You can switch between the layouts/layers of the keyboard by pressing the
⌨ key (little keyboard) the bottom-left (press shift to iterate back instead of
forward). If you only want a subset of the available layers, you can define
which you want and in what order you want to cycle through them using the
`-l` parameter (or `--landscape-layers` for landscape mode). This takes takes a ordered comma separated list of layout names
that are defined in your layout set.

The keyboard can be hidden by sending it a `SIGUSR1` signal, shown again by sending it `SIGUSR2` or toggled by sending it `SIGRTMIN`.
This saves some start up time and may be appropriate in some low-resource environments.

Wvkbd has an output mode `-o` that will echo its output to standard output. This facility can be used if users want
audio/haptic feedback, a feature explicitly out of scope for wvkbd. To achieve this, simply pipe wvkbd's output through the external tool
[clickclack](https://git.sr.ht/~proycon/clickclack):

`$ wvkbd-zenbook -l simple,special,emoji -o | clickclack -V -f keypress.wav`

Another output mode, `-O` will let the keyboard output keys which are swiped over. It can be used by an external program, such as [swipeGuess](https://git.sr.ht/~earboxer/swipeGuess) to get swipe-typing support.

`$ wvkbd-zenbook -O | swipeGuess.sh words.txt | completelyTypeWord.sh`

### wvkbd - Compose button

The default mobile international layout features a Compose button (`Cmp`)
which, when combined with another key, opens up a layout that offers variants
for that key. This is similar to functionality that other keyboards implemented
using a *long press* (wvkbd has no such notion, holding a key will repeat
it like on a physical keyboard).

For example, press Cmp + a to access variants with diacritics like á,à,â,ä, etc.. 

Most layouts also feature the following that are less obvious:

* Press Cmp + ``.`` to access more punctuation
* Press Cmp + ``-`` or ``,`` to access 'mathematical' symbols (+,-,=,etc)
* Press Cmp + ``'`` or ``0`` or ``9`` to access more brackets and quotes
* Press Cmp + ``q`` to access emojis

Last, but not least, pressing Cmp + space or Cmp + ⌨  or Cmp + Abc opens up an index that allows you to immediately jump to any
layout by name, even layouts not explicitly added to your layers on startup.