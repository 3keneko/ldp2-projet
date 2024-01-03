#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <FL/Fl_Window.H>
#include "ContentManagers/content_manager.hpp"

class MainWindow : public Fl_Window {
    private:
        std::shared_ptr<ContentManager> contents;
    public:
        MainWindow(std::shared_ptr<ContentManager> contents);
        void draw() override;
        int handle(int event) override;
        static void Timer_CB(void *userdata);
};

#endif // MAINWINDOW_H_
