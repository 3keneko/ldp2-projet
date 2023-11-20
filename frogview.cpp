/* 
This is the code containing the functions and classes that are used with fltk
to show the game to the user.
*/
#include "frogview.hpp"

FrogGraphics::FrogGraphics(Rectangle frogImage, Frog& frog)
    : frogImage{frogImage}, frog{frog} {}

void FrogGraphics::draw() {
    frogImage.draw(frogPos.xFltk(), frogPos.yFltk());
}

void FrogGraphics::moveLeft() {}
void FrogGraphics::moveRight() {}
void FrogGraphics::moveFrwrd() {}
void FrogGraphics::moveBckwrds() {}