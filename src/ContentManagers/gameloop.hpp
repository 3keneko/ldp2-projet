#ifndef GAMELOOP_H_
#define GAMELOOP_H_

#include <memory>

#include <FL/Fl_PNG_Image.H>
#include <FL/Fl.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Box.H>

#include "../Model/boardmodel.hpp"
#include "../View/boardview.hpp"
#include "../View/frogview.hpp"
#include "../Model/frog.hpp"
#include "../Controller/control.hpp"
#include "../View/scoreview.hpp"


#include "../constants.hpp"
#include "../tooling/image_classes.hpp"


#include "gameinit.hpp"

class GameLoop {
  private:
    std::shared_ptr<BoardModel> bm;
    std::shared_ptr<BoardView> bv;
    std::shared_ptr<FrogView> fv;
    std::shared_ptr<Frog> frog;
    std::shared_ptr<Score> score;
    std::shared_ptr<ScoreView> sv;
    std::shared_ptr<Controller> c;
    // bool is_lost = false;
  public:
    GameLoop(std::shared_ptr<BoardModel> bm, std::shared_ptr<BoardView> bv,
             std::shared_ptr<FrogView> fv, std::shared_ptr<Frog> frog):
      bm(bm), bv(bv), fv(fv), frog(frog), c(std::make_shared<Controller>(frog)){}

    GameLoop(std::shared_ptr<GameInit> gi): bm(gi->getBoardModel()), bv(gi->getBoardView()),
                            fv(gi->getFrogView()), frog(gi->getFrog()), score(gi->getScore()), 
                            sv{gi->getScoreView()}, c(std::make_shared<Controller>(frog)) {}

    GameLoop(std::string const& path) {
      GameInit init {};
      init.init_from_file(path);
      bm = init.getBoardModel();
      bv = init.getBoardView();
      frog = init.getFrog();
      fv = init.getFrogView();
      c = std::make_shared<Controller>(frog);
      score = init.getScore();
      sv = init.getScoreView();
    }


    void update() {

      if (bm->gameWon()) {
        FullScreenJPEGImage won_screen {"../imgs/won.jpeg"};
        won_screen.draw();
      } else if (frog->alive()) {
        score->update(frog->getLane());

        bm->update();
        bv->draw();
        fv->draw();
        sv->draw();

        char key = Fl::event_key();
        c->processKey(key);
        c->decrement();

        bm->handle_collision(*frog);

        int s = Fl::event();

        if (s == FL_KEYUP) c->resetPressedKeys();
      } else {
        FullScreenJPEGImage lost_screen {"../imgs/Untitled.jpeg" };
        lost_screen.draw();
      }

    }

    std::shared_ptr<BoardModel> getModel() { return bm; }
    std::shared_ptr<BoardView> getView() { return bv; }
    std::shared_ptr<FrogView> getFrog() { return fv; }

    ~GameLoop() {}
};


#endif // MAINLOOP_H_
