#include "laneview.hpp"
#include "../constants.hpp"
#include <FL/Enumerations.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <memory>
#include "../utils.hpp"

using namespace constants::lanes;

// LaneView::LaneView(std::shared_ptr<Lane> l) {
//     for (auto& obj: l->getObjects()) {

//     }
// }

// void LaneView::draw() {
//     for (auto& object: viewable) {
//         object->draw();
//     }
// }

// void WaterLaneView::draw() {
//     fl_draw_box(FL_FLAT_BOX, 0, HEIGHT * (NUMBER - lane->getId()),
//                 constants::window::WIDTH, HEIGHT, FL_BLUE);
//     for (auto& object: viewable)
//         object->draw();
// }

std::shared_ptr<LaneView> LaneView::makeView(std::shared_ptr<Lane> l) {
    auto try_safe = std::dynamic_pointer_cast<SafeLane>(l);
    if (try_safe != nullptr) return std::make_shared<SafeLaneView>(try_safe);

    auto try_road = std::dynamic_pointer_cast<RoadLane>(l);
    if (try_road != nullptr) return std::make_shared<RoadLaneView>(try_road);

    auto try_tl = std::dynamic_pointer_cast<TurtleLane>(l);
    if (try_tl != nullptr) return std::make_shared<TurtleLaneView>(try_tl);

    auto try_log = std::dynamic_pointer_cast<LogLane>(l);
    if (try_log != nullptr) return std::make_shared<LogLaneView>(try_log);


    auto try_finish = std::dynamic_pointer_cast<FinishLane>(l);
    if (try_finish != nullptr) return std::make_shared<FinishLaneView>(try_finish);

    return nullptr;
}

void SafeLaneView::draw() {
    fl_draw_box(FL_FLAT_BOX, 0, getLanePos(lane->getId()),
                constants::window::WIDTH, HEIGHT, FL_GREEN);
}

void RoadLaneView::draw() {
    fl_draw_box(FL_FLAT_BOX, 0, getLanePos(lane->getId()),
               constants::window::WIDTH, HEIGHT, FL_BLACK);
    for (auto& car: cv) {car->draw();}
}

void LogLaneView::draw() {
    fl_draw_box(FL_FLAT_BOX, 0, getLanePos(lane->getId()),
                constants::window::WIDTH, HEIGHT, FL_BLUE);
    for (auto& _log: lv) {_log->draw();}
}

void TurtleLaneView::draw() {
    fl_draw_box(FL_FLAT_BOX, 0, getLanePos(tl->getId()),
                constants::window::WIDTH, HEIGHT, FL_BLUE);
    for (auto& object: tv)
        object->draw();
}

// TODO
// void FinishLaneView::draw() {}

void FinishLaneView::draw() {
    fl_draw_box(FL_FLAT_BOX, 0, getLanePos(lane->getId()),
                constants::window::WIDTH, HEIGHT, FL_GREEN);
}
