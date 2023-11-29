#include "/opt/homebrew/Cellar/raylib/4.5.0/include/raylib.h"

class Slider {

    public:
        Rectangle bar;
        Rectangle handle;

        float value;
        float minValue;
        float maxValue;

        static Slider CreateSlider(int x, int y, int width, int height, float minValue, float maxValue);

        void updateSlider();
        void drawSlider();
};