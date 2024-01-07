#include "frogview.hpp"
#include "../utils.hpp"
#include "../tooling/colors.hpp"
#include "../tooling/drawing_methods.hpp"

#include <tuple>

FrogView::FrogView(std::shared_ptr<Frog> f): frog(f) {}

using namespace constants;

/// Retrieves the coordinate at which the frog should be placed
/// according to the column and lane it is in
std::tuple<int, int> getImagePos(const Frog& frog) {
    auto x = frog.getX();
    auto y = getLanePos(frog.getLane());
    return std::make_tuple(x, y);
}

// Draws the life counter in the board
void FrogView::showLives() {
    constexpr unsigned int LIVE_SIZE = 25;
    constexpr int X_POS = 25;
    constexpr int Y_POS = 25;
    constexpr int DIST_BETWEEN = 50;
    for (int i = 0; i <= 2; i++) {
        SquareDrawer sq { X_POS+i*DIST_BETWEEN, Y_POS, LIVE_SIZE, Color::LIVE_ON };
        if (i >= frog->getLives()) sq.colorSwitch(Color::LIVE_OFF);
        sq.draw();
    }
}

void FrogView::draw() {
    int a, b;
    std::tie(a, b) = getImagePos(*frog);
    FrogDirection dir = frog->getDirection();
    std::string to_draw;
    switch(dir) {
        case FrogDirection::North:
            to_draw = paths::frog_north_jpeg;
            break;
        case FrogDirection::South:
            to_draw = paths::frog_south_jpeg;
            break;
        case FrogDirection::West:
            to_draw = paths::frog_west_jpeg;
            break;
        case FrogDirection::East:
            to_draw = paths::frog_east_jpeg;
            break;
        default:
            break;
    }
    current_image.changePos(a, b);
    current_image.changeImg(to_draw);
    current_image.draw();
    showLives();
}
