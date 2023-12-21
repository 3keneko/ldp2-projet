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
#include "../tooling/image_classes.hpp"

using namespace constants::frog;

class FrogView {    
    std::shared_ptr<Frog> frog;
    // Paths to the images of the frog
    JPEGDrawer current_image{paths::frog_north_jpeg, frog->getX(),
                                static_cast<int>(frog->getLane()), HEIGHT, WIDTH};
public:
    FrogView(std::shared_ptr<Frog> f): frog(f) {}
    void showLives();
    void draw();
};

#endif

