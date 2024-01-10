#include "welcome_screen.hpp"
#include "level_select.hpp"
#include "../GameManagers/gameloop.hpp"

WelcomeScreen::WelcomeScreen(std::shared_ptr<ContentManager> cm): WindowContents(cm) {}

void WelcomeScreen::draw() {
    start_game_button.draw();
    go_to_levels.draw();
    welcome.draw();
}

void WelcomeScreen::manageButtonPush(int x, int y) {
    start_game_button.manageClick(x, y);
    go_to_levels.manageClick(x, y);
}
void WelcomeScreen::manageAction(actions& action) {
    if (action == actions::STARTGAME) {
       // Se charge du cas où le joueur clique sur le bouton start game
        if (auto cm_lock = cm.lock()) {
            auto new_game = std::make_unique<GameLoop>(1);
            cm_lock->startGame(std::move(new_game));
        }
    } else if (action == actions::LEVELS) {
        // Se charge du cas où le joueur clique sur le bouton pour jouer au jeu
        auto lev_sel = std::make_unique<LevelSelect>( cm );
        if (auto cm_lock  = cm.lock()) {
            cm_lock->changeContents(std::move(lev_sel));
        }
    }
}
