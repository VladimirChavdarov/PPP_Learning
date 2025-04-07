#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    vector<int> A = { 1, 1 };
    vector<int> B = { 2, 1 };
    vector<int> C;

    unordered_set<int> set;
    for (size_t i = 0; i < A.size(); i++)
    {
        if (A[i] == B[i])
        {
            set.insert(A[i]);
        }
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (set.count(A[i]) == 1)
        {
            C.push_back(A[i]);
            continue;
        }
        if (set.count(B[i]) == 1)
        {
            C.push_back(B[i]);
            continue;
        }
    }

    for (auto i : C)
        cout << i << endl;
}