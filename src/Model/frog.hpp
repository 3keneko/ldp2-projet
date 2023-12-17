#ifndef MODEL_H_
#define MODEL_H_
#include "../constants.hpp"

class Frog {
    private:
        unsigned int lane_number;
        int x;
    public:
        Frog() = default;
        Frog(unsigned int lane_number, int x): lane_number(lane_number), x(x) {}
        unsigned int getLane() const ;
        int getX() const;
        void goUp();
        void goDown();
        void goLeft();
        void goRight();
        bool inBoard();     // Returns false only if the frog is outside
        ~Frog(){}
};

#endif // MODEL_H_
