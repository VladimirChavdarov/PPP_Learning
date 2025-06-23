//#include "Date.h"
//
//Date::Date(int yyyy, int mm, int dd)
//	: m_year{ yyyy }, m_month{ mm }, m_day{ dd }
//{
//	if (!is_valid())
//		throw Invalid{};
//}
//
//Date::Date()
//	: m_year{ 2000 }, m_month{ 1 }, m_day{ 1 }
//{
//	if (!is_valid())
//		throw Invalid{};
//}
//
//bool Date::is_valid()
//{
//	if (m_month < 1 || m_month > 12)
//		return false;
//
//	return true;
//}
//
//void Date::add_day(int n)
//{
//
//}
