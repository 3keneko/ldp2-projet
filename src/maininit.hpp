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
#include <string>

class MainInit {
    private:
        bool can_start = false;
        std::shared_ptr<BoardView> board;
        std::shared_ptr<Frog> frg;
        std::shared_ptr<BoardModel> bm;
        std::shared_ptr<FrogView> fv;
    public:
        MainInit() {}

        void welcomeUser();

        // initializing from file and stuff
        void classic_init();
        void init_from_file(std::string path_to_file);

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
