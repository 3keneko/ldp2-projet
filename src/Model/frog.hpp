#ifndef MODEL_H_
#define MODEL_H_
#include "../constants.hpp"

class Frog {
    private:
        unsigned int lane_number;
        int column;
    public:
        Frog() = default;
        Frog(unsigned int lane_number, int column): lane_number(lane_number), column(column) {}
        unsigned int getLane() const ;
        int getColumn() const;
        void goUp();
        void goDown();
        void goLeft();
        void goRight();
        bool inBoard();     // Returns false only if the frog is outside
        ~Frog(){}
};

#endif // MODEL_H_
