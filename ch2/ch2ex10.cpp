#include "../PPP/PPP.h"

int main()
{
	string operation = "";
	double a = 0.0, b = 0.0;
	double result = 0;

	cout << "Operation (+, -, *, /): ";
	cin >> operation;
	cout << "Operands: ";
	cin >> a >> b;

	if (operation == "+" || operation == "plus")
	{
		result = a + b;
	}
	if (operation == "-" || operation == "minus")
	{
		result = a - b;
	}
	if (operation == "*" || operation == "mul")
	{
		result = a * b;
	}
	if (operation == "/" || operation == "div")
	{
		result = a / b;
	}

	cout << "Result: " << result << "\n";
}