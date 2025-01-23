#include "../PPP/PPP.h"

int main()
{
	vector<int> numbers;
	for (int i; cin >> i;)
		numbers.push_back(i);

	ranges::sort(numbers);
	cout << endl;
	for (int i : numbers)
		cout << i << " ";
	cout << endl;

	double median = 0;
	// odd vector size
	if (numbers.size() % 2 == 1)
		median = static_cast<double>(numbers[numbers.size() / 2]);
	// even vector size
	else
		median = static_cast<double>(numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2.0;

	cout << "Median: " << median << endl;
}