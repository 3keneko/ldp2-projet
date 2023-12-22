#ifndef DRAWING_METHODS_H_
#define DRAWING_METHODS_H_

#include <FL/Enumerations.H>
#include <FL/fl_draw.H>
#include "colors.hpp"
#include "../constants.hpp"
#include <memory>

class LaneDrawer {
    private:
        int pos_y;
        Fl_Color fl_color;
    public:
        LaneDrawer(int pos_y, Color&& color):
            pos_y(pos_y), fl_color(colors::color_convert(color)) {}
        void colorSwitch(const Color& new_col) {
            fl_color = colors::color_convert(new_col);
        }
        void draw() {
            fl_draw_box(FL_FLAT_BOX, 0, pos_y,
                        constants::window::WIDTH,
                        constants::lanes::HEIGHT,
                        fl_color);
        }
        ~LaneDrawer() {}
};

class SquareDrawer {
    protected:
        int x;
        int y;
        int size;
        Fl_Color fl_color;
    public:
        SquareDrawer(int x, int y, int size,
                     Color&& color): x(x), y(y), size(size),
                                    fl_color(colors::color_convert(color)) {}
        SquareDrawer(int x, int y, int size, const Color& color):
            x(x), y(y), size(size),  fl_color(colors::color_convert(color)) {}
        void colorSwitch(const Color&& new_col) {
            fl_color = colors::color_convert(new_col);
        }
        void colorSwitch(const Color& new_col) {
            fl_color = colors::color_convert(new_col);
        }
        void updatePos(int x, int y) {
            x=x;
            y=y;
        }
        void updateX(int new_x) { x = new_x; }
        virtual void draw() {
            fl_draw_box(FL_FLAT_BOX, x, y, size, size, fl_color);
        }
        virtual ~SquareDrawer() {}
};

class Text {
    protected:
        std::string s;
        int x_text, y_text;
        int fontSize;
        Color color;
    public:
        // Constructor
        Text(std::string s, int x, int y, int fontSize = 20, Color color = Color::TEXT)
            : s{s}, x_text{x}, y_text{y}, fontSize{fontSize}, color{color} {}

        // Draw
        void draw();

        // Setters and getters
        std::string getString() { return s; }
        void setString(const std::string &newString) { s = newString; }
};

class RectangleDrawer: public SquareDrawer {
    protected:
        int size_w;
    public:
        RectangleDrawer(int x, int y, int size_w, int size, Color&& color = Color::MENURECTANGLE):
            SquareDrawer(x, y, size, color), size_w(size_w) {}
        RectangleDrawer(int x, int y, int size_w, int size, const Color& color = Color::MENURECTANGLE):
            SquareDrawer(x, y, size, color), size_w(size_w) {}

        virtual void draw() override {
            fl_draw_box(FL_FLAT_BOX, x, y, size_w, size, fl_color);
        }
        int getCenterX() const;
        int getCenterY() const;
        bool contains(int xMouse, int yMouse);
        virtual ~RectangleDrawer() {}
};

class MessageReceiver {
    public:
        MessageReceiver() = default;
        virtual void act() = 0;
        virtual ~MessageReceiver() = default;    
};

class Clickable {
    std::shared_ptr<MessageReceiver> mr;
    public:
        Clickable(std::shared_ptr<MessageReceiver> mr): mr{mr} {}
        virtual void onClick() {mr->act();}
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

class ClickableRectangleWithText: public RectangleWithText, public Clickable {
    public:
        ClickableRectangleWithText(int x, int y, int size_w, int size, std::string s
                                    , std::shared_ptr<MessageReceiver> mr
                                    , int fontsize = 20, Color color = Color::MENURECTANGLE
                                    , Color text_color = Color::TEXT)
            : RectangleWithText{x, y, size_w, size, s, fontsize, color, text_color}
            , Clickable{mr} {}
        ~ClickableRectangleWithText() {};
};

#endif // DRAWING_METHODS_H_
