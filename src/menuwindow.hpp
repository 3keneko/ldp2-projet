#ifndef MENUWINDOW_H_
#define MENUWINDOW_H_

#include "constants.hpp"
#include "mainwindow.hpp"
#include <FL/Enumerations.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <stdexcept>

const double rps = 60;

class MenuWindow: public Fl_Window {
    public:
        MenuWindow(): Fl_Window(650, 650, constants::window::WIDTH,
                       constants::window::HEIGHT, "Menu") {
            Fl::add_timeout(1.0/constants::window::RPS, Timer_CB, this);
            resizable(this);
        }
        void draw() override {
            Fl_Window::draw();
        }
        static void Timer_CB(void *userdata) {
            MainWindow *o = static_cast<MainWindow*>(userdata);
            o->redraw();
            Fl::repeat_timeout(1.0/constants::window::RPS, Timer_CB, userdata);
        }
        ~MenuWindow() {}
};

#endif // MENUWINDOW_H_
