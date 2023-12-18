#include "boardmodel.hpp"
#include "frog.hpp"
#include "lanes.hpp"
#include <memory>
#include <algorithm>


/// THIS MACRO IS DEFINED FOR DEBUGGING, IT HELPS
/// PRINT OUT THE TUPLE V MORE EASILY
/// IT IS TO BE DELETED BEFORE WE SEND THE PROJECT BACK TO MR. IACONO
#define PRINTTUP(V) std::get<0>(V) << " " << std::get<1>(V)

// Returns False if frog is outside of the board
bool BoardModel::isOutOfBoard(Frog& frog) {
    return !frog.inBoard();
}

/*
bool BoardModel::collidesWithAuto(Frog& frog, RoadLane& rl) {
    auto car_list = rl.getCars();
    return std::any_of(car_list.begin(), car_list.end(),
                        [&frog](std::shared_ptr<Car> car) {
                                    return car->collide(frog); 
                                }); 
}
*/
// To do after defining finnishLane
bool BoardModel::collidesInFinnishLane(Frog& frog) {return false;}
/*
bool BoardModel::isOnLog(Frog& frog, LogLane& ll) {
    auto log_list = ll.getLogs();
    return std::any_of(log_list.begin(), log_list.end(),
                        [&frog](std::shared_ptr<Log> log) {
                                    return log->collide(frog); 
                                });     
}

bool BoardModel::isOnTurtle(Frog& frog, TurtleLane& tl) {
    auto turtle_list = tl.getTurtles();
    return std::any_of(turtle_list.begin(), turtle_list.end(),
                        [&frog](std::shared_ptr<Turtle> turtle) {
                                    return turtle->collide(frog); 
                                }); 
}
*/
// To do with upper functions
// bool BoardModel::isDrowning(Frog& frog, WaterLane& wl) {return false;}



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
    for (auto& lane: lanes) {
        if (lane->getId() == frog.getLane()) {
            auto try_mvl = std::dynamic_pointer_cast<MovingObjectLane>(lane);
            if (try_mvl != nullptr && try_mvl->frog_collide(frog)) {
                try_mvl->handle_after_collision(frog);
            } else if (try_mvl != nullptr && try_mvl->water_lane()) {
                frog.kill();
            }
        }
    }
}
