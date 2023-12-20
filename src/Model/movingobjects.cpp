#include "movingobjects.hpp"
#include "frog.hpp"
#include "../constants.hpp"
#include <iostream>

void MovingObject::move() {
    using namespace constants;
    x += speed;
    if (x < -static_cast<int>(size)) {
        x += window::WIDTH + window::PADDING + static_cast<int>(size);
    }
    if (x > window::WIDTH + window::PADDING + static_cast<int>(size)) {
        x = -static_cast<int>(size);
    }
}

bool MovingObject::collide(Frog& frog) {
    return ((getX() + static_cast<int>(getSize())) >= frog.getX()
            && getX() <= frog.getX() + constants::frog::WIDTH)
            && frog.getLane() == getId();
/*
    return ((static_cast<int>(getX()) <= frog.getX() &&
            static_cast<int>(getX() + getSize()) >= frog.getX())
            || (static_cast<int>(getX()) <= frog.getX() + constants::frog::WIDTH
            && static_cast<int>(getX()+ getSize()) >= frog.getX() + constants::frog::WIDTH))
            && frog.getLane() == getId();
*/
}

bool Turtle::collide(Frog& frog) {
    return !diving && MovingObject::collide(frog);
}

bool Log::collide(Frog& frog) {
    return (getX() <= frog.getX()
            && (getX()+ static_cast<int>(getSize())) >= frog.getX() + constants::frog::WIDTH)
            && frog.getLane() == getId();
}
