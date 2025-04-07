#include "../PPP/PPP.h"

void string_swap(string& s1, string& s2)
{
	string temp = s1;
	s1 = s2;
	s2 = temp;
}

vector<string> reverse_copy(const vector<string>& in_vec)
{
	vector<string> result;
	for (int i = in_vec.size() - 1; i >= 0; i--)
	{
		result.push_back(in_vec[i]);
	}
	return result;
}

void reverse_overwrite(vector<string>& vec_to_reverse)
{
	for (int i = 0; i < vec_to_reverse.size() / 2; ++i)
	{
		int opposite_index = vec_to_reverse.size() - 1 - i;
		string_swap(vec_to_reverse[i], vec_to_reverse[opposite_index]);
	}
}

int main()
{
	vector<string> in_vec1 = { "az", "buki", "vedi", "glagoli", "dobro"};
	vector<string> out_vec1 = reverse_copy(in_vec1);
	for (int i = 0; i < out_vec1.size(); i++)
		cout << out_vec1[i] << " ";
	cout << endl << endl;

	vector<string> in_vec2 = { "est", "zhivete", "dzelo", "zemlya", "izhe" };
	reverse_overwrite(in_vec2);
	for (int i = 0; i < in_vec2.size(); i++)
		cout << in_vec2[i] << " ";
	cout << endl;
}