#ifndef BOARDMODEL_H_
#define BOARDMODEL_H_

#include <vector>
#include <memory>
#include <iostream>

#include "lanes.hpp"
#include "movingobjects.hpp"
#include "score.hpp"

class BoardModel {
  private:
    std::shared_ptr<FinishLane> the_finish_lane;
    std::vector<std::shared_ptr<Lane>> lanes {};
    unsigned time = 0;
  public:
    BoardModel(std::vector<std::shared_ptr<Lane>> lanes): lanes(lanes) {
    for (auto& lane: lanes) {
        auto try_fl = std::dynamic_pointer_cast<FinishLane>(lane);
        if (try_fl != nullptr) {
            the_finish_lane = try_fl;
            break;
        }
    }
    }
    void update_turtles(std::shared_ptr<Lane> lane);

    // moves the objects on the board
    void update() {
      time++;
      for (auto& c: lanes) {
        auto try_mvl = std::dynamic_pointer_cast<MovingObjectLane>(c);
        if (try_mvl != nullptr) {
          for (auto& mov_obj: try_mvl->getMovingObjects()) { mov_obj->move(); }
        }
        update_turtles(c);
      }
    }

    bool gameWon();
    // Collision methods
    bool isOutOfBoard(Frog& frog);
    // bool collidesWithAuto(Frog &frog, RoadLane& lane);
    bool frogOnLily(Frog& frog);

    // bool isOnLog(Frog &frog, LogLane& lane);
    // bool isOnTurtle(Frog& frog, TurtleLane& tl);
    // bool isDrowning(Frog& frog, WaterLane& wl)

    void addLane(std::shared_ptr<Lane> lane) {
      lanes.push_back(lane);
    }
    std::vector<std::shared_ptr<Lane>> getLanes() {
      return lanes;
    }
    /// Collision handlers
    bool any_collision(Frog& frog);
    void handle_collision(Frog& frog);

    ~BoardModel() {}
    unsigned getTime() const  { return time; }
};


#endif // BOARDMODEL_H_
