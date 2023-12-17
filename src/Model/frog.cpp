#include "frog.hpp"

using namespace constants::frog;

unsigned int Frog::getLane() const {
    return lane_number;
}

int Frog::getX() const {
    return x;
}

void Frog::goUp() {
    lane_number++;
}

void Frog::goDown() {
    if (lane_number) {
        lane_number--;
    }
}

void Frog::goLeft() {
    x -= LEAP_SIZE;
}

void Frog::goRight() {
    x += LEAP_SIZE;
}

bool Frog::inBoard() {
    return ( 0 <= x ) &
            ( x <= constants::window::WIDTH );
}
