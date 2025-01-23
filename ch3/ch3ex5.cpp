#include "../PPP/PPP.h"

int main()
{
	int number = 0;
	while (number < 1 || number > 100)
	{
		cin >> number;
	}

	int upper_border = 100;
	int lower_border = 1;
	int guessed_number = -1;
	char hint = ' ';
	for (int i = 0; i < 7; i++)
	{
		guessed_number = (upper_border + lower_border) / 2;
		if (guessed_number == number)
		{
			cout << "Correct!" << endl;
			return 0;
		}
		cout << "Is your number " << guessed_number << "?\n";

		cout << "Enter Higher (h) or Lower (l): ";
		cin >> hint;
		switch (hint)
		{
		case 'h':
			lower_border = guessed_number;
			break;
		case 'l':
			upper_border = guessed_number;
			break;
		default:
			cout << "Invalid Input" << endl;
			i--;
			break;
		}

	}

	cout << "Game Over!" << endl;
}