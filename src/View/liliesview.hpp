#ifndef LILIESVIEW_H_
#define LILIESVIEW_H_

#include "../Model/waterlilies.hpp"
#include <memory>
#include "../tooling/drawing_methods.hpp"
#include "../tooling/image_classes.hpp"
#include "../utils.hpp"

class LiliesView {
    private:
        std::shared_ptr<WaterLilies> wl;
        std::unique_ptr<SquareDrawer> object_drawer;
        std::unique_ptr<JPEGDrawer> jpeg;
    public:
        LiliesView(std::shared_ptr<WaterLilies> wl): wl(wl) {
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
        void draw() {
            if (wl != nullptr && object_drawer != nullptr) {
                if (wl->hasBeenVisited())
                    jpeg->draw();
                else
                    object_drawer->draw();
            }
        }
        ~LiliesView(){}
};

#endif // LILIESVIEW_H_
