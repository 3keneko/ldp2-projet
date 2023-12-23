#ifndef CONTENT_MANAGER_H_
#define CONTENT_MANAGER_H_

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

        void changeContents(std::unique_ptr<WindowContents> new_contents) {
            contents = std::move(new_contents);
        }
        void updateWithAction(actions action) {
            switch (action) {
                case actions::STARTGAME:
                    GameInit g {  };
                    g.init_from_file("levels/level1.csv");
                    gl = std::make_shared<GameLoop>(g);
            }
        }
        void start_game(std::unique_ptr<GameLoop> g) {
            gl = std::move(g);
        }

        void show();

        ~ContentManager() {}
};

class WindowContents {
   protected:
        std::shared_ptr<ContentManager> cm; // Observer
    public:
        WindowContents(std::shared_ptr<ContentManager> cm): cm(cm) {}
        virtual void draw() = 0;
        virtual void informManager() = 0;
        // virtual void action() = 0;
        virtual ~WindowContents() {}
};


#endif // CONTENT_MANAGER_H_
