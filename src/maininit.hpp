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
            Frog frog {1, 10};
            frg = std::make_shared<Frog>(frog);
            fv = std::make_shared<FrogView>(frg);

            // Initializing the lanes
            std::vector<std::shared_ptr<Lane>> lanes;
            auto test_lane = std::make_shared<RoadLane>(3, 4, 10, 30, 0, 20);
            std::vector<std::shared_ptr<Lane>> v1 { test_lane };
            auto test_lane_view = std::make_shared<RoadLaneView>(test_lane);
            std::vector<std::shared_ptr<LaneView>> v { test_lane_view };

            // Putting the frog and the lanes together; initializing the board
            bm = std::make_shared<BoardModel>(v1);
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
