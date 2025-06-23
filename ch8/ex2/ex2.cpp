#include "../../PPP/PPP.h"
#include "NamePairs.h"

int main()
{
	Name_Pairs namePair;

	namePair.read_names();
	namePair.read_ages();
	namePair.print();
	namePair.sort_names();
	namePair.print();
}