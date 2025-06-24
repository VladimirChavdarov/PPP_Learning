#include "../PPP/Window.h"
#include "../PPP/Graph.h"
#include "../PPP/Simple_window.h"

using namespace Graph_lib;

void main(int, char* [])
{
	Application app;
	Point tl{ 900, 500 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Polygon poly_rect;
	poly_rect.add(Point{ 100, 50 });
	poly_rect.add(Point{ 200, 50 });
	poly_rect.add(Point{ 200, 100 });
	poly_rect.add(Point{ 100, 100 });
	poly_rect.set_color(Color::red);
	win.attach(poly_rect);
	win.set_label("Polyline");

	Rectangle r{ Point{300, 50}, 100, 50 };
	r.set_color(Color::blue);
	win.attach(r);
	win.set_label("Rectangle");

	win.wait_for_button();
}