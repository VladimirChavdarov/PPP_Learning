#include "../PPP/PPP.h"

// https://stackoverflow.com/questions/3418231/replace-part-of-a-string-with-another-string
void replace_all(string& str, const string& from, const string& to) {
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
	}
}

vector<string> split(const string& s)
{
	vector<string> result;
	istringstream iss{ s };
	for (string word; iss >> word;)
		result.push_back(word);
	
	return result;
}

vector<string> split(const string& s, const string& w)
{
	vector<string>result;
	
	// replace whitespaces with ' '.
	string whitespace = " ";
	whitespace += w;
	string s_copy = s;
	replace_all(s_copy, whitespace, " ");
	//	
	
	result = split(s_copy);
	return result;
}

int main()
{
	string input = " athis ais aa atest";
	vector<string> output;

	output = split(input, "a");
	for(auto& word : output)
		cout << word << endl;
}