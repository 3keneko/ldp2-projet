#include "lanes.hpp"

 const int MovingObject::getSpeed() const {
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
