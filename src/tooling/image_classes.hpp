#ifndef IMAGE_CLASSES_H_
#define IMAGE_CLASSES_H_

#include <string>
#include <Fl/Fl_JPEG_Image.H>
#include <memory>

#include "../constants.hpp"

class FullScreenJPEGImage {
    protected:
        std::unique_ptr<Fl_JPEG_Image> jpeg_img;
    public:
        FullScreenJPEGImage(std::string&& path_to_img);
        FullScreenJPEGImage(std::string const& path_to_img);
        void changeImg(std::string&& new_path);
        void changeImg(std::string const& new_path);
        virtual void draw() const;
        virtual ~FullScreenJPEGImage() {}
};

class JPEGDrawer: public FullScreenJPEGImage {
    private:
        int x, y;
        const unsigned h;
        const unsigned w;
    public:
        JPEGDrawer(std::string&& path_to_img, int x, int y, int h, int w);
        JPEGDrawer(std::string const& path_to_img, int x, int y, int h, int w);

        // Methods to change the x and y coordinates
        void changeX(int new_x);
        void changeY(int new_y);
        void changePos(int new_x, int new_y);

        // Showing the image method
        void draw() const final override;
        ~JPEGDrawer() {}
};

#endif // IMAGE_CLASSES_H_
