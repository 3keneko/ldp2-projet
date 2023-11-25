#ifndef BOARDMODEL_H_
#define BOARDMODEL_H_

#include <vector>
#include <memory>
#include "lanes.hpp"

class BoardModel {
    private:
        std::vector<std::shared_ptr<Lane>> lanes;
        std::shared_ptr<Frog> frog;
    public:
        BoardModel(std::vector<std::unique_ptr<Lane>> lanes, std::unique_ptr<Frog> frog): lanes(lanes) {}
        std::vector<std::shared_ptr<Lane>> getLanes() { return lanes; }
        ~BoardModel() {}
};

#endif // BOARDMODEL_H_
