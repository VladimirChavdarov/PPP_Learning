#include "PPP/Window.h"
#include "PPP/Graph.h"
#include "PPP/Simple_window.h"

using namespace Graph_lib;

//double dsin(double d) { return sin(d); }
//
//int main(int /*argc*/, char* /*argv*/[])
//{
//    //Application app;
//    //Window window({20, 20}, 600, 400, "Main window");
//    //Text text({150, 20}, "Well hello there!");
//    //window.attach(text);
//    //app.gui_main();
//
//    Application app;
//    Point tl{ 900, 500 };
//    Simple_window win{ tl, 600, 400, "Canvas" };
//    
//    Axis xa{ Axis::x, Point{20, 300}, 280, 10, "x axis" };
//    xa.set_color(Color::white);
//    win.attach(xa);
//    win.set_label("XA axis");
//
//    Axis ya{ Axis::y, Point{20, 300}, 280, 10, "y axis" };
//    ya.set_color(Color::white);
//    win.attach(ya);
//    win.set_label("YA axis");
//
//    Function sine{ dsin, 0, 100, Point{20, 150}, 1000, 50, 50 };
//    sine.set_color(Color::white);
//    win.attach(sine);
//    win.set_label("Sine");
//
//    Polygon poly;
//    poly.add(Point{ 300, 200 });
//    poly.add(Point{ 350, 100 });
//    poly.add(Point{ 400, 200 });
//    poly.set_color(Color::red);
//    poly.set_style(Line_style(Line_style::dash, 4));
//    win.attach(poly);
//    win.set_label("Triangle");
//
//    Rectangle r{ Point{200, 200}, 100, 50 };
//    r.set_color(Color::white);
//    r.set_fill_color(Color::yellow);
//    win.attach(r);
//    win.set_label("Rectangle");
//
//    Polygon poly_rect;
//    poly_rect.add(Point{ 100, 50 });
//    poly_rect.add(Point{ 200, 50 });
//    poly_rect.add(Point{ 200, 100 });
//    poly_rect.add(Point{ 100, 100 });
//    poly_rect.add(Point{ 50, 75 });
//    poly_rect.set_color(Color::white);
//    poly_rect.set_fill_color(Color::green);
//    poly_rect.set_style(Line_style(Line_style::dash, 2));
//    win.attach(poly_rect);
//    win.set_label("Polyline");
//
//    Text t{ Point{150, 150}, "Hello, graphical world!" };
//    t.set_color(Color::white);
//    t.set_font(Font::times_bold);
//    t.set_font_size(20);
//    win.attach(t);
//    win.set_label("Text");
//
//    Image copter{ Point{100, 50}, "myimage.png" };
//    copter.move(250, 250);
//    win.attach(copter);
//    win.set_label("The Pot");
//
//    win.wait_for_button();
//}
//