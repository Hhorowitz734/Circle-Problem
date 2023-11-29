#include "include/Circle.h"
#include "include/Enclosure.h"
#include "include/CircleFactory.h"
#include "include/Slider.h"

#include <string>
#include <iostream>


//RUN THIS CODE WITH g++ /Users/bhorowitz/Documents/CPLUSPLUS/CircleAreaProblem/problem.cpp /Users/bhorowitz/Documents/CPLUSPLUS/CircleAreaProblem/src/*.cpp -o problem -I/opt/homebrew/Cellar/raylib/4.5.0/include -L/opt/homebrew/lib -lraylib -std=c++11 && /Users/bhorowitz/Documents/CPLUSPLUS/CircleAreaProblem/problem

int main()
{

    // Initialize the window and set the frame rate
    const int screenWidth = 1000;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "CircleAreaProblem");
    SetTargetFPS(60);
    ClearBackground(BLACK);

    Enclosure* test = new Enclosure;

    Slider test_slider = Slider::CreateSlider(950, 200, 300, 20, 80, 100);

    double circle_r = 80.0;
    double old_r = 80.0;

    CircleFactory::generateCircles(test, circle_r);

    // Main game loop
    while (!WindowShouldClose())
    {   

        test_slider.updateSlider();
        test_slider.drawSlider();

        circle_r = test_slider.value;

        std::cout << old_r << ' ' << circle_r << '\n';

        if (old_r != circle_r) {
            //test->clearEnclosure();
            for (Circle* circle : CircleFactory::circles){
                circle->contractCircle(circle_r);
            }
            
            std::string real_fit = "Max Real Fit: " + std::to_string(test->getMaxFit(circle_r));
            std::string ideal_fit = "Max Ideal Fit: " + std::to_string(test->getMaxTheoreticalFit(circle_r));

            old_r = circle_r; 
        }

        std::string real_fit = "Max Real Fit: " + std::to_string(test->getMaxFit(circle_r));
        std::string ideal_fit = "Max Ideal Fit: " + std::to_string(test->getMaxTheoreticalFit(circle_r));

        DrawText(real_fit.c_str(), 10, 10, 30, GREEN);
        DrawText(ideal_fit.c_str(), 10, 50, 30, YELLOW);



        BeginDrawing();




        EndDrawing();
    }

    // Clean up and exit
    CloseWindow();
    return 0;
}
