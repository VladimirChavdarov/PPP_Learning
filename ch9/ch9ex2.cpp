#include "../PPP/PPP.h"

int main()
{
	string word = "test";
	string filename = "ch9/ex2.txt";

	ifstream ist{ filename };
	string line;
	int cnt = 0;
	while (getline(ist, line))
	{
		cnt++;
		if (line.find(word) != string::npos)
		{
			cout << cnt << ") " << line << endl;
		}
	}
}