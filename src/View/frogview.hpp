#ifndef FROGVIEW_HPP
#define FROGVIEW_HPP

#include "../Model/frog.hpp"
#include <memory>
#include <tuple>

class FrogView {    
    std::shared_ptr<Frog> frog;

public:
    FrogView(std::shared_ptr<Frog> f): frog(f) {}
    void draw();
};

#endif

