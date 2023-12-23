#include "welcome_screen.hpp"
#include "gameloop.hpp"

void WelcomeScreen::draw() {
    start_game_button->draw();
    Text welcome { "Lenny & Lucas game", 100, 200 };
    welcome.draw();
}

void WelcomeScreen::informManager() {
    if (true) {
        auto g = std::make_unique<GameLoop>( "../levels/level1.csv" );
        cm->start_game(std::move(g));
    }
}
