#include "../PPP/Window.h"
#include "../PPP/Graph.h"
#include "../PPP/Simple_window.h"

using namespace Graph_lib;

void main(int, char* [])
{
	Application app;
	Point tl{ 900, 500 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Image img{ Point{0, 0}, "myimage.jpg" };
	win.attach(img);
	win.set_label("The Pot");

	Text t{ Point{0, 310}, "Some nice text!" };
	t.set_color(Color::white);
	win.attach(t);
	win.set_label("Text");

	win.wait_for_button();
}