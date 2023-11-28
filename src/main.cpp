#include <iostream>
#include <memory>
#include "mainloop.hpp"
#include "mainwindow.hpp"
#include "View/boardview.hpp"
#include "View/movingobjectview.hpp"

int main(int argc, char *argv[]) {
  std::cout << "1" << std::endl;
  std::srand(static_cast<unsigned>(time(nullptr)));
  auto c = std::make_shared<Car>(1, 40, 40, 7);
  auto d = std::make_shared<Car>(-1, 500, 40, 8);
  std::vector<std::shared_ptr<MovingObject>> cs { c, d };
  auto b = std::make_shared<BoardModel>(cs);
  auto cv = std::make_shared<CarView>(c);
  auto dv = std::make_shared<CarView>(d);
  std::vector<std::shared_ptr<MovingObjectView>> cars { cv, dv };
  auto bv = std::make_shared<BoardView>(cars, b);
  MainLoop ml(b, bv);
  MainWindow window(std::make_shared<MainLoop>(ml));
  window.show(argc, argv);
  return Fl::run();
}
