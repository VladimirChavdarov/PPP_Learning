#include "../PPP/PPP.h"

int main()
{
	double a = 0.0, b = 0.0;
	char operation = ' ';
	double result = 0.0;

	cin >> a >> b >> operation;

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