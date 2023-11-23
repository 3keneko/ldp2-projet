#ifndef BOARDVIEW_H_
#define BOARDVIEW_H_

#include <memory>
#include "board.hpp"

class BoardView {
    private:
        std::shared_ptr<Board> board;
    public:
        BoardView(std::shared_ptr<Board> b):  board(b) {};
        ~BoardView();
};
#endif // BOARDVIEW_H_
