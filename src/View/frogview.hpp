#ifndef FROGVIEW_HPP
#define FROGVIEW_HPP

#include "../Model/frog.hpp"
#include "../tooling/image_classes.hpp"
#include "../constants.hpp"

#include <memory>

using namespace constants::frog;

class FrogView {    
    std::shared_ptr<Frog> frog;
    JPEGDrawer current_image{paths::frog_north_jpeg, frog->getX(),
                                static_cast<int>(frog->getLane()), HEIGHT, WIDTH};
public:
    FrogView(std::shared_ptr<Frog> f);
    void showLives();
    void draw();
};

#endif
