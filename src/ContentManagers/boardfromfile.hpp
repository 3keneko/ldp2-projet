#ifndef BOARDFROMFILE_H_
#define BOARDFROMFILE_H_

#include <memory>
#include <vector>
#include <string>

#include "../tooling/scoresaver.hpp"

#include "../View/boardview.hpp"
#include "../View/frogview.hpp"
#include "../View/laneview.hpp"
#include "../View/movingobjectview.hpp"
#include "../View/scoreview.hpp"


#include "../Model/score.hpp"
#include "../Model/boardmodel.hpp"
#include "../Model/lanes.hpp"
#include "../Model/frog.hpp"


class BoardFromFile {
    private:
        bool can_start = false;
        std::shared_ptr<BoardView> board;
        std::shared_ptr<Frog> frg;
        std::shared_ptr<BoardModel> bm;
        std::shared_ptr<FrogView> fv;
        std::unique_ptr<ScoreSaver> ssv;

        // initializing from file
        void init_from_file(std::string const& path_to_file);

    public:
        BoardFromFile() {}

        void init_from_lvl(unsigned i) {
            std::string path_file = "levels/level" + std::to_string(i) + ".csv";
            this->init_from_file(path_file); //+ std::to_string(i)
                                 //+ ".csv");
            ssv = std::make_unique<ScoreSaver>(i);
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
        std::unique_ptr<ScoreSaver> getScoreSaver() {
            return std::move(ssv);
        }
        ~BoardFromFile() {}
};

#endif // BOARDFROMFILE_H_
