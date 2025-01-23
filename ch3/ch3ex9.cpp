#include "../PPP/PPP.h"

int main()
{
	int total_squares = 64;
	int rice_grains = 0;
	int square_value = 1;
	bool thousand_reached = false, million_reached = false, billion_reached = false;

	for (int i = 0; i < total_squares; i++)
	{
		rice_grains += square_value;
		square_value *= 2;

		if (rice_grains >= 1000 && !thousand_reached)
		{
			cout << "You need " << i + 1 << " squares for 1 000 grains: " << rice_grains << endl;
			thousand_reached = true;
		}
		if (rice_grains >= 1000000 && !million_reached)
		{
			cout << "You need " << i + 1 << " squares for 1 000 000 grains: " << rice_grains << endl;
			million_reached = true;
		}
		if (rice_grains >= 1000000000 && !billion_reached)
		{
			cout << "You need " << i + 1 << " squares for 1 000 000 000 grains: " << rice_grains << endl;
			billion_reached = true;
		}
	}
}