#ifndef FROGVIEW_HPP
#define FROGVIEW_HPP

#include "../Model/frog.hpp"
#include <memory>
#include <tuple>
#include <FL/Enumerations.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_JPEG_Image.H>

class FrogView {    
    std::shared_ptr<Frog> frog;
    Fl_JPEG_Image frog_north_jpeg = "../imgs/frog_north.jpeg";
    Fl_JPEG_Image frog_south_jpeg = "../imgs/frog_south.jpeg";
    Fl_JPEG_Image frog_west_jpeg = "../imgs/frog_west.jpeg";
    Fl_JPEG_Image frog_east_jpeg = "../imgs/frog_east.jpeg";
public:
    FrogView(std::shared_ptr<Frog> f): frog(f) {}
    void showLives();
    void draw();
    void draw2(); // Will replace draw afterwards
};

#endif

