#include "../PPP/PPP.h"

int main()
{
	string s = "";
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << "\t" << (int)s[i] << endl;
	}
}