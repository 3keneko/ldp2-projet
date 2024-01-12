#ifndef DRAWING_METHODS_H_
#define DRAWING_METHODS_H_

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

class LaneDrawer: public ToDraw {
    private:
        int pos_y;
        Fl_Color fl_color;
    public:
        LaneDrawer(int pos_y, Color&& color);
        void colorSwitch(const Color& new_col);
        void draw() final override;
        ~LaneDrawer() {}
};

class SquareDrawer: public ToDraw{
    protected:
        int x;
        int y;
        int size;
        Fl_Color fl_color;
    public:
        SquareDrawer(int x, int y, int size, Color&& color);
        SquareDrawer(int x, int y, int size, const Color& color);
        void colorSwitch(const Color&& new_col);
        void colorSwitch(const Color& new_col);
        void updatePos(int x, int y);
        void updateX(int new_x);
        virtual void draw() override;
        virtual ~SquareDrawer() {}
};

class Text: public ToDraw{
    protected:
        std::string s;
        int x_text, y_text;
        int fontSize;
        Color color;
    public:
        Text(std::string&& s, int x, int y, int fontSize = 20, Color color = Color::TEXT);
        Text(std::string const& s, int x, int y, int fontSize = 20
                , Color color = Color::TEXT);
        virtual void draw() override;
        std::string getString();
        void setString(const std::string &newString);
        virtual ~Text() {}
};

class RectangleDrawer: public SquareDrawer {
    protected:
        int size_w;
    public:
        RectangleDrawer(int x, int y, int size_w, int size
                        , Color&& color = Color::MENURECTANGLE);
        RectangleDrawer(int x, int y, int size_w, int size
                        , const Color& color = Color::MENURECTANGLE);
        virtual void draw() override;
        int getCenterX() const;
        int getCenterY() const;
        virtual bool contains(int xMouse, int yMouse);
        virtual ~RectangleDrawer() {}
};

#endif // DRAWING_METHODS_H_
