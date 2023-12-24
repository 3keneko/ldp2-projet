#include "buttons.hpp"

void RectangleWithText::draw() {
    RectangleDrawer::draw();
    Text::draw();
}

bool ActionButton::contains(int xMouse, int yMouse) {
    return RectangleDrawer::contains(xMouse, yMouse);
}

void ActionButton::manageClick(int xMouse, int yMouse) {
    if (this->contains(xMouse, yMouse)) {
        if (auto shared_cm_ptr = cm_ptr.lock()) {
            shared_cm_ptr->updateWithAction(action);
        }
        else {
            throw 1;
        }
    }
}
