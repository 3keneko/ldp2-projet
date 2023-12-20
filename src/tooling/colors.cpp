#include "colors.hpp"
#include <FL/Enumerations.H>

Fl_Color colors::color_convert(const Color& color) {
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

    }
}
