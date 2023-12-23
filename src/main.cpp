#include <iostream>
#include <memory>
#include <type_traits>
#include "ContentManagers/content_manager.hpp"
#include "ContentManagers/gameinit.hpp"
#include "ContentManagers/gameloop.hpp"
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
  auto c = std::make_unique<ContentManager>(std::move(g));

  MainWindow window(std::move(c));
  window.show(argc, argv);
  return Fl::run();
}
