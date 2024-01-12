#include "scoreview.hpp"


ScoreView::ScoreView(std::shared_ptr<Score> score, int const& x, int const& y, bool is_best): score{score},
    score_text{Text{std::to_string(score->getScore()), x, y}}, is_best(is_best) {}


std::string ScoreView::stringForScore() {
    if (is_best)
        return "Highscore: " + std::to_string(score->getScore());
    return "Score: " + std::to_string(score->getScore());
}

void ScoreView::draw() {
    score_text.setString(stringForScore());
    score_text.draw();
}
