#include "scoreview.hpp"

ScoreView::ScoreView(std::shared_ptr<Score> score): score{score}, 
    score_text{Text{std::to_string(score->getScore()), 400, 475}} {}


std::string ScoreView::stringForScore() {
    return "Score: " + std::to_string(score->getScore());
}

void ScoreView::draw() {
    score_text.setString(stringForScore());
    score_text.draw();
}