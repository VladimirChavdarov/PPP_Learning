#include "../PPP/PPP.h"

int main()
{
	vector<char> punctuation = {'.', ',', ';', '?', '-', '\'',};
	string input = "-don't use the as-if rule.";

	for (char& symbol : punctuation)
	{
		replace(input.begin(), input.end(), symbol, ' ');
	}
	cout << input << endl;
}