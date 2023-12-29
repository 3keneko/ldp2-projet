#include "score.hpp"
#include <iostream>
#include <compare>

std::string getLevelScoreAdress(const std::string& level_adress) {
    unsigned int STR_SIZE = static_cast<unsigned int>(level_adress.size());
    unsigned int level_id_pos = STR_SIZE - 5;
    unsigned int level_id_size = 1;

    // Looks if the id of the level is an integer with more than 2 digits
    while (level_adress.at(level_id_pos - 1) != 'l') {
        level_id_pos--;
        level_id_size++;
    }
    // Gets the id of the level
    std::string level_id(&level_adress.at(level_id_pos));
    for (int i = 1; i > level_id_size; i++) {
        level_id + level_adress.at(level_id_pos + i);
    }

    return "../levels/level" + level_id + "_score.csv";
}


bool operator<(Score const& s1, Score const& s2) {
    return s1.the_score < s2.the_score;
}
bool operator>(Score const& s1, Score const& s2) {
    return s1.the_score > s2.the_score;
}

bool operator==(Score const& s1, Score const& s2) {
    return s1.the_score == s2.the_score;
}
