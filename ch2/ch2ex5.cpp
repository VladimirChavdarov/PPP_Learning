#include "../PPP/PPP.h"

int main()
{
	double val1 = 0, val2 = 0;

	cout << "Enter 1st value: ";
	cin >> val1;
	cout << "Enter 2nd value: ";
	cin >> val2;

	if (val1 > val2)
	{
		cout << val1 << " is greater than " << val2 << "\n";
	}
	else if (val1 < val2)
	{
		cout << val1 << " is smaller than " << val2 << "\n";
	}
	else if (val1 == val2)
	{
		cout << "Values are equal\n";
	}

	cout << val1 << " + " << val2 << " = " << val1 + val2 << "\n";
	cout << val1 << " - " << val2 << " = " << val1 - val2 << "\n";
	cout << val1 << " * " << val2 << " = " << val1 * val2 << "\n";
	cout << val1 << " / " << val2 << " = " << val1 / val2 << "\n";
}