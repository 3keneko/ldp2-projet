#include "drawing_methods.hpp"

//
// LaneDrawer
//

LaneDrawer::LaneDrawer(int pos_y, Color&& color):
    pos_y(pos_y), fl_color(colors::colorConvert(color)) {}

void LaneDrawer::colorSwitch(const Color& new_col) {
    fl_color = colors::colorConvert(new_col);
}

void LaneDrawer::draw() {
    fl_draw_box(FL_FLAT_BOX, 0, pos_y, constants::window::WIDTH, constants::lanes::HEIGHT,
                    fl_color);
}

//
// SquareDrawer
//

SquareDrawer::SquareDrawer(int x, int y, int size, Color&& color): x(x), y(y), size(size),
                            fl_color(colors::colorConvert(color)) {}

SquareDrawer::SquareDrawer(int x, int y, int size, const Color& color):
            x(x), y(y), size(size),  fl_color(colors::colorConvert(color)) {}

void SquareDrawer::colorSwitch(const Color&& new_col) {
    fl_color = colors::colorConvert(new_col);
}

void SquareDrawer::colorSwitch(const Color& new_col) {
    fl_color = colors::colorConvert(new_col);
}

void SquareDrawer::updatePos(int x, int y) {
    x=x;
    y=y;
}

void SquareDrawer::updateX(int new_x) { x = new_x; }

void SquareDrawer::draw() {
    fl_draw_box(FL_FLAT_BOX, x, y, size, size, fl_color);
}

//
// Text
//

Text::Text(std::string&& s, int x, int y, int fontSize, Color color)
    : s{s}, x_text{x}, y_text{y}, fontSize{fontSize}, color{color} {}

Text::Text(std::string const& s, int x, int y, int fontSize, Color color)
    : s{s}, x_text{x}, y_text{y}, fontSize{fontSize}, color{color} {}

void Text::draw() {
    fl_color(colors::colorConvert(color));
    fl_font(FL_HELVETICA, fontSize);
    int width = 0;
    int height = 0;
    fl_measure(s.c_str(), width, height, true);
    fl_draw(s.c_str(), x_text - width / 2, y_text - fl_descent() + height / 2);
}

std::string Text::getString() { return s; }

void Text::setString(const std::string &newString) { s = newString; }

//
// RectangleDrawer
//

RectangleDrawer::RectangleDrawer(int x, int y, int size_w, int size, Color&& color):
            SquareDrawer(x, y, size, color), size_w(size_w) {}

RectangleDrawer::RectangleDrawer(int x, int y, int size_w, int size, const Color& color):
    SquareDrawer(x, y, size, color), size_w(size_w) {}

void RectangleDrawer::draw() {
    fl_draw_box(FL_FLAT_BOX, x, y, size_w, size, fl_color);
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
