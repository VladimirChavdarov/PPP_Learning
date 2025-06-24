#include "../PPP/Window.h"
#include "../PPP/Graph.h"
#include "../PPP/Simple_window.h"

using namespace Graph_lib;

void main(int, char* [])
{
	Application app;
	Point tl{ 900, 500 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Circle c1 = Circle(Point{100, 250}, 50);
	c1.set_color(Color::blue);
	win.attach(c1);

	Circle c2 = Circle(Point{ 220, 250 }, 50);
	c2.set_color(Color::white);
	win.attach(c2);

	Circle c3 = Circle(Point{ 340, 250 }, 50);
	c3.set_color(Color::red);
	win.attach(c3);

	Circle c4 = Circle(Point{ 160, 300 }, 50);
	c4.set_color(Color::yellow);
	win.attach(c4);

	Circle c5 = Circle(Point{ 280, 300 }, 50);
	c5.set_color(Color::green);
	win.attach(c5);

	win.wait_for_button();
}