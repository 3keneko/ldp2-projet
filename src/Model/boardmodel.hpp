#ifndef BOARDMODEL_H_
#define BOARDMODEL_H_

#include <vector>
#include <memory>
#include "lanes.hpp"
#include "movingobjects.hpp"
#include <iostream>

class BoardModel {
  private:
    std::vector<std::shared_ptr<Lane>> cs;
    unsigned time = 0;
  public:
    BoardModel(std::vector<std::shared_ptr<Lane>> mv): cs(mv) {}

    void update() {
      time++;
      for (auto& c: cs) {
        auto try_rl = std::dynamic_pointer_cast<RoadLane>(c);
        if (try_rl != nullptr) {
          for (auto& car: try_rl->getCars()) { car->move(); }
        }
      }
    }
    ~BoardModel() {}
    unsigned getTime() const  { return time; }
};


#endif // BOARDMODEL_H_
