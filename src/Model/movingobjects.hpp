#ifndef MOVINGOBJECTS_H_
#define MOVINGOBJECTS_H_
#include "frog.hpp"
#include <tuple>

const int HEIGHT_LANE = 20;


/// An abstract class that represents moving objects

class MovingObject {
  protected:
    const int speed;
    unsigned int centerX;
    const unsigned int size;
    const unsigned int lane_id;
  public:
    MovingObject(const int speed, unsigned int centerX, const unsigned int size, const unsigned lane_id):
      speed(speed), centerX(centerX), size(size), lane_id(lane_id) {}

    // moves the object
    void move() {
          centerX += speed;
    }

    unsigned getSize() const { return size; }
    unsigned getId() { return lane_id; }

    // returns the x coordinate of the center of the object
    unsigned getCenterX() { return centerX; }
    std::tuple<unsigned, unsigned> getBoundaries() {
      if (centerX <= size / 2) {
        return std::make_tuple(0, centerX+size/2);
      }
      return std::make_tuple(centerX - size/2, centerX + size/2);
    }

    // returns the y coordinate of the top left element of the object
    unsigned getUpY() { return lane_id * HEIGHT_LANE; }
    std::tuple<unsigned, unsigned> getUpLeft()  {
      if (centerX <= size / 2) {
        return std::make_tuple(0, getUpY());
      }
      return std::make_tuple(centerX - size/2, getUpY());
    }

    // returns the x coordinate of the top left element of the object
    unsigned getUpX() {
      return std::get<0>(getUpLeft());
    }

    // returns true if this element collides with the frog
    virtual bool collide(Frog& frog);

    int getSpeed() const { return speed; }
    virtual ~MovingObject() {}
};


class Car: public MovingObject {
    public:
        Car(int speed, unsigned int head, const unsigned int size, const unsigned lane_id) :
            MovingObject(speed, head, size, lane_id) {}
        ~Car() {}
};

class Turtle: public MovingObject {
    private:
        bool diving;
    public:
        Turtle(int speed, const unsigned int head, const unsigned int size, const unsigned lane_id):
            MovingObject(speed, head, size, lane_id), diving(false) {}
        void dive() { diving=true; }
        void undive() { diving=false; }
        bool collide(Frog& frog) final override;
        ~Turtle() {}
};

class Log: public MovingObject {
    public:
        Log(int speed, unsigned int head, const unsigned int size, const unsigned lane_id):
            MovingObject(speed, head, size, lane_id) {}
        ~Log() {}
};

#endif // MOVINGOBJECTS_H_
