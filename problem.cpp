#include "include/Circle.h"
#include "include/Enclosure.h"
#include "include/CircleFactory.h"

//RUN THIS CODE WITH cd "/Users/bhorowitz/Documents/CPLUSPLUS/CircleAreaProblem/" && g++ problem.cpp -o problem -I/opt/homebrew/Cellar/raylib/4.5.0/include -L/opt/homebrew/lib -lraylib -std=c++11 && "/Users/bhorowitz/Documents/CPLUSPLUS/CircleAreaProblem/problem"


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


        EndDrawing();
    }

    // Clean up and exit
    CloseWindow();
    return 0;
}
