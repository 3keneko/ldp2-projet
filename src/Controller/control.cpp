#include "control.hpp"
#include <FL/Fl.H>


Controller::Controller(std::shared_ptr<Frog> f)
    : f(f), is_pressed({{'z', false}, {'d', false}, {'q', false}, {'s', false}}) {}

void Controller::decrement() {
    if (count > 0) count--;
}

void Controller::resetPressedKeys() {
    for (auto& [a, last_pressed]: is_pressed) last_pressed = false;
}
void Controller::updatePressedKeys(const char&& last_key_pressed) {
    for (auto&[key, last_pressed]: is_pressed) {
        last_pressed = key == last_key_pressed;
    }
}

void Controller::processKey(char& c) {
    const unsigned int delay_between_moves = 10;
    switch (c) {
        case 'z':
            if (Fl::get_key('z') && !is_pressed['z'] && count == 0) {
                updatePressedKeys('z');
                f->goUp();
                count = delay_between_moves;
            }
            break;
        case 'q':
            if (Fl::get_key('q') && !is_pressed['q'] && count == 0) {
                updatePressedKeys('q');
                f->goLeft();
                count = delay_between_moves;
            }
            break;
        case 's':
            if (Fl::get_key('s') && !is_pressed['s'] && count == 0) {
                updatePressedKeys('s');
                f->goDown();
                count = delay_between_moves;
            }
            break;
        case 'd':
            if (Fl::get_key('d') && !is_pressed['d'] && count == 0) {
                updatePressedKeys('d');
                f->goRight();
                count = delay_between_moves;
            }
            break;
        default:
            return;
    }
}
