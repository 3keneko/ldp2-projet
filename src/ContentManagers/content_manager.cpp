#include "content_manager.hpp"
#include "level_select.hpp"
#include <memory>


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
    std:: cout << x << " " << y << std::endl;
    if (gl != nullptr) {
            return;
        }
    contents->manageButtonPush(x, y);
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
                    std::cout << "okay 1" << std::endl;
                    contents->manageAction(action);
                    break;
                case actions::LEVELS: {
                    auto lev_sel = std::make_unique<LevelSelect>(
                        nullptr
                        // std::weak_ptr<ContentManager>(this)
                    );
                    changeContents(std::move(lev_sel));
                    break;
                }
                case actions::EDIT:
                case actions::NOTHING:
                default:
                    return;
            }
}
