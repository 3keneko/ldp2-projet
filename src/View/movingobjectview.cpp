#include "movingobjectview.hpp"
#include <memory>
#include <iostream>
#include "../constants.hpp"
#include "../utils.hpp"

using namespace constants;

void MovingObjectView::draw() {
  if (mv != nullptr && object_drawer != nullptr) {
    object_drawer->updateX(mv->getX());
    object_drawer->draw();
  }
}

void TurtleView::draw() {
    auto turtle = std::dynamic_pointer_cast<Turtle>(mv);
    if (!turtle->isDiving()) MovingObjectView::draw();
}
