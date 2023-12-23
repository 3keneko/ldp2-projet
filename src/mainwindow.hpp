#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <FL/Fl_Window.H>
#include <FL/Fl.H>

#include "ContentManagers/gameloop.hpp"
#include "ContentManagers/content_manager.hpp"

#include "constants.hpp"

class MainWindow : public Fl_Window {
  private:
    std::shared_ptr<ContentManager> contents;
    public:
        MainWindow(std::shared_ptr<ContentManager> contents) :
            Fl_Window(650, 650, constants::window::WIDTH, constants::window::HEIGHT, "Frogger Game"),
            contents(contents) {
            Fl::add_timeout(1.0/constants::window::RPS, Timer_CB, this);
            resizable(this);
        }
        void draw() override {
            Fl_Window::draw();
            contents->show();
        }

        int handle(int event) override {
            switch (event) {
                case FL_PUSH:
                    contents->manage_button_push(Fl::event_x(), Fl::event_y());
                    return 1;
                default:
                    return 0;
            }
            return 0;
        }
        static void Timer_CB(void *userdata) {
            MainWindow *o = static_cast<MainWindow*>(userdata);
            o->redraw();
            Fl::repeat_timeout(1.0/constants::window::RPS, Timer_CB, userdata);
        }

};



#endif // MAINWINDOW_H_
