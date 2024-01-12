#ifndef LILIESVIEW_H_
#define LILIESVIEW_H_

#include "../Model/waterlilies.hpp"
#include <memory>
#include "../tooling/drawing_methods.hpp"
#include "../tooling/image_classes.hpp"


class LiliesView {
    private:
        std::shared_ptr<WaterLilies> wl;
        std::unique_ptr<SquareDrawer> object_drawer;
        std::unique_ptr<JPEGDrawer> jpeg;
    public:
        LiliesView(std::shared_ptr<WaterLilies> wl);
        void draw();
        ~LiliesView(){}
};

#endif // LILIESVIEW_H_
