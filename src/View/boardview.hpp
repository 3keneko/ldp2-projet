#ifndef BOARDVIEW_H_
#define BOARDVIEW_H_

#include <memory>
#include "../Model/boardmodel.hpp"
#include "laneview.hpp"
#include "movingobjectview.hpp"

class BoardView {
  private:
    std::vector<std::shared_ptr<MovingObjectView>> cv;
    std::shared_ptr<BoardModel> b;
  public:
    BoardView(std::vector<std::shared_ptr<MovingObjectView>> cv,
              std::shared_ptr<BoardModel> b): cv(cv), b(b) {}
    void draw();
    std::vector<std::shared_ptr<MovingObjectView>> getCarList() { return cv; }
    ~BoardView() {}
};

#endif // BOARDVIEW_H_
