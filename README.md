# Fract-ol
### real-time interactive fractal zoomer

Fract-ol shows you depths of famous fractals - Mandelbrot set, Julia set, Newton pool set in real time. You can zoom into the fractal almost infinitely.

![img](https://github.com/antikostya/Fract-ol/blob/master/img/scr.jpg?raw=true)

## Features
- Linux and OSX support
- Mandelbrot set fractal
- Julia set fractal
- Newton pool fractal
- mooving and zooming by keyboard and mouse
- select location and parameters of fractal
- making screenshots in .bmp format

## Keyboard shortcuts
- zoom into mouse position: `mousewheel`
- zoom into center of screen: `+` and `-` buttons
- mooving position by numpad arrows
- upscaling and downscaling iterations: `up` and `down` keys
- changing color palettes: `left` ans `right` keys
- changing set parameters: `w` `a` `s` `d` buttons
- making screenshot: `p`
- print information about position and set parameters: `i`

## Dependencies
you will need these packages: `make gcc clang xorg libxext-dev libbsd-dev`

## Installation
### Linux
run in the root of repository to install dependence packages
```
sudo make install
```
run in the root of repository to build project
```
make
```
this may help to speed-up program
```
make f
```
to clean object files
```
make clean
```
to clean all binaries
```
make fclean
```

## Launching
simply run command
```
./Fract-ol [set]
```
where [set] is one of options - `mandelbrot` or `m`, `julia` or `j`, `newton` or `pool` or `n`
##
You can get information about launch options by command
```
./Fract-ol --help
```
