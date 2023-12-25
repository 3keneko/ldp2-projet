#include "frog.hpp"
#include <iostream>

using namespace constants::frog;

// Getters
unsigned int Frog::getLane() const {
    return lane_number;
}

int Frog::getX() const {
    return x;
}

int Frog::getLives() const {
    return lives;
}

FrogDirection Frog::getDirection() const {
    return direction;
}

// Moving the frog (interacting with controller)
void Frog::goUp() {
    lane_number++;
    direction = FrogDirection::North;
}

void Frog::goDown() {
    if (lane_number) lane_number--;
    direction = FrogDirection::South;
}

void Frog::goLeft() {
    x -= LEAP_SIZE;
    direction = FrogDirection::West;
}

void Frog::goRight() {
    x += LEAP_SIZE;
    direction = FrogDirection::East;
}


// Moves the frog in the given direction
void Frog::go(int speed) {
    x += speed;
}


// Checks if the frog is inside the board
bool Frog::inBoard() {
    return ( -25 <= x ) &
            ( x <= constants::window::WIDTH );
}

void Frog::resetPos() {
    x = constants::window::WIDTH / 2;
    lane_number = 0;
    score->reset_best_lane();
}


// In charge of life and death of the Frog
void Frog::kill() {
    lives--;
    if (alive()) {
        resetPos();
    }
}

void Frog::inWaterLilies() {
    resetPos();
    score->reached_waterlily();
}
