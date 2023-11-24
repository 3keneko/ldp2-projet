#ifndef LANE_H_
#define LANE_H_
#include "frog.hpp"
#include "movingobjects.hpp"
#include <vector>
#include <memory>

class Lane {
    private:
        const unsigned int id_num;
        const unsigned int length;
    public:
        Lane(const unsigned int id_num, const unsigned int length):
            id_num(id_num), length(length) {}
        const unsigned int getId() { return id_num; }
        const unsigned int getLength() { return length; }

        ~Lane() {};
};

class RoadLane: public Lane {
    private:
        const unsigned int car_by_pack;
        const unsigned int space_between_cars;
        std::vector<std::unique_ptr<Car>> cars;
    public:
        RoadLane();
        ~RoadLane();
};

class SafeLane: public Lane {
    public:
        SafeLane(const unsigned int id, const unsigned int length):
            Lane(id, length) {}
        ~SafeLane();
};

class WaterLane: public Lane {
    public:
        WaterLane(const unsigned int id, const unsigned int length):
            Lane(id, length) {}
        ~WaterLane();
};

class LogLane: public WaterLane {
    private:
        const unsigned int logs_per_pack;
        const unsigned int space_between_logs;
        std::vector<std::unique_ptr<Log>> logs;
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
    private:
        const unsigned int turtle_per_pack;
        const unsigned int space_between_turtles;
        std::vector<std::unique_ptr<Turtle>> turtles;
    public:
        TurtleLane();
        ~TurtleLane();
};

#endif // LANE_H_
