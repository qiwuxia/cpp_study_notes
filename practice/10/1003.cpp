#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    double sum = 0;
    vector<double> dvec = {1, 2, 3, 4.6, 54, 6};
    sum = accumulate(dvec.begin(), dvec.end(), 0);
    cout << sum << endl;
}