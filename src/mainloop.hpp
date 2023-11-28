#ifndef MAINLOOP_H_
#define MAINLOOP_H_
#include <memory>
#include "Model/boardmodel.hpp"
#include "View/boardview.hpp"

class MainLoop {
  private:
    std::shared_ptr<BoardModel> bm;
    std::shared_ptr<BoardView> bv;
  public:
    MainLoop(std::shared_ptr<BoardModel> bm, std::shared_ptr<BoardView> bv): bm(bm), bv(bv) {}
    void update() {
      std::cout << "2" << std::endl;
      bm->update();
      bv->draw();
    }
    std::shared_ptr<BoardModel> getModel() { return bm; }
    std::shared_ptr<BoardView> getView() { return bv; }
    ~MainLoop() {}
};


#endif // MAINLOOP_H_
