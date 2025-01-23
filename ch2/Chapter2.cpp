#include "../PPP/PPP.h"

//int main() // read name and age
//{
//	cout << "Please enter your first name and age\n";
//	string first_name = "???"; // string variable ("???" indicates "don’t know the name")
//	double age = -1; // integer variable (-1 means "don’t know the age")
//	cin >> first_name >> age; // read a string followed by an integer
//	// PERSONAL NOTE: If we ented invalid input in an int via std::cin, the int value defaults to 0.
//	// This change is introduced since C++ 11. The book is not updated: https://stackoverflow.com/questions/32378911/why-does-cin-expecting-an-int-change-the-corresponding-int-variable-to-zero-in
//	cout << "Hello, " << first_name << " (age in months " << age * 12 << ")\n";
//
//	return 0;
//}

//int main() // simple program to exercise operators
//{
//	cout << "Please enter a floating-point value: ";
//	int n = 0;
//	cin >> n;
//	cout << "n == " << n
//		<< "\nn+1 == " << n + 1
//		<< "\nthree times n == " << 3 * n
//		<< "\ntwice n == " << n + n
//		<< "\nn squared == " << n * n
//		<< "\nhalf of n == " << n / 2
//		<< "\nn%2 == " << n % 2
//		<< "\nsquare root of n == " << sqrt(n)
//		<< '\n'
//		<< '\n';
//
//	int a = 2;
//	int b = 4;
//	a << b;
//	cout << a << " " << b << '\n';
//}

//int main()
//{
//	string previous; // previous word; initialized to ""
//	string current; // current word
//	while (cin >> current) { // read a stream of words
//		if (previous == current) // check if the word is the same as last
//			cout << "repeated word: " << current << '\n';
//		previous = current;
//	}
//}

//int main()
//{
//	double d = 0;
//	while (cin >> d) { // repeat the statements below as long as we type in numbers
//		int i = d; // try to squeeze a floating-point value into an integer value
//		char c = i; // try to squeeze an integer into a char
//		cout << "d==" << d // the original double
//			<< " i==" << i // double converted to int
//			<< " c==" << c // int value of char
//			<< " char(" << c << ")\n"; // the char
//	}
//}

int main()
{
	string first_name = "????";
	int age = 0;

	cout << "Please enter your first name (followed by 'Enter'):\n";
	cin >> first_name;
	cout << "Please enter your age (followed by 'Enter'):\n";
	cin >> age;
	if (age <= 0 || age >= 110)
	{
		cout << "Error: you're kidding!\n";
		return 0;
	}
	cout << "\nDear " << first_name << ",\n\n";
	cout << "\tHow are you? I miss you.\n";
	if (age <= 12)
		cout << "Lorem Impsun sth sth sth sth. Next year you will be " << age + 1 << " years old\n";
	else if (age == 17)
		cout << "Lorem Impsun sth sth sth sth. Next year you will be able to vote!\n";
	else if (age >= 70)
		cout << "Are you retired?\n";

	cout << "\n\nYours sincerely,\nV.CH.";

}
