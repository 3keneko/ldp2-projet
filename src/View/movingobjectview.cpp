#include "movingobjectview.hpp"
#include <FL/Enumerations.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <memory>
#include <iostream>
#include "../constants.hpp"
#include "../utils.hpp"

using namespace constants;

void CarView::draw() {
  std::shared_ptr<Car> c = std::dynamic_pointer_cast<Car>(getMovin());
  if (c) {
    fl_draw_box(FL_FLAT_BOX, c->getUpX(), getLanePos(c->getId()), c->getSize(), lanes::HEIGHT, FL_BLUE);
    // std::cout << c->getUpX() << " " << c->getUpY() << std::endl;
  }
  //fl_color(FL_BLACK);
  //fl_draw_box(FL_FLAT_BOX, 20, 20, 10, 10, FL_BLUE);
  // std::cout << std::get<1>(c->getBoundaries()) << "\n";
  //repr->position(c->getUpX(),c->getUpY());
  //repr->parent()->redraw();
}


void LogView::draw() {
  std::shared_ptr<Log> l = std::dynamic_pointer_cast<Log>(getMovin());
  if (l)
    fl_draw_box(FL_FLAT_BOX, l->getUpX(), getLanePos(l->getId()), l->getSize(),
                lanes::HEIGHT, fl_rgb_color(139, 69, 16));
}

void TurtleView::draw() {
  std::shared_ptr<Turtle> t = std::dynamic_pointer_cast<Turtle>(getMovin());
  if (t && !t->isDiving()) {
    fl_draw_box(FL_FLAT_BOX, t->getUpX(), getLanePos(t->getId()), t->getSize(),
                lanes::HEIGHT, fl_rgb_color(3, 75, 3));
  }
};
