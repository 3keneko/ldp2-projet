#ifndef FROG_H_
#define FROG_H_

#include <memory>

#include "../constants.hpp"
#include "score.hpp"

enum class FrogDirection {
    North, South, East, West 
};

class Frog {
  private:
        // Frog Position and Direction (important for display)
        unsigned int lane_number;
        int x;
        FrogDirection direction = FrogDirection::North;
        int lives;
        std::shared_ptr<Score> score;
   public:
        Frog(unsigned int lane_number, int x, std::shared_ptr<Score> score):
                lane_number(lane_number), x(x), lives(3), score(score) {}

        // Standard getters
        unsigned int getLane() const ;
        int getX() const;
        int getLives() const;
        FrogDirection getDirection() const;

        // Methods in charge of moving the frog (interacting with the controller)
        void goUp();
        void goDown();
        void goLeft();
        void goRight();

        // Moves the frog in a given direction (helpful when frog is sitting on logs)
        void go(int speed);
        // Returns false only if the frog is outside
        bool inBoard();

        // Methods in charge of life and death of the frog
        void resetPos();
        bool alive() {return lives > 0;}
        void kill();
        void inWaterLilies();

        ~Frog(){}
};

#endif // FROG_H_
