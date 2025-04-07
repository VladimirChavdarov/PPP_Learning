#include "../PPP/PPP.h"



int main()
{
	// data
	vector<string> names = { "Dimitar", "Anton", "Georgi", "Boris", "Vasil" };
	vector<int>ages;

	vector<string> names_unsorted = names;
	vector<int> ages_unsorted;
	//

	// input
	for (const auto& name : names)
	{
		int age = -1;
		cout << name << ": ";
		cin >> age;
		if (age < 0)
			error("Age can't be less than 0");
		ages.push_back(age);
	}
	ages_unsorted = ages;
	//

	// sort names
	std::sort(names.begin(), names.end());
	//

	// sort ages
	for (int i = 0; i < names.size(); i++)
	{
		for (int j = 0; j < names_unsorted.size(); j++)
		{
			if (names[i] == names_unsorted[j])
			{
				ages[i] = ages_unsorted[j];
			}
		}
	}
	//

	// output
	cout << endl;
	cout << "--------------------------" << endl;
	for (int i = 0; i < names.size(); i++)
	{
		cout << names[i] << ", " << ages[i] << endl;
	}
	//
}