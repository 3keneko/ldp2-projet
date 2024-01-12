#include "content_manager.hpp"
#include "level_select.hpp"

//
// ContentManager
//

ContentManager::ContentManager(std::unique_ptr<WindowContents> first_contents):
            contents(std::move(first_contents)), gl(nullptr) {}

void ContentManager::startGame(std::unique_ptr<GameLoop> g) {
    gl = std::move(g);
}

void ContentManager::changeContents(std::unique_ptr<WindowContents> new_contents) {
    contents = std::move(new_contents);
}

void ContentManager::show() {
    if (gl != nullptr) {
        gl->update();
    } else {
        contents->draw();
    }
}

void ContentManager::manageButtonPush(int x, int y) {
    if (gl != nullptr) {
            return;
        }
    contents->manageButtonPush(x, y);
}

void ContentManager::contentManageAction(actions& action) {
    contents->manageAction(action);
}

//
// WindowContents
//

WindowContents::WindowContents(std::shared_ptr<ContentManager> cm): cm(cm) {}

WindowContents::WindowContents(std::weak_ptr<ContentManager> cm): cm(cm) {}

std::weak_ptr<ContentManager> WindowContents::getCM() {return cm;}

//
// ActionButton
//

ActionButton::ActionButton(int x, int y, int size_w, int size, std::string s
                            , actions action, WindowContents* wc , int fontsize, Color color
                            , Color text_color)
    : RectangleWithText{x, y, size_w, size, s, fontsize, color, text_color}
    , Clickable(), action(action), wc(wc) {}

void ActionButton::draw() {RectangleWithText::draw();}

bool ActionButton::contains(int xMouse, int yMouse) {
    return RectangleDrawer::contains(xMouse, yMouse);
}

void ActionButton::manageClick(int xMouse, int yMouse) {
    if (this->contains(xMouse, yMouse))
        wc->manageAction(action);
}
