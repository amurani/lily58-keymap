# Lily58 Layout

TODO: @amurani

### Setup

- Clone the qmk firmware repository

```bash
➜ git clone https://github.com/qmk/qmk_firmware.git
```

- Change directories to the lily58 keymaps directory

```bash
➜ cd ~/qmk_firmware/keyboards/lily58/keymaps
```

- Add this keymap as a submodule

```bash
➜ git submodule add git@github.com:amurani/lily58-keymap.git amurani
```

- Change directories back to the root qmk firmware directory

```bash
➜ cd ~/qmk_firmware
```

- Compile the keymap via the qmk firmware cli

```bash
➜ qmk compile -kb lily58 -km amurani
```

- Flush the keymap to the connected board

```bash
➜ sudo make lily58:amurani:avrdude
```
