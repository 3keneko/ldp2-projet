#ifndef BOARDFROMFILE_H_
#define BOARDFROMFILE_H_

#include <memory>
#include <vector>
#include <string>

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
        std::shared_ptr<Score> score = std::make_shared<Score>(0);
        std::shared_ptr<ScoreView> sv = std::make_shared<ScoreView>(score);
    public:
        BoardFromFile() {}

        // initializing from file
        void init_from_file(std::string const& path_to_file);

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
        std::shared_ptr<Score> getScore() {
            return score; 
        }
        std::shared_ptr<ScoreView> getScoreView() {
            return sv;
        }
        ~BoardFromFile() {}
};

#endif // BOARDFROMFILE_H_
