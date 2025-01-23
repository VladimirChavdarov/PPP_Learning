#include "../PPP/PPP.h"

double ConvertCurrency(double amount, double in_currency_per_gold, double out_currency_per_gold)
{
	return (amount * in_currency_per_gold) / out_currency_per_gold;
}

double ConvertMeasurements(double measure, double in_unit_to_mm)
{
	return measure * in_unit_to_mm;
}

bool IsWordAllowed(string word, const vector<string>& blacklist)
{
	for (string blacklist_word : blacklist)
	{
		if (word == blacklist_word)
			return false;
	}
	return true;
}

bool AlmostEqual(double a, double b, double tolerance = 0.01)
{
	return abs(a - b) < tolerance;
}

int main()
{
	//----------------------------
	// convert from inches to centimeters or centimeters to inches
	// a suffix ’i’ or ’c’ indicates the unit of the input
	//constexpr double cm_per_inch = 2.54; // number of centimeters in an inch
	//double length = 1; // length in inches or centimeters
	//char unit = ' ';
	//cout << "Please enter a length followed by a unit (c or i):\n";
	//cin >> length >> unit;

	//if (unit == 'i')
	//	cout << length << "in == " << length * cm_per_inch << "cm\n";
	//else if (unit == 'c')
	//	cout << length << "cm == " << length / cm_per_inch << "in\n";
	//else
	//	cout << "Sorry, I don't know a unit called '" << unit << "'\n";


	//--------------------------------
	/*constexpr double yen_per_krone = 0.072;
	double amount = 1;
	char currency = ' ';
	cout << "Please enter an amount followed by currency (y or k):\n";
	cin >> amount >> currency;

	if (currency == 'y')
		cout << amount << " yen == " << amount * yen_per_krone << "krone\n";
	else if (currency == 'k')
		cout << amount << " krone == " << amount / yen_per_krone << "yen\n";
	else
		cout << "Sorry, I don't know a unit called '" << currency << "'\n";*/


	//--------------------------------
	//// yen, krone, lev, dollar, franc
	//constexpr double yen_per_gold = 0.000002365323563;
	//constexpr double krone_per_gold = 0.000032783009832;
	//constexpr double lev_per_gold = 0.000196867106165;
	//constexpr double dollar_per_gold = 0.0003735552;
	//constexpr double franc_per_gold = 0.000408988784469;

	//double amount = 1;
	//char currency = ' ';
	//cout << "Please enter an amount followed by currency (y, k, l, d, f):\n";
	//cin >> amount >> currency;
	//
	//switch (currency)
	//{
	//case 'y':
	//	cout << amount << " yen == " << ConvertCurrency(amount, yen_per_gold, krone_per_gold) << " krone\n";
	//	cout << amount << " yen == " << ConvertCurrency(amount, yen_per_gold, lev_per_gold) << " lev\n";
	//	cout << amount << " yen == " << ConvertCurrency(amount, yen_per_gold, dollar_per_gold) << " dollar\n";
	//	cout << amount << " yen == " << ConvertCurrency(amount, yen_per_gold, franc_per_gold) << " franc\n";
	//	break;
	//case 'k':
	//	cout << amount << " krone == " << ConvertCurrency(amount, krone_per_gold, yen_per_gold) << " yen\n";
	//	cout << amount << " krone == " << ConvertCurrency(amount, krone_per_gold, lev_per_gold) << " lev\n";
	//	cout << amount << " krone == " << ConvertCurrency(amount, krone_per_gold, dollar_per_gold) << " dollar\n";
	//	cout << amount << " krone == " << ConvertCurrency(amount, krone_per_gold, franc_per_gold) << " franc\n";
	//	break;
	//case 'l':
	//	cout << amount << " lev == " << ConvertCurrency(amount, lev_per_gold, yen_per_gold) << " yen\n";
	//	cout << amount << " lev == " << ConvertCurrency(amount, lev_per_gold, krone_per_gold) << " krone\n";
	//	cout << amount << " lev == " << ConvertCurrency(amount, lev_per_gold, dollar_per_gold) << " dollar\n";
	//	cout << amount << " lev == " << ConvertCurrency(amount, lev_per_gold, franc_per_gold) << " franc\n";
	//	break;
	//case 'd':
	//	cout << amount << " dollar == " << ConvertCurrency(amount, dollar_per_gold, yen_per_gold) << " yen\n";
	//	cout << amount << " dollar == " << ConvertCurrency(amount, dollar_per_gold, krone_per_gold) << " krone\n";
	//	cout << amount << " dollar == " << ConvertCurrency(amount, dollar_per_gold, lev_per_gold) << " lev\n";
	//	cout << amount << " dollar == " << ConvertCurrency(amount, dollar_per_gold, franc_per_gold) << " franc\n";
	//	break;
	//case 'f':
	//	cout << amount << " franc == " << ConvertCurrency(amount, franc_per_gold, yen_per_gold) << " yen\n";
	//	cout << amount << " franc == " << ConvertCurrency(amount, franc_per_gold, krone_per_gold) << " krone\n";
	//	cout << amount << " franc == " << ConvertCurrency(amount, franc_per_gold, lev_per_gold) << " lev\n";
	//	cout << amount << " franc == " << ConvertCurrency(amount, franc_per_gold, dollar_per_gold) << " dollar\n";
	//	break;
	//default:
	//	cout << "Currency not recognized!\n";
	//	break;
	//}


	//-------------------------------
	//int i = 0; // start from 0
	//char letter = 'a';
	//while (i < 26) {
	//	cout << letter << '\t' << (int)letter << '\n';
	//	++i; // increment i (that is, i becomes i+1)
	//	letter = char('a'+i);
	//}


	//-------------------------------
	// Same output
	//for (int i = 0; i < 10; i++)
	//	cout << i << endl;
	//cout << endl;
	//for (int i = 0; i < 10; ++i)
	//	cout << i << endl;


	//-------------------------------
	//char s_letter = 'a';
	//char c_letter = 'A';
	//for (int i = 0; i < 26; i++)
	//{
	//	cout << s_letter << '\t' << (int)s_letter << '\n';
	//	s_letter = char(s_letter + 1);
	//}
	//for (int i = 0; i < 26; i++)
	//{
	//	cout << c_letter << '\t' << (int)c_letter << '\n';
	//	c_letter = char(c_letter + 1);
	//}


	//-----------------------------------------
	//vector<string> words;
	//for (string temperature; cin >> temperature;)
	//	words.push_back(temperature);
	//cout << "NUmber of words: " << words.size() << '\n';
	//
	//ranges::sort(words);

	//for (int i = 0; i < words.size(); i++)
	//{
	//	if (i == 0 || words[i - 1] != words[i])
	//		cout << words[i] << "\n";
	//}


	//------------------------------------------
	//vector<string> disliked = { "ball", "hell", "apple" };
	//vector<string> dictionary;
	//for (string word; cin >> word;)
	//{
	//	dictionary.push_back(word);
	//}

	//ranges::sort(dictionary);

	//for (int i = 0; i < dictionary.size(); i++)
	//{
	//	if (i == 0 || dictionary[i - 1] != dictionary[i])
	//	{
	//		if (IsWordAllowed(dictionary[i], disliked))
	//			cout << dictionary[i] << "\n";
	//		else
	//			cout << "BLEEP" << endl;
	//	}
	//}

	
	// ------------------------------------
	// DRILLS
	// -----------------------------------
	
	// 1.
	//int a = 0, b = 0;
	//while (cin >> a >> b)
	//{
	//	cout << a << " " << b << endl;
	//}

	// 2. and 3.
	//int a = 0, b = 0;
	//while (cin >> a >> b)
	//{
	//	if (a < b)
	//	{
	//		cout << "Smaller value is: " << a << endl;
	//		cout << "Larger value is: " << b << endl;
	//	}
	//	else if (a > b)
	//	{
	//		cout << "Smaller value is: " << b << endl;
	//		cout << "Larger value is: " << a << endl;
	//	}
	//	else
	//		cout << "Values are equal" << endl;
	//}

	// 4. and 5.
	//double a = 0, b = 0;
	//while (cin >> a >> b)
	//{
	//	if (a < b)
	//	{
	//		cout << "Smaller value is: " << a << endl;
	//		cout << "Larger value is: " << b << endl;
	//		if (AlmostEqual(a, b))
	//			cout << "Numbers are almost equal" << endl;
	//	}
	//	else if (a > b)
	//	{
	//		cout << "Smaller value is: " << b << endl;
	//		cout << "Larger value is: " << a << endl;
	//		if (AlmostEqual(a, b))
	//			cout << "Numbers are almost equal" << endl;
	//	}
	//	else
	//		cout << "Values are equal" << endl;
	//}

	// 6. and 7. and 8. and 9. and 10. and 11.
	double mm_to_cm = 10;
	double mm_to_m = 1000;
	double mm_to_in = 25.4000137160025794;
	double mm_to_ft = 304.80016459203096701;

	double smallest = 99999999999999999999999.0;
	double largest = -999999999999999999999999.0;
	double sum = 0.0;
	int count = 0;
	vector<double> entries;

	double input = 0.0;
	double input_in_mm = 0.0;
	string unit = "";

	while(cin>>input>>unit)
	{
		if (unit == "cm")
			input_in_mm = ConvertMeasurements(input, mm_to_cm);
		else if (unit == "m")
			input_in_mm = ConvertMeasurements(input, mm_to_m);
		else if (unit == "in")
			input_in_mm = ConvertMeasurements(input, mm_to_in);
		else if (unit == "ft")
			input_in_mm = ConvertMeasurements(input, mm_to_ft);
		else
		{
			cout << "Unit not recognized!" << endl;
			continue;
		}

		count++;
		sum += input_in_mm;
		entries.push_back(input_in_mm / 1000.0f);

		if (input_in_mm < smallest)
		{
			smallest = input_in_mm;
			cout << "Smallest so far: " << input << unit << endl;
		}
		if(input_in_mm > largest)
		{
			largest = input_in_mm;
			cout << "Largest so far: " << input << unit << endl;
		}
	}

	ranges::sort(entries);

	cout << "\n--- Final Result ---\n";
	cout << "Smallest Measure: " << smallest / 1000.0 << "meters" << endl;
	cout << "Largest Measure: " << largest / 1000.0 << "meters" << endl;
	cout << "Number of valid inputs: " << count << endl;
	cout << "Sum: " << sum / 1000.0 << "meters" << endl;
	cout << "History (in meters): ";
	for (double entry : entries)
		cout << entry << ", ";
}