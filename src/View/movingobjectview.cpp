#include "movingobjectview.hpp"
#include <FL/Enumerations.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <memory>
#include <iostream>
#include "../constants.hpp"
#include "../utils.hpp"

using namespace constants;

void MovingObjectView::draw() {
  if (mv != nullptr && object_drawer != nullptr) {
    object_drawer->updateX(mv->getUpX());
    object_drawer->draw();
  }
}
