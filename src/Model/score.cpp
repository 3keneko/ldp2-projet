#include "score.hpp"
#include <iostream>
#include <compare>

void Score::reachedWaterlily() {
            the_score += 400;
            max_lane = 0;
}

void Score::update(int new_lane_id) {
    if (new_lane_id > max_lane && new_lane_id != 13) {
        max_lane = new_lane_id;
        the_score += 100;
    }
}

unsigned Score::getScore() const {
    return the_score;
}

void Score::resetBestLane() {
    max_lane = 0;
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
