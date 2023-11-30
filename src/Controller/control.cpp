/*
This is the code containing the functions and the classes that are used
with FLTK to let the user control the game
*/

#include "control.hpp"
#include <FL/Fl.H>
#include <iostream>

void Controller::processKey() {
    auto c = Fl::event_key();
    switch (c) {
        case 'z':
            f->goUp();
            break;
        case 'q':
            f->goLeft(); break;
        case 's':
            f->goDown(); break;
        case 'd':
            f->goRight(); break;
        default:
            return;
    }
}
