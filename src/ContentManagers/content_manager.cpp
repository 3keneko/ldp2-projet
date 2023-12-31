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


void ContentManager::contentManageAction(actions& action) {
    contents->manageAction(action);
}


void ContentManager::updateWithAction(std::shared_ptr<ContentManager> cm, actions& action) {
            switch (action) {
                case actions::STARTGAME: {
                    // auto gi = std::make_unique<BoardFromFile>();
                    // gi->init_from_lvl(1);
                    cm->start_game(std::make_unique<GameLoop>(2));
                    break;
                }
                case actions::STARTAFTERSEL:
                case actions::INCR:
                case actions::DIMIN:
                    cm->contentManageAction(action);
                    break;
                case actions::LEVELS: {
                    auto lev_sel = std::make_unique<LevelSelect>(
                        cm
                        // std::weak_ptr<ContentManager>(this)
                    );
                    cm->changeContents(std::move(lev_sel));
                    break;
                }
                case actions::EDIT:
                case actions::NOTHING:
                default:
                    return;
            }
}
