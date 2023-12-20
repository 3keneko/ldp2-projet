#ifndef COLORS_H_
#define COLORS_H_

#include <FL/Enumerations.H>
#include <Fl/fl_draw.H>

enum class Color {
    TURTLE,
    FROG,
    LIVE_ON,
    ROAD,
    LIVE_OFF,
    WATER,
    SAFE,
    LOG,
    CAR,
    UNKNOWN,
};


namespace colors {
    Fl_Color color_convert(const Color& color);
}


#endif // COLORS_H_
