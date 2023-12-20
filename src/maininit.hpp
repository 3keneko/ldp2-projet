#ifndef MAININIT_H_
#define MAININIT_H_

#include "View/frogview.hpp"
#include "View/laneview.hpp"
#include "View/movingobjectview.hpp"
#include "Model/boardmodel.hpp"
#include "View/boardview.hpp"
#include "Model/lanes.hpp"
#include <memory>
#include <vector>
#include "Model/frog.hpp"


class MainInit {
    private:
        std::shared_ptr<BoardView> board;
        std::shared_ptr<Frog> frg;
        std::shared_ptr<BoardModel> bm;
        std::shared_ptr<FrogView> fv;
    public:
        MainInit() {
            // Intializing the frog
            Frog frog {0, 250};
            frg = std::make_shared<Frog>(frog);
            fv = std::make_shared<FrogView>(frg);

            // Initializing the lanes
            std::vector<std::shared_ptr<Lane>> lanes;
            lanes.push_back(std::make_shared<SafeLane>(1));
            lanes.push_back(std::make_shared<SafeLane>(2));
            lanes.push_back(std::make_shared<RoadLane>(3, 3, 150, 350, 0, 30, 1));
            lanes.push_back(std::make_shared<RoadLane>(4, 3, 150, 350, 0, 30, 2));
            lanes.push_back(std::make_shared<RoadLane>(5, 10, 150, 350, 0, 40, 3));
            lanes.push_back(std::make_shared<RoadLane>(6, 3, 150, 350, 0, 40, -2));
            lanes.push_back(std::make_shared<SafeLane>(7));
            lanes.push_back(std::make_shared<TurtleLane>(8, 5, 10, 200, 0, 50, 1));
            lanes.push_back(std::make_shared<TurtleLane>(9, 5, 10, 200, 0, 50, -1));
            lanes.push_back(std::make_shared<LogLane>(10, 3, 30, 350, 2, 200, 1));
            lanes.push_back(std::make_shared<LogLane>(11, 3, 30, 350, -2, 200, 2));
            lanes.push_back(std::make_shared<LogLane>(12, 3, 30, 350, 2, 200, -1));
            lanes.push_back(std::make_shared<FinishLane>(13));

            std::vector<std::shared_ptr<MovingObjectLane>> v1 { };
            for (auto& lane: lanes) {
                auto moving_object_lane = std::dynamic_pointer_cast<MovingObjectLane>(lane);
                if (moving_object_lane != nullptr) {
                    v1.push_back(moving_object_lane);
                }
            }

            std::vector<std::shared_ptr<LaneView>> v {};

            for (auto& lane: lanes) {
                v.push_back(LaneView::makeView(lane));
            }
            // Putting the frog and the lanes together; initializing the board
            bm = std::make_shared<BoardModel>(lanes);
            board = std::make_shared<BoardView>(v, bm) ;
        }
        std::shared_ptr<BoardView> getBoardView() {
            return board;
        }
        std::shared_ptr<Frog> getFrog() {
            return frg;
        }
        std::shared_ptr<BoardModel> getBoardModel() {
            return bm;
        }
        std::shared_ptr<FrogView> getFrogView() {
            return fv;
        }
        ~MainInit() {}
};

#endif // MAININIT_H_
