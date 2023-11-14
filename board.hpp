#ifndef BOARD_H_
#define BOARD_H_

#include "lanes.hpp"
#include <vector>
#include <memory>

// This is the model

class Board {
    private:
        std::vector<std::unique_ptr<Lane>> board;
        // std::unique_ptr<Frog> frog;
        Frog frog;
    public:
        Board();
        ~Board();
};

#endif // BOARD_H_
