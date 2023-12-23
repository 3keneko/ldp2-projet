#ifndef WELCOME_SCREEN_H_
#define WELCOME_SCREEN_H_

#include "content_manager.hpp"
#include "../constants.hpp"

class WelcomeScreen: public WindowContents {
   private:
        std::unique_ptr<ClickableRectangleWithText> start_game_button = std::make_unique<ClickableRectangleWithText>( constants::window::WIDTH/2 - constants::buttons::WIDTH/2,
                        constants::buttons::START_Y,
                        constants::buttons::WIDTH,
                        constants::buttons::HEIGHT,
                        "START GAME",
                        actions::STARTGAME );
   public:
        WelcomeScreen(std::shared_ptr<ContentManager> cm): WindowContents(cm) {
                start_game_button->callback(Button::make_pay);
        }
        void draw() override;
        void informManager() override;
        // void action() override;
        ~WelcomeScreen() {}

};
#endif // WELCOME_SCREEN_H_
