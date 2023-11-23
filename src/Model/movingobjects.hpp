#ifndef MOVINGOBJECTS_H_
#define MOVINGOBJECTS_H_
#include "frog.hpp"

class MovingObject {
    protected:
        const unsigned int size;
        const int speed;
        unsigned int head;
    public:
        MovingObject(const int speed, unsigned int head, const unsigned int size):
            speed(speed), head(head), size(size) {};
        virtual bool collide(Frog& frog);
        void move();
        const int getSpeed() const { return speed; };
        virtual ~MovingObject() {};
};

class Car: public MovingObject {
    public:
        Car(int speed, unsigned int head, const unsigned int size) :
            MovingObject(speed, head, size) {};
        ~Car() {};
};

class Turtle: public MovingObject {
    private:
        bool diving;
    public:
        Turtle(int speed, const unsigned int head, const unsigned int size):
            MovingObject(speed, head, size), diving(false) {};
        void dive() { diving=true; }
        void undive() { diving=false; }
        bool collide(Frog& frog) final override;
        ~Turtle() {};
};

class Log: public MovingObject {
    public:
        Log(int speed, unsigned int head, const unsigned int size):
            MovingObject(speed, head, size) {};
        ~Log() {};
};

#endif // MOVINGOBJECTS_H_
