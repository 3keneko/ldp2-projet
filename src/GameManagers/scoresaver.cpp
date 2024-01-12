#include "scoresaver.hpp"

#include <fstream>
#include <sstream>

ScoreSaver::ScoreSaver(unsigned level): lvl(level) {}

void ScoreSaver::writeToFile() {
    std::ofstream myFile;
    myFile.open(file_name);
    for (auto& [level, score]: scores) {
        myFile << level << " " << score << std::endl;
    }
    myFile.close();
}

void ScoreSaver::getFromFile() {
    std::ifstream myFile;
    myFile.open(file_name);
    std::string line;
    unsigned level, score;
    if (myFile.good()) {
        while (std::getline(myFile, line)) {
            std::stringstream ss(line);
            ss >> level >> score;
            scores.insert({ level, score });
        }
    }
    myFile.close();
}

Score ScoreSaver::getHighScore() { return Score(scores.at(lvl)); }

void ScoreSaver::setNewScore(Score const& score) {
    if (getHighScore() < score) {
        scores[lvl] = score.getScore();
    }
}

void ScoreSaver::resetHighScore() {
    scores[lvl] = 0;
}

void ScoreSaver::setLevel(unsigned& level) {
    lvl = level;
}
