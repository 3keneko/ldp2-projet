#ifndef SAVESCORE_H_
#define SAVESCORE_H_

#include <memory>
#include <map>

#include "../Model/score.hpp"

class SaveScore {
    private:
        unsigned lvl;
        const std::string file_name { "scores.csv" };
        std::map<unsigned, unsigned> scores;
    public:
        SaveScore(unsigned level): lvl(level) {}
        void writeToFile();
        void getFromFile();

        Score getHighScore() { return Score(scores.at(lvl)); }
        ~SaveScore() {}
};


#endif // SAVESCORE_H_
