#ifndef BOARDVIEW_H_
#define BOARDVIEW_H_

#include <memory>
#include "../Model/boardmodel.hpp"
#include "laneview.hpp"
#include "movingobjectview.hpp"

class BoardView {
  private:
    std::vector<std::shared_ptr<LaneView>> lanes;
    std::shared_ptr<BoardModel> b;
  public:
    BoardView(std::vector<std::shared_ptr<LaneView>> lanes,
              std::shared_ptr<BoardModel> b): lanes(lanes), b(b) {}
    void draw();
    std::vector<std::shared_ptr<LaneView>> getLaneList() { return lanes; }
    ~BoardView() {}
};

#endif // BOARDVIEW_H_
