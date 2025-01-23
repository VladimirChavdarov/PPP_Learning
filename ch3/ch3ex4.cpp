#include "../PPP/PPP.h"

int main()
{
	vector<double> distances;
	for (double i; cin >> i;)
		distances.push_back(i);

	double sum = 0.0;
	for (double dist : distances)
		sum += dist;

	cout << "Sum: " << sum << endl;
	cout << "Mean: " << sum / distances.size() << endl;
}