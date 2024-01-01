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
#include "../tooling/scoresaver.hpp"

#include "boardfromfile.hpp"

class GameLoop {
  private:
    std::shared_ptr<BoardModel> bm;
    std::shared_ptr<BoardView> bv;
    std::shared_ptr<FrogView> fv;
    std::shared_ptr<Frog> frog;
    std::shared_ptr<Score> score;
    std::shared_ptr<ScoreView> sv;
    std::shared_ptr<Controller> c;
    std::unique_ptr<ScoreSaver> ssv;
    std::shared_ptr<Score> best_score;
    std::unique_ptr<ScoreView> bs_show;
    // bool is_lost = false;
  public:
    /*
    GameLoop(std::shared_ptr<BoardModel> bm, std::shared_ptr<BoardView> bv,
             std::shared_ptr<FrogView> fv, std::shared_ptr<Frog> frog):
      bm(bm), bv(bv), fv(fv), frog(frog), c(std::make_shared<Controller>(frog)){}
    */
    /*GameLoop(std::shared_ptr<BoardFromFile> gi): bm(gi->getBoardModel()), bv(gi->getBoardView()),
                            fv(gi->getFrogView()), frog(gi->getFrog()), score(gi->getScore()), 
                            sv{gi->getScoreView()}, c(std::make_shared<Controller>(frog)) {}
    */
    GameLoop(unsigned int lvl) {
      BoardFromFile init {};
      init.init_from_lvl(lvl);

      bm = init.getBoardModel();
      bv = init.getBoardView();

      score = std::make_shared<Score>(0);
      sv = std::make_shared<ScoreView>(score,
                                       constants::score::curr_x,
                                       constants::score::curr_y
      );

      Frog frg {0, 250, score};
      frog = std::make_shared<Frog>(frg);
      fv = std::make_shared<FrogView>(frog);
      c = std::make_shared<Controller>(frog);

      ssv = init.getScoreSaver();
      ssv->getFromFile();
      best_score = std::make_shared<Score>(ssv->getHighScore().getScore());
      bs_show = std::make_unique<ScoreView>(best_score,
                                            constants::score::best_x, constants::score::best_y,
                                            true);
    }


    void update();

    std::shared_ptr<BoardModel> getModel() { return bm; }
    std::shared_ptr<BoardView> getView() { return bv; }
    std::shared_ptr<FrogView> getFrog() { return fv; }

    ~GameLoop() {}
};


#endif // MAINLOOP_H_
