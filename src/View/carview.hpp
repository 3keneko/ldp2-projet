#ifndef CARVIEW_H_
#define CARVIEW_H_
#include <memory>
#include "../Model/movingobjects.hpp"

class CarView {
  private:
    std::shared_ptr<Car> c;
    //std::shared_ptr<Fl_Box> repr;
  public:
    CarView(std::shared_ptr<Car> c):  c(c)/*, repr(std::make_shared<Fl_Box>(FL_FLAT_BOX, std::get<0>(c->getUpLeft()),
                                                                  c->getUpY(), c->getSize(), HEIGHT_LANE, "")) */ {}
    void draw(unsigned time);
    Car getCar() { return *c; }
    ~CarView() {}
};


#endif // CARVIEW_H_
