#include "welcome_screen.hpp"
#include "gameloop.hpp"

void WelcomeScreen::draw() {
    start_game_button->draw();
    // Text welcome { "Lenny & Lucas prod", 100, 200 };
    // welcome.draw();
}

void WelcomeScreen::informManager() {
    if (auto cm_shared = cm.lock()) {
        // auto g = std::make_unique<GameLoop>( "../levels/level1.csv" );
        // cm_shared->start_game(std::move(g));
    }
}
