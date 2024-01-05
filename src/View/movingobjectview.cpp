#include "movingobjectview.hpp"
#include "../constants.hpp"
#include "../utils.hpp"

using namespace constants;

MovingObjectView::MovingObjectView(std::shared_ptr<MovingObject> mv): mv(mv) {
    object_drawer = mv == nullptr ? nullptr :
        std::make_unique<RectangleDrawer>(mv->getX(), getLanePos(mv->getId())
                                          , mv->getSize()
                                          , constants::lanes::HEIGHT, Color::UNKNOWN);
}

void MovingObjectView::draw() {
    if (mv != nullptr && object_drawer != nullptr) {
        object_drawer->updateX(mv->getX());
        object_drawer->draw();
    }
}

std::shared_ptr<MovingObject> MovingObjectView::getMovin() { return mv; }

CarView::CarView(std::shared_ptr<Car> c): MovingObjectView(c) {
    if (object_drawer) object_drawer->colorSwitch(Color::CAR);
}

LogView::LogView(std::shared_ptr<Log> l): MovingObjectView(l) {
    if (object_drawer) object_drawer->colorSwitch(Color::LOG);
}

TurtleView::TurtleView(std::shared_ptr<Turtle> t): MovingObjectView(t) {
    if (object_drawer) object_drawer->colorSwitch(Color::TURTLE);
}

void TurtleView::draw() {
    if (!mv->isDiving()) MovingObjectView::draw();
}
