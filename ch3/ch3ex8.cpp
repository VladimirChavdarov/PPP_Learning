#include "../PPP/PPP.h"

int main()
{
	vector<string> s_numbers = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<string> d_numbers = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	string s_a = "", s_b = "";
	int a = 0, b = 0;
	int result = 0;
	char operation = ' ';
	cin >> s_a >> s_b >> operation;

	for(int i = 0; i < s_numbers.size(); i++)
	{
		if (s_numbers[i] == s_a)
			a = i;
		if (s_numbers[i] == s_b)
			b = i;
	}
	for (int i = 0; i < d_numbers.size(); i++)
	{
		if (d_numbers[i] == s_a)
			a = i;
		if (d_numbers[i] == s_b)
			b = i;
	}

	switch (operation)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	default:
		cout << "Invalid operator" << endl;
		break;
	}

	cout << a << " " << operation << " " << b << " = " << result << endl;
}