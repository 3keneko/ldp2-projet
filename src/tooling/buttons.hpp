#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <memory>
#include "drawing_methods.hpp"
#include "../ContentManagers/content_manager.hpp"


class Clickable {
    public:
        Clickable() {}
        virtual void draw() = 0;
        // virtual void onClick(int xMouse, int yMouse) = 0;
        virtual bool contains(int xMouse, int yMouse) = 0;
        virtual ~Clickable() {}
};

class RectangleWithText: public RectangleDrawer, public Text {
    public:
        RectangleWithText(int x, int y, int size_w, int size
                                    , std::string s, int fontsize = 20
                                    , Color color = Color::MENURECTANGLE
                                    , Color text_color = Color::TEXT)
            : RectangleDrawer{x, y, size_w, size, color}
            , Text{s, x + size_w / 2, y + size / 2, fontsize, text_color} {}
        virtual void draw() override;
        virtual ~RectangleWithText() {}
};

class ActionButton: public RectangleWithText, public Clickable {
    private:
        actions action;
        std::weak_ptr<ContentManager> cm_ptr;
    public:
        ActionButton(int x, int y, int size_w, int size, std::string s, actions action
                     , std::weak_ptr<ContentManager> cm_ptr
                     , int fontsize = 20, Color color = Color::MENURECTANGLE
                     , Color text_color = Color::TEXT)
            : RectangleWithText{x, y, size_w, size, s, fontsize, color, text_color}
            , Clickable(), action(action), cm_ptr(cm_ptr) {}
        void draw() override {RectangleWithText::draw();}
        void manageClick(int xMouse, int yMouse);
        bool contains(int xMouse, int yMouse) override;
        ~ActionButton() {}
};

#endif // BUTTONS_H_
