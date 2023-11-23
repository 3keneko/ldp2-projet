#ifndef FROGVIEW_HPP
#define FROGVIEW_HPP

#include "fltk_tools.hpp"
#include "frog.hpp"

class FrogGraphics {
    Rectangle frogImage;   // The type will be changed to Fl_Image
    Frog frog;
    Point frogPos{0, 7};   // At the start by default
    const unsigned int size = 40;
    const unsigned int maxTickMove = 10;  // How many ticks the frog will take
                                          // to move from a case to another
    unsigned int tick = 0;

public:
    FrogGraphics(Rectangle frogImage, Frog& frog);
    void draw();
    void moveLeft();
    void moveRight();
    void moveFrwrd();
    void moveBckwrds();
};

#endif

