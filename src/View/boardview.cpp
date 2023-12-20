#include "boardview.hpp"

void BoardView::draw() {
  for (auto& lane: lanes) {
    lane->draw();
  }
}
