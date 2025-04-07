#include "../PPP/PPP.h"

struct digit
{
	int value = -1;
	string keyword = "none";
};

int main()
{
	string input = "";
	int digit_amount = 0;
	string keywords[4] = { "thousand", "hundred", "tens", "ones" };
	digit digits[4];
	
	// Input handling
	while (cin >> input)
	{
		if (input.size() <= 4)
		{
			digit_amount = input.size();
			break;
		}
		else
			cout << "Number must be 4 digits or less!" << endl;
	}
	//

	// Process input
	int diff = 4 - input.size();
	for (int i = input.size() - 1; i >= 0; i--)
	{
		digits[i].value = input[i] - '0';
		digits[i].keyword = keywords[i + diff];
	}
	//

	// Output
	cout << input << " is ";
	for (int i = 0; i < sizeof(digits) / sizeof(digits[0]); i++)
	{
		if (digits[i].value == -1)
			continue;
		cout << digits[i].value << " " << digits[i].keyword;
		if (i < digit_amount - 1)
			cout << " and ";

	}
	cout << "." << endl;
	//
}