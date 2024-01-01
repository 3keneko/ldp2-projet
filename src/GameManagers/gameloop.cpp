#include "gameloop.hpp"

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
