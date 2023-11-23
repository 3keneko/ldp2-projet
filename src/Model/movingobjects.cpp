#include "movingobjects.hpp"

bool MovingObject::collide(Frog& frog) {
    if (speed > 0)
        return frog.getColumn() <= head &&
            frog.getColumn() >= head - size;
    else
        return frog.getColumn() >= head &&
            frog.getColumn() <= head + size;
}

bool Turtle::collide(Frog& frog) {
    return !diving && MovingObject::collide(frog);
}
