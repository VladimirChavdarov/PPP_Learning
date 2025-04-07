#include "../PPP/PPP.h"



int main()
{
	// data
	vector<string> names /*= { "Dimitar", "Anton", "Georgi", "Boris", "Vasil" }*/;
	vector<int>ages;

	vector<string> names_unsorted;
	vector<int> ages_unsorted;
	//

	// input
	string in_name = "";
	int in_age = -1;
	while (in_name != "q")
	{
		cout << "Input (example: Name Age): ";
		cin >> in_name >> in_age;
		if (in_age < 0)
			error("Age can't be less than 0");
		if (in_name == "q")
			continue;
		names.push_back(in_name);
		ages.push_back(in_age);
	}
	names_unsorted = names;
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