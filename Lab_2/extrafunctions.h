#ifndef EXTRAFUNCTIONS_H
#define EXTRAFUNCTIONS_H

#include<iostream>
#include"complex.h"
using namespace std;

int INT_INF = 10e8;
float FLOAT_INF = 10e8;

int readInt(int *a) {
    int mode = 0;
    cin >> *a;
    if (!cin) {
        while (getchar() != '\n') {};
        cout << "Incorrect input. Please, enter one integer number.\n";
        mode = -1;
    }
    if (mode == 0) while (getchar() != '\n') {};
    return mode;
}

int readFloat(float *a) {
    int mode = 0;
    cin >> *a;
    if (!cin) {
        while (getchar() != '\n') {};
        cout << "Incorrect input. Please, enter one float number.\n";
        mode = -1;
    }
    if (mode == 0) while (getchar() != '\n') {};
    return mode;
}

int readComplex(Complex *a) {
    int mode = 0;
    double Re, Im;
    cout << "Input real part: ";
    cin >> Re;
    if (!cin) {
        while (getchar() != '\n') {};
        cout << "Incorrect input. Please, enter one float number.\n";
        mode = -1;
        return mode;
    }
    cout << "\t\tInput imaginary part: ";
    cin >> Im;
    if (!cin) {
        while (getchar() != '\n') {};
        cout << "Incorrect input. Please, enter one float number.\n";
        mode = -1;
        return mode;
    }
    a->Set(Re, Im);
    if (mode == 0) while (getchar() != '\n') {};
    return mode;
}

int randomInt() {
    return rand() % 10;
}

float randomFloat() {
    int del = rand() % 7;
    while (del == 0) del = rand() % 7;
    return (rand() % 10) * 1.0 / del;
}

#endif // EXTRAFUNCTIONS_H
