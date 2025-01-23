#include "../PPP/PPP.h"

int main()
{
	vector<string> names;
	vector<int> scores;
	string name_input = "";
	int score_input = -1;

	while (name_input != "NoName" && score_input != 0)
	{
		cout << "Enter name and score: ";
		cin >> name_input >> score_input;
		cout << endl;

		bool unique_name = true;
		for (int i = 0; i < names.size(); i++)
		{
			if (name_input == names[i])
			{
				unique_name = false;
				break;
			}
		}

		if (unique_name)
		{
			names.push_back(name_input);
			scores.push_back(score_input);
		}
		else
		{
			cout << "Name already exists! Terminating input sequence." << endl;
			name_input = "NoName";
			score_input = 0;
		}
	}

	cout << "The full list: " << endl;
	for (int i = 0; i < names.size(); i++)
	{
		cout << names[i] << " " << scores[i] << endl;
	}
	cout << endl;

	string name_lookup = "";
	while (cin >> name_lookup)
	{
		bool success = false;
		for (int i = 0; i < names.size(); i++)
		{
			if (name_lookup == names[i])
			{
				success = true;
				cout << "Score: " << scores[i] << endl;
			}
		}
		if (!success)
			cout << "ERROR: No corresponding name." << endl;
	}
}