#include "boardview.hpp"

BoardView::BoardView(std::vector<std::shared_ptr<LaneView>> lanes,
                      std::shared_ptr<BoardModel> b)
    : lanes(lanes), b(b) {}

void BoardView::draw() {
  for (auto& lane: lanes) {
    lane->draw();
  }
}

std::vector<std::shared_ptr<LaneView>> BoardView::getLaneList() { return lanes; }
