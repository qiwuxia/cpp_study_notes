#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

void elimDips()
{
    vector<int> ivec;
    int i;
    while (cin >> i)
    {
        ivec.push_back(i);
    }
    cout << "输入后：";
    for (auto x : ivec)
    {
        cout << x << " ";
    }
    cout << endl;
    auto iter = unique(ivec.begin(), ivec.end());
    cout << "unique后: ";
    for (auto x : ivec)
    {
        cout << x << " ";
    }
    cout << endl;
    ivec.erase(iter, ivec.end());
    cout << "erase后: ";
    for (auto x : ivec)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    elimDips();
}