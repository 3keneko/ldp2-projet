#include "canvas.hpp"

/*-----------------------------------------------------------------------------------

Canvas class
------------------------------------------------------------------------------------*/
Canvas::Canvas() {
    
}

Canvas::~Canvas() {
    
}

void Canvas::draw() {
    
}

void Canvas::mouseClick(Point mouseLoc) {
    
}


void Canvas::keyPressed(int keyCode) {
  switch (keyCode) {
  case 'q':
    exit(0);
  }
}

/*-----------------------------------------------------------------------------------

MainWindow class
------------------------------------------------------------------------------------*/

MainWindow::MainWindow() : Fl_Window(500, 500, windowWidth, windowHeight, "Frogger") {
    Fl::add_timeout(1.0 / refreshPerSecond, Timer_CB, this);
    resizable(this);
}

void MainWindow::draw() {
    Fl_Window::draw();
    canvas.draw();
}

int MainWindow::handle(int event) {
    switch (event) {
    case FL_PUSH:
      canvas.mouseClick(Point{static_cast<unsigned int>(Fl::event_x()), static_cast<unsigned int>(Fl::event_y())});
      return 1;
    case FL_KEYDOWN:
      canvas.keyPressed(Fl::event_key());
      return 1;
    default:
      return 0;
    }
    return 0;
  }

void MainWindow::Timer_CB(void *userdata) {
    MainWindow *o = static_cast<MainWindow *>(userdata);
    o->redraw();
    Fl::repeat_timeout(1.0 / refreshPerSecond, Timer_CB, userdata);
}
