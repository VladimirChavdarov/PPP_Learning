#include "../PPP/PPP.h"

int main()
{
	ifstream ist{ "ch9/ex16.txt" };
	if (!ist)
		error("can't open file");

	int number = 0;
	int sum = 0;
	while (ist >> number)
	{
		sum += number;
		cout << number << endl;
	}
	cout << "Sum: " << sum << endl;
}