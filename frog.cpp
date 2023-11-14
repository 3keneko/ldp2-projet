#include "frog.hpp"

unsigned int Frog::getLane() {
    return lane_number;
}

unsigned int Frog::getColumn() {
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
