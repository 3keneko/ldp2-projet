#ifndef MOVINGOBJECTS_H_
#define MOVINGOBJECTS_H_

#include "frog.hpp"
#include <memory>
#include <tuple>


class MovingObject {
  protected:
    const int speed;
    int x;
    const unsigned int size;
    const unsigned int lane_id;
  public:
    MovingObject(const int speed, int x, const unsigned int size, const unsigned lane_id);
    void move();
    unsigned getSize() const;
    unsigned getId() const;
    // returns the x coordinate of the center of the object
    int getCenterX() const;
    std::tuple<int, int> getBoundaries() const;
    int getX() const;
    // returns true if this element collides with the frog
    virtual bool collide(Frog& frog) = 0;
    int getSpeed() const;

    // Methods regarding diving turtles
    virtual void dive() {}
    virtual void undive() {}
    virtual bool isDiving() const;
    virtual ~MovingObject() {}
};

class Car: public MovingObject {
    public:
        Car(int speed, unsigned int head, const unsigned int size, const unsigned lane_id);
        bool collide(Frog& frog) final override;
        ~Car() {}
};

class Turtle: public MovingObject {
    private:
        bool diving;
    public:
        Turtle(int speed, const unsigned int head, const unsigned int size
                , const unsigned lane_id);
        void dive() final override;
        void undive() final override;
        bool isDiving() const final override;
        bool collide(Frog& frog) final override;
        ~Turtle() {}
};

class Log: public MovingObject {
    public:
        Log(int speed, unsigned int head, const unsigned int size, const unsigned lane_id);
        bool collide(Frog& frog) final override;
        ~Log() {}
};

#endif // MOVINGOBJECTS_H_
