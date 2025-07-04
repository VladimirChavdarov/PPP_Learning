#pragma once
#include "../../PPP/PPP.h"

// calculate greatest common denominator of two numbers
int gcd(int a, int b)
{
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

class Rational
{
public:
    Rational() {};
    Rational(int numerator) : numer(numerator) {};
    Rational(int numerator, int denominator) : numer(numerator), denom(denominator)
    {
        normalize();
    };

    const int get_numer() const { return numer; }
    const int get_denom() const { return denom; }
    const double conv_double() const { return (double)numer / denom; }

    void normalize();

private:
    int numer = 0;
    int denom = 1;
};

// operators
Rational operator+(const Rational& r1, const Rational& r2);
Rational operator-(const Rational& r1, const Rational& r2);
Rational operator*(const Rational& r1, const Rational& r2);
Rational operator/(const Rational& r1, const Rational& r2);
bool operator==(const Rational& r1, const Rational& r2);
bool operator!=(const Rational& r1, const Rational& r2);
ostream& operator<<(ostream& os, const Rational& r);

Rational operator+(const Rational& r1, const Rational& r2)
{
    Rational r(r1.get_numer() * r2.get_denom() + r1.get_denom() * r2.get_numer(),
        r1.get_denom() * r2.get_denom());
    r.normalize();
    return r;
}

Rational operator-(const Rational& r1, const Rational& r2)
{
    Rational r(r1.get_numer() * r2.get_denom() - r1.get_denom() * r2.get_numer(),
        r1.get_denom() * r2.get_denom());
    r.normalize();
    return r;
}

Rational operator*(const Rational& r1, const Rational& r2)
{
    Rational r(r1.get_numer() * r2.get_numer(), r1.get_denom() * r2.get_denom());
    r.normalize();
    return r;
}

Rational operator/(const Rational& r1, const Rational& r2)
{
    Rational r(r1.get_numer() * r2.get_denom(), r1.get_denom() * r2.get_numer());
    r.normalize();
    return r;
}

bool operator==(const Rational& r1, const Rational& r2)
{
    return r1.get_numer() * r2.get_denom() == r1.get_denom() * r2.get_numer();
}

bool operator!=(const Rational& r1, const Rational& r2)
{
    return !(r1 == r2);
}

ostream& operator<<(ostream& os, const Rational& r)
{
    return cout << r.get_numer() << '/' << r.get_denom();
}

int main()
try {
    // constructors
    Rational r1;
    Rational r2(5);
    Rational r3(7, 3);
    cout << "r1: " << r1 << endl
        << "r2: " << r2 << endl
        << "r3: " << r3 << endl;

    // operators
    cout << "5/3 + 7/2 = " << Rational(5, 3) + Rational(7, 2) <<
        " = " << (Rational(5, 3) + Rational(7, 2)).conv_double() << endl;
    cout << "8/5 - 40/7 = " << Rational(8, 5) - Rational(40, 7) <<
        " = " << (Rational(8, 5) - Rational(40, 7)).conv_double() << endl;
    cout << "10/11 * 17/18 = " << Rational(10, 11) * Rational(17, 18) <<
        " = " << (Rational(10, 11) * Rational(17, 18)).conv_double() << endl;
    //cout << "5 / (0/3) = " << Rational(5) / Rational(0,3) << endl;
    cout << "(5/7) / (1/3) = " << Rational(5, 7) / Rational(1, 3) <<
        " = " << (Rational(5, 7) / Rational(1, 3)).conv_double() << endl;

    if (r1 == Rational(0, 1)) cout << "r1 == 0/1" << endl;
    if (Rational(1, 2) == Rational(2, 4)) cout << "1/2 == 2/4" << endl;
    if (r2 != r2) cout << "r2 != r2" << endl;

    cout << r3 << " = " << r3.conv_double() << endl;
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
}
catch (...) {
    cerr << "exception" << endl;
}

void Rational::normalize()
{
    if (denom == 0)
        error("Denominator cannot be 0!");

    if (denom < 0)
    {
        denom = -denom;
        numer = -numer;
    }

    int n = gcd(numer, denom);
    numer /= n;
    denom /= n;
}