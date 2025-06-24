#include "../PPP/Window.h"
#include "../PPP/Graph.h"
#include "../PPP/Simple_window.h"

using namespace Graph_lib;

void main(int, char* [])
{
	Application app;
	Point tl{ 900, 500 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Rectangle r{ Point{50, 50}, 100, 30 };
	r.set_color(Color::white);
	win.attach(r);
	win.set_label("Rectangle");

	Text t{ Point{55, 55}, "Howdy!" };
	t.set_color(Color::white);
	win.attach(t);
	win.set_label("Text");

	win.wait_for_button();
}