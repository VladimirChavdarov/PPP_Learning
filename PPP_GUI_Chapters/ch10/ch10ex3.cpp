#include "../PPP/Window.h"
#include "../PPP/Graph.h"
#include "../PPP/Simple_window.h"

using namespace Graph_lib;

void main(int, char* [])
{
	Application app;
	Point tl{ 900, 500 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Text t{ Point{50, 50}, "V" };
	t.set_color(Color::white);
	t.set_font(Font::times_bold);
	t.set_font_size(150);
	win.attach(t);
	win.set_label("V");

	Text t1{ Point{200, 50}, "S" };
	t1.set_color(Color::green);
	t1.set_font(Font::times_bold);
	t1.set_font_size(150);
	win.attach(t1);
	win.set_label("S");

	Text t2{ Point{350, 50}, "CH" };
	t2.set_color(Color::red);
	t2.set_font(Font::times_bold);
	t2.set_font_size(150);
	win.attach(t2);
	win.set_label("CH");

	win.wait_for_button();
}