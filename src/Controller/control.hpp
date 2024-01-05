#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "../Model/frog.hpp"
#include <memory>
#include <map>

class Controller {
    private:
        std::shared_ptr<Frog> f;
        std::map<char, bool> is_pressed;
        unsigned int count = 0;
    public:
        Controller(std::shared_ptr<Frog> f);
        void decrement();
        void processKey(char& c);
        void updatePressedKeys(const char&& c);
        void resetPressedKeys();
        ~Controller() {}
};

#endif
