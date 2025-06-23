#include "../PPP/PPP.h"

int main()
{
	string filename = "ch9/ex11-1.txt";
	vector<string> output;

	ifstream ist{ filename };
	string line;
	while (getline(ist, line))
	{
		reverse(line.begin(), line.end());
		output.push_back(line);
	}

	ofstream ost{ "ch9/ex11-2.txt" };
	for (string& line : output)
	{
		ost << line << endl;
	}
}