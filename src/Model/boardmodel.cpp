#include "boardmodel.hpp"
#include "frog.hpp"
#include "movingobjects.hpp"
#include "score.hpp"
#include "waterlilies.hpp"
#include "../constants.hpp"

#include <algorithm>

BoardModel::BoardModel(std::vector<std::shared_ptr<Lane>> lanes): lanes(lanes) {
    for (auto& lane: lanes) {
        auto try_fl = std::dynamic_pointer_cast<FinishLane>(lane);
        if (try_fl != nullptr) {
            the_finish_lane = try_fl;
            break;
        }
    }
}

void BoardModel::update_turtles(std::shared_ptr<Lane> lane) {
    lane->dive_update();
}

void BoardModel::update() {
    time++;
    for (auto& c: lanes) {
        auto try_mvl = std::dynamic_pointer_cast<MovingObjectLane>(c);
        if (try_mvl != nullptr) {
            for (auto& mov_obj: try_mvl->getMovingObjects()) { mov_obj->move(); }
        }
    update_turtles(c);
      }
}

bool BoardModel::isOutOfBoard(Frog& frog) {
    return !frog.inBoard();
}

bool BoardModel::gameWon() {
    auto lilies = the_finish_lane->getLilies();
    return std::all_of(lilies.begin(), lilies.end(),
                       [](auto& lily) { return lily->hasBeenVisited(); });
}

bool BoardModel::frogOnLily(Frog& frog) {
    for (auto& lily: the_finish_lane->getLilies()) {
        if (lily->collide(frog)) {
            lily->visit();
            return true;
        }
    }
    return false;
}

void BoardModel::addLane(std::shared_ptr<Lane> lane) {
    lanes.push_back(lane);
}

std::vector<std::shared_ptr<Lane>> BoardModel::getLanes() {
    return lanes;
}

bool BoardModel::any_collision(Frog& frog) {
    for (auto& lane: lanes) {
        auto try_mvl = std::dynamic_pointer_cast<MovingObjectLane>(lane);
        if (try_mvl != nullptr) {
            auto mv_list = try_mvl->getMovingObjects();
            return std::any_of(mv_list.begin(), mv_list.end(),
                                [&frog](std::shared_ptr<MovingObject> mv) {
                                    return mv->collide(frog);
                                });    
        }
    }
    return false;    
}

void BoardModel::handle_collision(Frog& frog) {
    if (frog.getLane() == constants::lanes::NUMBER) {
        // First we handle collisions with the waterlilies
        bool got_one = frogOnLily(frog);
        if (!got_one) frog.kill();
        else {
            frog.inWaterLilies();
        }

    } else {
        // We then handle collisions with the rest of the objects
        for (auto& lane: lanes) {
            if (lane->getId() == frog.getLane()) {
                auto try_mvl = std::dynamic_pointer_cast<MovingObjectLane>(lane);
                if (try_mvl != nullptr && try_mvl->frog_collide(frog)) {
                    try_mvl->handle_after_collision(frog);
                // In water lane but not in object means instant death...
                } else if (try_mvl != nullptr && try_mvl->water_lane()) {
                    frog.kill();
                }
            }
        }
    }
    if (isOutOfBoard(frog)) {
        frog.kill();
    }
}
