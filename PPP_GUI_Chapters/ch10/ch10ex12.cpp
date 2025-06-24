#include "../PPP/Window.h"
#include "../PPP/Graph.h"
#include "../PPP/Simple_window.h"

using namespace Graph_lib;

double sgn(double d)
{
    if (d > 0) return 1;
    else if (d < 0) return -1;
    else return 0;
}

void main(int, char* [])
{
    const double pi = 3.14159;
    int a = 100 * 4;
    int b = 100 * 4;
    double m = 0.5f;
    double n = 0.5f;
    int N = 50;

    Application app;
    Point tl(300, 25);
    Simple_window win(tl, a * 2 + 20, b * 2 + 20, "Superellipse");

    // Obtain the points we want to connect via the superelipse formula.
    vector<Point> points;

    for (double theta = 0; theta < 2 * pi; theta += 2 * pi / N)
    {
        double x = pow(abs(cos(theta)), 2 / m) * a * sgn(cos(theta)) + a + 10;
        double y = pow(abs(sin(theta)), 2 / n) * b * sgn(sin(theta)) + b + 10;
        points.push_back(Point(x, y));
    }
    //

    // split the vector in 4 parts, color each a different color
    Open_polyline interior1;
    for (int i = 0; i < points.size() / 4; ++i)
    {
        interior1.add(points[i]);
        for (int j = i; j < points.size(); ++j)
        {
            if (i != j) {
                interior1.add(points[j]);
                interior1.add(points[i]);
            }
        }
    }
    interior1.set_color(Color::red);
    win.attach(interior1);

    Open_polyline interior2;
    for (int i = points.size() / 4; i < points.size() / 2; ++i)
    {
        interior2.add(points[i]);
        for (int j = i; j < points.size(); ++j)
        {
            if (i != j)
            {
                interior2.add(points[j]);
                interior2.add(points[i]);
            }
        }
    }
    interior2.set_color(Color::green);
    win.attach(interior2);

    Open_polyline interior3;
    for (int i = points.size() / 2; i < 3 * points.size() / 4; ++i)
    {
        interior3.add(points[i]);
        for (int j = i; j < points.size(); ++j)
        {
            if (i != j)
            {
                interior3.add(points[j]);
                interior3.add(points[i]);
            }
        }
    }
    interior3.set_color(Color::blue);
    win.attach(interior3);

    Open_polyline interior4;
    for (int i = 3 * points.size() / 4; i < points.size(); ++i)
    {
        interior4.add(points[i]);
        for (int j = i; j < points.size(); ++j)
        {
            if (i != j)
            {
                interior4.add(points[j]);
                interior4.add(points[i]);
            }
        }
    }
    interior4.set_color(Color::yellow);
    win.attach(interior4);
    //

    // draw borders of the superelipse
    Closed_polyline superell;
    for (int i = 0; i < points.size(); ++i)
        superell.add(points[i]);
    superell.set_color(Color::white);
    superell.set_style(Line_style(Line_style::solid, 4));
    win.attach(superell);
    //

    win.wait_for_button();
}