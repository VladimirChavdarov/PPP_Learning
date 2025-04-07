//NOTE: also includes ex11

#include "../PPP/PPP.h"

struct vector_props
{
	vector_props();
	vector_props(int a_smallest, int a_biggest, double a_mean, int a_median);
	int smallest;
	int biggest;
	double mean;
	int median;
};

vector_props::vector_props()
	: smallest(0), biggest(0), mean(0), median(0)
{}

vector_props::vector_props(int a_smallest, int a_biggest, double a_mean, int a_median)
	: smallest(a_smallest), biggest(a_biggest), mean(a_mean), median(a_median)
{}


int maxv(const vector<int>& vec)
{
	if (vec.size() == 0)
		error("meanv: argument vector is empty");
	int result = -1000000;
	for (const int item : vec)
		if (item > result)
			result = item;
	return result;
}

int minv(const vector<int>& vec)
{
	if (vec.size() == 0)
		error("meanv: argument vector is empty");
	int result = 100000000;
	for (const int item : vec)
		if (item < result)
			result = item;
	return result;
}

double meanv(const vector<int>& vec)
{
	if (vec.size() == 0)
		error("meanv: argument vector is empty");
	double v_sum = 0;
	for (int i = 0; i < vec.size(); ++i)
		v_sum += vec[i];
	return v_sum / vec.size();
}

int medianv(vector<int> vec)
{
	if (vec.size() == 0)
		error("medianv: argument vector is empty");
	sort(vec.begin(), vec.end());
	return vec[vec.size() / 2];
}

vector_props GetProps(const vector<int>& vec)
{
	vector_props result;
	result.biggest = maxv(vec);
	result.smallest = minv(vec);
	result.mean = meanv(vec);
	result.median = medianv(vec);

	return result;
}

int main()
{
	vector<int> invec = { 100, 12, 23, 1, 15, 256 };
	vector_props result = GetProps(invec);

	cout << "max: " << result.biggest << endl;
	cout << "min: " << result.smallest << endl;
	cout << "mean: " << result.mean << endl;
	cout << "median: " << result.median << endl;
}