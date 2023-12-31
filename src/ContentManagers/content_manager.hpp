#ifndef CONTENT_MANAGER_H_
#define CONTENT_MANAGER_H_

#include "boardfromfile.hpp"
#include "gameloop.hpp"
#include <memory>

class WindowContents;

class ContentManager {
    private:
        std::unique_ptr<WindowContents> contents;
        std::unique_ptr<GameLoop> gl;
    public:
        ContentManager(std::unique_ptr<WindowContents> first_contents):
            contents(std::move(first_contents)), gl(nullptr) {}

        void changeContents(std::unique_ptr<WindowContents> new_contents);

        void manageButtonPush(int x, int y);

        void contentManageAction(actions& action);

        void start_game(std::unique_ptr<GameLoop> g) {
            gl = std::move(g);
        }

        void show();

        static void updateWithAction(std::shared_ptr<ContentManager> cm, actions& action);

        ~ContentManager() { }
};

class WindowContents {
   protected:
        std::weak_ptr<ContentManager> cm; // Observer
    public:
        WindowContents(std::shared_ptr<ContentManager> cm): cm(cm) {}
        WindowContents(std::weak_ptr<ContentManager> cm): cm(cm) {}
        virtual void draw() = 0;
        // virtual void informManager() = 0;
        virtual void manageButtonPush(int x, int y) = 0;
        virtual void manageAction([[maybe_unused]] actions& action) { }
        // virtual void action() = 0;
        std::weak_ptr<ContentManager> getCM() {
            return cm;
        }

        // void setContentManager(ContentManager& new_cm) {
        //    cm = std::shared_ptr<ContentManager>(&new_cm);
        // }
        virtual ~WindowContents() {}
};


#endif // CONTENT_MANAGER_H_
