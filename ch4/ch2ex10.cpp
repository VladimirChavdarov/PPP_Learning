#include "../PPP/PPP.h"

int main()
{
	int n = 0;
	cout << "Amount of numbers to sum ";
	cin >> n;
	try
	{
		if (n <= 0)
			error("N must be >= 0");
	}
	catch (const exception& e)
	{
		cout << "Exception: " << e.what() << endl;
		return 1;
	}

	vector<double> vec;
	while (cin)
	{
		double a = 0;
		cin >> a;

		try
		{
			if (a == std::numeric_limits<double>::max())
				error("Input is too big to be represented as an double");
		}
		catch (const exception& e)
		{
			cout << "Exception: " << e.what() << endl;
			return 1;
		}

		vec.push_back(a);
	}
	vec.pop_back();

	for (auto& item : vec)
		cout << item << " ";
	cout << endl;

	try
	{
		if (vec.size() < n)
			error("N is bigger than the size of the vector");
	}
	catch (const exception& e)
	{
		cout << "Exception: " << e.what() << endl;
		return 1;
	}

	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += vec[i];

	try
	{
		if (sum < 0)
			error("Sum is too big to be represented as an integer");
	}
	catch (const exception& e)
	{
		cout << "Exception: " << e.what() << endl;
		return 1;
	}

	cout << sum << endl;

	vector<double> diff;
	for (int i = 0; i < vec.size() - 1; i++)
	{
		diff.push_back(vec[i] - vec[i + 1]);
	}
	for (auto& item : diff)
		cout << item << " " << endl;
}