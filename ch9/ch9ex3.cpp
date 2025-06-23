#include "../PPP/PPP.h"


int main()
{
	vector<char> vowels{ 'a', 'e', 'i', 'o', 'u' };

	ifstream ist{ "ch9/ex3.txt" };
	string line;
	while (getline(ist, line))
	{
		for (char& vowel : vowels)
		{
			line.erase(std::remove(line.begin(), line.end(), vowel), line.end());
		}
		cout << line << endl;
	}
}