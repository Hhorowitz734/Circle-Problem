#include "../include/Circle.h"
#include <iostream>

void Circle::contractCircle(double newRadius){

    double increment = (radius - newRadius) / 100;

    while (radius != newRadius){

        eraseCircle();
        radius -= increment;
        drawCircle();

        if (radius < newRadius && increment < 0) { break; }
        if (radius > newRadius && increment > 0) { break; }

    }

}