#ifndef BOARDMODEL_H_
#define BOARDMODEL_H_

#include <vector>
#include <memory>
#include "lanes.hpp"
#include "movingobjects.hpp"
#include <iostream>

class BoardModel {
  private:
    std::vector<std::shared_ptr<MovingObject>> cs;
    unsigned time = 0;
  public:
    BoardModel(std::vector<std::shared_ptr<MovingObject>> mv): cs(mv) {}

    void update() {
      time++;
      for (auto& c: cs) {
        c->move();
      }
    }
    ~BoardModel() {}
    unsigned getTime() const  { return time; }
};


#endif // BOARDMODEL_H_
