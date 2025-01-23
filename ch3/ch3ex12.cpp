#include "../PPP/PPP.h"

int main()
{
	vector<int> prime_numbers;
	bool is_prime = true;

	for (int i = 1; i <= 100; i++)
	{
		is_prime = true;

		if (i == 1)
			continue;
		if (prime_numbers.empty()) // 1 is not a prime number
		{
			prime_numbers.push_back(i);
		}

		for (int j = 0; j < prime_numbers.size(); j++)
		{
			if (i % prime_numbers[j] == 0)
			{
				is_prime = false;
				break;
			}
		}

		if (is_prime)
			prime_numbers.push_back(i);
	}

	cout << "Prime numbers from 1 to 100: ";
	for (int i = 0; i < prime_numbers.size(); i++)
	{
		cout << prime_numbers[i] << ", ";
	}
}