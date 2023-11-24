#include <iostream>
#include "View/canvas.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  MainWindow window;
  window.show(argc, argv);
  return Fl::run();
}
