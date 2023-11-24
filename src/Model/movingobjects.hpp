#ifndef MOVINGOBJECTS_H_
#define MOVINGOBJECTS_H_
#include "frog.hpp"

class MovingObject {
    protected:
        const unsigned int size;
        const int speed;
        unsigned int head;
        const unsigned int lane_id;
    public:
        MovingObject(const int speed, unsigned int head, const unsigned int size, const unsigned lane_id):
        speed(speed), head(head), size(size), lane_id(lane_id) {};

        virtual bool collide(Frog& frog);
        void move();
        unsigned getSize() const { return size; }
        unsigned getId() const { return lane_id; }
        unsigned getHead() const { return head; }
        const int getSpeed() const { return speed; }
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
