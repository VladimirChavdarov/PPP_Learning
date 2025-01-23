#include "../PPP/PPP.h"

int main()
{
	int a = 0;

	cout << "Enter an integer: ";
	cin >> a;
	cout << "\n";

	if (a % 2 == 0)
		cout << a << " is an even number.\n";
	else
		cout << a << " is an odd number.\n";
}