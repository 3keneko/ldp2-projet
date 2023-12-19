#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "../Model/frog.hpp"
#include <memory>
#include <map>

// Move commands: Edit the position of the frog in the model
// and calls the corresponding functions from view.hpp to edit
// user's interface

// ? Il faudrait une classe controlleur
// On travaille avec MVC

class Controller {
    private:
        std::shared_ptr<Frog> f;
        std::map<char, bool> is_pressed;
        unsigned int count = 0;
    public:
        Controller(std::shared_ptr<Frog> f):
            f(f), is_pressed({{'z', false}, {'d', false}, {'q', false}, {'s', false}}) {}
        void decrement();
        void processKey(char& c);
        void updatePressedKeys(const char&& c);
        void resetPressedKeys();
        ~Controller() {}
};
// Will take user's input in parameters and execute 
// the upper commands depending on the input.


#endif
