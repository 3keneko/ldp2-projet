#ifndef BOARDMODEL_H_
#define BOARDMODEL_H_

#include <vector>
#include <memory>
#include "lanes.hpp"
#include "movingobjects.hpp"
#include <iostream>

class BoardModel {
  private:
    std::vector<std::shared_ptr<Lane>> lanes;
    unsigned time = 0;
  public:
    BoardModel(std::vector<std::shared_ptr<Lane>> mv): lanes(mv) {}

    void update() {
      time++;
      for (auto& c: lanes) {
        auto try_mvl = std::dynamic_pointer_cast<MovingObjectLane>(c);
        if (try_mvl != nullptr) {
          for (auto& mov_obj: try_mvl->getMovingObjects()) { mov_obj->move(); }
        }
      }
    }
    // Collision methods
    bool isOutOfBoard(Frog& frog);
    bool collidesWithAuto(Frog &frog, RoadLane& lane);
    bool collidesInFinnishLane(Frog& frog);
    bool isOnLog(Frog &frog, LogLane& lane);
    bool isOnTurtle(Frog& frog, TurtleLane& tl);
    // bool isDrowning(Frog& frog, WaterLane& wl)
    bool any_collision(Frog& frog);
    void handle_collision(Frog& frog);
    ~BoardModel() {}
    unsigned getTime() const  { return time; }
};


#endif // BOARDMODEL_H_
