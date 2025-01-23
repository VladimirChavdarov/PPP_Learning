#include "../PPP/PPP.h"

double FahrenheitToCelsius(double f) // converts Celsius to Kelvin
{
	if (f < -459.67)
		error("Temperature is below absolute zero. Cannot be lower than -273.15 Celsius.");
	double c = (f - 32.0) * 5.0 / 9.0;
	return c;
}
double CelsiusToFahrenheit(double c) // converts Celsius to Kelvin
{
	if (c < -273.15)
		error("Temperature is below absolute zero. Cannot be lower than -459.67 Fahrenheit.");
	double f = (c * 9.0 / 5.0) + 32.0;
	return f;
}
int main()
{
	double c = 0; // declare input variable
	cin >> c; // retrieve temperature to input variable
	double k = CelsiusToFahrenheit(c); // convert temperature
	cout << k << '\n'; // print out temperature
	// cout << k << '/n';
	// this is equivalent to cout << (k << '/' << 'n');
	// The three values get bit-shifted, resulting in a logical error
}