#ifndef BOARDMODEL_H_
#define BOARDMODEL_H_

#include <vector>
#include <memory>

#include "lanes.hpp"

class BoardModel {
    private:
        std::shared_ptr<FinishLane> the_finish_lane;
        std::vector<std::shared_ptr<Lane>> lanes {};
        unsigned time = 0;
    public:
        BoardModel(std::vector<std::shared_ptr<Lane>> lanes);
        void update_turtles(std::shared_ptr<Lane> lane);
        void update(); // moves the objects on the board
        bool gameWon();
        bool isOutOfBoard(Frog& frog);
        bool frogOnLily(Frog& frog);
        void addLane(std::shared_ptr<Lane> lane);
        std::vector<std::shared_ptr<Lane>> getLanes();
        bool any_collision(Frog& frog);
        void handle_collision(Frog& frog);
        ~BoardModel() {}
        unsigned getTime() const  { return time; }
};

#endif // BOARDMODEL_H_
