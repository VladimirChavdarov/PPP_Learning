#include "NamePairs.h"
#pragma once

void Name_Pairs::read_names()
{
	cout << "Enter names. NoName to finish: " << endl;
	string s;
	while (cin >> s && s != "NoName")
	{
		bool name_exists = false;
		for (int i = 0; i < names.size(); i++)
		{
			if (names[i] == s)
			{
				name_exists = true;
				cout << "Operation Failed! Name already exists." << endl;
				break;
			}
		}
		if (!name_exists)
		{
			names.push_back(s);
			ages.push_back(0); // always synchronize the two vectors.
			cout << "Operation Successful!" << endl;
		}
	}
}

void Name_Pairs::read_ages()
{
	for (int i = 0; i < names.size(); i++)
	{
		cout << "Enter age for " << names[i] << ": ";
		double age;
		cin >> age;
		if (age < 0.0)
		{
			cout << "Operation Failed! Age can't be negative." << endl;
			i--;
			continue;
		}
		
		ages[i] = age;
		cout << "Operation Successful!" << endl;
	}
}

void Name_Pairs::print()
{
	if (names.size() != ages.size())
		error("Error: Names and Ages vectors are not the same size!");
	for (int i = 0; i < names.size(); i++)
	{
		cout << i+1 << ". " << names[i] << ", " << ages[i] << endl;
	}
}

void Name_Pairs::sort_names()
{
	if (names.size() != ages.size())
		error("Error: Names and Ages vectors are not the same size!");

	// sort the pair vector
	struct na_pair
	{
		na_pair(string a_name, double a_age) : name(a_name), age(a_age) {}

		string name = "";
		double age = 0;
	};
	vector<na_pair> name_pairs;
	for (int i = 0; i < names.size(); i++)
	{
		name_pairs.push_back(na_pair(names[i], ages[i]));
	}
	sort(name_pairs.begin(), name_pairs.end(), [](na_pair a, na_pair b) { return a.name < b.name; });
	//

	// update names and ages vectors
	for (int i = 0; i < name_pairs.size(); i++)
	{
		names[i] = name_pairs[i].name;
		ages[i] = name_pairs[i].age;
	}
	//

	cout << "List sorted by names!" << endl;
}
