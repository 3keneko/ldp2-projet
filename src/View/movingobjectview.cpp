#include "movingobjectview.hpp"
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

void CarView::draw() {
  fl_draw_box(FL_FLAT_BOX, c->getUpX(), c->getUpY(), c->getSize(), HEIGHT_LANE, FL_BLUE);
  //
  //std::cout << c->getUpX() << " " << c->getUpY() << std::endl;
  //
  //fl_color(FL_BLACK);
  //fl_draw_box(FL_FLAT_BOX, 20, 20, 10, 10, FL_BLUE);
  // std::cout << std::get<1>(c->getBoundaries()) << "\n";
  //repr->position(c->getUpX(),c->getUpY());
  //repr->parent()->redraw();
}
