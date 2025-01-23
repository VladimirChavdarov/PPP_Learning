#include "../PPP/PPP.h"



int main()
{
	// [a b c]
	// 
	// a b c
	// a c b
	// b a c
	// b c a
	// c a b
	// c b a
	string val1 = "";
	string val2 = "";
	string val3 = "";
	string temp = "";

	cout << "Enter 1st value: ";
	cin >> val1;
	cout << "Enter 2nd value: ";
	cin >> val2;
	cout << "Enter 3rd value: ";
	cin >> val3;

	// 8 3 5
	// look for smallest value
	if (val1 > val2)
	{
		temp = val2;
		val2 = val1;
		val1 = temp;
	}
	// 3 8 5
	if (val1 > val3)
	{
		temp = val3;
		val3 = val1;
		val1 = temp;
	}
	// 3 8 5
	if (val2 > val3)
	{
		temp = val3;
		val3 = val2;
		val2 = temp;
	}
	// 3 5 8

	cout << "\n" << val1 << ", " << val2 << ", " << val3 << "\n";

}