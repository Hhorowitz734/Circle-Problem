#include "../include/Slider.h"

/**
 * @brief Clamps a value within a specified range.
 *
 * @tparam T The data type of the value and bounds. Must support comparison operators.
 * @param value The value to be clamped.
 * @param min The lower bound of the range.
 * @param max The upper bound of the range.
 * @return T The clamped value. If 'value' is less than 'min', returns 'min'. 
 *         If 'value' is greater than 'max', returns 'max'. Otherwise, returns 'value'.
 *
 */
template<typename T>
T Clamp(T value, T min, T max) {
    return (value < min) ? min : (value > max) ? max : value;
}

/**
 * @brief Creates a vertical slider object.
 *
 * This function initializes a vertical slider with specified position, size, and value range.
 * The slider consists of a bar and a handle, where the handle can move vertically along the bar.
 *
 * @param x The x-coordinate of the top-left corner of the slider.
 * @param y The y-coordinate of the top-left corner of the slider.
 * @param width The width of the slider (and also the handle).
 * @param height The height of the slider bar.
 * @param minValue The minimum value of the slider.
 * @param maxValue The maximum value of the slider.
 * @return Slider A Slider object with the specified properties.
 *
 * The function sets the initial value of the slider to the midpoint of minValue and maxValue.
 * The handle's size is set to be a square with sides equal to the width of the slider.
 * Note: The x and y coordinates represent the position of the slider bar in the window.
 */
Slider Slider::CreateSlider(int x, int y, int width, int height, float minValue, float maxValue) {
    
    Slider slider;

    slider.bar = {
         (float)x, 
         (float)y, 
         (float)height, 
         (float)width 
    };

    // The handle is a vertical bar
    slider.handle = { 
        (float)x, 
        (float)(y + height / 2), 
        (float)height, 
        (float)height
    };

    slider.minValue = minValue;
    slider.maxValue = maxValue;
    slider.value = (minValue + maxValue) / 2;

    return slider;

}

void Slider::updateSlider() {

    Vector2 mousePoint = GetMousePosition();
    
    if (CheckCollisionPointRec(mousePoint, handle)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            handle.y = mousePoint.y - handle.height / 2;
            handle.y = Clamp(handle.y, bar.y, bar.y + bar.height - handle.height);
            value = ((handle.y - bar.y) / (bar.height - handle.height)) * (maxValue - minValue) + minValue;
        }
    }

}

void Slider::drawSlider() {

    DrawRectangleRec(bar, GRAY);
    DrawRectangleRec(handle, DARKGRAY);

}
