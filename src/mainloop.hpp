#ifndef MAINLOOP_H_
#define MAINLOOP_H_
#include <memory>
#include "Model/boardmodel.hpp"
#include "View/boardview.hpp"
#include "View/frogview.hpp"
#include "Model/frog.hpp"
#include <FL/Fl_PNG_Image.H>
#include "Controller/control.hpp"

class MainLoop {
  private:
    std::shared_ptr<BoardModel> bm;
    std::shared_ptr<BoardView> bv;
    std::shared_ptr<FrogView> fv;
    std::shared_ptr<Frog> frog;
    Controller c;
  public:
    MainLoop(std::shared_ptr<BoardModel> bm, std::shared_ptr<BoardView> bv,
             std::shared_ptr<FrogView> fv, std::shared_ptr<Frog> frog):
      bm(bm), bv(bv), fv(fv), frog(frog), c(Controller(frog)){}
    void update() {
      bm->update();
      bv->draw();
      fv->draw();
      c.processKey();
    }
    std::shared_ptr<BoardModel> getModel() { return bm; }
    std::shared_ptr<BoardView> getView() { return bv; }
    std::shared_ptr<FrogView> getFrog() { return fv; }
    ~MainLoop() {}
};


#endif // MAINLOOP_H_
