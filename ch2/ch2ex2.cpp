#include "../PPP/PPP.h"

int main()
{
	double miles = 0.0;
	double kilometers = 0.0;

	cout << "Enter miles: ";
	cin >> miles;

	kilometers = miles * 1.609;

	cout << "\n" << "Kilometers: " << kilometers << "\n";
}