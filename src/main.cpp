#include <iostream>
#include <memory>
#include <type_traits>
#include "ContentManagers/content_manager.hpp"
#include "ContentManagers/gameinit.hpp"
#include "ContentManagers/gameloop.hpp"
#include "ContentManagers/welcome_screen.hpp"
#include "mainwindow.hpp"
#include "View/boardview.hpp"
#include "View/movingobjectview.hpp"
#include "Model/frog.hpp"
#include "View/frogview.hpp"

void init() {}

int main(int argc, char *argv[]) {
  std::srand(static_cast<unsigned>(time(nullptr)));
  // MainInit m {};
  // m.welcomeUser();
  auto g = std::make_unique<GameLoop>("levels/level6.csv");
  //m.init_from_file("levels/sure_win.csv");
  //m.classic_init();
  auto c = std::make_shared<ContentManager>(nullptr);
  c->start_game(std::move(g));
  // auto ws = std::make_unique<WelcomeScreen>(c);
  // c->changeContents(std::move(ws));
  MainWindow window(c);
  window.show(argc, argv);
  return Fl::run();
}
