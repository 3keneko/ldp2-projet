#ifndef CONTENT_MANAGER_H_
#define CONTENT_MANAGER_H_

#include "window_contents.hpp"
#include <memory>

class ContentSwapper {
    private:
        std::unique_ptr<WindowContents> contents;
    public:
        ContentSwapper() {}

        void changeContents(std::unique_ptr<WindowContents> new_contents) {
            contents = std::move(new_contents);
        }

        void draw() {
            contents->draw();
        }

        ~ContentSwapper() {}
};


#endif // CONTENT_MANAGER_H_
