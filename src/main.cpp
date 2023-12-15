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
  std::cout << "1" << std::endl;
  MainInit maininit {};
  std::srand(static_cast<unsigned>(time(nullptr)));
  Frog frog { 1, 10 };
  MainInit m {};
  auto ml = std::make_unique<MainLoop>(m.getBoardModel(), m.getBoardView(), m.getFrogView(), fr);
  MainWindow window(std::move(ml));
  window.show(argc, argv);
  return Fl::run();
}
