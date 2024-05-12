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
- zoom into center of screen: `+` (or `=`) and `-` buttons
- moving position by numpad arrows and with `w` `a` `s` `d` buttons
- upscaling and downscaling render precision: `up` and `down` arrow keys
- changing color palettes: `left` ans `right` arrow keys
- changing set parameters: `shift` + `w` `a` `s` `d` buttons (only for julia set)
- making screenshot: `p`
- print information about position and set parameters: `i`
- exit by pressing `x` key

## Dependencies
you will need these packages: `make gcc clang`
and GUIlib window library *(https://github.com/tlucanti/GUIlib)*

## Installation
1) put GUIlib repo into parent directory to get this structure:
	```
	..
	├─ Fract-ol
	└─ GUIlib
	```
2) build GUIlib library following its `README`
3) set enviroment variable `$GUILIB` to select GUIlib window frontend
4) build Fract-ol with `make`

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

## Examples

Example of Mandelbrot from set from image above:
```
./Fract-ol m -R1920+1080 -c-0.743643-0.131826i -w2e-5 -d1300
```

Example of spiral in Julia set
```
./Fract-ol j -c-3.45e-4i+7.05e-4 -w0.0004 -d6000 -s4 -R1920+1080
```