#ifndef SCORE_H_
#define SCORE_H_

#include <string>

class Score {
    private:
        unsigned the_score = 0;
        int max_lane = 0;
    public:
        Score() = default;
        Score(unsigned score): the_score(score) {}

        void reached_waterlily() {
            the_score += 400;
            max_lane = 0;
        }

        void update(int new_lane_id) {
            if (new_lane_id > max_lane && new_lane_id != 13) {
                max_lane = new_lane_id;
                the_score += 100;
            }
        }

        unsigned getScore() const {
            return the_score;
        }

        void reset_best_lane() {
            max_lane = 0;
        }
        ~Score() = default;
}; 

// Takes the adress of a csv level file and returns the associated csv score file
// as an adress of the form "../levels/level..._score.csv".
std::string getLevelScoreAdress(const std::string& level_adress);

#endif // SCORE_H_
