#include "../PPP/PPP.h"

int main()
{
	int n = 0;
	cout << "Enter n: ";
	cin >> n;
	cout << endl;

	vector<int> prime_numbers;
	vector<int> marked_numbers;
	for (int i = 0; i < n-1; i++)
		marked_numbers.push_back(0);

	// 1st step
	for (int j = 2; j <= n; j++)
	{
		if (j % 2 == 0 && j > 2)
		{
			marked_numbers[j - 2] = 1;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (marked_numbers[i - 2] == 0)
		{
			for (int j = 2; j <= n; j++)
			{
				if (j % i == 0 && j > i)
				{
					marked_numbers[j - 2] = 1;
				}
			}
		}
	}

	for (int i = 0; i < marked_numbers.size(); i++)
	{
		if (marked_numbers[i] == 0)
			prime_numbers.push_back(i + 2);
	}

	for (int num : prime_numbers)
		cout << num << ", ";
}