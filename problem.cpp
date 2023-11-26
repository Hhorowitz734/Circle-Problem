#include "/opt/homebrew/Cellar/raylib/4.5.0/include/raylib.h"
#include <iostream>
#include <unistd.h> 
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>

//RUN THIS CODE WITH cd "/Users/bhorowitz/Documents/CPLUSPLUS/CircleAreaProblem/" && g++ problem.cpp -o problem -I/opt/homebrew/Cellar/raylib/4.5.0/include -L/opt/homebrew/lib -lraylib -std=c++11 && "/Users/bhorowitz/Documents/CPLUSPLUS/CircleAreaProblem/problem"

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


int main()
{

    // Initialize the window and set the frame rate
    const int screenWidth = 1000;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "CircleAreaProblem");
    SetTargetFPS(60);
    ClearBackground(BLACK);

    Enclosure* test = new Enclosure;

    

    // Main game loop
    while (!WindowShouldClose())
    {
        


        BeginDrawing();

        test->drawEnclosure();
        CircleFactory::generateCircles(test, 50);
        std::cout << test->width << ' ' << test->height << '\n';


        EndDrawing();
    }

    // Clean up and exit
    CloseWindow();
    return 0;
}
