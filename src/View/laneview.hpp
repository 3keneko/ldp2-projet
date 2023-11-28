#ifndef LANEVIEW_H_
#define LANEVIEW_H_

#include <memory>
#include "../Model/lanes.hpp"
#include "movingobjectview.hpp"

class LaneView {
    private:
        std::shared_ptr<Lane> lane;
        std::vector<std::shared_ptr<MovingObjectView>> viewable;
    public:
        LaneView(std::shared_ptr<Lane> lane, std::vector<std::shared_ptr<MovingObjectView>> mvv): lane(lane), viewable(mvv) {}
        void draw() {
            for (auto &obj: viewable) {
                obj->draw();
            }
        }
        ~LaneView() {}
};

#endif // LANEVIEW_H_
