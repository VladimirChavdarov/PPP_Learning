#include "../PPP/PPP.h"

double compute_index(const vector<double>& price, const vector<double>& weight)
{
	if (price.size() != weight.size())
		error("Vectors are different sizes. Must be the same size.");

	double result = 0.0;
	for (int i = 0; i < price.size(); i++)
	{
		result += price[i] * weight[i];
	}

	return result;
}

int main()
{
	vector<double> price = { 1.0, 2.0, 3.0 };
	vector<double> weight = { 4.0, 5.0, 6.0 };

	cout << compute_index(price, weight) << endl;
}