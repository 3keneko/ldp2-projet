#ifndef LANE_H_
#define LANE_H_

#include <vector>
#include <memory>

#include "frog.hpp"
#include "movingobjects.hpp"
#include "waterlilies.hpp"
/// An abstract class that helps model a lane
class Lane {
    private:
        const unsigned int id_num;
    public:
        Lane(const unsigned int id_num);
        unsigned int getId() const;
        virtual void diveUpdate() {}
        virtual ~Lane() {}
};

class FinishLane: public Lane {
    private:
        std::vector<std::shared_ptr<WaterLilies>> lilies;
    public:
        FinishLane(const unsigned int id);
        std::vector<std::shared_ptr<WaterLilies>> getLilies();
        ~FinishLane() {}
};

class SafeLane: public Lane {
    public:
        SafeLane(const unsigned int id);
        ~SafeLane() {}
};

class MovingObjectLane: public Lane {
    protected:
        std::vector<std::shared_ptr<MovingObject>> mv;
        int lane_speed;
    public:
        MovingObjectLane(const unsigned int id, int lane_speed=0);
        bool frogCollide(Frog& frog);
        std::vector<std::shared_ptr<MovingObject>> getMovingObjects();
        virtual void handleAfterCollision(Frog& frog) = 0;
        virtual bool waterLane() const = 0 ;
        virtual ~MovingObjectLane() {}
};

class LogLane: public MovingObjectLane {
    public:
        LogLane(const unsigned int id_num, const unsigned int& log_by_pack,
                const unsigned int& space_between_logs,
                const unsigned& space_between_packs,
                const int& first_log_placement,
                const unsigned int& size_log, const int& speed=0);
        bool waterLane() const override { return 1; }
        void handleAfterCollision(Frog& frog) override;
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
                   , const unsigned& space_between_packsOui
                   , const int& first_turtle_placement
                   , const unsigned int& size_turtle
                   , const int& speed=1
                   , const unsigned int diving_pack_id = 0
                   , const unsigned int diving_time = 180
                   , const unsigned int undiving_time = 360);
        std::vector<std::shared_ptr<Turtle>> getTurtles() const;
        void handleAfterCollision(Frog& frog) override;
        bool waterLane() const override { return 1; }
        void packDive();
        void packUndive();
        void diveUpdate() final override;
        ~TurtleLane() {}
};

class RoadLane: public MovingObjectLane {
    public:
        RoadLane(const unsigned int id_num
                , const unsigned int& car_by_pack
                , const unsigned int& space_between_cars
                , const unsigned& space_between_packs
                , const int& first_car_placement
                , const unsigned int& size_car
                , const int& speed=1);
        bool waterLane() const override { return 0; }
        void handleAfterCollision(Frog& frog) override;
        std::vector<std::shared_ptr<Car>> getCars() const;
        ~RoadLane() {}
};

#endif // LANE_H_
