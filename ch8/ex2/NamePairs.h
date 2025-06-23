#pragma once
#include "../../PPP/PPP.h"

class Name_Pairs
{
public:
	Name_Pairs() {};

	const vector<string>& get_names() const { return names; }
	const vector<double>& get_ages() const { return ages; }

	void read_names();
	void read_ages();
	void print();
	void sort_names();

private:
	vector<string> names;
	vector<double> ages;
};

ostream& operator<<(ostream& os, const Name_Pairs& np)
{
	if (np.get_names().size() != np.get_ages().size())
		error("<<: name and age must be the same size");
	for (int i = 0; i < np.get_names().size(); ++i)
		os << '(' << np.get_names()[i] << ',' << np.get_ages()[i] << ')' << endl;
	return os;
}

bool operator==(const Name_Pairs& a, const Name_Pairs& b)
{
	if (a.get_names().size() != b.get_names().size() || a.get_ages().size() != b.get_ages().size())
		return false;
	bool equal = true;
	for (int i = 0; i < a.get_names().size(); ++i) {
		if (a.get_names()[i] != b.get_names()[i])
			return false;
	}
	for (int i = 0; i < a.get_ages().size(); ++i) {
		if (a.get_ages()[i] != b.get_ages()[i])
			return false;
	}
	return true;
}

bool operator!=(const Name_Pairs& a, const Name_Pairs& b)
{
	return !(a == b);
}