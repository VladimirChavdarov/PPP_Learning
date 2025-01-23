#include "../PPP/PPP.h"

int GetNumberFromDigits(vector<int> digits)
{
	int result = 0;
	int size = digits.size();
	for (int i = 0; i < size; i++)
		result += digits[size - 1 - i] * std::pow(10, i);

	return result;
}

// Number is between 1000 and 9999
int GetDigitAtPosition(int number, int position)
{
	int digit = -1;
	for (int i = 0; i < position; i++)
	{
		int multiplier = std::pow(10, 4 - 1 - i);
		digit = number / multiplier;
		number -= digit * multiplier;
	}
	
	if (digit < 0)
		error("Result is not between 0 and 9");
	return digit;
}

bool RepeatedDigit(vector<int>digits, int new_digit)
{
	for (auto& d : digits)
	{
		if (d == new_digit)
			return false;
	}
	return true;
}

int main()
{
	// setup seed
	//seed(time(0));
	//

	// Game Init
	vector<int> digits;
	int number = 0;
	for (int i = 0; i < 4; i++)
	{
		//generate digit
		int d = random_int(0, 9);
		while (!RepeatedDigit(digits, d))
		{
			d = random_int(0, 9);
		}
		digits.push_back(d);
	}
	number = GetNumberFromDigits(digits);
	//

	// Game Loop
	int rounds = 0;
	int input = 0;
	while (input != number)
	{
		// Input phase
		cout << "Enter a 4-digit number: ";
		cin >> input;
		try
		{
			if (!cin)
			{
				error("Invalid input. Needs Integers!");
			}
			if (input < 1000 || input > 9999)
				error("Invalid input. Out of Bounds!");
		}
		catch (const exception& e)
		{
			cout << "Exception: " << e.what() << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		//

		// Check phase
		int number_of_cows = 0;
		int number_of_bulls = 0;
		for (int i = 0; i < 4; i++)
		{
			bool cow = false;
			bool bull = false;
			int digit = GetDigitAtPosition(input, i+1);
			// Go through the bot's number to check for bulls and cows
			for (int j = 0; j < digits.size(); j++)
			{
				// digit match = cow
				if (digit == digits[j])
				{
					cow = true;

					// position match = bull
					if (i == j)
						bull = true;
				}
			}
			if (cow && !bull)
				number_of_cows++;
			if (cow && bull)
				number_of_bulls++;
		}
		//
		
		cout << "Cows: " << number_of_cows << endl;
		cout << "Bulls: " << number_of_bulls << endl;
		cout << endl;
		
		rounds++;
	}
	cout << "You won in " << rounds << " turns!" << endl;
	//
}