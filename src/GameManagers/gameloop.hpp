#ifndef GAMELOOP_H_
#define GAMELOOP_H_

#include <memory>

#include "../Model/boardmodel.hpp"
#include "../View/boardview.hpp"
#include "../View/frogview.hpp"
#include "../Model/frog.hpp"
#include "../Controller/control.hpp"
#include "../View/scoreview.hpp"
#include "../tooling/scoresaver.hpp"

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
  public:
    GameLoop(unsigned int lvl);
    void update();
    std::shared_ptr<BoardModel> getModel();
    std::shared_ptr<BoardView> getView();
    std::shared_ptr<FrogView> getFrog();
    ~GameLoop() {}
};

#endif // MAINLOOP_H_
