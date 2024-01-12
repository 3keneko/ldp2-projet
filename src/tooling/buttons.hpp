#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <memory>
#include "drawing_methods.hpp"


class Clickable {
    public:
        Clickable() {}
        virtual void draw() = 0;
        virtual bool contains(int xMouse, int yMouse) = 0;
        virtual ~Clickable() {}
};

class RectangleWithText: public RectangleDrawer, public Text {
    public:
        RectangleWithText(int x, int y, int size_w, int size
                            , std::string s, int fontsize = 20
                            , Color color = Color::MENURECTANGLE
                            , Color text_color = Color::TEXT);
        virtual void draw() override;
        virtual ~RectangleWithText() {}
};

#endif // BUTTONS_H_
