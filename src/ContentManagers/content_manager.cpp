#include "content_manager.hpp"

void ContentManager::show() {
    if (gl != nullptr) {
        gl->update();
    } else {
        contents->draw();
    }
}

void ContentManager::manage_button_push(int x, int y) {
        if (gl != nullptr) {
                return;
            }
        contents->manage_button_push(x, y);
}
