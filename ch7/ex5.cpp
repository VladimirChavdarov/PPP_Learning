#include "../PPP/PPP.h"

vector<int> reverse_copy(const vector<int>& in_vec)
{
	vector<int> result;
	for (int i = in_vec.size() - 1; i >= 0; i--)
	{
		result.push_back(in_vec[i]);
	}
	return result;
}

void reverse_overwrite(vector<int>& vec_to_reverse)
{
	for (int i = 0; i < vec_to_reverse.size() / 2; ++i)
	{
		int opposite_index = vec_to_reverse.size() - 1 - i;
		std::swap(vec_to_reverse[i], vec_to_reverse[opposite_index]);
	}
}

int main()
{
	vector<int> in_vec1 = { 1, 2, 3, 4, 5 };
	vector<int> out_vec1 = reverse_copy(in_vec1);
	for (auto item : out_vec1)
		cout << item << " ";
	cout << endl << endl;

	vector<int> in_vec2 = {6, 7, 8, 9, 10};
	reverse_overwrite(in_vec2);
	for (auto item : in_vec2)
		cout << item << " ";
	cout << endl;
}