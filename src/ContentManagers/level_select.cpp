#include "level_select.hpp"

LevelSelect::LevelSelect(std::shared_ptr<ContentManager> cm): WindowContents(cm) {
    ss.getFromFile();
    best_score_show.setString("Highest Score: " + std::to_string(ss.getHighScore().getScore()));
}

LevelSelect::LevelSelect(std::weak_ptr<ContentManager> cm): WindowContents(cm) {
    ss.getFromFile();
    best_score_show.setString("Highest Score: " + std::to_string(ss.getHighScore().getScore()));
}

void LevelSelect::draw() {
    increase_lvl.draw();
    reduce_lvl.draw();
    play_game.draw();
    lvl_show.draw();
    reset_score.draw();
    best_score_show.draw();
}


void LevelSelect::manageButtonPush(int x, int y) {
    const unsigned int max_level = 9;
    if (selected_level < max_level) increase_lvl.manageClick(x, y);
    reduce_lvl.manageClick(x, y);
    play_game.manageClick(x, y);
    reset_score.manageClick(x, y);
}


unsigned LevelSelect::getLevel() {
    return selected_level;
}
void LevelSelect::manageAction(actions const& action) {
    if (action == actions::DIMIN && selected_level > 1) {
        selected_level--;
    } else if (action == actions::INCR) {
        selected_level++;
    } else if (action == actions::RESET) {
        ss.getFromFile();
        ss.resetHighScore();
        ss.writeToFile();
    }
    ss.setLevel(selected_level);
    best_score_show.setString("Highest Score: " + std::to_string(ss.getHighScore().getScore()));
    lvl_show.setString("Selected level: " + std::to_string(selected_level));
    if (action == actions::STARTAFTERSEL) {
        if (auto cm_lock = cm.lock()) {
            auto new_game = std::make_unique<GameLoop>(selected_level);
            cm_lock->startGame(std::move(new_game));
        }
    }
}
