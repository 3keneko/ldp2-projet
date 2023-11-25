#ifndef MOVINGOBJECTVIEW_H_
#define MOVINGOBJECTVIEW_H_

#include <memory>
#include "../Model/movingobjects.hpp"

class MovingObjectView {
    private:
        std::shared_ptr<MovingObject> mv;
    public:
        MovingObjectView(std::shared_ptr<MovingObject> mv): mv(mv) {}
        ~MovingObjectView() {}
};

#endif // MOVINGOBJECTVIEW_H_
