#include "content_manager.hpp"
#include "level_select.hpp"
#include <memory>


void ContentManager::startGame(std::unique_ptr<GameLoop> g) {
    gl = std::move(g);
}

void ContentManager::changeContents(std::unique_ptr<WindowContents> new_contents) {
    contents = std::move(new_contents);
}

void ContentManager::show() {
    if (gl != nullptr) {
        gl->update();
    } else {
        contents->draw();
    }
}


void ContentManager::manageButtonPush(int x, int y) {
    if (gl != nullptr) {
            return;
        }
    contents->manageButtonPush(x, y);
}


void ContentManager::contentManageAction(actions& action) {
    contents->manageAction(action);
}
