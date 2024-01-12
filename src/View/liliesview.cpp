#include "liliesview.hpp"
#include "../utils.hpp"


LiliesView::LiliesView(std::shared_ptr<WaterLilies> wl): wl(wl) {
    object_drawer = wl == nullptr ? nullptr :
        std::make_unique<SquareDrawer>(wl->getX(),
                                       getLanePos(constants::lanes::NUMBER),
                                       constants::lanes::HEIGHT, Color::TURTLE);
    jpeg = wl == nullptr ? nullptr :
        std::make_unique<JPEGDrawer>(paths::frog_south_jpeg,
                                     wl->getX(),
                                     getLanePos(constants::lanes::NUMBER),
                                     constants::lanes::HEIGHT, constants::lanes::HEIGHT);
}

void LiliesView::draw() {
    if (wl != nullptr && object_drawer != nullptr) {
        if (wl->hasBeenVisited())
            jpeg->draw();
        else
            object_drawer->draw();
    }
}
