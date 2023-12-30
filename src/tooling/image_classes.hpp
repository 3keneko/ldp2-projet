#ifndef IMAGE_CLASSES_H_
#define IMAGE_CLASSES_H_

#include <string>
#include <Fl/Fl_JPEG_Image.H>
#include <memory>
#include <iostream>

#include "../constants.hpp"

class FullScreenJPEGImage {
    protected:
        std::unique_ptr<Fl_JPEG_Image> jpeg_img;
    public:
        FullScreenJPEGImage(std::string&& path_to_img):
            jpeg_img(std::make_unique<Fl_JPEG_Image>(path_to_img.c_str())) {}
        FullScreenJPEGImage(std::string const& path_to_img):
            jpeg_img(std::make_unique<Fl_JPEG_Image>(path_to_img.c_str())) {}

        void changeImg(std::string&& new_path) {
            jpeg_img = std::make_unique<Fl_JPEG_Image>(new_path.c_str());
        }
        void changeImg(std::string const& new_path) {
            jpeg_img = std::make_unique<Fl_JPEG_Image>(new_path.c_str());
        }

        virtual void draw() {
            if (jpeg_img->fail()) {
                std::cout << "Couldn't open the image, sorry :'(";
                return;
            }
            jpeg_img->draw(0, 0, constants::window::HEIGHT, constants::window::WIDTH);
        }
        virtual ~FullScreenJPEGImage() {}
};

class JPEGDrawer: public FullScreenJPEGImage {
    private:
        int x, y;
        const unsigned h;
        const unsigned w;
    public:
        JPEGDrawer(std::string&& path_to_img, int x, int y, int h, int w):
            FullScreenJPEGImage(path_to_img), x(x), y(y), h(h), w(w) {}
        JPEGDrawer(std::string const& path_to_img, int x, int y, int h, int w):
            FullScreenJPEGImage(path_to_img), x(x), y(y), h(h), w(w) {}

        // Methods to change the x and y coordinates
        void changeX(int new_x) { x = new_x; }
        void changeY(int new_y) { y=new_y; }
        void changePos(int new_x, int new_y) {
            x = new_x;
            y = new_y;
        }

        // Showing the image method
        void draw() override {
            if (jpeg_img->fail()) {
                std::cout << "Couldn't open the image, sorry :'(";
                return;
            }
           jpeg_img->draw(x, y, h, w);
        }

        ~JPEGDrawer() {}
};



#endif // IMAGE_CLASSES_H_
