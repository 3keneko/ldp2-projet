#include "movingobjects.hpp"
#include "../constants.hpp"

// MovingObject

MovingObject::MovingObject(const int speed, int x, const unsigned int size, const unsigned lane_id):
      speed(speed), x(x), size(size), lane_id(lane_id) {}

void MovingObject::move() {
    using namespace constants;
    x += speed;
    if (x < -static_cast<int>(size)) {
        x += window::WIDTH + window::PADDING + static_cast<int>(size);
    }
    if (x > window::WIDTH + window::PADDING + static_cast<int>(size)) {
        x = -static_cast<int>(size);
    }
}

unsigned MovingObject::getSize() const { return size; }

unsigned MovingObject::getId() const { return lane_id; }

int MovingObject::getCenterX() const { return x + static_cast<int>(size) / 2; }

std::tuple<int, int> MovingObject::getBoundaries() const {
    int size_int = static_cast<int>(size);
    return std::make_tuple(x, x+size_int);
}

int MovingObject::getX() const { return x; }

int MovingObject::getSpeed() const { return speed; }

bool MovingObject::isDiving() const {return 0;}

// Car

Car::Car(int speed, unsigned int head, const unsigned int size, const unsigned lane_id) :
            MovingObject(speed, head, size, lane_id) {}

bool Car::collide(Frog& frog) {
    return (getX() + static_cast<int>(getSize()) >= frog.getX()
            && getX() <= frog.getX() + constants::frog::WIDTH)
            && frog.getLane() == getId();
}

// Function to deal with collisions for Logs and Turtles
bool isOnObject(Frog& frog, int objX, int objSize, unsigned int objLane) {
    return objX <= frog.getX()    
            && objX + objSize >= frog.getX() + constants::frog::WIDTH
            && frog.getLane() == objLane;
}

// Turtle

Turtle::Turtle(int speed, const unsigned int head, const unsigned int size
                , const unsigned lane_id)
    :MovingObject(speed, head, size, lane_id), diving(false) {}

void Turtle::dive() { diving=true;}

void Turtle::undive() { diving=false;}

bool Turtle::isDiving() const { return diving; }

bool Turtle::collide(Frog& frog) {
    return !diving 
            && isOnObject(frog, getX(), static_cast<int>(getSize()), getId());
}

// Log

Log::Log(int speed, unsigned int head, const unsigned int size, const unsigned lane_id)
    : MovingObject(speed, head, size, lane_id) {}

bool Log::collide(Frog& frog) {
    return isOnObject(frog, getX(), static_cast<int>(getSize()), getId());
}