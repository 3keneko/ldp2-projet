#ifndef SCOREVIEW_H_
#define SCOREVIEW_H_

#include <memory>
#include "../Model/score.hpp"
#include "../tooling/drawing_methods.hpp"

class ScoreView {
        std::shared_ptr<Score> score;
        Text score_text;
        bool is_best;
    public:
        ScoreView(std::shared_ptr<Score> score, int const& x, int const& y, bool is_best=false);
        std::string stringForScore();
        void draw();
        ~ScoreView() {}
};

#endif
