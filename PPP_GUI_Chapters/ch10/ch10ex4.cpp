#include "../PPP/Window.h"
#include "../PPP/Graph.h"
#include "../PPP/Simple_window.h"

using namespace Graph_lib;

void main(int, char* [])
{
	Application app;
	Point tl{ 900, 500 };
	Simple_window win{ tl, 600, 400, "Canvas" };

    // create squares
    Graph_lib::Rectangle rect1(Point(100, 100), 100, 100);
    rect1.set_color(Color::Transparency::invisible);
    rect1.set_fill_color(Color::white);
    win.attach(rect1);

    Graph_lib::Rectangle rect2(Point(200, 100), 100, 100);
    rect2.set_fill_color(Color::red);
    rect2.set_color(Color::Transparency::invisible);
    win.attach(rect2);

    Graph_lib::Rectangle rect3(Point(300, 100), 100, 100);
    rect3.set_fill_color(Color::white);
    rect3.set_color(Color::Transparency::invisible);
    win.attach(rect3);

    Graph_lib::Rectangle rect4(Point(100, 200), 100, 100);
    rect4.set_fill_color(Color::red);
    rect4.set_color(Color::Transparency::invisible);
    win.attach(rect4);

    Graph_lib::Rectangle rect5(Point(200, 200), 100, 100);
    rect5.set_fill_color(Color::white);
    rect5.set_color(Color::Transparency::invisible);
    win.attach(rect5);

    Graph_lib::Rectangle rect6(Point(300, 200), 100, 100);
    rect6.set_fill_color(Color::red);
    rect6.set_color(Color::Transparency::invisible);
    win.attach(rect6);

    Graph_lib::Rectangle rect7(Point(100, 300), 100, 100);
    rect7.set_fill_color(Color::white);
    rect7.set_color(Color::Transparency::invisible);
    win.attach(rect7);

    Graph_lib::Rectangle rect8(Point(200, 300), 100, 100);
    rect8.set_fill_color(Color::red);
    rect8.set_color(Color::Transparency::invisible);
    win.attach(rect8);

    Graph_lib::Rectangle rect9(Point(300, 300), 100, 100);
    rect9.set_fill_color(Color::white);
    rect9.set_color(Color::Transparency::invisible);
    win.attach(rect9);

	win.wait_for_button();
}