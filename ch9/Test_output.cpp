#include "../PPP/PPP.h"

//struct PersonalInfo
//{
//	string first_name;
//	string last_name;
//	string phone_number;
//	string email;
//};

struct point
{
	float x;
	float y;
};

ostream& operator<<(ostream& os, const point& p)
{
	return os << '(' << p.x << ',' << p.y << ')';
}

istream& operator>>(istream& is, point& p)
{
	float x, y;
	char c1, c2, c3;
	is >> c1 >> x >> c2 >> y >> c3;
	if (!is)
		return is;
	if (c1 != '(' || c2 != ',' || c3 != ')') // format error
	{
		is.clear(ios::failbit);
		return is;
	}
	p = { x, y };
	return is;
}

int main()
{
	/*int birth_year = 2002;
	int age = 23;
	cout << "\t" << dec << birth_year << " - " << dec << birth_year << endl;
	cout << "\t" << dec << birth_year << " - " << hex << birth_year << endl;
	cout << "\t" << dec << birth_year << " - " << oct << birth_year << endl;
	cout << "\t" << dec << age << endl;*/

	/*int a, b, c, d;
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';*/

	/*float n = 1234567.89f;
	cout << "defaultfloat: " << defaultfloat << n << endl;
	cout << "fixed: " << fixed << n << endl;
	cout << "scientific: " << scientific << n << endl;*/

	/*PersonalInfo test1 = { "Vladimir", "Chavdarov", "4543765630", "vlad.chav@gmail.com" };
	PersonalInfo test2 = { "Irena", "Vasileva", "4543765630", "ir.v@gmail.com" };
	PersonalInfo test3 = { "Vasil", "Donkov", "4543765630", "vasil.donkov@gmail.com" };
	PersonalInfo test4 = { "Dimitar", "Kalpakchiev", "4543765630", "dim.kalpakchiev@gmail.com" };
	PersonalInfo test5 = { "Anton", "Siromahov", "4543765630", "aonton.s@gmail.com" };
	cout << setw(16) << "First Name" <<  "\t" << setw(16) << "Last Name" << "\t" << setw(12) << "Phone Number" << "\t" << setw(30) << "Email" << endl;
	cout << setw(16) << test1.first_name << "\t" << setw(16) << test1.last_name << "\t" << setw(12) << test1.phone_number << "\t" << setw(30) << test1.email << endl;
	cout << setw(16) << test2.first_name << "\t" << setw(16) << test2.last_name << "\t" << setw(12) << test2.phone_number << "\t" << setw(30) << test2.email << endl;
	cout << setw(16) << test3.first_name << "\t" << setw(16) << test3.last_name << "\t" << setw(12) << test3.phone_number << "\t" << setw(30) << test3.email << endl;
	cout << setw(16) << test4.first_name << "\t" << setw(16) << test4.last_name << "\t" << setw(12) << test4.phone_number << "\t" << setw(30) << test4.email << endl;
	cout << setw(16) << test5.first_name << "\t" << setw(16) << test5.last_name << "\t" << setw(12) << test5.phone_number << "\t" << setw(30) << test5.email << endl;*/

	/*point p;
	cin >> p;
	cout << p << endl;*/

	vector<point> original_points;
	for (int i = 0; i < 7; i++)
	{
		point p;
		cin >> p;
		original_points.push_back(p);
	}
	for (int i = 0; i < 7; i++)
	{
		cout << original_points[i] << endl;
	}
}