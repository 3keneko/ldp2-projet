#include "laneview.hpp"
#include "../constants.hpp"
#include <FL/Enumerations.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <memory>

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

void TurtleLaneView::draw() {
    fl_draw_box(FL_FLAT_BOX, 0, HEIGHT * (NUMBER - tl->getId()),
                constants::window::WIDTH, HEIGHT, FL_BLUE);
    for (auto& object: tv)
        object->draw();
}
