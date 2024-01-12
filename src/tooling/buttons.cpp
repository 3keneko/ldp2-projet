#include "buttons.hpp"

RectangleWithText::RectangleWithText(int x, int y, int size_w, int size
                                    , std::string s, int fontsize
                                    , Color color, Color text_color)
    : RectangleDrawer{x, y, size_w, size, color}
    , Text{s, x + size_w / 2, y + size / 2, fontsize, text_color} {}

void RectangleWithText::draw() {
    RectangleDrawer::draw();
    Text::draw();
}
