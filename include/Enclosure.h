#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include "/opt/homebrew/Cellar/raylib/4.5.0/include/raylib.h"

class Enclosure {
    
    public:

        //Basic rectangle properties
        double width;
        double height;
        double area;

        int xpos = 100;
        int ypos = 100;

        //Constructors
        Enclosure() : height(GetScreenHeight() - 200), width(GetScreenWidth() - 200), area(width * height) {}
        Enclosure(double height, double width) : height(height), width(width), area(width * height) {}

        //Visualizing functions
        void drawEnclosure(){ DrawRectangleLines( xpos, ypos, width, height, WHITE ); }

        //Calculations

        /**
         * Computes the maximum number of circles of a given radius that can fit within the enclosed space.
         * 
         * @param radius The radius of the circles.
         * @return The maximum number of circles that can fit within the enclosed space.
         */
        int getMaxFit(double radius){

            int horizontal_max = width / (2 * radius);
            int vertical_max = height / (2 * radius);

            return horizontal_max * vertical_max;

        }

};

#endif