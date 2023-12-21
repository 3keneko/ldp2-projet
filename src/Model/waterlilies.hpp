#ifndef WATERLILIES_H_
#define WATERLILIES_H_

#include "frog.hpp"

class WaterLilies {
    private:
        int x;
        bool visited=false;
    public:
        WaterLilies(int x): x(x) {}

        int getX() {
            return x;
        }

        bool collide(Frog& frog);

        bool hasBeenVisited() { return visited; }
        void visit() { visited=true; }

        ~WaterLilies() {}
};

#endif // DAISIES_H_
