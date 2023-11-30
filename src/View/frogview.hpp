#ifndef FROGVIEW_HPP
#define FROGVIEW_HPP

#include "../Model/frog.hpp"
#include <memory>
#include <tuple>

class FrogView {
    std::shared_ptr<Frog> frog;
    unsigned int tick = 0;

public:
    FrogView(std::shared_ptr<Frog> f): frog(f) {}
    void draw();
    void moveLeft();
    void moveRight();
    void moveFrwrd();
    void moveBckwrds();
};

#endif

