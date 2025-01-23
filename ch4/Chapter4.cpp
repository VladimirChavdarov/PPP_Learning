#include "../PPP/PPP.h"

//int area(int length, int width); // calculate area of a rectangle
//int main()
//{
//	int x = area(2, 3);
//}


//int area(int length, int width)
//// calculate area of a rectangle
//{
//	return length * width;
//}
//int framed_area(int x, int y)
//// calculate area within frame
//{
//	return area(x-2, y-2);
//}
//void test(int x, int y, int z)
//{
//	int area1 = area(x, y);
//	int area2 = framed_area(1, z);
//	int area3 = framed_area(y, z);
//	double ratio = double(area1) / area3; // convert to double to get floating-point division
//	// ratio is "inf" because area3 is 0. Does	NOT throw a runtime-error.
//	// ...
//}
//
//int main()
//{
//	test(-1, 2, 3);
//}


//int area(int length, int width)
//// calculate area of a rectangle;
//// return -1 to indicate a bad argument
//{
//	if (length <= 0 || width <= 0)
//		return -1;
//	return length * width;
//}
//
//int framed_area(int x, int y)
//// calculate area within frame
//{
//	return area(x-2, y-2);
//}
//
//int f(int x, int y, int z)
//{
//	int area1 = area(x, y);
//	if (area1 <= 0)
//		error("non-positive area");
//	int area2 = framed_area(1, z);
//	int area3 = framed_area(y, z);
//	double ratio = double(area1) / area3;
//	// ...
//	cout << "area1: " << area1 << endl;
//	cout << "area2: " << area2 << endl;
//	cout << "area3: " << area3 << endl;
//	cout << "ratio: " << ratio << endl;
//
//	return 0;
//}
//
//int main()
//{
//	int x, y, z;
//	cin >> x >> y >> z;
//	f(x, y, z);
//}


//int main()
//{
//	vector<int> v(5);
//	int x = v[5];
//	/*int x = -10;
//	try
//	{
//		for (auto item : v)
//			cout << item << " ";
//		cout << endl;
//		x = v[5];
//		cout << "X in try block: " << x << endl;
//	}
//	catch (out_of_range)
//	{
//		cerr << "Catch in Chapter4.cpp, line 89: Range error!\n";
//	}
//	cout << x << endl;*/
//}


//int main()
//{
//	try
//	{
//		int a = 10;
//		if (a == 10)
//		{
//			error("I just don't like the number 10");
//		}
//	}
//	catch (exception& e)
//	{
//		cerr << "exception: " << e.what() << endl;
//		return 1;
//	}
//}



// ------------------------------
//           DRILLS
// ------------------------------
int main()
try {
	
	//1.
	//Cout << "Success!\n";
	//cout << "Success!\n";

	//2.
	//cout << "Success!\n;
	//cout << "Success!\n";

	//3.
	//cout << "Success" << !\n"
	//cout << "Success" << "!\n";

	//4.
	//cout << success << ’\n’;
	//cout << "success" << '\n';

	//5.
	//string res = 7;
	/*int res = 7;
	vector<int> v(10);
	v[5] = res;
	cout << "Success!\n";*/

	//6.
	/*vector<int> v(10);
	v(5) = 7;
	if (v(5) != 7)
		cout << "Success!\n";*/
	/*vector<int> v(10);
	v[5] = 7;
	if (v[5] == 7)
		cout << "Success!\n";*/

	//7.
	/*bool cond = true;
	if (cond)
		cout << "Success!\n";
	else
		cout << "Fail!\n";*/

	//8.
	//bool c = true;
	//if (c)
	//	cout << "Success!\n";
	//else
	//	cout << "Fail!\n";

	//9.
	/*string s = "ape";
	boo c = "fool" < s;
	if (c)
		cout << "Success!\n";*/
	/*string s = "ape";
	bool c = "fool" < s;
	if (!c)
		cout << "Success!\n";*/

	//10.
	/*string s = "ape";
	if (s == "fool")
		cout << "Success!\n";*/
	/*string s = "ape";
	if (s != "fool")
		cout << "Success!\n";*/

	//11.
	/*string s = "ape";
	if (s == "fool")
		cout < "Success!\n";*/
	/*string s = "ape";
	if (s != "fool")
		cout << "Success!\n";*/

	//12.
	/*string s = "ape";
	s += "fool";
	if (s == "apefool")
		cout << "Success!\n";*/

	//13.
	//vector<char> v(5);
	////for (int i = 0; 0 < v.size(); ++i);
	//for (int i = 0; i < v.size(); ++i) //empty loop?
	//	cout << "Success!\n";

	//14.
	//vector<char> v(5);
	////for (int i = 0; i <= v.size(); ++i);
	//for (int i = 0; i <= v.size(); ++i) //empty loop?
	//cout << "Success!\n";

	//15.
	//string s = "Success!\n";
	////for (int i = 0; i < 6; ++i)
	//for (int i = 0; i < s.size(); ++i)
	//	cout << s[i];

	//16.
	//if (true)
	//	//then cout << "Success!\n";
	//	cout << "Success!\n";
	//else cout << "Fail!\n";

	//17.
	/*int x = 2000;
	char c = (char)x;
	if (c == (char)2000)
		cout << "Success!\n";*/

	//18.
	/*string s = "Success!\n";
	for (int i = 0; i < s.size(); ++i)
		cout << s[i];*/

	//19.
	//vector<int> v(5);
	//for (int i = 0; i <= v.size(); ++i); //empty loop?
	//	cout << "Success!\n";

	//20.
	/*int i = 0;
	int j = 9;
	while (i < 10)
		++i;
	if (j < i)
		cout << "Success!\n";*/

	//21.
	/*int x = 2;
	double d = 5 / (x-2); // 0 division
	if (d == 2 * x + 0.5)
		cout << "Success!\n";*/
	//int x = 2;
	//double d = (double)5 / x;
	//if (d == x + 0.5)
	//	cout << "Success!\n";

	//22.
	/*string s = "Success!\n";
	for (int i = 0; i <s.size(); ++i)
		cout << s[i];*/

	//23.
	//int i = 0;
	//int j = 9;
	//while (i < 10)
	//	++i;
	//if (j < i)
	//	cout << "Success!\n";

	//24.
	/*int x = 4;
	double d = (double)5 / (x-2);
	if (d == x / 2 + 0.5)
		cout << "Success!\n";*/

	//25.
	//cin << "Success!\n";
	cout << "Success!\n";

	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	return 2;
}

int Interest()