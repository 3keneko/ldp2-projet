#include "scoreview.hpp"

ScoreView::ScoreView(std::shared_ptr<Score> score, int const& x, int const& y): score{score},
    score_text{Text{std::to_string(score->getScore()), x, y}} {}


std::string ScoreView::stringForScore() {
    return "Score: " + std::to_string(score->getScore());
}

void ScoreView::draw() {
    score_text.setString(stringForScore());
    score_text.draw();
}
