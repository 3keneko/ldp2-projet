/*
This is the code containing the functions and the classes that are used
with FLTK to let the user control the game
*/

#include "control.hpp"
#include <FL/Fl.H>
#include <iostream>
#include <algorithm>

void Controller::resetPressedKeys() {
    for (auto& [a, last_pressed]: is_pressed) last_pressed = false;
}
void Controller::updatePressedKeys(const char&& last_key_pressed) {
    for (auto&[key, last_pressed]: is_pressed) {
        last_pressed = key == last_key_pressed;
    }
}


void Controller::processKey(char& c) {
    switch (c) {
        case 'z':
            if (Fl::get_key('z') && !is_pressed['z']) {
                updatePressedKeys('z');
                f->goUp();
            }
            break;
        case 'q':
            if (Fl::get_key('q') && !is_pressed['q']) {
                updatePressedKeys('q');
                f->goLeft();
            }
            break;
        case 's':
            if (Fl::get_key('s') && !is_pressed['s']) {
                updatePressedKeys('s');
                f->goDown();
            }
            break;
        case 'd':
            if (Fl::get_key('d') && !is_pressed['d']) {
                updatePressedKeys('d');
                f->goRight();
            }
            break;
        default:
            return;
    }
}
