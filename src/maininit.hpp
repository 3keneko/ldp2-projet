#ifndef MAININIT_H_
#define MAININIT_H_

#include "View/frogview.hpp"
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
            Frog frog {1, 10};
            std::vector<std::shared_ptr<Lane>> lanes;
            frg = std::make_shared<Frog>(frog);
            fv = std::make_shared<FrogView>(frg);
            auto c = std::make_shared<Car>(1, 40, 40, 7);
            auto d = std::make_shared<Car>(-1, 500, 40, 8);
            auto e = std::make_shared<Log>(2, 20, 100, 9);
            std::vector<std::shared_ptr<MovingObject>> cs { c, d, e };
            bm = std::make_shared<BoardModel>(cs);
            auto cv = std::make_shared<CarView>(c);
            auto dv = std::make_shared<CarView>(d);
            auto lv = std::make_shared<LogView>(e);
            std::vector<std::shared_ptr<MovingObjectView>> cars { cv, dv, lv };
            board = std::make_shared<BoardView>(cars, bm) ;
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
