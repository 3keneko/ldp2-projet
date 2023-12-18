#include "frog.hpp"

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

// Moving the frog (interacting with controller)
void Frog::goUp() {
    lane_number++;
}

void Frog::goDown() {
    if (lane_number) {
        lane_number--;
    }
}

void Frog::goLeft() {
    x -= LEAP_SIZE;
}

void Frog::goRight() {
    x += LEAP_SIZE;
}


// Moves the frog in the given direction
void Frog::go(int speed) {
    x += speed;
}


// Checks if the frog is inside the board
bool Frog::inBoard() {
    return ( 0 <= x ) &
            ( x <= constants::window::WIDTH );
}


// In charge of life and death of the Frog
void Frog::kill() {
    lives--;
    if (alive()) {
        x = constants::window::WIDTH / 2;
        lane_number = 0;
    }
}
