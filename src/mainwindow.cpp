#include "mainwindow.hpp"

#include <FL/Fl.H>

#include "constants.hpp"
#include "GameManagers/gameloop.hpp"

MainWindow::MainWindow(std::shared_ptr<ContentManager> contents) :
    Fl_Window(500, 500, constants::window::WIDTH, constants::window::HEIGHT, "Frogger Game"),
    contents(contents) {
        Fl::add_timeout(1.0/constants::window::RPS, Timer_CB, this);
        resizable(this);
        }

void MainWindow::draw() {
    Fl_Window::draw();
    contents->show();
}

int MainWindow::handle(int event) {
    switch (event) {
        case FL_PUSH:
            contents->manageButtonPush(Fl::event_x(), Fl::event_y());
            return 1;
        default:
            return 0;
    }
    return 0;
}

void MainWindow::Timer_CB(void *userdata) {
    MainWindow *o = static_cast<MainWindow*>(userdata);
    o->redraw();
    Fl::repeat_timeout(1.0/constants::window::RPS, Timer_CB, userdata);
}