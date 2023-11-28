#include "boardview.hpp"

void BoardView::draw() {
  for (auto& c: cv) {
    c->draw();
  }
}
