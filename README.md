Usage

First, compile the project using make:

make


If everything is already compiled, you may see:

make: Nothing to be done for 'all'.


Run the program as follows:

./fractol Mandelbrot <number_of_iterations>


or

./fractol Julia <1 to 4> <number_of_iterations>

Parameters

Number of iterations:
This value controls how many times the fractal calculation is repeated per pixel.
Higher numbers increase detail and precision, but may reduce performance.
Lower numbers render faster but with less detail.

Julia parameter (1 to 4):
Selects different predefined Julia sets.

Controls

Mouse scroll wheel:
Use the scroll wheel to zoom in and out of the fractal for interactive exploration.
