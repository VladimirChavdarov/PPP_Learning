//#pragma once
//#include "../PPP/PPP.h"
//
//struct Year
//{
//	Year()
//	{
//
//	}
//	int y = 0;
//};
//
//enum class Month
//{
//	jan = 1, feb, mar, apr, may, jun, jul, aug, oct, nov, dec
//};
//
//Month operator++(Month& m) // prefix increment operator
//{
//	m = (m == Month::dec) ? Month::jan : Month{ int(m) + 1 }; // "wrap around"
//	return m;
//}
//
//ostream& operator<<(ostream& os, Date d)
//{
//	return os << d.year() << '/' << d.month() << '/' << d.day();
//}
//
//class Date
//{
//public:
//	class Invalid {}; // to be used as exception
//	
//	Date(int yyyy, int mm, int dd);
//	Date();
//
//	bool is_valid();
//
//	void add_day(int n);
//	inline int day() { return m_day; }
//	inline int month() { return m_month; }
//	inline int year() { return m_year; }
//
//
//private:
//	int m_year, m_month, m_day;
//};