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

const int HEIGHT_LANE = 20;
const int FROG_WIDTH = 200;
const int FROG_HEIGHT = 200;

std::tuple<int, int> getImagePos(const Frog& frog) {
    auto x = frog.getLane() * (HEIGHT_LANE + 1);
    auto y = frog.getColumn() * 30;
    return std::make_tuple(x, y);
}

void FrogView::draw() {
    int a, b;
    std::cout << "frog drawn" << std::endl;
    std::tie(a, b) = getImagePos(*frog);
    //auto frog_drawing = std::make_unique<Fl_PNG_Image>("14-1.png");
    //frog_drawing->draw(a, b, FROG_WIDTH, FROG_HEIGHT);
    fl_draw_box(FL_FLAT_BOX, a, b, FROG_WIDTH, FROG_HEIGHT, FL_GREEN);
}
