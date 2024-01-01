#ifndef WELCOME_SCREEN_H_
#define WELCOME_SCREEN_H_

#include "content_manager.hpp"
#include "../constants.hpp"
#include "../tooling/buttons.hpp"
#include "level_select.hpp"
#include "../GameManagers/gameloop.hpp"

class WelcomeScreen: public WindowContents {
    private:
        ActionButton start_game_button {
                constants::window::WIDTH / 2 - constants::buttons::WIDTH/2,
                constants::buttons::START_Y,
                constants::buttons::WIDTH,
                constants::buttons::HEIGHT,
                "START GAME",
                actions::STARTGAME,
                this
        };

        ActionButton go_to_levels  {
            constants::window::WIDTH / 2 - constants::buttons::WIDTH/2,
            constants::buttons::START_Y + 40,
            constants::buttons::WIDTH,
            constants::buttons::HEIGHT,
            "GO TO LEVELS",
            actions::LEVELS,
            this,
            20,
            Color::CAR
        };

        actions to_take = actions::NOTHING;
        Text welcome { "Lenny & Lucas prod", 100, 200 };
   public:
        WelcomeScreen(std::shared_ptr<ContentManager> cm): WindowContents(cm) {}
        void manageButtonPush(int x, int y) override {
             start_game_button.manageClick(x, y);
             go_to_levels.manageClick(x, y);
        }
        void manageAction(actions& action) override {
            if (action == actions::STARTGAME) {
                if (auto cm_lock = cm.lock()) {
                    auto new_game = std::make_unique<GameLoop>(1);
                    cm_lock->start_game(std::move(new_game));
                }
            } else if (action == actions::LEVELS) {
                auto lev_sel = std::make_unique<LevelSelect>( cm );
                if (auto cm_lock  = cm.lock()) {
                    cm_lock->changeContents(std::move(lev_sel));
                }
            }
        }
        void draw() override;
        // void informManager() override;
        // void action() override;
        ~WelcomeScreen() {}

};

#endif // WELCOME_SCREEN_H_
