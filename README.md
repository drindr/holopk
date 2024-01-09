# Holo Polkit Agent

Polkit agent that uses whatever dmenu compatible command you provide as a prompt.

# Usage

Add this command to your compositor startup script or `.xinitrc`:  
`holopk <menu command, inlined>`

ie.  
`holopk dmenu`  
`holopk bemenu --password indicator`  
`holopk fuzzel --dmenu`  

### Example from my Hyprland config
`exec-once = holopk fuzzel --dmenu --password=● --lines 0`

# Building
```
    git clone --depth=1 https://github.com/czadowanie/holopk
    cd holopk
    meson setup build --prefix=$HOME/.local --buildtype=minsize
    cd build
    meson install
```

## Special thanks to [xfce-polkit](https://github.com/ncopa/xfce-polkit)
I used it as a reference

