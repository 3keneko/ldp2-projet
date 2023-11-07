#ifndef LANE_H_
#define LANE_H_
#include <cstdint>
#include "frog.hpp"

class MovingObject {
    protected:
        int speed;
        std::uint8_t head;
    public:
        MovingObject(int speed, std::uint8_t head):
            speed(speed), head(head) {};
        virtual bool collide(Frog& frog);
        void move();
        int getSpeed();
        ~MovingObject() {};
};

class Car: public MovingObject {
    private:
        std::uint8_t size;
    public:
        Car(int speed, std::uint8_t head, std::uint8_t size) :
            MovingObject(speed, head), size(size) {};
        bool collide(Frog frog);
        ~Car() {};
};

class Turtle: public MovingObject {
    private:
        bool diving;
    public:
        Turtle(int speed, std::uint8_t head):
            MovingObject(speed, head), diving(false) {};
        void dive();
        void undive();
        bool collide(Frog frog);
        ~Turtle() {};
};

class Log: public MovingObject {
    private:
        std::uint8_t size;
    public:
        Log(int speed, std::uint8_t head, std::uint8_t size):
            MovingObject(speed, head), size(size) {};
        bool collide(Frog frog);
        ~Log() {};
};

class Lane {
    private:
        std::uint8_t id_num;
        std::uint8_t length;
    public:
        Lane(std::uint8_t id_num, std::uint8_t length):
            id_num(id_num), length(length) {};
        std::uint8_t getId();
        ~Lane() {};
};

class RoadLane: public Lane {
    private:
        std::uint8_t car_by_pack;
        std::uint8_t space_between_cars;

    public:
        RoadLane();
        ~RoadLane();
};

class SafeLane: public Lane {
    public:
        SafeLane();
        ~SafeLane();
};

class WaterLane: public Lane {
    public:
        WaterLane();
        ~WaterLane();
};

class LogLane: public WaterLane {
    public:
        LogLane();
        ~LogLane();
};

class FinishLane: public WaterLane {
    public:
        FinishLane();
        ~FinishLane();
};

class TurtleLane: public WaterLane {
    public:
        TurtleLane();
        ~TurtleLane();
};
#endif // LANE_H_
