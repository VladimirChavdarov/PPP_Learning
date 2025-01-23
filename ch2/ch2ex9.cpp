#include "../PPP/PPP.h"

int main()
{
	/*string s_number = "";

	cout << "Enter number with words: ";
	cin >> s_number;

	if(s_number == "one" || s_number == "One")
	{
		cout << "1\n";
	}
	else if (s_number == "two" || s_number == "Two")
	{
		cout << "2\n";
	}
	else if (s_number == "three" || s_number == "Three")
	{
		cout << "3\n";
	}
	else if (s_number == "Four" || s_number == "four")
	{
		cout << "4\n";
	}
	else
	{
		cout << "not a number I know\n";
	}*/

	// -----------------------------
	// Bank investment
	// -----------------------------

	double initial_investment = 0.0;
	double accumulated_value = 0.0;
	int years = 0;
	double monthly_interest_rate = 0.0;

	cout << "Initial investment: ";
	cin >> initial_investment;
	cout << "Monthly interest rate: ";
	cin >> monthly_interest_rate;
	cout << "Years of monthly investments: ";
	cin >> years;

	accumulated_value = initial_investment;

	for (int i = 0; i < years * 12; i++)
	{
		double gain = accumulated_value * monthly_interest_rate / 100.0;
		accumulated_value += gain;
	}

	cout << "Accumulated value: " << accumulated_value << endl;
	cout << "Monthly gain after " << years << " years: " << accumulated_value * monthly_interest_rate / 100.0 << endl;
}