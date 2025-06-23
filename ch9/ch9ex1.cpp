#include "../PPP/PPP.h"

void tolower(string& s)
{
	for (char& c : s)
	{
		c = tolower(c);
	}
}

int main()
{
	ifstream ist{ "ch9/ex1.txt" };
	if (!ist)
		error("can't open file");

	vector<string> lowercase_file;
	string line;
	while (getline(ist, line))
	{
		tolower(line);
		lowercase_file.push_back(line);
	}

	ofstream ost{ "ch9/ex1-1.txt" };
	for (string& line : lowercase_file)
	{
		ost << line<< endl;
	}
}