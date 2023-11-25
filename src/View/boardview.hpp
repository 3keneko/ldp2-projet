#ifndef BOARDVIEW_H_
#define BOARDVIEW_H_

#include <memory>
#include "../Model/boardmodel.hpp"
#include "laneview.hpp"

class BoardView {
    private:
        std::shared_ptr<BoardModel> board;
    public:
        BoardView(std::shared_ptr<BoardModel> bm):  board(bm) {}
        void draw() {
            for (auto& lane: board->getLanes()) {
                LaneView l { lane };
                l.draw();
            }
        }
        ~BoardView() {}
};
#endif // BOARDVIEW_H_
