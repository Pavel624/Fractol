# Fractol
## Overall review
Fractol is the second project on the graphical branch at 42. The program takes a fractal name as a parameter and draws it in the 
window.
You can zoom in and out with the mouse wheel. Obviously pattern repeats when you zoom more and more. Also with the julia 
fractal you can change real and imaginary part of a constant. There are 5 different color schemes which set using NUMPAD.
Multithreading is also implemented so program runs much more faster. 
See menu in the console to get additional information.
![](https://user-images.githubusercontent.com/39954654/63109213-55134480-bf91-11e9-82e4-ce109c38cfb3.png)
## Useful links
1. [Julia and Mandelbrot Sets](https://lodev.org/cgtutor/juliamandelbrot.html)
2. [Useful wiki for this project](https://github.com/VBrazhnik/Fract-ol/wiki)
3. [man pthread_create](http://man7.org/linux/man-pages/man3/pthread_create.3.html)
4. [man pthread_join](http://man7.org/linux/man-pages/man3/pthread_join.3.html)
## TO DO
1. 2 valid parameters result in 2 open windows (http://man7.org/linux/man-pages/man2/fork.2.html)
## Installation
```
make
./fractol [julia]/[mandelbrot]/[burning_ship]/[tricorn]/[douady_rabbit]/[celtic_mandelbrot]/[heart_mandelbrot]
```
Works on Mac and Linux.
