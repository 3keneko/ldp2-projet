#include "boardview.hpp"

void BoardView::draw() {
  for (auto& c: cv) {
    std::cout << "3" << std::endl;
    c->draw();
  }
}
