#include "waterlilies.hpp"
#include "../constants.hpp"

WaterLilies::WaterLilies(int x): x(x) {}

int WaterLilies::getX() {return x;}

bool WaterLilies::collide(Frog& frog) {
            using namespace constants;
            bool sameLane = frog.getLane() == lanes::NUMBER;
            bool in_by_left_side = x + waterlilies::SIZE >= frog.getX()
                && x <= frog.getX();
            bool in_by_right_side
                = x <= frog.getX() + frog::WIDTH
                && frog.getX() + frog::WIDTH <= x+waterlilies::SIZE;

            return !visited && sameLane && (in_by_left_side || in_by_right_side);
}

bool WaterLilies::hasBeenVisited() { return visited; }

void WaterLilies::visit() { visited=true; }