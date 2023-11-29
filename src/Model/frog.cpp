#include "frog.hpp"

unsigned int Frog::getLane() const {
    return lane_number;
}

unsigned int Frog::getColumn() const {
    return column;
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
    column--;
}

void Frog::goRight() {
    column++;
}
