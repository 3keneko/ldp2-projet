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
    public:
        LaneView() {}
        virtual void draw() = 0;
        virtual ~LaneView() {}
};

class WaterLaneView: public LaneView {
    public:
        WaterLaneView(): LaneView() {}
        virtual void draw() override;
        virtual ~WaterLaneView() {}
};

class SafeLaneView: public LaneView {
    private:
        std::shared_ptr<SafeLane> sfl;
    public:
        SafeLaneView(std::shared_ptr<SafeLane> sfl): sfl(sfl) {}
        virtual void draw() final;
        ~SafeLaneView() {}
};

class RoadLaneView: public LaneView {
    private:
        std::shared_ptr<RoadLane> rl;
    public:
        RoadLaneView(std::shared_ptr<RoadLane> rl): LaneView(), rl(rl) {}
        void draw() final;
        ~RoadLaneView() {}
};

class LogLaneView: public WaterLaneView {
    private:
        std::shared_ptr<LogLane> ll;
    public:
        LogLaneView(std::shared_ptr<LogLane> ll): WaterLaneView(), ll(ll) {}
        void draw() final;
        ~LogLaneView() {}
};

class TurtleLaneView: public WaterLaneView {
    private:
        std::shared_ptr<TurtleLane> tl;
    public:
        TurtleLaneView(std::shared_ptr<TurtleLane> tl): WaterLaneView(), tl(tl) {}
        void draw() final;
        ~TurtleLaneView() {}
};

class FinalLaneView: public WaterLaneView {
    public:
        FinalLaneView(): WaterLaneView() {}
        void draw() final;
        ~FinalLaneView() {}
};

#endif // LANEVIEW_H_
