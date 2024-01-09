#ifndef SCORESAVER_H_
#define SCORESAVER_H_

#include <memory>
#include <map>

#include "../Model/score.hpp"
#include "../constants.hpp"

class ScoreSaver {
    private:
        unsigned lvl;
        const std::string file_name { paths::scores };
        std::map<unsigned, unsigned> scores;
    public:
        ScoreSaver(unsigned level): lvl(level) {}
        void writeToFile();
        void getFromFile();

        Score getHighScore() { return Score(scores.at(lvl)); }
        void setNewScore(Score const& score);
        void resetHighScore();
        void setLevel(unsigned& level);
        ~ScoreSaver() {}
};


#endif // SCORESAVER_H_
