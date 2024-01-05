#ifndef MOVINGOBJECTVIEW_H_
#define MOVINGOBJECTVIEW_H_

#include <memory>
#include "../Model/movingobjects.hpp"
#include "../tooling/drawing_methods.hpp"

class MovingObjectView {
    protected:
        std::shared_ptr<MovingObject> mv;
        std::unique_ptr<RectangleDrawer> object_drawer;
    public:
        MovingObjectView(std::shared_ptr<MovingObject> mv);
        virtual void draw();
        std::shared_ptr<MovingObject> getMovin();
        virtual ~MovingObjectView() {}
};

class CarView: public MovingObjectView {
    public:
        CarView(std::shared_ptr<Car> c);
        ~CarView() {}
};

class LogView: public MovingObjectView {
    public:
        LogView(std::shared_ptr<Log> l);
        ~LogView() {}
};

class TurtleView: public MovingObjectView {
    public:
        TurtleView(std::shared_ptr<Turtle> t);
        void draw() final override;
        ~TurtleView() {}
};

#endif // MOVINGOBJECTVIEW_H_
