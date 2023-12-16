#include "lanes.hpp"
#include "../constants.hpp"
#include <bits/types/FILE.h>
#include <memory>
#include <vector>

template <class T>
void pack_initializer(const unsigned int& by_pack, const unsigned int& space_between,
                      const unsigned& space_between_packs, const unsigned int& first_placement,
                      const unsigned int& size_each, std::vector<std::shared_ptr<T>>& to_initialize,
                      const int& speed, const unsigned lane_id, int padding=0) {
    using namespace constants::window;
    int buffer = first_placement;
    while (buffer < WIDTH + padding) {
        unsigned int in_pack = 0;
        while (buffer < WIDTH + padding && in_pack <= by_pack) {
            buffer += space_between;
            to_initialize.push_back(std::make_shared<T>(speed, buffer, size_each, lane_id));
            in_pack++;
            buffer += size_each;
        }
        buffer += space_between_packs;
    }
}

RoadLane::RoadLane(const unsigned int id_num, const unsigned int& car_by_pack, const unsigned int& space_between_cars,
                   const unsigned& space_between_packs,const int& first_car_placement, const unsigned int& size_car, const int& speed): Lane(id_num) {
    pack_initializer<Car>(car_by_pack, space_between_cars, space_between_packs, first_car_placement, size_car, cars, speed, id_num);
}

LogLane::LogLane(const unsigned int id_num, const unsigned int& log_by_pack, const unsigned int& space_between_logs,
                   const unsigned& space_between_packs,const int& first_log_placement, const unsigned int& size_log, const int& speed): WaterLane(id_num) {
    pack_initializer<Log>(log_by_pack, space_between_logs, space_between_packs, first_log_placement, size_log, logs, speed, id_num);
}

TurtleLane::TurtleLane(const unsigned int id_num, const unsigned int& turtle_by_pack, const unsigned int& space_between_turtles,
                   const unsigned& space_between_packs,const int& first_turtle_placement, const unsigned int& size_turtle, const int& speed): WaterLane(id_num) {
    pack_initializer<Turtle>(turtle_by_pack, space_between_turtles, space_between_packs, first_turtle_placement, size_turtle, turtles, speed, id_num);
}
