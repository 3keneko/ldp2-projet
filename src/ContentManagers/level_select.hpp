#ifndef LEVEL_SELECT_H_
#define LEVEL_SELECT_H_

#include "content_manager.hpp"
#include "../tooling/buttons.hpp"
#include "../constants.hpp"
#include "../GameManagers/gameloop.hpp"
#include <memory>
#include <string>

class LevelSelect: public WindowContents {
    private:
        unsigned selected_level = 1;
        ScoreSaver ss {selected_level};

        ActionButton increase_lvl {
            constants::buttons::INC_X,
            constants::buttons::INC_Y,
            constants::buttons::WIDTH,
            constants::buttons::HEIGHT,
            "+",
            actions::INCR,
            this
        };

        ActionButton reduce_lvl {
            constants::buttons::MIN_X,
            constants::buttons::MIN_Y,
            constants::buttons::WIDTH,
            constants::buttons::HEIGHT,
            "-",
            actions::DIMIN,
            this
        };

        Text lvl_show { "Selected level: " + std::to_string(selected_level),
            constants::window::WIDTH / 2,
            constants::window::HEIGHT / 2,
            50
        };
        ActionButton play_game {
            constants::window::WIDTH/2,
            100,
            constants::buttons::WIDTH,
            constants::buttons::HEIGHT,
            "START GAME",
            actions::STARTAFTERSEL,
            this
        };

        Text best_score_show { "Highest Score: ",
           constants::window::WIDTH/3,
           constants::window::HEIGHT * 4/5,
           20,
        };

        ActionButton reset_score {
        constants::window::WIDTH/4,
        constants::window::HEIGHT * 11/12,
        constants::buttons::WIDTH,
        constants::buttons::HEIGHT,
        "Reset Score",
        actions::RESET,
        this
        };

    public:
        LevelSelect(std::shared_ptr<ContentManager> cm);
        LevelSelect(std::weak_ptr<ContentManager> cm);
        void draw() override;
        void manageButtonPush(int x, int y) override;
        unsigned getLevel();
        void manageAction(actions const& action) override;
        ~LevelSelect() {}
};

#endif // LEVEL_SELECT_H_
