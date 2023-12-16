#ifndef LANE_H_
#define LANE_H_
#include "frog.hpp"
#include "movingobjects.hpp"
#include <vector>
#include <memory>

/// An abstract class that helps model a lane
class Lane {
    private:
        const unsigned int id_num;
    public:
        Lane(const unsigned int id_num):
            id_num(id_num) {}
        unsigned int getId() const { return id_num; }
        virtual ~Lane() {}
};

class RoadLane: public Lane {
    private:
        std::vector<std::shared_ptr<Car>> cars;
    public:
        RoadLane(const unsigned int id_num, const unsigned int& car_by_pack,
                 const unsigned int& space_between_cars, const unsigned& space_between_packs,
                 const int& first_car_placement, const unsigned int& size_car, const int& speed=1);
        std::vector<std::shared_ptr<Car>> getCars() {return cars;}
        ~RoadLane() {}
};

class SafeLane: public Lane {
    public:
        SafeLane(const unsigned int id):
            Lane(id) {}
        ~SafeLane() {}
};

class WaterLane: public Lane {
    public:
        WaterLane(const unsigned int id):
            Lane(id) {}
        ~WaterLane() {}
};

class LogLane: public WaterLane {
    private:
        std::vector<std::shared_ptr<Log>> logs;
    public:
        LogLane(const unsigned int id_num, const unsigned int& log_by_pack,
            const unsigned int& space_between_logs, const unsigned& space_between_packs,
            const int& first_log_placement, const unsigned int& size_log, const int& speed=1);
        std::vector<std::shared_ptr<Log>> getLogs() {return logs;}
        ~LogLane() {}
};

class FinishLane: public WaterLane {
    public:
        FinishLane();
        ~FinishLane() {}
};

class TurtleLane: public WaterLane {
    private:
        std::vector<std::shared_ptr<Turtle>> turtles;
    public:
        TurtleLane(const unsigned int id_num, const unsigned int& turtle_by_pack,
            const unsigned int& space_between_turtles, const unsigned& space_between_packs,
            const int& first_turtle_placement, const unsigned int& size_turtle, const int& speed=1);
        std::vector<std::shared_ptr<Turtle>> getTurtles() { return turtles; }
        ~TurtleLane() {}
};

#endif // LANE_H_
