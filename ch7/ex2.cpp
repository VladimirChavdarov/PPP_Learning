#include "../PPP/PPP.h"

namespace ch7
{

void print(const string& label, const vector<int>& vec)
{
	std::cout << label <<": ";
	for (int i = 0; i < vec.size(); i++)
	{
		if (i != 0)
			cout << ", ";
		cout << vec[i]; // checked_vector gives weird output if I don't comment out its cerr...
	}
	cout << endl;
}

}

int main()
{
	vector<int> in_vec = { 1,2, 4, 65, 6 };
	ch7::print("my_vector", in_vec);
}