#include "content_manager.hpp"

void ContentManager::show() {
    if (gl != nullptr) {
        gl->update();
    } else {
        contents->draw();
    }
}
