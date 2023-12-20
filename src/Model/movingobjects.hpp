#ifndef MOVINGOBJECTS_H_
#define MOVINGOBJECTS_H_
#include "frog.hpp"
#include <memory>
#include <tuple>

const int HEIGHT_LANE = 20;


/// An abstract class that represents moving objects

class MovingObject {
  protected:
    const int speed;
    int centerX;
    const unsigned int size;
    const unsigned int lane_id;
  public:
    MovingObject(const int speed, int centerX, const unsigned int size, const unsigned lane_id):
      speed(speed), centerX(centerX), size(size), lane_id(lane_id) {}

    // moves the object
    void move();

    unsigned getSize() const { return size; }
    unsigned getId() { return lane_id; }

    // returns the x coordinate of the center of the object
    int getCenterX() { return centerX; }

    std::tuple<int, int> getBoundaries() {

      int size_int = static_cast<int>(size);
      return std::make_tuple(centerX - size_int/2, centerX + size_int/2);
    }

    // returns the y coordinate of the top left element of the object
    // unsigned getUpY() { return lane_id* HEIGHT_LANE; }
    // std::tuple<unsigned, unsigned> getUpLeft()  {
    //   if (centerX <= size / 2) {
    //     return std::make_tuple(0, getUpY());
    //   }
    //   return std::make_tuple(centerX - size/2, getUpY());
    // }
    // returns the x coordinate of the top left element of the object
    int getUpX() {
      int size_int = static_cast<int>(size);
      return centerX <= size_int / 2 ? 0 : centerX - size_int/2;
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
        bool isDiving() const { return diving; }
        bool collide(Frog& frog) final override;
        ~Turtle() {}
};

class Log: public MovingObject {
    public:
        Log(int speed, unsigned int head, const unsigned int size, const unsigned lane_id):
            MovingObject(speed, head, size, lane_id) {}
        bool collide(Frog& frog) final override;
        ~Log() {}
};

#endif // MOVINGOBJECTS_H_
