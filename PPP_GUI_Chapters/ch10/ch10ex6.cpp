#include "../PPP/Window.h"
#include "../PPP/Graph.h"
#include "../PPP/Simple_window.h"

using namespace Graph_lib;

// both the Window and the rectangle go outside of the screen or the window, respectively.
void main(int, char* [])
{
	Application app;
	Point tl{ 900, 500 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Graph_lib::Rectangle rect(Point(100, 100), 1500, 800);
	win.attach(rect);
	win.wait_for_button();
}