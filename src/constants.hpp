#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#include <string>

namespace constants {
    namespace window {
        const int WIDTH = 500;
        const int HEIGHT = 500;
        const int PADDING = 100;
        constexpr double RPS = 60;
    }
    namespace lanes {
        const int NUMBER = 13;
        const int HEIGHT = constants::window::HEIGHT / NUMBER - 2;
    }
    namespace frog {
        const int WIDTH = constants::lanes::HEIGHT;
        const int HEIGHT = WIDTH;
        const int LEAP_SIZE = WIDTH * (6/5);
    }
    namespace turtle {
        const int LENGTH = constants::frog::WIDTH;
    }
    namespace waterlilies {
        const int SIZE = 40;
    }
    namespace buttons {
        const int WIDTH = 100;
        const int HEIGHT = 40;
        constexpr int START_Y = 40;
        constexpr int INC_X = 400;
        constexpr int INC_Y = 100;
        constexpr int MIN_X = 400;
        constexpr int MIN_Y = 300;
    }
    namespace score {
        const unsigned curr_x = 400;
        const unsigned curr_y = 470;
        const unsigned best_x = 100;
        const unsigned best_y = 470;
    }
}

namespace paths {
    const std::string frog_north_jpeg = "../imgs/frog_north.jpeg";
    const std::string frog_south_jpeg = "../imgs/frog_south.jpeg";
    const std::string frog_west_jpeg = "../imgs/frog_west.jpeg";
    const std::string frog_east_jpeg = "../imgs/frog_east.jpeg";
    const std::string scores = "levels/scores.csv";
}


enum class actions {
    STARTGAME,
    NOTHING,
    EDIT,
    LEVELS,
    INCR,
    DIMIN,
    STARTAFTERSEL,
};


#endif // CONSTANTS_H_
