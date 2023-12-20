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
#include <iostream>
#include "frogview.hpp"
#include <memory>
#include <tuple>
#include "../constants.hpp"
#include "../utils.hpp"
#include "../tooling/colors.hpp"
#include "../tooling/drawing_methods.hpp"

using namespace constants;
/// Retrieves the coordinate at which the frog should be placed
/// according to the column and lane it is in
std::tuple<int, int> getImagePos(const Frog& frog) {
    auto x = frog.getX();
    auto y = getLanePos(frog.getLane());
    return std::make_tuple(x, y);
}
/// * <------- LANE 8 -------> */ <- y=0
/// * <------- LANE 7 -------> */ <- y=1
/// * <------- LANE 6 -------> */ <- y=2
/// ...
///

// Draws the life counter in the board
void FrogView::showLives() {
    constexpr unsigned int LIVE_SIZE = 25;
    constexpr int X_POS = 25;
    constexpr int Y_POS = 25;
    constexpr int DIST_BETWEEN = 50;
    for (int i = 0; i <= 2; i++) {
        SquareDrawer sq { X_POS+i*DIST_BETWEEN, Y_POS, LIVE_SIZE, Color::LIVE_ON };
        if (i >= frog->getLives()) sq.colorSwitch(Color::LIVE_OFF);
        sq.draw();
    }
}

/// Draws the frog at the coordinates specified by
/// getImagePos.

/*
void FrogView::draw() {
    int a, b;
    std::tie(a, b) = getImagePos(*frog);
    //auto frog_drawing = std::make_unique<Fl_PNG_Image>("14-1.png");
    //frog_drawing->draw(a, b, FROG_WIDTH, FROG_HEIGHT);
    fl_draw_box(FL_FLAT_BOX, a, b, frog::WIDTH, frog::HEIGHT, FL_GREEN);
    showLives();
}
*/

void FrogView::draw() {
    int a, b;
    std::tie(a, b) = getImagePos(*frog);
    FrogDirection dir = frog->getDirection();
    std::string to_draw;
    switch(dir) {
        case FrogDirection::North:
            to_draw = frog_north_jpeg;
            break;
        case FrogDirection::South:
            to_draw = frog_south_jpeg;
            break;
        case FrogDirection::West:
            to_draw = frog_west_jpeg; 
            break;
        case FrogDirection::East:
            to_draw = frog_east_jpeg;  
            break;
        default:
            break;
    }
    current_image.changeX(a);
    current_image.changeY(b);
    current_image.changeImg(to_draw);
    current_image.draw();
}
