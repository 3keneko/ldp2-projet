#ifndef MOVINGOBJECTVIEW_H_
#define MOVINGOBJECTVIEW_H_

#include <memory>
#include "../Model/movingobjects.hpp"

class MovingObjectView {
    protected:
        std::shared_ptr<MovingObject> mv;
    public:
        MovingObjectView(std::shared_ptr<MovingObject> mv): mv(mv) {}
        virtual void draw()=0;
        virtual ~MovingObjectView() {}
};

class CarView: public MovingObjectView {
  /*private:
    std::shared_ptr<Car> c;
    //std::shared_ptr<Fl_Box> repr;
    */
    private:
        std::shared_ptr<Car> c;
  public:
    CarView(std::shared_ptr<Car> c):  MovingObjectView(c) /*, repr(std::make_shared<Fl_Box>(FL_FLAT_BOX, std::get<0>(c->getUpLeft()),
                                                                  c->getUpY(), c->getSize(), HEIGHT_LANE, "")) */ {}
    void draw() override;
    // Car getCar() { return *c; }
    ~CarView() {}
};


#endif // MOVINGOBJECTVIEW_H_
