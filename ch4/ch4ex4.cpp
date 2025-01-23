#include "../PPP/PPP.h"

double CelciusToKelvin(double c) // converts Celsius to Kelvin
{
	if (c < -273.15)
		error("Temperature is below absolute zero. Cannot be lower than -273.15 Celsius.");
	double k = c + 273.25;
	return k;
}
double KelvinToCelcius(double k)
{
	if(k < 0)
		error("Temperature is below absolute zero. Cannot be lower than 0 Kelvin.");
	double c = k - 273.25;
	return c;
}
int main()
{
	double k = 0; // declare input variable
	cin >> k; // retrieve temperature to input variable
	double c = KelvinToCelcius(k); // convert temperature
	cout << c << '/n'; // print out temperature
}