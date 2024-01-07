#ifndef WATERLILIES_H_
#define WATERLILIES_H_

#include "frog.hpp"

class WaterLilies {
    private:
        int x;
        bool visited=false;
    public:
        WaterLilies(int x);
        int getX();
        bool collide(Frog& frog);
        bool hasBeenVisited();
        void visit();
        ~WaterLilies() {}
};

#endif // DAISIES_H_
