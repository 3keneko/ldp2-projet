#include "movingobjects.hpp"
#include "frog.hpp"

bool MovingObject::collide(Frog& frog) {
    int a, b;
    std::tie(a, b) = getBoundaries();
    return a <= frog.getColumn() && b <= frog.getColumn() &&
        frog.getLane() == getId();
}

bool Turtle::collide(Frog& frog) {
    return !diving && MovingObject::collide(frog);
}
