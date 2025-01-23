#include "../PPP/PPP.h"

int main()
{
	int total_squares = 64;
	unsigned long long rice_grains = 0;
	int square_value = 1;
	//ool thousand_reached = false, million_reached = false, billion_reached = false;

	for (int i = 0; i < total_squares; i++)
	{
		rice_grains += square_value;
		square_value *= 2;

		cout << "Total: " << rice_grains << " rice grains on square "<< i << endl << endl;
	}
}