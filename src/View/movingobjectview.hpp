#ifndef MOVINGOBJECTVIEW_H_
#define MOVINGOBJECTVIEW_H_

#include <memory>
#include "../Model/movingobjects.hpp"
#include "../tooling/drawing_methods.hpp"
#include "../utils.hpp"

class MovingObjectView {
    protected:
        std::shared_ptr<MovingObject> mv;
        std::unique_ptr<RectangleDrawer> object_drawer;
    public:
        MovingObjectView(std::shared_ptr<MovingObject> mv): mv(mv) {
            object_drawer = mv == nullptr ? nullptr :
                std::make_unique<RectangleDrawer>(mv->getX(), getLanePos(mv->getId()), mv->getSize(),
                                                  constants::lanes::HEIGHT, Color::UNKNOWN);
        }
        virtual void draw();
        std::shared_ptr<MovingObject> getMovin() { return mv; }
        virtual ~MovingObjectView() {}
};

class CarView: public MovingObjectView {
  public:
        CarView(std::shared_ptr<Car> c): MovingObjectView(c) {
            if (object_drawer) object_drawer->colorSwitch(Color::CAR);
        }
    // Car getCar() { return *c; }
    ~CarView() {}
};

class LogView: public MovingObjectView {
    public:
        LogView(std::shared_ptr<Log> l): MovingObjectView(l) {
            if (object_drawer) object_drawer->colorSwitch(Color::LOG);
        }
        ~LogView() {}
};

class TurtleView: public MovingObjectView {
    public:
        TurtleView(std::shared_ptr<Turtle> t): MovingObjectView(t) {
            if (object_drawer) object_drawer->colorSwitch(Color::TURTLE);
        }
        void draw() final override;
        ~TurtleView() {}
};

#endif // MOVINGOBJECTVIEW_H_
