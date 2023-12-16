#include "movingobjects.hpp"
#include "frog.hpp"
#include "../constants.hpp"

void MovingObject::move() {
    using namespace constants;
    centerX += speed;
    if (centerX < 0) {
        centerX += window::WIDTH + window::PADDING;
    }
    centerX %= (window::WIDTH+window::PADDING);
}

bool MovingObject::collide(Frog& frog) {
    int a, b;
    std::tie(a, b) = getBoundaries();
    return a <= frog.getColumn() && b <= frog.getColumn() &&
        frog.getLane() == getId();
}

bool Turtle::collide(Frog& frog) {
    return !diving && MovingObject::collide(frog);
}
