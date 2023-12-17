#include "lanes.hpp"
#include "../constants.hpp"
#include "movingobjects.hpp"
#include <bits/types/FILE.h>
#include <memory>
#include <vector>

MovingObjectLane::MovingObjectLane(const unsigned int id, const unsigned int& by_pack, const unsigned int& space_between,
                      const unsigned& space_between_packs, const unsigned int& first_placement,
                      const unsigned int& size_each, const int& speed, int padding): Lane(id) {
    using namespace constants::window;
    int buffer = first_placement;
    while (buffer < WIDTH + padding) {
        unsigned int in_pack = 0;
        while (buffer < WIDTH + padding && in_pack <= by_pack) {
            buffer += space_between;
            mv.push_back(std::make_shared<MovingObject>(speed, buffer, size_each, id));
            in_pack++;
            buffer += size_each;
        }
        buffer += space_between_packs;
    }
}
/*
RoadLane::RoadLane(const unsigned int id_num, const unsigned int& car_by_pack, const unsigned int& space_between_cars,
                   const unsigned& space_between_packs,const int& first_car_placement, const unsigned int& size_car, const int& speed): MovingObjectLane(id_num) {
    pack_initialize(car_by_pack, space_between_cars, space_between_packs, first_car_placement, size_car, mv, speed, id_num);
}

LogLane::LogLane(const unsigned int id_num, const unsigned int& log_by_pack, const unsigned int& space_between_logs,
                   const unsigned& space_between_packs,const int& first_log_placement, const unsigned int& size_log, const int& speed): MovingObjectLane(id_num) {
    pack_initialize(log_by_pack, space_between_logs, space_between_packs, first_log_placement, size_log, mv, speed, id_num);
}

TurtleLane::TurtleLane(const unsigned int id_num, const unsigned int& turtle_by_pack, const unsigned int& space_between_turtles,
                   const unsigned& space_between_packs,const int& first_turtle_placement, const unsigned int& size_turtle, const int& speed): MovingObjectLane(id_num) {
    pack_initialize(turtle_by_pack, space_between_turtles, space_between_packs, first_turtle_placement, size_turtle, mv, speed, id_num);
}
*/
