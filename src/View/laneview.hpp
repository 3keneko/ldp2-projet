#ifndef LANEVIEW_H_
#define LANEVIEW_H_

#include <FL/Enumerations.H>
#include <memory>
#include <vector>
#include "../Model/lanes.hpp"
#include "movingobjectview.hpp"
/*
class LaneView {
    protected:
        std::shared_ptr<Lane> lane;
        std::vector<std::shared_ptr<MovingObjectView>> viewable {};
    public:
        LaneView(std::shared_ptr<Lane> lane);
        LaneView(std::shared_ptr<Lane> lane,
                 std::vector<std::shared_ptr<MovingObjectView>> mvv): lane(lane), viewable(mvv) {}
        virtual void draw() = 0;
        virtual ~LaneView() {}
};
*/

class LaneView {
    protected:
        std::shared_ptr<Lane> lane;
    public:
        LaneView(std::shared_ptr<Lane> lane): lane(lane){}
        virtual void draw() = 0;
        static std::shared_ptr<LaneView> makeView(std::shared_ptr<Lane> l);
        virtual ~LaneView() {}
};

// class WaterLaneView: public LaneView {
//     public:
//         WaterLaneView(): LaneView() {}
//         virtual void draw() override = 0;
//         virtual ~WaterLaneView() {}
// };

class SafeLaneView: public LaneView {
    // private:
    //     std::shared_ptr<SafeLane> sfl;
    public:
        SafeLaneView(std::shared_ptr<SafeLane> sfl): LaneView(sfl) {}
        void draw() final;
        ~SafeLaneView() {}
};

class FinishLaneView: public LaneView {
    public:
        FinishLaneView(std::shared_ptr<FinishLane> fl): LaneView(fl) {}
        void draw() final;
        ~FinishLaneView() {}
};

class RoadLaneView: public LaneView {
    private:
        std::vector<std::shared_ptr<CarView>> cv;
    public:
        RoadLaneView(std::shared_ptr<RoadLane> rl): LaneView(rl) {
            for (auto& car: rl->getMovingObjects()) {
                cv.push_back(std::make_shared<CarView>(std::dynamic_pointer_cast<Car>(car)));
            }
        }
        void draw() final;
        ~RoadLaneView() {}
};

class LogLaneView: public LaneView {
    private:
        std::vector<std::shared_ptr<LogView>> lv;
    public:
        LogLaneView(std::shared_ptr<LogLane> ll): LaneView(ll) {
            for (auto& _log: ll->getMovingObjects()) {
                lv.push_back(std::make_shared<LogView>(std::dynamic_pointer_cast<Log>(_log)));
            }
        }
        void draw() final;
        ~LogLaneView() {}
};

class TurtleLaneView: public LaneView {
    private:
        std::shared_ptr<TurtleLane> tl;
        std::vector<std::shared_ptr<TurtleView>> tv {};
    public:
        TurtleLaneView(std::shared_ptr<TurtleLane> tl): LaneView(tl) {
            for (auto& turtle: tl->getMovingObjects()) {
                tv.push_back(std::make_shared<TurtleView>(std::dynamic_pointer_cast<Turtle>(turtle)));
            }
        }
        void draw() final;
        ~TurtleLaneView() {}
};

#endif // LANEVIEW_H_
