#ifndef CONSTANTS_H_
#define CONSTANTS_H_

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
}

#endif // CONSTANTS_H_
