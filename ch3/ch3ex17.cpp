#include "../PPP/PPP.h"

inline double squared(double x)
{
	return x * x;
}

int main()
{
	double a = 0.0, b = 0.0, c = 0.0;
	cout << "a*x^2 + b*x + c = 0" << endl;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;

	double D = squared(b) - 4 * a * c;
	double x1 = -1, x2 = -1;

	if (D < 0)
	{
		cout << "No real solutions." << endl;
		return 0;
	}
	else if(D > 0)
	{
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);
	}
	else if (D == 0)
	{
		x1 = -b / (2 * a);
		x2 = x1;
	}
	
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
}