#ifndef MODEL_H_
#define MODEL_H_
#include "../constants.hpp"

class Frog {
   private:
        unsigned int lane_number;
        int x;
        int lives;
   public:
        Frog(unsigned int lane_number, int x):
                lane_number(lane_number), x(x), lives(3) {}

        // Standard getters
        unsigned int getLane() const ;
        int getX() const;
        int getLives() const;

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
        bool alive() {return lives != 0;}
        void kill();


        ~Frog(){}
};

#endif // MODEL_H_
