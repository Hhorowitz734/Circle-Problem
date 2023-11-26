#ifndef CIRCLE_H
#define CIRCLE_H

#include "/opt/homebrew/Cellar/raylib/4.5.0/include/raylib.h"
#include <cmath>

class Circle {

    public:
        
        //Basic circle properites
        double radius;
        double area;

        double xpos = 150;
        double ypos = 150;

        //Constructors
        Circle(double radius, double xpos, double ypos) : radius(radius), area(PI * radius * radius), xpos(xpos), ypos(ypos) {}

        //Visualization
        void drawCircle() { DrawCircleLines(xpos, ypos, radius, WHITE); }

};

#endif