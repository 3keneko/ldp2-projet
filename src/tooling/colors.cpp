#include "colors.hpp"


Fl_Color colors::colorConvert(const Color& color) {
    switch (color) {
        case Color::FROG:
            return FL_GREEN;
        case Color::ROAD:
            return FL_BLACK;
        case Color::WATER:
            return FL_BLUE;
        case Color::SAFE:
            return fl_rgb_color(186, 85, 211); // Purplish
        case Color::LIVE_ON:
            return FL_RED;
        case Color::LIVE_OFF:
            return FL_GRAY;
        case Color::LOG:
            return fl_rgb_color(139, 69, 16); // Brownish
        case Color::TURTLE:
            return fl_rgb_color(3, 75, 3); // Dark green
        case Color::CAR:
            return FL_YELLOW;
        case Color::TEXT:
            return FL_BLACK;
        case Color::MENURECTANGLE:
            return FL_NUM_BLUE;
        case Color::UNKNOWN:
        default:
            return fl_rgb_color(255, 255, 255); // Very white
    }
}
