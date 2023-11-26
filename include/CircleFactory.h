#ifndef CIRCLEFACTORY_H
#define CIRCLEFACTORY_H

#include "Circle.h"
#include "Enclosure.h"
#include "vector"

class CircleFactory{

    public:

        static int count;
        static std::vector<Circle*> circles;

        static void generateCircles(Enclosure* enclosure, double radius);

};

int CircleFactory::count = 0;
std::vector<Circle*> CircleFactory::circles = {};


void CircleFactory::generateCircles(Enclosure* enclosure, double radius){
    double curr_x = radius;
    double curr_y = radius;
    
    while (curr_y + radius <= enclosure->height){

        while (curr_x + radius <= enclosure->width){

            Circle* new_circle = new Circle(radius, curr_x + enclosure->xpos, curr_y + enclosure->ypos);
            
            circles.push_back(new_circle);
            new_circle->drawCircle();

            curr_x += radius * 2;
            count++;
        }

        curr_y += radius * 2;
        curr_x = radius;

    }
}

#endif