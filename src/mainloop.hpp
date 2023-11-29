#ifndef MAINLOOP_H_
#define MAINLOOP_H_
#include <memory>
#include "Model/boardmodel.hpp"
#include "View/boardview.hpp"
#include "View/frogview.hpp"
#include "Model/frog.hpp"
#include <FL/Fl_PNG_Image.H>

class MainLoop {
  private:
    std::shared_ptr<BoardModel> bm;
    std::shared_ptr<BoardView> bv;
    std::unique_ptr<FrogView> fv;
    std::unique_ptr<Frog> frog;
  public:
    MainLoop(std::shared_ptr<BoardModel> bm, std::shared_ptr<BoardView> bv,
             std::unique_ptr<FrogView> fv, std::unique_ptr<Frog> frog):
      bm(bm), bv(bv), fv(std::move(fv)), frog(std::move(frog)) {}
    void update() {
      bm->update();
      bv->draw();
      fv->draw();
    }
    std::shared_ptr<BoardModel> getModel() { return bm; }
    std::shared_ptr<BoardView> getView() { return bv; }
    std::unique_ptr<FrogView> getFrog() { return std::move(fv); }
    ~MainLoop() {}
};


#endif // MAINLOOP_H_
