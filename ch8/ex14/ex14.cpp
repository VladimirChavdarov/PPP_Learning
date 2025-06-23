#pragma once
#include "../../PPP/PPP.h"

long int true_round(double d)
{
	// using implicit double-int conversion.
	return (d > 0.0) ? (d + 0.5) : (d - 0.5);
}

class Money
{
public:
	enum class Currency { USD, CHF, KYD };

	Money() {};
	Money(long int fraction) : cents(fraction) {};
	Money(int full_currency, int fraction) : cents(full_currency * 100 + fraction) { if (fraction >= 100) error("Fraction must be between 0 and 99!"); };
	Money(Currency cur) : cur(cur) {};
	Money(int fraction, Currency cur) : cents(fraction), cur(cur) {};
	Money(int full_currency, int fraction, Currency cur) : cents(full_currency * 100 + fraction), cur(cur) { if (fraction >= 100) error("Fraction must be between 0 and 99!"); };

	const int GetFull() const { return cents / 100; }
	const int GetFraction() const { return cents % 100; }
	const long int GetTotalInFractions() const { return cents; }
	const Currency GetCurrency() const { return cur; }

private:
	long int cents = 0;
	Currency cur = Currency::USD;
};

// one unit of c2 is worth how many units of c1?
double exch_rate(Money::Currency c1, Money::Currency c2)
{
    switch (c1) {
    case Money::Currency::USD:
        switch (c2) {
        case Money::Currency::CHF:
            return 1.11;
        case Money::Currency::KYD:
            return 1.22;
        default:
            error("exch_rate: illegal combination of currencies");
        }
    case Money::Currency::CHF:
        switch (c2) {
        case Money::Currency::USD:
            return 0.91;
        case Money::Currency::KYD:
            return 1.1;
        default:
            error("exch_rate: illegal combination of currencies");
        }
    case Money::Currency::KYD:
        switch (c2) {
        case Money::Currency::USD:
            return 0.82;
        case Money::Currency::CHF:
            return 0.91;
        default:
            error("exch_rate: illegal combination of currencies");
        }
    default:
        error("exch_rate: illegal combination of currencies");
    }
}

Money operator+(const Money& a, const Money& b)
{
    if (a.GetCurrency() == b.GetCurrency())
        return Money(a.GetTotalInFractions() + b.GetTotalInFractions(), a.GetCurrency());

    double d = exch_rate(a.GetCurrency(), b.GetCurrency());

    return Money(a.GetTotalInFractions() + true_round(d * double(b.GetTotalInFractions())), a.GetCurrency());
}

Money operator-(const Money& a, const Money& b)
{
    if (a.GetCurrency() == b.GetCurrency())
        return Money(a.GetTotalInFractions() - b.GetTotalInFractions(), a.GetCurrency());

    double d = exch_rate(a.GetCurrency(), b.GetCurrency());

    return Money(a.GetTotalInFractions() - true_round(d * double(b.GetTotalInFractions())), a.GetCurrency());
}

Money operator-(const Money& a)
{
    return Money(-a.GetTotalInFractions(), a.GetCurrency());
}

Money operator*(int n, const Money& m)
{
    return Money(n * m.GetTotalInFractions(), m.GetCurrency());
}

Money operator*(const Money& m, int n)
{
    return n * m;
}

Money operator/(const Money& m, int n)
{
    if (n == 0)
        error("division by zero");
    double d = double(m.GetTotalInFractions()) / n;
    long int c = true_round(d);
    return Money(c, m.GetCurrency());
}

ostream& operator<<(ostream& os, const Money::Currency& cur)
{
    switch (cur) {
    case Money::Currency::USD:
        return os << "USD";
    case Money::Currency::CHF:
        return os << "CHF";
    case Money::Currency::KYD:
        return os << "KYD";
    }
}

ostream& operator<<(ostream& os, const Money& m)
{
    os << m.GetCurrency() << m.GetFull() << '.';
    if (abs(m.GetFraction()) < 10)
        os << '0';
    os << abs(m.GetFraction());
    return os;
}

istream& operator>>(istream& is, Money& m)
{
    string s;
    int d;
    char ch;
    int c;
    is >> s >> d >> ch >> c;
    if (!is) return is;
    if (!(s == "USD" || s == "CHF" || s == "KYD") || ch != '.')
    {
        is.clear(ios_base::failbit);                    // set the fail bit
        return is;
    }

    Money::Currency cur;
    if (s == "USD") cur = Money::Currency::USD;
    else if (s == "CHF") cur = Money::Currency::CHF;
    else if (s == "KYD") cur = Money::Currency::KYD;
    else error("illegal currency in input");
    m = Money(d, (c < 10) ? (10 * c) : c, cur);   // '123.1' means '123.10' and not '123.01'
    return is;
}

int main()
try {
    Money m1;
    Money m2(105);
    Money m3(5, 12);

    cout << "m1: " << m1 << endl;
    cout << "m2(105): " << m2 << endl;
    cout << "m3(5,12): " << m3 << endl;
    cout << "-m3: " << -m3 << endl;

    //Money m5;
    //cout << "Enter amount as in CUR xxx.xx: ";
    //cin >> m5;
    //cout << "You entered " << m5 << endl;

    cout << m2 << " + " << m3 << " = " << m2 + m3 << endl;
    cout << m2 << " - " << m3 << " = " << m2 - m3 << endl;
    cout << "5 * " << m2 << " = " << 5 * m2 << endl;
    cout << m2 << " * 5 = " << m2 * 5 << endl;

    cout << m3 << " - " << m2 << " = " << m3 - m2 << endl;

    cout << Money(1, 0) << " / 7 = " << Money(1, 0) / 7 << endl;
    cout << Money(0, 9) << " / 6 = " << Money(0, 9) / 6 << endl << endl;

    m1 = Money(7, 12, Money::Currency::USD);
    m2 = Money(100, 5, Money::Currency::CHF);
    m3 = Money(55, 12, Money::Currency::KYD);
    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;
    cout << "m3 = " << m3 << endl << endl;
    cout << m1 << " + " << m2 << " = " << m1 + m2 << endl;
    cout << m1 << " + " << m3 << " = " << m1 + m3 << endl;
    cout << m2 << " + " << m1 << " = " << m2 + m1 << endl;
    cout << m2 << " + " << m3 << " = " << m2 + m3 << endl;
    cout << m3 << " + " << m1 << " = " << m3 + m1 << endl;
    cout << m3 << " + " << m2 << " = " << m3 + m2 << endl;
    cout << m3 << " - " << m2 << " = " << m3 - m2 << endl;
    cout << 3 << " * " << m2 << " = " << 3 * m2 << endl;
    cout << m3 << " / " << 17 << " = " << m3 / 17 << endl;

}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception\n";
}