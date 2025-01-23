#include "../PPP/PPP.h"

int main()
{
	vector<string> sequence;
	string input = "";

	while (cin >> input)
	{
		sequence.push_back(input);
	}

	ranges::sort(sequence);

	vector<string> value;
	vector<int> value_count;

	for (int i = 0; i < sequence.size(); i++)
	{
		bool new_value = true;
		if (value.empty())
		{
			value.push_back(sequence[i]);
			value_count.push_back(1);
			continue;
		}
		for (int j = 0; j < value.size(); j++)
		{

			if (sequence[i] == value[j])
			{
				value_count[j]++;
				new_value = false;
			}
		}
		if (new_value)
		{
			value.push_back(sequence[i]);
			value_count.push_back(1);
		}
	}

	cout << "Sequence: ";
	for (int i = 0; i < sequence.size(); i++)
		cout << sequence[i] << ", ";
	cout << endl << endl;

	cout << "Value: ";
	for (int i = 0; i < value.size(); i++)
		cout << value[i] << ", ";
	cout << endl << endl;

	cout << "Count: ";
	for (int i = 0; i < value_count.size(); i++)
		cout << value_count[i] << ", ";
	cout << endl << endl;

	int max_count = -1;
	int max_count_index = -1;
	for (int i = 0; i < value_count.size(); i++)
	{
		if (max_count < value_count[i])
		{
			max_count = value_count[i];
			max_count_index = i;
		}
	}

	cout << "Min value (word): " << sequence.front() << endl;
	cout << "Max value (word): " << sequence.back() << endl;
	cout << "The most repeated word was " << value[max_count_index] << ". It was repeated " << max_count << " times." << endl;
}