#include <iostream>
#include <memory>
#include <type_traits>
#include "mainloop.hpp"
#include "mainwindow.hpp"
#include "View/boardview.hpp"
#include "View/movingobjectview.hpp"
#include "Model/frog.hpp"
#include "View/frogview.hpp"

int main(int argc, char *argv[]) {
  std::cout << "1" << std::endl;
  std::srand(static_cast<unsigned>(time(nullptr)));
  Frog frog { 1, 10 };
  auto frg_ptr = std::make_shared<Frog>(frog);
  auto fv = std::make_shared<FrogView>(frg_ptr);
  auto c = std::make_shared<Car>(1, 40, 40, 7);
  auto d = std::make_shared<Car>(-1, 500, 40, 8);
  auto e = std::make_shared<Log>(2, 20, 100, 9);
  std::vector<std::shared_ptr<MovingObject>> cs { c, d, e };
  auto b = std::make_shared<BoardModel>(cs);
  auto cv = std::make_shared<CarView>(c);
  auto dv = std::make_shared<CarView>(d);
  auto lv = std::make_shared<LogView>(e);
  std::vector<std::shared_ptr<MovingObjectView>> cars { cv, dv, lv };
  auto bv = std::make_shared<BoardView>(cars, b);
  auto ml = std::make_unique<MainLoop>(b, bv, fv, frg_ptr);
  MainWindow window(std::move(ml));
  window.show(argc, argv);
  return Fl::run();
}
