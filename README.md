# Holo Polkit Agent

Polkit agent that uses whatever dmenu compatible command you provide as a prompt.

## MAY THEE BE WARNED: 
As of right now this is very much a proof of concept, I'm not sure
how secure is it to use this thing. Also it might just crash or leak memory.

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

