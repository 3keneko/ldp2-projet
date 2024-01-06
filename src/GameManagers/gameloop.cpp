#include "gameloop.hpp"

#include <FL/Fl_PNG_Image.H>
#include <FL/Fl.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Box.H>

#include "../constants.hpp"
#include "../tooling/image_classes.hpp"
#include "boardfromfile.hpp"



GameLoop::GameLoop(unsigned int lvl) {
    BoardFromFile init {};
    init.init_from_lvl(lvl);
    bm = init.getBoardModel();
    bv = init.getBoardView();
    score = std::make_shared<Score>(0);
    sv = std::make_shared<ScoreView>(score, constants::score::curr_x,
                                        constants::score::curr_y);
    Frog frg {0, 250, score};
    frog = std::make_shared<Frog>(frg);
    fv = std::make_shared<FrogView>(frog);
    c = std::make_shared<Controller>(frog);
    ssv = init.getScoreSaver();
    ssv->getFromFile();
    best_score = std::make_shared<Score>(ssv->getHighScore().getScore());
    bs_show = std::make_unique<ScoreView>(best_score, constants::score::best_x,
                                            constants::score::best_y, true);
}

void GameLoop::update() {

    if (bm->gameWon()) {
        FullScreenJPEGImage won_screen {"../imgs/won.jpeg"};
        won_screen.draw();
        ssv->setNewScore(*best_score);
        ssv->writeToFile();
    } else if (frog->alive()) {
        
    // Updating the score, the board and drawing them
    score->update(frog->getLane());
    bm->update();
    bv->draw();
    fv->draw();
    sv->draw();
    bs_show->draw();

    *best_score = *best_score > *score ? *best_score : *score;

    // Processing the game commands
    char key = Fl::event_key();
    c->processKey(key);
    c->decrement();
    bm->handle_collision(*frog);

    int s = Fl::event();

    if (s == FL_KEYUP) c->resetPressedKeys();
    } else {
        FullScreenJPEGImage lost_screen {"../imgs/Untitled.jpeg" };
        lost_screen.draw();
        ssv->setNewScore(*best_score);
        ssv->writeToFile();
    }
}

std::shared_ptr<BoardModel> GameLoop::getModel() { return bm; }

std::shared_ptr<BoardView> GameLoop::getView() { return bv; }

std::shared_ptr<FrogView> GameLoop::getFrog() { return fv; }
