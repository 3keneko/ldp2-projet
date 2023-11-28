#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_
#include "mainloop.hpp"
#include <FL/Fl_Window.H>
#include <FL/Fl.H>

const double refreshPerSecond = 60;
const int windowWidth = 500;
const int windowHeight = 500;

class MainWindow : public Fl_Window {
  private:
    std::shared_ptr<MainLoop> main;
    public:
        MainWindow(std::shared_ptr<MainLoop> main) : Fl_Window(650, 650, windowWidth, windowHeight, "Frogger Game"), main(main) {
            Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
            resizable(this);
        }
        void draw() override {
            std::cout << "huh" << std::endl;
            Fl_Window::draw();
          main->update();
        }

        static void Timer_CB(void *userdata) {
            MainWindow *o = static_cast<MainWindow*>(userdata);
            o->redraw();
            Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
        }

};



#endif // MAINWINDOW_H_
