#ifndef CONTENT_MANAGER_H_
#define CONTENT_MANAGER_H_

#include "../GameManagers/boardfromfile.hpp"
#include "../GameManagers/gameloop.hpp"
#include <memory>

class WindowContents;

class ContentManager {
    private:
        std::unique_ptr<WindowContents> contents;
        std::unique_ptr<GameLoop> gl;
    public:
        ContentManager(std::unique_ptr<WindowContents> first_contents);
        void changeContents(std::unique_ptr<WindowContents> new_contents);
        void manageButtonPush(int x, int y);
        void contentManageAction(actions& action);
        void startGame(std::unique_ptr<GameLoop> g);
        void show();
        ~ContentManager() { }
};

class WindowContents {
   protected:
        std::weak_ptr<ContentManager> cm; // Observer
    public:
        WindowContents(std::shared_ptr<ContentManager> cm);
        WindowContents(std::weak_ptr<ContentManager> cm);
        virtual void draw() = 0;
        virtual void manageButtonPush(int x, int y) = 0;
        virtual void manageAction(actions& action) = 0;
        std::weak_ptr<ContentManager> getCM();
        virtual ~WindowContents() {}
};

#endif // CONTENT_MANAGER_H_
