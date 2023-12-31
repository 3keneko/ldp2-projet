#ifndef LEVEL_SELECT_H_
#define LEVEL_SELECT_H_

#include "content_manager.hpp"
#include "../tooling/buttons.hpp"
#include "../constants.hpp"
#include "gameloop.hpp"
#include <memory>
#include <string>

class LevelSelect: public WindowContents {
    private:
        unsigned selected_level = 1;

        std::unique_ptr<ActionButton> increase_lvl = std::make_unique<ActionButton>(
            constants::buttons::INC_X,
            constants::buttons::INC_Y,
            constants::buttons::WIDTH,
            constants::buttons::HEIGHT,
            "+",
            actions::INCR,
            getCM());

        std::unique_ptr<ActionButton> reduce_lvl = std::make_unique<ActionButton>(
            constants::buttons::MIN_X,
            constants::buttons::MIN_Y,
            constants::buttons::WIDTH,
            constants::buttons::HEIGHT,
            "-",
            actions::DIMIN,
            getCM());

        Text lvl_show { "Selected level: " + std::to_string(selected_level),
            constants::window::WIDTH / 2,
            constants::window::HEIGHT / 2,
            50
    };
        std::unique_ptr<ActionButton> play_game = std::make_unique<ActionButton>(
            constants::window::WIDTH/2,
            100,
            constants::buttons::WIDTH,
            constants::buttons::HEIGHT,
            "START GAME",
            actions::STARTAFTERSEL,
            getCM());
    public:
        LevelSelect(std::shared_ptr<ContentManager> cm): WindowContents(cm) {}
        LevelSelect(std::weak_ptr<ContentManager> cm): WindowContents(cm) {}
        // void informManager() override;
        void draw() override {
            increase_lvl->draw();
            reduce_lvl->draw();
            play_game->draw();
            lvl_show.draw();
        }

        void manageButtonPush(int x, int y) override {
            increase_lvl->manageClick(x, y);
            reduce_lvl->manageClick(x, y);
            play_game->manageClick(x, y);
        }

        unsigned getLevel() {
            return selected_level;
        }

        void manageAction(actions& action) override {
            if (action == actions::DIMIN && selected_level > 1) {
                selected_level--;
            } else if (action == actions::INCR) {
                selected_level++;
            }
            lvl_show.setString("Selected level: " + std::to_string(selected_level));
            if (action == actions::STARTAFTERSEL) {
                if (auto cm_lock = cm.lock()) {
                    auto new_game = std::make_unique<GameLoop>(selected_level);
                    cm_lock->start_game(std::move(new_game));
                }
            }
        }
        ~LevelSelect() {}

};

#endif // LEVEL_SELECT_H_
