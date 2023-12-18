#ifndef CONSTANTS_H_
#define CONSTANTS_H_

namespace constants {
    namespace window {
        const int WIDTH = 500;
        const int HEIGHT = 500;
        const int PADDING = 100;
    }
    namespace lanes {
        const int NUMBER = 13;
        const int HEIGHT = constants::window::HEIGHT / NUMBER;
    }
    namespace frog {
        const int WIDTH = constants::lanes::HEIGHT;
        const int HEIGHT = WIDTH;
        const int LEAP_SIZE = WIDTH * (6/5);
    }
    namespace turtle {
        const int LENGTH = constants::frog::WIDTH;
    }
}

#endif // CONSTANTS_H_
