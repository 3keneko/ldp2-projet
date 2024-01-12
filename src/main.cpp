#include <memory>
#include <type_traits>

#include "ContentManagers/content_manager.hpp"
#include "ContentManagers/welcome_screen.hpp"

#include "mainwindow.hpp"


int main(int argc, char *argv[]) {
  std::srand(static_cast<unsigned>(time(nullptr)));
  auto c = std::make_shared<ContentManager>(nullptr);
  auto ws = std::make_unique<WelcomeScreen>(c);
  c->changeContents(std::move(ws));
  MainWindow window(c);
  window.show(argc, argv);
  return Fl::run();
}
