#ifndef LANEVIEW_H_
#define LANEVIEW_H_

#include <memory>
#include <vector>
#include "../Model/lanes.hpp"
#include "liliesview.hpp"
#include "movingobjectview.hpp"
#include "../tooling/drawing_methods.hpp"


class LaneView {
    protected:
        std::shared_ptr<Lane> lane;
        LaneDrawer ld;
    public:
        LaneView(std::shared_ptr<Lane> lane);
        virtual void draw() = 0;
        static std::shared_ptr<LaneView> makeView(std::shared_ptr<Lane> l);
        virtual ~LaneView() {}
};

class SafeLaneView: public LaneView {
    public:
        SafeLaneView(std::shared_ptr<SafeLane> sfl);
        void draw() final override;
        ~SafeLaneView() {}
};

class FinishLaneView: public LaneView {
    private:
        std::vector<std::shared_ptr<LiliesView>> lilies;
    public:
        FinishLaneView(std::shared_ptr<FinishLane> fl);
        void draw() final;
        ~FinishLaneView() {}
};

class RoadLaneView: public LaneView {
    private:
        std::vector<std::shared_ptr<CarView>> cv;
    public:
        RoadLaneView(std::shared_ptr<RoadLane> rl);
        void draw() final;
        ~RoadLaneView() {}
};

class LogLaneView: public LaneView {
    private:
        std::vector<std::shared_ptr<LogView>> lv;
    public:
        LogLaneView(std::shared_ptr<LogLane> ll);
        void draw() final;
        ~LogLaneView() {}
};

class TurtleLaneView: public LaneView {
    private:
        std::vector<std::shared_ptr<TurtleView>> tv;
    public:
        TurtleLaneView(std::shared_ptr<TurtleLane> tl);
        void draw() final;
        ~TurtleLaneView() {}
};

#endif // LANEVIEW_H_
