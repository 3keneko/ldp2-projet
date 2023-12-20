#ifndef DRAWING_METHODS_H_
#define DRAWING_METHODS_H_

#include <FL/Enumerations.H>
#include <FL/fl_draw.H>
#include "colors.hpp"
#include "../constants.hpp"

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
            x(x), y(y), fl_color(colors::color_convert(color)) {}
        void colorSwitch(const Color&& new_col) {
            fl_color = colors::color_convert(new_col);
        }
        virtual void draw() {
            fl_draw_box(FL_FLAT_BOX, x, y, size, size, fl_color);
        }
        virtual ~SquareDrawer() {}
};

class RectangleDrawer: public SquareDrawer {
    private:
        int size_w;
    public:
        RectangleDrawer(int x, int y, int size_w, int size, Color&& color):
            SquareDrawer(x, y, size, color), size_w(size_w) {}
        RectangleDrawer(int x, int y, int size_w, int size, const Color& color):
            SquareDrawer(x, y, size, color), size_w(size_w) {}

        void draw() override {
            fl_draw_box(FL_FLAT_BOX, x, y, size_w, size, fl_color);
        }
        ~RectangleDrawer() {}
};

class CircleDrawer {

};

class ImgDrawer {

};



#endif // DRAWING_METHODS_H_
