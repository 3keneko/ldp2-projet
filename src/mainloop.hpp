#ifndef MAINLOOP_H_
#define MAINLOOP_H_
#include <memory>
#include "Model/boardmodel.hpp"
#include "View/boardview.hpp"
#include "View/frogview.hpp"
#include "Model/frog.hpp"
#include <FL/Fl_PNG_Image.H>
#include "Controller/control.hpp"
#include "constants.hpp"
#include <FL/Fl.H>
#include <FL/Fl_JPEG_Image.H>
#include <FL/Fl_Box.H>

class MainLoop {
  private:
    std::shared_ptr<BoardModel> bm;
    std::shared_ptr<BoardView> bv;
    std::shared_ptr<FrogView> fv;
    std::shared_ptr<Frog> frog;
    Controller c;
    // bool is_lost = false;
  public:
    MainLoop(std::shared_ptr<BoardModel> bm, std::shared_ptr<BoardView> bv,
             std::shared_ptr<FrogView> fv, std::shared_ptr<Frog> frog):
      bm(bm), bv(bv), fv(fv), frog(frog), c(Controller(frog)){}
    void update() {
      if (bm->inFinishLane(*frog)) {
        auto jpeg = std::make_unique<Fl_JPEG_Image>("../imgs/won.jpeg" );
        if (jpeg->fail()) { std::cout << "couldn't open the image!" << std::endl;}
        jpeg->draw(0, 0, constants::window::HEIGHT, constants::window::WIDTH);
      } else if (frog->alive()) {
        bm->update();
        bv->draw();
        fv->draw();
        char key = Fl::event_key();
        c.processKey(key);
        bm->handle_collision(*frog);
        int s = Fl::event();
        if (s == FL_KEYUP) c.resetPressedKeys();
      } else {
        auto jpeg = std::make_unique<Fl_JPEG_Image>("../imgs/Untitled.jpeg" );
        if (jpeg->fail()) { std::cout << "couldn't open the image!" << std::endl;}
        jpeg->draw(0, 0, constants::window::HEIGHT, constants::window::WIDTH);
      }
    }
    std::shared_ptr<BoardModel> getModel() { return bm; }
    std::shared_ptr<BoardView> getView() { return bv; }
    std::shared_ptr<FrogView> getFrog() { return fv; }
    ~MainLoop() {}
};


#endif // MAINLOOP_H_
