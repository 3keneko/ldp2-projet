#ifndef MOVINGOBJECTS_H_
#define MOVINGOBJECTS_H_
#include "frog.hpp"
#include <tuple>

const int HEIGHT_LANE = 20;

class MovingObject {
  protected:
    const int speed;
    unsigned int centerX;
    const unsigned int size;
    const unsigned int lane_id;
  public:
    MovingObject(const int speed, unsigned int centerX, const unsigned int size, const unsigned lane_id):
          speed(speed), centerX(centerX), size(size), lane_id(lane_id) {};
    void move() {
          centerX += speed;
    }
    unsigned getSize() const { return size; }
    unsigned getId() { return lane_id; }
    unsigned getCenterX() { return centerX; }
    std::tuple<unsigned, unsigned> getBoundaries() {
      if (centerX <= size / 2) {
        return std::make_tuple(0, centerX+size/2);
      }
      return std::make_tuple(centerX - size/2, centerX + size/2);
    }
    unsigned getUpY() { return lane_id * HEIGHT_LANE; }
    std::tuple<unsigned, unsigned> getUpLeft()  {
      if (centerX <= size / 2) {
        return std::make_tuple(0, getUpY());
      }
      return std::make_tuple(centerX - size/2, getUpY());
    }
    unsigned getUpX() {
      return std::get<0>(getUpLeft());
    }
    virtual bool collide(Frog& frog);
    const int getSpeed() { return speed; }
    virtual ~MovingObject() {};
};


class Car: public MovingObject {
    public:
        Car(int speed, unsigned int head, const unsigned int size, const unsigned lane_id) :
            MovingObject(speed, head, size, lane_id) {};
        ~Car() {};
};

class Turtle: public MovingObject {
    private:
        bool diving;
    public:
        Turtle(int speed, const unsigned int head, const unsigned int size, const unsigned lane_id):
            MovingObject(speed, head, size, lane_id), diving(false) {};
        void dive() { diving=true; }
        void undive() { diving=false; }
        bool collide(Frog& frog) final override;
        ~Turtle() {};
};

class Log: public MovingObject {
    public:
        Log(int speed, unsigned int head, const unsigned int size, const unsigned lane_id):
            MovingObject(speed, head, size, lane_id) {};
        ~Log() {};
};

#endif // MOVINGOBJECTS_H_
