#ifndef WELCOME_SCREEN_H_
#define WELCOME_SCREEN_H_

#include "content_manager.hpp"
#include "../constants.hpp"
#include "../tooling/buttons.hpp"

class WelcomeScreen: public WindowContents {
   private:
        std::unique_ptr<ActionButton> start_game_button = std::make_unique<ActionButton>(
                constants::window::WIDTH/2 - constants::buttons::WIDTH/2,
                constants::buttons::START_Y,
                constants::buttons::WIDTH,
                constants::buttons::HEIGHT,
                "START GAME",
                actions::STARTGAME,
                getCM());

        std::unique_ptr<ActionButton> go_to_levels = std::make_unique<ActionButton>(
            constants::window::WIDTH / 2 - constants::buttons::WIDTH/2,
            constants::buttons::START_Y + 40,
            constants::buttons::WIDTH,
            constants::buttons::HEIGHT,
            "GO TO LEVELS",
            actions::LEVELS,
            getCM(),
            20,
            Color::CAR
     );
        actions to_take = actions::NOTHING;
        Text welcome { "Lenny & Lucas prod", 100, 200 };
   public:
        WelcomeScreen(std::shared_ptr<ContentManager> cm): WindowContents(cm) {}
        void manageButtonPush(int x, int y) override {
             start_game_button->manageClick(x, y);
             go_to_levels->manageClick(x, y);
         }
        void draw() override;
        // void informManager() override;
        // void action() override;
        ~WelcomeScreen() {}

};

#endif // WELCOME_SCREEN_H_
