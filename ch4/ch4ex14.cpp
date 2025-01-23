#include "../PPP/PPP.h"

char asciitolower(char in) {
	if (in <= 'Z' && in >= 'A')
		return in - ('Z' - 'z');
	return in;
}

char asciitoupper(char in) {
	if (in <= 'z' && in >= 'a')
		return in + ('Z' - 'z');
	return in;
}

// Checks all uppercase and lowercase cases
bool CompareStringExtended(string s1, string s2)
{
	// normal comparison
	if (s1 == s2)
		return true;

	// lowercase
	std::transform(s1.begin(), s1.end(), s1.begin(), asciitolower);
	std::transform(s2.begin(), s2.end(), s2.begin(), asciitolower);
	if (s1 == s2)
		return true;

	// uppercase
	std::transform(s1.begin(), s1.end(), s1.begin(), asciitoupper);
	std::transform(s2.begin(), s2.end(), s2.begin(), asciitoupper);
	if (s1 == s2)
		return true;

	return false;
}

int main()
{
	vector<string> dictionary = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	vector<string> dictionary_shorts = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

	vector<vector<int>> weekdays = { {}, {}, {}, {}, {}, {}, {} };
	int rejected_input = 0;

	// Input
	while (cin)
	{
		string day = "";
		int value = 0;
		cin >> day >> value;

		bool rejected = true;
		for (int i = 0; i < dictionary.size(); i++)
		{
			if (CompareStringExtended(day, dictionary[i]) || CompareStringExtended(day, dictionary_shorts[i]))
			{
				weekdays[i].push_back(value);
				rejected = false;
			}
		}
		if (rejected)
		{
			rejected_input++;
			cout << "Rejected Input!" << endl;
		}
	}
	//

	// Output
	//
	// Values of each day + sum
	for (int i = 0; i < weekdays.size(); i++)
	{
		int sum = 0;
		cout << dictionary[i] << ": ";
		for (int j = 0; j < weekdays[i].size(); j++)
		{
			sum += weekdays[i][j];
			cout << weekdays[i][j] << ", ";
		}
		cout << endl;
		cout << "Sum: " << sum << endl;
	}
	cout << endl;
	//

	// Rejected tries
	cout << "Rejected inputs: " << rejected_input << endl;
}