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

        Text welcome { "Lenny & Lucas prod", 100, 200 };
   public:
        WelcomeScreen(std::shared_ptr<ContentManager> cm): WindowContents(cm) {}
        void manageButtonPush(int x, int y) override;
        void manageAction(actions& action) override;
        void draw() override;
        ~WelcomeScreen() {}

};

#endif // WELCOME_SCREEN_H_
