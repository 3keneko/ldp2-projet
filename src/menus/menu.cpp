#include "menu.hpp"

void Menu::draw() {
    for (auto &obj: objects) {
        obj->draw();
    }
}

void Menu::mouseClick(int xMouse, int yMouse) {
    for (auto &button: buttons) {
        if (button->contains(xMouse, yMouse)) button->onClick();
    }
}

void Menu::add_object(std::shared_ptr<ToDraw> obj) {
    objects.push_back(obj);
}

void Menu::add_button(std::shared_ptr<Clickable> button) {
    buttons.push_back(button);
}