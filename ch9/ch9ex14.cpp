#include "../PPP/PPP.h"

int main()
{
	ifstream ist{ "ch9/ex14.txt" };
	if (!ist)
		error("can't open file");

	float number;
	int cnt = 0;
	while (ist >> number)
	{
		cnt++;

		cout << std::format("{:20.8e}", number);

		//double d = number;
		//cout << format("- {:12} - {:12.8f} - {:30.20e} -\n", d, d, d);

		if (cnt % 4 == 0)
			cout << '\n';
	}
}