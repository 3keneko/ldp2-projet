// #include "fltk_tools.hpp"

// /*----------------------------------------------------------------------------------

// Point class
// -----------------------------------------------------------------------------------*/

// unsigned int Point::xFltk() const{
//     return (25 + 50 * (12 - x));
// }

// unsigned int Point::yFltk() const{
//     return (25 + 50 * y);
// }

// /*----------------------------------------------------------------------------------

// Rectangle class
// -----------------------------------------------------------------------------------*/

// Rectangle::Rectangle(Point center, int w, int h, Fl_Color frameColor,
//                      Fl_Color fillColor)
//     : center{center},
//       w{w},
//       h{h},
//       fillColor{fillColor},
//       frameColor{frameColor} {}

// void Rectangle::draw() {
//   fl_draw_box(FL_FLAT_BOX, center.x - w / 2, center.y - h / 2, w, h, fillColor);
//   fl_draw_box(FL_BORDER_FRAME, center.x - w / 2, center.y - h / 2, w, h,
//               frameColor);
// }

// void Rectangle::draw(unsigned int x, unsigned int y) {
//   fl_draw_box(FL_FLAT_BOX, x - w / 2, y - h / 2, w, h, fillColor);
//   fl_draw_box(FL_BORDER_FRAME, x - w / 2, y - h / 2, w, h,
//               frameColor);
// }

// void Rectangle::setFillColor(Fl_Color newFillColor) {
//   fillColor = newFillColor;
// }

// void Rectangle::setFrameColor(Fl_Color newFrameColor) {
//   frameColor = newFrameColor;
// }

// bool Rectangle::contains(Point p) {
//   return p.x >= center.x - w / 2 && p.x < center.x + w / 2 &&
//          p.y >= center.y - h / 2 && p.y < center.y + h / 2;
// }

// /*----------------------------------------------------------------------------------

// Text class
// -----------------------------------------------------------------------------------*/

// Text::Text(std::string &&s, Point center, int fontSize /*= 10 */, Fl_Color color /*= FL_BLACK */)
//     : center{center}, s{s}, fontSize{fontSize}, color{color} {}

// void Text::draw() {
//   fl_color(color);
//   fl_font(FL_HELVETICA, fontSize);
//   int width, height;
//   fl_measure(s.c_str(), width, height, false);
//   int x = static_cast<int>(fl_transform_x(
//       center.x - width / 2, center.y - fl_descent() + height / 2));
//   int y = static_cast<int>(fl_transform_y(
//       center.x - width / 2, center.y - fl_descent() + height / 2));
//   fl_draw(s.c_str(), x, y);
// }

// /*----------------------------------------------------------------------------------

// Translation class
// -----------------------------------------------------------------------------------*/

// Translation::Translation(Point p) {
//     fl_push_matrix();
//     fl_translate(p.x, p.y);
// }

// /*----------------------------------------------------------------------------------

// Rotation class
// -----------------------------------------------------------------------------------*/

// Rotation::Rotation(Point center, double angle) {
//     fl_push_matrix();
//     fl_translate(center.x, center.y);
//     fl_rotate(angle);
//     fl_translate(-1 * center.x, -1 * center.y);
// }
