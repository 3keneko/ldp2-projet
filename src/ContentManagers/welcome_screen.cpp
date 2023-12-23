#include "welcome_screen.hpp"
#include "gameloop.hpp"

// void start_game_callback(Button* button, void*) {
//     button->make_pay();
// }

void WelcomeScreen::draw() {
    start_game_button->draw();
    Text welcome { "Lenny & Lucas game", 100, 200 };
    welcome.draw();
}

void WelcomeScreen::informManager() {
    if (start_game_button->getPayoff() != actions::NOTHING) {
        auto g = std::make_unique<GameLoop>( "../levels/level1.csv" );
        cm->start_game(std::move(g));
    }
}
