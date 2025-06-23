#include "../PPP/PPP.h"

void convert_to_decimal(const string& s, int& result, string& format)
{
	int base = 0;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
	{
		format = "hexadecimal";
		base = 16;
		//cout << "hex" << endl;
	}
	else if (s[0] == '0' && s[1] != 'x' && s[1] != 'X')
	{
		format = "octal";
		base = 8;
		//cout << "oct" << endl;
	}
	else
	{
		format = "decimal";
		base = 10;
		//cout << "dec" << endl;
	}
	result = std::stoi(s, nullptr, base);
}

int main()
{
	vector<string> raw_input;
	vector<string> format_input;
	vector<int> dec_input;
	string number;
	string format;
	int decimal_input;
	for (int i = 0; i < 5; i++)
	{
		cin >> number;
		convert_to_decimal(number, decimal_input, format);
		raw_input.push_back(number);
		format_input.push_back(format);
		dec_input.push_back(decimal_input);
	}

	for (int i = 0; i < raw_input.size(); i++)
	{
		cout << raw_input[i] << "\t" << format_input[i] << "\t" << "converts to" << "\t" << dec_input[i] << "\t" << "decimal" << endl;
	}
}