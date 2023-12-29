#include "savescore.hpp"

#include <fstream>
#include <sstream>

void SaveScore::writeToFile() {
    std::ofstream myFile;
    myFile.open(file_name);
    // myFile << score->getScore();
    myFile.close();
}


void SaveScore::getFromFile() {
    std::ifstream myFile;
    myFile.open(file_name);
    std::string line;
    unsigned level, score;
    if (myFile.good()) {
        while (std::getline(myFile, line)) {
            std::stringstream ss(line);
            ss >> level >> score;
            scores.insert(level, score);
        }
    }
    myFile.close();
}
