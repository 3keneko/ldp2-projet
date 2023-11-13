//Contains some classes and functions to use fltk easily.
//These functions and classes come from the labs.


#ifndef FLTK_TOOLS_HPP
#define FLTK_TOOLS_HPP

#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <math.h>
#include <time.h>
#include <iostream>
#include <array>
#include <string>
#include <vector>

const int windowWidth = 450;
const int windowHeight = 450;
const double refreshPerSecond = 60;

/*----------------------------------------------------------------------------------

Point class
-----------------------------------------------------------------------------------*/

struct Point {
    int x, y;
};

/*----------------------------------------------------------------------------------

Text class
-----------------------------------------------------------------------------------*/

class Text {
  Point    center;
  std::string   s;
  int      fontSize;
  Fl_Color color;

 public:
  Text(std::string &&s, Point center, int fontSize = 10, Fl_Color color = FL_BLACK);
  void draw();
  std::string getString() { return s; }
  void   setString(const std::string &newString) { s = newString; }
  int    getFontSize() { return fontSize; }
  void   setFontSize(int newFontSize) { fontSize = newFontSize; }
  Point  getCenter() { return center; }
  void   setCenter(Point newCenter) { center = newCenter; }
};

/*----------------------------------------------------------------------------------

Translation class
-----------------------------------------------------------------------------------*/

struct Translation {
  explicit Translation(Point p);
  ~Translation() { fl_pop_matrix(); }
};

/*----------------------------------------------------------------------------------

Rotation class
-----------------------------------------------------------------------------------*/

struct Rotation {
  Rotation(Point center, double angle) {
    fl_push_matrix();
    fl_translate(center.x, center.y);
    fl_rotate(angle);
    fl_translate(-1 * center.x, -1 * center.y);
  }
  ~Rotation() { fl_pop_matrix(); }
};

/*-----------------------------------------------------------------------------------

Polygon class
------------------------------------------------------------------------------------*/

class Polygon {
  const std::vector<Point> vertexes;
  Point center;
  Fl_Color fillColor, frameColor;

 public:
  Polygon(const std::vector<Point> &vertexes, Point center,
          Fl_Color frameColor = FL_BLACK, Fl_Color fillColor = FL_WHITE);

  std::vector<Point> getVertexes();
  Point getCenter();
  void draw() const;
};

/*-----------------------------------------------------------------------------------

Canvas class
------------------------------------------------------------------------------------*/

class Canvas {

 public:
  Canvas();
  void draw();
  void mouseClick(Point mouseLoc);
  void keyPressed(int keyCode);
};

/*-----------------------------------------------------------------------------------

MainWindow class
------------------------------------------------------------------------------------*/

class MainWindow : public Fl_Window {
  Canvas canvas;

 public:
  MainWindow();
  void draw() override;
  int handle(int event) override;
  static void Timer_CB(void *userdata);
  };


#endif