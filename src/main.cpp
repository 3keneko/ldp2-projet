#include <iostream>
#include <memory>
#include <type_traits>
#include "maininit.hpp"
#include "mainloop.hpp"
#include "mainwindow.hpp"
#include "View/boardview.hpp"
#include "View/movingobjectview.hpp"
#include "Model/frog.hpp"
#include "View/frogview.hpp"

void init() {}

int main(int argc, char *argv[]) {
  std::srand(static_cast<unsigned>(time(nullptr)));
  MainInit maininit {};
  MainInit m {};
  // m.welcomeUser();
  m.init_from_file("levels/level6.csv");
  //m.init_from_file("levels/sure_win.csv");
  //m.classic_init();
  auto ml = std::make_unique<MainLoop>(m.getBoardModel(), m.getBoardView(), m.getFrogView(), m.getFrog());
  MainWindow window(std::move(ml));
  window.show(argc, argv);
  return Fl::run();
}
