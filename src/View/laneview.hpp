#ifndef LANEVIEW_H_
#define LANEVIEW_H_

#include <memory>
#include "../Model/lanes.hpp"

class LaneView {
    private:
        std::shared_ptr<Lane> lane;
    public:
        LaneView(std::shared_ptr<Lane> l): lane(l) {}
        void draw() {
            for (auto &obj: lane->getObjects()) {

            }
        }
        ~LaneView() {}
};

#endif // LANEVIEW_H_
