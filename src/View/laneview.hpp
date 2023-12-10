#ifndef LANEVIEW_H_
#define LANEVIEW_H_

#include <FL/Enumerations.H>
#include <memory>
#include <vector>
#include "../Model/lanes.hpp"
#include "movingobjectview.hpp"

class LaneView {
    protected:
        std::shared_ptr<Lane> lane;
        std::vector<std::shared_ptr<MovingObjectView>> viewable;
    public:
        LaneView(std::shared_ptr<Lane> lane, std::vector<std::shared_ptr<MovingObjectView>> mvv): lane(lane), viewable(mvv) {}
        virtual void draw() = 0;
        virtual ~LaneView() {}
};

class WaterLaneView: public LaneView {
    public:
        WaterLaneView(std::shared_ptr<WaterLane> wl, std::vector<std::shared_ptr<MovingObjectView>> mvv): LaneView(wl, mvv) {}
        void draw() override;
        ~WaterLaneView() {}
};

#endif // LANEVIEW_H_
