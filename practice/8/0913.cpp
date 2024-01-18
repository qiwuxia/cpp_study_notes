#include <iostream>
#include <vector>
#include <list>

using namespace std;
int main()
{
    list<int> ivec{1, 2, 3, 4, 5};
    vector<double> dvec(ivec.begin(), ivec.end());
    for (auto dnum : dvec)
    {
        cout << dnum << ' ';
    }
    cout << endl;
    dvec.assign(ivec.begin(), --ivec.end());
    for (auto dnum : dvec)
    {
        cout << dnum << ' ';
    }
    cout << endl;
    return 0;
}