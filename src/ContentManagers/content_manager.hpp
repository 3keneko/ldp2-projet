#ifndef CONTENT_MANAGER_H_
#define CONTENT_MANAGER_H_

#include "window_contents.hpp"
#include <memory>

class ContentManager {
    private:
        std::unique_ptr<WindowContents> contents;
    public:
        ContentManager(std::unique_ptr<WindowContents> first_contents):
        contents(std::move(first_contents)) {}

        void changeContents(std::unique_ptr<WindowContents> new_contents) {
            contents = std::move(new_contents);
        }

        void show() {
            contents->draw();
        }

        ~ContentManager() {}
};


#endif // CONTENT_MANAGER_H_
