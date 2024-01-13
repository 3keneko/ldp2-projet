#ifndef UTILS_H_
#define UTILS_H_

#include "constants.hpp"

// Takes an id of a lane and returns the y position for using fl_draw_box()
constexpr unsigned int getLanePos(unsigned int lane_id) noexcept {
    return constants::window::HEIGHT - ((lane_id + 1) *constants::lanes::HEIGHT);
}

#endif // UTILS_H_
