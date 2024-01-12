#ifndef COLORS_H_
#define COLORS_H_

#include <FL/Enumerations.H>

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
    TEXT,
    MENURECTANGLE,
    UNKNOWN,
};

namespace colors {
    Fl_Color colorConvert(const Color& color);
}

#endif // COLORS_H_
