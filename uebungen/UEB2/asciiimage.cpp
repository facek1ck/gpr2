#include <iostream>
#include <string>
#include "asciiimage.h"

int width;
int height;
char **pic;
char charset[70] = {'$', '@', 'B', '%', '8', '&', 'W', 'M', '#', '*',
                    'o', 'a', 'h', 'k', 'b', 'd', 'p', 'q', 'w', 'm',
                    'Z', 'O', '0', 'Q', 'L', 'C', 'J', 'U', 'Y', 'X',
                    'z', 'c', 'v', 'u', 'n', 'x', 'r', 'j', 'f', 't',
                    '/', '\\', '|', '(', ')', '1', '{', '}', '[', ']',
                    '\?', '-', '_', '+', '~', '<', '>', 'i', '!', 'l',
                    'I', ';', ':', ',', '"', '^', '`', '\'', '.', ' '};

myAscii::myAscii(int width, int height) {
    this->width = width;
    this->height = height;

    //Erzeugen eines 2-Dimensionalen Arrays
    pic = new char *[width];
    for (int i = 0; i < width; i++) {
        pic[i] = new char[height];
    }

    //Mit 0 auffuellen
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            setPix(x, y, 0);
        }
    }

}

void myAscii::setPix(int x, int y, int color) {
    int index = 70 - color - 1;

    if (index < 0)
        index = 0;
    else if (index > 69)
        index = 69;

    char a = charset[index];
    pic[x][y] = a;
}

void myAscii::show() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            std::cout << pic[x][y];
        }

        std::cout << std::endl;
    }
}

myAscii::~myAscii() {
    //Loeschen aller Pointer des Array
    for (int i = 0; i < width; i++) {
        delete[] pic[i];
    }

    //Speicher des Arrays freigeben
    delete[] pic;
}
