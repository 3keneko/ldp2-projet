#include "lanes.hpp"

int MovingObject::getSpeed() {
    return speed;
}

bool Car::collide(Frog& frog) {
    if (speed > 0)
        return frog.getColumn() <= head &&
            frog.getColumn() >= head - size;
    else
        return frog.getColumn() >= head &&
            frog.getColumn() <= head + size;
}
