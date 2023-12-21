#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_
#include "constants.hpp"
#include "mainloop.hpp"
#include <FL/Fl_Window.H>
#include <FL/Fl.H>

const double refreshPerSecond = 60;

class MainWindow : public Fl_Window {
  private:
    std::unique_ptr<MainLoop> main;
    public:
        MainWindow(std::unique_ptr<MainLoop> main) : Fl_Window(650, 650, constants::window::WIDTH,
                                                               constants::window::HEIGHT, "Frogger Game"), main(std::move(main)) {
            Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
            resizable(this);
        }
        void draw() override {
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
