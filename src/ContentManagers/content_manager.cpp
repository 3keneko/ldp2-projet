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

void ContentManager::updateWithAction(actions& action) {
            switch (action) {
                case actions::STARTGAME: {
                    // auto gi = std::make_unique<BoardFromFile>();
                    // gi->init_from_lvl(1);
                    gl = std::make_unique<GameLoop>(1);
                    break;
                }
                case actions::INCR:
                case actions::DIMIN:
                    contents->manageAction(action);
                    break;
                case actions::EDIT:
                case actions::LEVELS:
                case actions::NOTHING:
                default:
                    return;
            }
}
