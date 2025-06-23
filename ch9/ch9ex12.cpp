#include "../PPP/PPP.h"

int main()
{
	ifstream ist{ "ch9/ex12.txt" };
	if (!ist)
		error("can't open file");

	vector<string> output;
	string word;
	while (ist>>word)
	{
		cout << word << endl;
		output.push_back(word);
	}

	ofstream ost{ "ch9/ex12-1.txt" };
	for (int i = output.size() - 1; i >= 0;i--)
	{
		ost << output[i] << endl;
	}
}