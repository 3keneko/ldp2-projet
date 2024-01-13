#include "image_classes.hpp"
#include <iostream>

FullScreenJPEGImage::FullScreenJPEGImage(std::string&& path_to_img):
    jpeg_img(std::make_unique<Fl_JPEG_Image>(path_to_img.c_str())) {}

FullScreenJPEGImage::FullScreenJPEGImage(std::string const& path_to_img):
    jpeg_img(std::make_unique<Fl_JPEG_Image>(path_to_img.c_str())) {}

void FullScreenJPEGImage::changeImg(std::string&& new_path) {
    jpeg_img = std::make_unique<Fl_JPEG_Image>(new_path.c_str());
}

void FullScreenJPEGImage::changeImg(std::string const& new_path) {
    jpeg_img = std::make_unique<Fl_JPEG_Image>(new_path.c_str());
}

void FullScreenJPEGImage::draw() const {
    if (jpeg_img->fail()) {
        std::cout << "Couldn't open the image, sorry :'(";
        return;
    }
    jpeg_img->draw(0, 0, constants::window::HEIGHT, constants::window::WIDTH);
}

JPEGDrawer::JPEGDrawer(std::string&& path_to_img, int x, int y, int h, int w):
    FullScreenJPEGImage(path_to_img), x(x), y(y), h(h), w(w) {}

JPEGDrawer::JPEGDrawer(std::string const& path_to_img, int x, int y, int h, int w):
    FullScreenJPEGImage(path_to_img), x(x), y(y), h(h), w(w) {}

void JPEGDrawer::changeX(int new_x) { x = new_x; }

void JPEGDrawer::changeY(int new_y) { y=new_y; }

void JPEGDrawer::changePos(int new_x, int new_y) {
    x = new_x;
    y = new_y;
}

void JPEGDrawer::draw() const {
    if (jpeg_img->fail()) {
        std::cout << "Couldn't open the image, sorry :'(";
        return;
    }
    jpeg_img->draw(x, y, h, w);
}
