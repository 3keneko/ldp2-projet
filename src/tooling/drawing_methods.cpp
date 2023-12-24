#include "drawing_methods.hpp"

void Text::draw() {
    fl_color(colors::color_convert(color));
    fl_font(FL_HELVETICA, fontSize);
    int width = 0;
    int height = 0;
    fl_measure(s.c_str(), width, height, true);
    fl_draw(s.c_str(), x_text - width / 2, y_text - fl_descent() + height / 2);
}

int RectangleDrawer::getCenterX() const {
    return x + ( size_w / 2);
}

int RectangleDrawer::getCenterY() const {
    return y + (size / 2);
}

bool RectangleDrawer::contains(int xMouse, int yMouse) {
    return x <= xMouse && xMouse <= x + size_w 
            && y <= yMouse && yMouse <= y + size;
}
