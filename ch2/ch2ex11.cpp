#include "../PPP/PPP.h"

int main()
{
	string currency_names_pl[6] = { "pennies", "nickels", "dimes", "quarters", "half dollars", "dollars" };
	string currency_names_sg[6] = { "penny", "nickel", "dime", "quarter", "half dollar", "dollar" };
	double currency_values[6] = { 0.01, 0.05, 0.10, 0.25, 0.50, 1.00 };

	double purse[6] = { 0.0 };
	double sum = 0.0;

	for (int i = 0; i < 6; i++)
	{
		cout << "Enter number of " << currency_names_pl[i] << ": ";
		cin >> purse[i];
	}
	cout << "\n";

	for (int i = 0; i < 6; i++)
	{
		string currency_name = currency_names_pl[i];
		if (purse[i] == 1)
			currency_name = currency_names_sg[i];
		cout << "You have " << purse[i] << " " << currency_name << ".\n";

		sum += purse[i] * currency_values[i];
	}
	cout << "You have " << sum << " dollars in your purse.\n";

}