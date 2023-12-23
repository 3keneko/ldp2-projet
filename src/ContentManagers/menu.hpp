#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <vector>
#include "../tooling/drawing_methods.hpp"

class Menu {
    std::vector<std::shared_ptr<ToDraw>> objects;
    std::vector<std::shared_ptr<Clickable>> buttons;
    public:
        Menu() {}
        Menu(std::vector<std::shared_ptr<ToDraw>>& objects): objects{objects} {}
        Menu(std::vector<std::shared_ptr<ToDraw>>& objects
                , std::vector<std::shared_ptr<Clickable>>& buttons)
            : objects{objects}, buttons{buttons} {}
            
        void add_object(std::shared_ptr<ToDraw> obj);
        void add_button(std::shared_ptr<Clickable> button);
        void draw();
        void mouseClick(int xMouse, int yMouse);
        ~Menu() {}
};


#endif
