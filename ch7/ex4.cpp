#include "../PPP/PPP.h"

namespace ch7
{

	int max_int_approximation()
	{
		int result = 0;
		int cnt = 2;
		vector<int> vec{ 1, 2 }; // first two numbers from the fibonacci sequence
		while (vec.back() > 0)
		{
			result = vec.back();
			int new_num = vec[cnt - 2] + vec[cnt - 1];
			vec.push_back(new_num);
			cnt++;
		};

		return result;
	}

}

int main()
{
	int result = ch7::max_int_approximation();
	cout << result << endl;
}