#ifndef BOARDFROMFILE_H_
#define BOARDFROMFILE_H_

#include <memory>
#include <string>

#include "scoresaver.hpp"

#include "../View/boardview.hpp"
#include "../View/frogview.hpp"

#include "../Model/boardmodel.hpp"
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
        // initializing from level number
        void init_from_lvl(unsigned i);
        // getters
        std::shared_ptr<BoardView> getBoardView();
        std::shared_ptr<Frog> getFrog();
        std::shared_ptr<BoardModel> getBoardModel();
        std::shared_ptr<FrogView> getFrogView();
        std::unique_ptr<ScoreSaver> getScoreSaver();
        ~BoardFromFile() {}
};

#endif // BOARDFROMFILE_H_
