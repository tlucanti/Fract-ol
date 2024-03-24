# Fract-ol
### real-time interactive fractal zoomer

Fract-ol shows you depths of famous fractals - Mandelbrot set, Julia set, Newton pool set in real time. You can zoom into the fractal almost infinitely.

![img](https://github.com/antikostya/Fract-ol/blob/master/img/scr.jpg?raw=true)

## Features
- Linux and OSX support
- Mandelbrot set fractal
- Julia set fractal
- Newton pool fractal
- moving and zooming by keyboard and mouse
- select location and parameters of fractal
- making screenshots in .bmp format

## Keyboard shortcuts
- zoom into mouse position: `mousewheel`
- zoom into center of screen: `+` and `-` buttons
- moving position by numpad arrows
- upscaling and downscaling render precision: `up` and `down` arrow keys
- changing color palettes: `left` ans `right` arrow keys
- changing set parameters: `w` `a` `s` `d` buttons (only for julia set)
- making screenshot: `p`
- print information about position and set parameters: `i`
- exit by pressing `x` key

## Dependencies
you will need these packages: `make gcc clang xorg`
and GUIlib window library *(https://github.com/tlucanti/GUIlib)*

## Installation
put GUIlib repo into parent directory to get this structure:
```
..
├─ Fract-ol
└─ GUIlib
```

## Launching
simply run command
```
./Fract-ol [set]
```
where [set] is one of options - `mandelbrot` or `m`, `julia` or `j`, `newton` or `pool` or `n`

##
You can get information about launch options with `--help` option
```
./Fract-ol --help
```
