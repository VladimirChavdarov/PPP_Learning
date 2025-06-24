#include "../PPP/Window.h"
#include "../PPP/Graph.h"
#include "../PPP/Simple_window.h"

using namespace Graph_lib;

void DrawBigBox(Simple_window& win, Point p, const string& box_label, const string& box_comment, const string& box_content)
{
    int width = std::max(box_comment.length(), box_content.length()) * 20;
    Text label(p, box_label);
    label.set_color(Color::blue);
    label.set_font_size(20);
    win.attach(label);

    Rectangle rect(Point(p.x, p.y - 20), 100, 100);
    rect.set_fill_color(Color::yellow);
    win.attach(rect);
}

void DrawSmallBox(Simple_window& win, Point p, const string& box_label, const string& box_content)
{

}

void main(int, char* [])
{
	Application app;
	Point tl{ 900, 500 };
	Simple_window win{ tl, 600, 400, "Canvas" };

    DrawBigBox(win, Point(100, 100), "Graph.h", "//Graphing interface", "struct Shape {...};");

    // TODO: I need to do all the memory management for this to work without code repetition.

	win.wait_for_button();
}