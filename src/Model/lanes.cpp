#include "lanes.hpp"
#include "../constants.hpp"
#include "movingobjects.hpp"
#include <algorithm>
#include <bits/types/FILE.h>
#include <memory>
#include <vector>


bool MovingObjectLane::frog_collide(Frog& frog) {
    return std::any_of(mv.begin(), mv.end(), [&frog](std::shared_ptr<MovingObject> elems) {
                                    return elems->collide(frog);
                    });
}

template <class T>
void pack_initialize(const unsigned int& by_pack, const unsigned int& space_between,
                     const unsigned& space_between_packs, const unsigned int& first_placement,
                     const unsigned int& size_each, std::vector<std::shared_ptr<MovingObject>>& initializee,
                     const int speed, const unsigned int id, int padding=0)  {
    using namespace constants::window;
    int buffer = first_placement;
    while (buffer < WIDTH + padding) {
        unsigned int in_pack = 0;
        while (buffer < WIDTH + padding && in_pack <= by_pack) {
            buffer += space_between;
            initializee.push_back(std::make_shared<T>(speed, buffer, size_each, id));
            in_pack++;
            buffer += size_each;
        }
        buffer += space_between_packs;
    }
}


RoadLane::RoadLane(const unsigned int id_num, const unsigned int& car_by_pack, const unsigned int& space_between_cars,
                   const unsigned& space_between_packs,const int& first_car_placement, const unsigned int& size_car, const int& speed): MovingObjectLane(id_num) {
    pack_initialize<Car>(car_by_pack, space_between_cars, space_between_packs, first_car_placement,
                         size_car, mv, speed, id_num, constants::window::PADDING);
}

LogLane::LogLane(const unsigned int id_num, const unsigned int& log_by_pack, const unsigned int& space_between_logs,
                   const unsigned& space_between_packs,const int& first_log_placement, const unsigned int& size_log, const int& speed): MovingObjectLane(id_num) {
    pack_initialize<Log>(log_by_pack, space_between_logs, space_between_packs, first_log_placement, size_log, mv, speed, id_num, constants::window::PADDING);
}

TurtleLane::TurtleLane(const unsigned int id_num, const unsigned int& turtle_by_pack, const unsigned int& space_between_turtles,
                   const unsigned& space_between_packs,const int& first_turtle_placement, const unsigned int& size_turtle, const int& speed): MovingObjectLane(id_num) {
    pack_initialize<Turtle>(turtle_by_pack, space_between_turtles, space_between_packs, first_turtle_placement, size_turtle, mv, speed, id_num, constants::window::PADDING);
}


template <class T>
std::vector<std::shared_ptr<T>> preCastedGet(std::vector<std::shared_ptr<MovingObject>> mv) {
    std::vector<std::shared_ptr<T>> res {};
    std::transform(mv.begin(), mv.end(), res.begin(),
                   [](std::shared_ptr<MovingObject> mov) { return std::dynamic_pointer_cast<T>(mov); }
    );
    return res;
}

std::vector<std::shared_ptr<Log>> LogLane::getLogs() const {
    return preCastedGet<Log>(mv);
}

std::vector<std::shared_ptr<Car>> RoadLane::getCars() const {
    return preCastedGet<Car>(mv);
}

std::vector<std::shared_ptr<Turtle>> TurtleLane::getTurtles() const {
    return preCastedGet<Turtle>(mv);
}
