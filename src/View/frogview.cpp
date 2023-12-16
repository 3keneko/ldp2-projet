// /*
// This is the code containing the functions and classes that are used with fltk
// to show the game to the user.
// */
// #include "frogview.hpp"

// FrogGraphics::FrogGraphics(Rectangle frogImage, Frog& frog)
//     : frogImage{frogImage}, frog{frog} {}

// void FrogGraphics::draw() {
//     frogImage.draw(frogPos.xFltk(), frogPos.yFltk());
// }

// void FrogGraphics::moveLeft() {}
// void FrogGraphics::moveRight() {}
// void FrogGraphics::moveFrwrd() {}
// void FrogGraphics::moveBckwrds() {}
#include <FL/Enumerations.H>
#include <iostream>
#include "frogview.hpp"
#include <memory>
#include <tuple>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include "../constants.hpp"

using namespace constants;
/// Retrieves the coordinate at which the frog should be placed
/// according to the column and lane it is in
std::tuple<int, int> getImagePos(const Frog& frog) {
    auto x = frog.getColumn() * lanes::HEIGHT;
    auto y = (lanes::NUMBER - frog.getLane())
        * (lanes::HEIGHT + 1);
    return std::make_tuple(x, y);
}
/// * <------- LANE 8 -------> */ <- y=0
/// * <------- LANE 7 -------> */ <- y=1
/// * <------- LANE 6 -------> */ <- y=2
/// ...
///

/// Draws the frog at the coordinates specified by
/// getImagePos.
void FrogView::draw() {
    int a, b;
    std::tie(a, b) = getImagePos(*frog);
    //auto frog_drawing = std::make_unique<Fl_PNG_Image>("14-1.png");
    //frog_drawing->draw(a, b, FROG_WIDTH, FROG_HEIGHT);
    fl_draw_box(FL_FLAT_BOX, a, b, frog::WIDTH, frog::HEIGHT, FL_GREEN);
}
