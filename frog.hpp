#ifndef MODEL_H_
#define MODEL_H_
#include <cstdint>

class Frog {
    private:
        uint8_t lane;
        uint8_t column;
    public:
        Frog() {};
        uint8_t getLane();
        uint8_t getColumn();
        uint8_t goUp();
        uint8_t goDown();
        uint8_t goLeft();
        uint8_t goRight();
        ~Frog() {};
};

#endif // MODEL_H_
