#include "../PPP/PPP.h"

namespace ch7
{

	void print(const string& label, const vector<int>& vec)
	{
		std::cout << label << ": ";
		for (int i = 0; i < vec.size(); i++)
		{
			if (i != 0)
				cout << ", ";
			cout << vec[i]; // checked_vector gives weird output if I don't comment out its cerr...
		}
		cout << endl;
	}

	void fibonacci(int a, int b, vector<int>& vec, int n)
	{
		vec.push_back(a);
		vec.push_back(b);
		
		for (int i = 2; i < n; i++)
		{
			int new_num = vec[i - 2] + vec[i - 1];
			vec.push_back(new_num);
		}
	}

}

int main()
{
	vector<int> in_vec;

	ch7::fibonacci(1, 2, in_vec, 13);
	ch7::print("my_vector", in_vec);
}