#ifndef MODEL_H_
#define MODEL_H_

class Frog {
    private:
        unsigned int lane_number;
        unsigned int column;
    public:
        Frog() {}
        unsigned int getLane();
        unsigned int getColumn();
        void goUp();
        void goDown();
        void goLeft();
        void goRight();
        ~Frog(){}
};

#endif // MODEL_H_
