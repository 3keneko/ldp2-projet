#ifndef SAVESCORE_H_
#define SAVESCORE_H_

#include <memory>
#include "../Model/score.hpp"

class SaveScore {
    private:
        std::unique_ptr<const std::string> file_name;
        std::shared_ptr<Score> score;
    public:
        SaveScore(const std::string& file_name, std::shared_ptr<Score> sc):
            file_name(std::make_unique<const std::string>(file_name)), score(sc) {}
        void writeToFile();
        void getFromFile();

        std::shared_ptr<Score> get_score() { return score; }
        ~SaveScore() {}
};


#endif // SAVESCORE_H_
