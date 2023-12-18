#include "movingobjects.hpp"
#include "frog.hpp"
#include "../constants.hpp"
#include <iostream>

void MovingObject::move() {
    using namespace constants;
    centerX += speed;
    if (centerX < 0) {
        centerX += window::WIDTH + window::PADDING;
    }
    centerX %= (window::WIDTH + window::PADDING);
}

bool MovingObject::collide(Frog& frog) {
    return (static_cast<int>(getUpX() + getSize()) >= frog.getX()
            && static_cast<int>(getUpX()) <= frog.getX() + constants::frog::WIDTH)
            && frog.getLane() == getId();
/*
    return ((static_cast<int>(getUpX()) <= frog.getX() && 
            static_cast<int>(getUpX() + getSize()) >= frog.getX()) 
            || (static_cast<int>(getUpX()) <= frog.getX() + constants::frog::WIDTH 
            && static_cast<int>(getUpX()+ getSize()) >= frog.getX() + constants::frog::WIDTH))
            && frog.getLane() == getId();
*/
}

bool Turtle::collide(Frog& frog) {
    return !diving && MovingObject::collide(frog);
}

bool Log::collide(Frog& frog) {
    return (static_cast<int>(getUpX()) <= frog.getX()
            && static_cast<int>(getUpX()+ getSize()) >= frog.getX() + constants::frog::WIDTH)
            && frog.getLane() == getId();
}