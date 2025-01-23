#include "../PPP/PPP.h"

int main()
{
	vector<string> s_numbers = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	int input = -1;
	cin >> input;
	if (input >= 0 && input <= 9)
		cout << s_numbers[input] << endl;
	else
		cout << "Invalid input" << endl;
}