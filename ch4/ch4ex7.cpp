#include "../PPP/PPP.h"

double Determinant(double a, double b, double c)
{
	double d = b*b - 4 * a * c;
	if (d < 0)
		error("No real roots.");
	return d;
}

int main()
{
	double a, b, c;
	double d = 0.0;
	cin >> a >> b >> c;
	try
	{
		d = Determinant(a, b, c);
	}
	catch(const exception& e)
	{
		cerr << "exception: " << e.what() << endl;
		return 1;
	}
	cout << "Determinant: " << d << endl;

	double x1 = (-b + std::sqrt(d)) / (2.0 * a);
	double x2 = (-b - std::sqrt(d)) / (2.0 * a);

	cout << x1 << endl << x2 << endl;
}