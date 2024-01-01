#include "welcome_screen.hpp"
#include "gameloop.hpp"

void WelcomeScreen::draw() {
    start_game_button.draw();
    go_to_levels.draw();
    welcome.draw();
}
