#ifndef CONTENT_MANAGER_H_
#define CONTENT_MANAGER_H_

#include "../tooling/buttons.hpp"
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
        virtual void manageAction(actions const& action) = 0;
        std::weak_ptr<ContentManager> getCM();
        virtual ~WindowContents() {}
};

class ActionButton: public RectangleWithText, public Clickable {
    private:
        actions action;
        WindowContents* wc;
    public:
        ActionButton(int x, int y, int size_w, int size, std::string s, actions action
                     , WindowContents* wc
                     , int fontsize = 20, Color color = Color::MENURECTANGLE
                     , Color text_color = Color::TEXT);
        void draw() override;
        void manageClick(int xMouse, int yMouse);
        bool contains(int xMouse, int yMouse) override;
        ~ActionButton() {}
};

#endif // CONTENT_MANAGER_H_
