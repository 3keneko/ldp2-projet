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

const int windowWidth = 650;
const int windowHeight = 650;
const double refreshPerSecond = 60;

/*----------------------------------------------------------------------------------

Point class
-----------------------------------------------------------------------------------*/

struct Point {
    int x, y;
};

/*----------------------------------------------------------------------------------

Rectangle class
-----------------------------------------------------------------------------------*/

class Rectangle {
  Point    center;
  int      w, h;
  Fl_Color fillColor, frameColor;

 public:
  Rectangle(Point center, int w, int h, Fl_Color frameColor = FL_BLACK,
            Fl_Color fillColor = FL_WHITE);
  void     draw();
  void     setFillColor(Fl_Color newFillColor);
  Fl_Color getFillColor() { return fillColor; }
  void     setFrameColor(Fl_Color newFrameColor);
  Fl_Color getFrameColor() { return frameColor; }
  void     setWidth(int neww) { w = neww; }
  void     setHeight(int newh) { h = newh; }
  int      getWidth() { return w; }
  int      getHeight() { return h; }
  bool     contains(Point p);
  Point    getCenter() { return center; }
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
  Rotation(Point center, double angle);
  ~Rotation() { fl_pop_matrix(); }
};

#endif