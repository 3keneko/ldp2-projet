#ifndef DRAWING_METHODS_H_
#define DRAWING_METHODS_H_

#include <FL/Enumerations.H>
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>
#include <FL/Fl.H>

#include "colors.hpp"
#include "../constants.hpp"
#include <memory>

class ToDraw {
    public:
    ToDraw() = default;
    virtual void draw() = 0;
    virtual ~ToDraw() = default;
};

class LaneDrawer: public ToDraw{
    private:
        int pos_y;
        Fl_Color fl_color;
    public:
        LaneDrawer(int pos_y, Color&& color):
            pos_y(pos_y), fl_color(colors::color_convert(color)) {}
        void colorSwitch(const Color& new_col) {
            fl_color = colors::color_convert(new_col);
        }
        void draw() final override {
            fl_draw_box(FL_FLAT_BOX, 0, pos_y,
                        constants::window::WIDTH,
                        constants::lanes::HEIGHT,
                        fl_color);
        }
        ~LaneDrawer() {}
};

class SquareDrawer: public ToDraw{
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
        virtual void draw() override{
            fl_draw_box(FL_FLAT_BOX, x, y, size, size, fl_color);
        }
        virtual ~SquareDrawer() {}
};

class Text: public ToDraw{
    protected:
        std::string s;
        int x_text, y_text;
        int fontSize;
        Color color;
    public:
        // Constructor
        Text(std::string&& s, int x, int y, int fontSize = 20, Color color = Color::TEXT)
            : s{s}, x_text{x}, y_text{y}, fontSize{fontSize}, color{color} {}

        Text(std::string const& s, int x, int y, int fontSize = 20, Color color = Color::TEXT)
            : s{s}, x_text{x}, y_text{y}, fontSize{fontSize}, color{color} {}
        // Draw
        virtual void draw() override;
        // Setters and getters
        std::string getString() { return s; }
        void setString(const std::string &newString) { s = newString; }
        virtual ~Text() {}
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
        virtual bool contains(int xMouse, int yMouse);
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
        virtual void draw() = 0;
        virtual void onClick() {mr->act();}
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

class ClickableRectangleWithText: public RectangleWithText, public Clickable {
    public:
        ClickableRectangleWithText(int x, int y, int size_w, int size, std::string s
                                    , std::shared_ptr<MessageReceiver> mr
                                    , int fontsize = 20, Color color = Color::MENURECTANGLE
                                    , Color text_color = Color::TEXT)
            : RectangleWithText{x, y, size_w, size, s, fontsize, color, text_color}
            , Clickable{mr} {}
            void draw() override {RectangleWithText::draw();}
            bool contains(int xMouse, int yMouse) override;
        ~ClickableRectangleWithText() {}
};


#include <iostream>
class Button: public Fl_Button {
    private:
        actions payoff;
        actions curr_payoff = actions::NOTHING;
    public:
        Button(int x, int y, int W, int H, const char* label,
               actions&& payoff):
            Fl_Button(x, y, W, H, label), payoff(payoff) { this->value(0); }
        bool pushed() {
            return value() == 1;
        }
        void draw() override {
            Fl_Button::draw();
        }
        /*
        int handle(int event) override {

            // std::cout << "yes" << std::endl;
            switch (event) {
                case FL_PUSH:
                    if (Fl::event_button() == FL_LEFT_MOUSE && Fl::event_inside(this)) {
                        curr_payoff = payoff;
                        return 1;
                    }
                    break;
            }
            return Fl_Button::handle(event);
        }

        */
        //void onPush(Fl_Widget* f, void*) {
        //    this->make_pay();
        // }
        /*
        void onPush(void*) {
            Button::onPush(this);
        }
        */
        void exchange() {
            this->curr_payoff = this->payoff;
        }
        static void make_pay(Fl_Widget* w, void*) {
            auto b = static_cast<Button*>(w);
            std::cout << "yo" << std::endl;
            b->exchange();
        } // {
        //    this->curr_payoff = payoff;
        // }
        // static void make_pay_static(Fl_Widget* w, void* f) {
        //    if ( (FL_Button*) w)->value()) {
        //    exchange
        // }
        actions getPayoff() {
            return curr_payoff;
        }
        ~Button() {}
};

#endif // DRAWING_METHODS_H_
