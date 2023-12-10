#ifndef MODEL_H_
#define MODEL_H_

class Frog {
    private:
        unsigned int lane_number;
        unsigned int column;
    public:
        Frog() = default;
        Frog(unsigned int lane_number, unsigned int column): lane_number(lane_number), column(column) {}
        unsigned int getLane() const ;
        unsigned int getColumn() const;
        void goUp();
        void goDown();
        void goLeft();
        void goRight();
        ~Frog(){}
};

#endif // MODEL_H_
