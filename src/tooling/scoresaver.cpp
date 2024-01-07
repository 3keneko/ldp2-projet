#include "scoresaver.hpp"

#include <fstream>
#include <sstream>

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


void ScoreSaver::setNewScore(Score const& score) {
    if (getHighScore() < score) {
        scores[lvl] = score.getScore();
    }
}

void ScoreSaver::resetHighScore() {
    Score new_score { 0 };
    setNewScore(new_score);
}
