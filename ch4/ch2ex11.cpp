#include "../PPP/PPP.h"

int main()
{
	int n = 0;
	cout << "Fibonacci sequence length: ";
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

	vector<int> fibonacci;
	for (int i = 0; i < n; i++)
	{
		int result = 0;
		// first two values
		if (i - 2 < 0)
			result = 1;
		// all other cases
		else
		{
			int a = fibonacci[i - 2];
			int b = fibonacci[i - 1];
			result = a + b;
		}
		//

		try
		{
			if (result < 0)
			{
				error("Integer Overflow at position", i);
			}
		}
		catch (const exception& e)
		{
			cout << "Exception: " << e.what() << endl;
			return 1;
		}

		fibonacci.push_back(result);
	}

	for (auto& number : fibonacci)
		cout << number << " ";
	cout << endl;
}