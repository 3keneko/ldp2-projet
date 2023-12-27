#include "savescore.hpp"

#include <fstream>

void SaveScore::writeToFile() {
    std::ofstream myFile;
    myFile.open(*file_name);
    myFile << score->getScore();
    myFile.close();
}


void SaveScore::getFromFile() {
    std::ifstream myFile;
    myFile.open(*file_name);
    unsigned score_num;
    if (myFile.good()) myFile >> score_num;

    myFile.close();

    score = std::make_shared<Score>(score_num);
}
