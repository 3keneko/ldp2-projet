#include "fltk_tools.hpp"

/*----------------------------------------------------------------------------------

Text class
-----------------------------------------------------------------------------------*/

Text::Text(std::string &&s, Point center, int fontSize = 10, Fl_Color color = FL_BLACK)
    : center{center}, s{s}, fontSize{fontSize}, color{color} {}

void Text::draw() {
  fl_color(color);
  fl_font(FL_HELVETICA, fontSize);
  int width, height;
  fl_measure(s.c_str(), width, height, false);
  int x = static_cast<int>(fl_transform_x(
      center.x - width / 2, center.y - fl_descent() + height / 2));
  int y = static_cast<int>(fl_transform_y(
      center.x - width / 2, center.y - fl_descent() + height / 2));
  fl_draw(s.c_str(), x, y);
}

/*----------------------------------------------------------------------------------

Translation class
-----------------------------------------------------------------------------------*/

explicit Translation::Translation(Point p) {
    fl_push_matrix();
    fl_translate(p.x, p.y);
  }

/*----------------------------------------------------------------------------------

Rotation class
-----------------------------------------------------------------------------------*/

Rotation::Rotation(Point center, double angle) {
    fl_push_matrix();
    fl_translate(center.x, center.y);
    fl_rotate(angle);
    fl_translate(-1 * center.x, -1 * center.y);
  }

/*----------------------------------------------------------------------------------

Polygon class
-----------------------------------------------------------------------------------*/

Polygon::Polygon(const std::vector<Point> &vertexes, Point center,
                 Fl_Color frameColor, Fl_Color fillColor)
    : vertexes{vertexes}, center{center}, fillColor{fillColor},
      frameColor{frameColor} {}

void Polygon::draw() const {
  const Point v0 = vertexes.at(0);
  fl_color(fillColor);
  fl_begin_polygon();
  for (auto &point : vertexes) {
    fl_vertex(point.x, point.y);
  }
  fl_vertex(v0.x, v0.y);
  fl_end_polygon();
  fl_color(frameColor);
  fl_begin_line();
  for (auto &point : vertexes) {
    fl_vertex(point.x, point.y);
  }
  fl_vertex(v0.x, v0.y);
  fl_end_line();
}

/*-----------------------------------------------------------------------------------

Canvas class
------------------------------------------------------------------------------------*/

void Canvas::keyPressed(int keyCode) {
  switch (keyCode) {
  case 'q':
    exit(0);
  }
}

/*-----------------------------------------------------------------------------------

MainWindow class
------------------------------------------------------------------------------------*/

MainWindow::MainWindow() : Fl_Window(500, 500, windowWidth, windowHeight, "Lab 7") {
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
      canvas.mouseClick(Point{Fl::event_x(), Fl::event_y()});
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