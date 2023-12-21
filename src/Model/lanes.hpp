#ifndef LANE_H_
#define LANE_H_
#include "frog.hpp"
#include "movingobjects.hpp"
#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

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

class FinishLane: public Lane {
    public:
        FinishLane(const unsigned int id):
            Lane(id) {}
        ~FinishLane() {}
};


class SafeLane: public Lane {
    public:
        SafeLane(const unsigned int id):
            Lane(id) {}
        ~SafeLane() {}
};


class MovingObjectLane: public Lane {
    protected:
        std::vector<std::shared_ptr<MovingObject>> mv;
        int lane_speed;
    public:
        MovingObjectLane(const unsigned int id, int lane_speed=0):
            Lane(id), lane_speed(lane_speed) {}
        /*
        MovingObjectLane(const unsigned int id, const unsigned int& by_pack, const unsigned int& space_between,
                      const unsigned& space_between_packs, const unsigned int& first_placement,
                      const unsigned int& size_each, const int& speed, int padding=0);
        */
        bool frog_collide(Frog& frog);
        std::vector<std::shared_ptr<MovingObject>> getMovingObjects() { return mv; }
        virtual void handle_after_collision(Frog& frog) = 0;
        virtual bool water_lane() const = 0 ;
        virtual ~MovingObjectLane() {}
};

class LogLane: public MovingObjectLane {
    public:
        // LogLane(const unsigned int id_num) : MovingObjectLane(id_num) {}

        LogLane(const unsigned int id_num, const unsigned int& log_by_pack,
                const unsigned int& space_between_logs,
                const unsigned& space_between_packs,
                const int& first_log_placement,
                const unsigned int& size_log, const int& speed=0);
            // for (auto& log: mv) {
            //     log = std::dynamic_pointer_cast<Log>(log);
            // }
        bool water_lane() const override { return 1; }
        void handle_after_collision(Frog& frog) override;
        std::vector<std::shared_ptr<Log>> getLogs() const;
        ~LogLane() {}
};


class TurtleLane: public MovingObjectLane {
    unsigned int turtle_by_pack;
    unsigned int diving_pack_id;
    bool is_diving = true;
    unsigned int diving_time;   // In frames
    unsigned int undiving_time;
    unsigned int diving_count = 0;
    public:
        TurtleLane(const unsigned int id_num
                   , const unsigned int& turtle_by_pack
                   , const unsigned int& space_between_turtles
                   , const unsigned& space_between_packs
                   , const int& first_turtle_placement
                   , const unsigned int& size_turtle
                   , const int& speed=1
                   , const unsigned int diving_pack_id = 0
                   , const unsigned int diving_time = 120
                   , const unsigned int undiving_time = 120);
        std::vector<std::shared_ptr<Turtle>> getTurtles() const;
        void handle_after_collision(Frog& frog) override;
        bool water_lane() const override { return 1; }
        // Methods that handle diving turtles
        void pack_dive();
        void pack_undive();
        void dive_update();
        ~TurtleLane() {}
};

class RoadLane: public MovingObjectLane {
    public:
        RoadLane(const unsigned int id_num, const unsigned int& car_by_pack,
                 const unsigned int& space_between_cars, const unsigned& space_between_packs,
                 const int& first_car_placement, const unsigned int& size_car, const int& speed=1);
            // for (auto& car: mv) {
            //     auto car_attempt = std::dynamic_pointer_cast<Car>(car);
            //     if (car_attempt == nullptr) std::cout << "problem with the cars" << std::endl;
            //     car = car_attempt;
            // }
        bool water_lane() const override { return 0; }
        void handle_after_collision(Frog& frog) override;
        std::vector<std::shared_ptr<Car>> getCars() const;
        ~RoadLane() {}
};

#endif // LANE_H_
