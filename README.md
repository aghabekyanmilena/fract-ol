# Fractol

Fractol is a graphical application written in C that renders fractals in real-time using the MiniLibX graphics library. 
It supports interactive exploration of several fractal types, including Mandelbrot, Julia, and Burning Ship.

## Features

- Real-time rendering of Mandelbrot, Julia, and Burning Ship fractals.
- Zoom in/out with mouse scroll.
- Move the view with arrow keys.
- Change color schemes with the `m` key.
- Lock/unlock Julia set interactivity with the `l` key.
- Adjust iteration depth with `+` and `-`.
- Responsive mouse tracking for Julia sets.

### Requirements

- Linux
- cc
- Make
- MiniLibX (included or install via your 42 environment)

### Build

```bash
make
```

## Usage

```bash
./fractol mandelbrot
./fractol julia x y
./fractol burningship
```

## Notes

- The Julia set responds to mouse movement only when unlocked (`L` key).
- Zooming is centered around the mouse position.
- Color schemes can be customized in `get_color()` function.
