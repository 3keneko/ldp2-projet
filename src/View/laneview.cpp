#include "laneview.hpp"
#include "../constants.hpp"
#include "../utils.hpp"
#include "../tooling/colors.hpp"

using namespace constants::lanes;

LaneView::LaneView(std::shared_ptr<Lane> lane)
    : lane(lane), ld(LaneDrawer(getLanePos(lane->getId()), Color::UNKNOWN)) {}

std::shared_ptr<LaneView> LaneView::makeView(std::shared_ptr<Lane> l) {
  auto try_safe = std::dynamic_pointer_cast<SafeLane>(l);
  if (try_safe != nullptr)
    return std::make_shared<SafeLaneView>(try_safe);

  auto try_road = std::dynamic_pointer_cast<RoadLane>(l);
  if (try_road != nullptr)
    return std::make_shared<RoadLaneView>(try_road);

  auto try_tl = std::dynamic_pointer_cast<TurtleLane>(l);
  if (try_tl != nullptr)
    return std::make_shared<TurtleLaneView>(try_tl);

  auto try_log = std::dynamic_pointer_cast<LogLane>(l);
  if (try_log != nullptr)
    return std::make_shared<LogLaneView>(try_log);

  auto try_finish = std::dynamic_pointer_cast<FinishLane>(l);
  if (try_finish != nullptr)
    return std::make_shared<FinishLaneView>(try_finish);

  return nullptr;
}

void SafeLaneView::draw() {
    ld.draw();
}

SafeLaneView::SafeLaneView(std::shared_ptr<SafeLane> sfl): LaneView(sfl) {
    ld.colorSwitch(Color::SAFE);
}

FinishLaneView::FinishLaneView(std::shared_ptr<FinishLane> fl): LaneView(fl) {
    ld.colorSwitch(Color::WATER);
    for (auto& _lily: fl->getLilies()) {
        auto lily_view = std::make_shared<LiliesView>(_lily);
        lilies.push_back(lily_view);
    }
}

RoadLaneView::RoadLaneView(std::shared_ptr<RoadLane> rl): LaneView(rl) {
    ld.colorSwitch(Color::ROAD);
    for (auto& car: rl->getMovingObjects()) {
        cv.push_back(std::make_shared<CarView>(std::static_pointer_cast<Car>(car)));
    }
}

void RoadLaneView::draw() {
    ld.draw();
    for (auto& car: cv) {car->draw();}
}

LogLaneView::LogLaneView(std::shared_ptr<LogLane> ll): LaneView(ll) {
    ld.colorSwitch(Color::WATER);
    for (auto& _log: ll->getMovingObjects()) {
        lv.push_back(std::make_shared<LogView>(std::static_pointer_cast<Log>(_log)));
    }
}

void LogLaneView::draw() {
    ld.draw();
    for (auto& _log: lv) {_log->draw();}
}

TurtleLaneView::TurtleLaneView(std::shared_ptr<TurtleLane> tl): LaneView(tl) {
    ld.colorSwitch(Color::WATER);
    for (auto& turtle: tl->getMovingObjects()) {
        tv.push_back(std::make_shared<TurtleView>(std::static_pointer_cast<Turtle>(turtle)));
    }
}

void TurtleLaneView::draw() {
    ld.draw();
    for (auto& object: tv)
        object->draw();
}

void FinishLaneView::draw() {
    ld.draw();
    for (auto& object: lilies)
      object->draw();
}
