#include "boardview.hpp"

void BoardView::draw() {
  for (auto& lane: lanes) {
    // std::cout << "3" << std::endl;
    lane->draw();
  }
}
