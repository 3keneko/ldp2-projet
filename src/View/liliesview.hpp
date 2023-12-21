#ifndef LILIESVIEW_H_
#define LILIESVIEW_H_

#include "../Model/waterlilies.hpp"
#include <memory>
#include "../tooling/drawing_methods.hpp"
#include "../utils.hpp"

class LiliesView {
    private:
        std::shared_ptr<WaterLilies> wl;
        std::unique_ptr<SquareDrawer> object_drawer;
    public:
        LiliesView(std::shared_ptr<WaterLilies> wl): wl(wl) {
            object_drawer = wl == nullptr ? nullptr :
                std::make_unique<SquareDrawer>(wl->getX(),
                                               getLanePos(constants::lanes::NUMBER),
                                               constants::lanes::HEIGHT, Color::TURTLE);
        }
        void draw() {
            if (wl != nullptr && object_drawer != nullptr)
                object_drawer->draw();
        }
        ~LiliesView(){}
};

#endif // LILIESVIEW_H_
