#include "../PPP/PPP.h"

double CelciusToKelvin(double c) // converts Celsius to Kelvin
{
	double k = c + 273.25;
	return k;
}
int main()
{
	double c = 0; // declare input variable
	cin >> c; // retrieve temperature to input variable
	if (c < -273.15)
		error("Temperature is below absolute zero. Cannot be lower than -273.15 Celsius.");
	double k = CelciusToKelvin(c); // convert temperature
	cout << k << '/n'; // print out temperature
}