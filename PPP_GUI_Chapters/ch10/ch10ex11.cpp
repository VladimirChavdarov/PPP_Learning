#include "../PPP/Window.h"
#include "../PPP/Graph.h"
#include "../PPP/Simple_window.h"

using namespace Graph_lib;

void main(int, char* [])
{
	Application app;
	Point tl{ 900, 500 };
	Simple_window win{ tl, 600, 400, "Canvas" };

    Graph_lib::Polygon tri;
    tri.add(Point(200, 20));
    tri.add(Point(300, 20));
    tri.add(Point(250, 106));
    tri.set_color(Color::white);
    win.attach(tri);

    Open_polyline square;
    square.add(Point(200, 20));
    square.add(Point(200, 120));
    square.add(Point(300, 120));
    square.add(Point(300, 20));
    square.set_color(Color::white);
    win.attach(square);

    Open_polyline pentagon;
    pentagon.add(Point(200, 20));
    pentagon.add(Point(169, 115));
    pentagon.add(Point(250, 179));
    pentagon.add(Point(331, 115));
    pentagon.add(Point(300, 20));
    pentagon.set_color(Color::white);
    win.attach(pentagon);

    Open_polyline hexagon;
    hexagon.add(Point(200, 20));
    hexagon.add(Point(150, 107));
    hexagon.add(Point(200, 194));
    hexagon.add(Point(300, 194));
    hexagon.add(Point(350, 107));
    hexagon.add(Point(300, 20));
    hexagon.set_color(Color::white);
    win.attach(hexagon);

	win.wait_for_button();
}