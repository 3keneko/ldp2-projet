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
            auto lane1 = std::make_shared<SafeLane>(1);
            auto lane2 = std::make_shared<SafeLane>(2);
            auto lane3 = std::make_shared<RoadLane>(3, 3, 150, 350, 0, 150, 5);
            auto lane4 = std::make_shared<RoadLane>(3, 3, 150, 350, 0, 150, 5);
            auto lane5 = std::make_shared<RoadLane>(3, 3, 150, 350, 0, 150, 5);
            auto lane6 = std::make_shared<RoadLane>(3, 3, 150, 350, 0, 150, 5);
            auto lane7 = std::make_shared<SafeLane>(7);
            auto lane8 = std::make_shared<TurtleLane>(8, 5, 10, 200, 0, 50);
            auto lane9 = std::make_shared<TurtleLane>(9, 5, 10, 200, 0, 50);
            auto lane10 = std::make_shared<LogLane>(10, 3, 100, 350, 0, 200);
            auto lane11 = std::make_shared<LogLane>(11, 3, 100, 350, 0, 200);
            auto lane12 = std::make_shared<LogLane>(12, 3, 100, 350, 0, 200);
            auto lane13 = std::make_shared<FinishLane>(13);
            std::vector<std::shared_ptr<MovingObjectLane>> v1 { lane1, lane2, lane3, lane4, lane5, 
                                                    lane6, lane7, lane8, lane9, lane10, 
                                                    lane11, lane12, lane13};
            // Problème au niveau du vecteur
            auto lane1_view = std::make_shared<SafeLaneView>(lane1);
            auto lane2_view = std::make_shared<SafeLaneView>(lane2);
            auto lane3_view = std::make_shared<RoadLaneView>(lane3);
            auto lane4_view = std::make_shared<RoadLaneView>(lane4);
            auto lane5_view = std::make_shared<RoadLaneView>(lane5);
            auto lane6_view = std::make_shared<RoadLaneView>(lane6);
            auto lane7_view = std::make_shared<SafeLaneView>(lane7);
            auto lane8_view = std::make_shared<TurtleLaneView>(lane8);
            auto lane9_view = std::make_shared<TurtleLaneView>(lane9);
            auto lane10_view = std::make_shared<LogLaneView>(lane10);
            auto lane11_view = std::make_shared<LogLaneView>(lane11);
            auto lane12_view = std::make_shared<LogLaneView>(lane12);
            // On a pas encore de classe FinishLaneView
            std::vector<std::shared_ptr<LaneView>> v { lane1_view, lane2_view, lane3_view,
                                                       lane4_view, lane5_view, lane6_view,
                                                       lane7_view, lane8_view, lane9_view,
                                                       lane10_view, lane11_view, lane12_view,
                                                     };

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
