//
// Created by Gabriel Asherov on 2019-05-01.
//

#include "mandelbrot.h"

#include "mandelbrot.h"
#include "asciiimage.h"
#include <iostream>


using namespace std;


void mandelbrot()
{
    int width;
    int height;
    double x0;
    double y0;
    double x1;
    double y1;
    int max; //iterations

    cout << "Enter Width: " << endl;
    cin >> width;

    cout << "Enter Height: " << endl;
    cin >> height;

    cout << "Enter x0: " << endl;
    cin >> x0;

    cout << "Enter y0: " << endl;
    cin >> y0;

    cout << "Enter x1: " << endl;
    cin >> x1;

    cout << "Enter y1: " << endl;
    cin >> y1;

    cout << "Enter max: " << endl;
    cin >> max;

    myAscii mandelbrot(width, height);

    double x;
    double y;

    //scale image according to imaginary image
    for (int s = 0; s<width; s++) {
        x = x0 + (x1 - x0) / ((double)width)*(double)s;
        for (int t = 0; t<height; t++) {
            y = y0 + (y1 - y0) / ((double)height)*(double)t;

            double zr = 0;
            double zi = 0;
            int i;

            //calculate color code
            for (i = 0; i < max; ++i) {
                // calculate next iteration
                double nextzr = zr * zr - zi * zi + x;
                double nextzi = 2 * zr * zi + y;

                if (nextzr * nextzr + nextzi * nextzi > 4) {
                    break; //Zeichnen
                }
                zr = nextzr;
                zi = nextzi;
            }

            int color = i % 70;
            mandelbrot.setPix(s, t, color);
        }
    }

    mandelbrot.show();
}