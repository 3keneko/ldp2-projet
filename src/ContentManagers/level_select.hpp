#ifndef LEVEL_SELECT_H_
#define LEVEL_SELECT_H_

#include "content_manager.hpp"
#include "../tooling/buttons.hpp"
#include "../constants.hpp"
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

    public:
        LevelSelect(std::shared_ptr<ContentManager> cm): WindowContents(cm) {}
        LevelSelect(std::weak_ptr<ContentManager> cm): WindowContents(cm) {}
        // void informManager() override;
        void draw() override {
            increase_lvl->draw();
            reduce_lvl->draw();
            lvl_show.draw();
        }

        void manageButtonPush(int x, int y) override {
            increase_lvl->manageClick(x, y);
            reduce_lvl->manageClick(x, y);
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
            lvl_show.setString(std::to_string(selected_level));
        }

        ~LevelSelect() {}

};

#endif // LEVEL_SELECT_H_
