#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    int a[] = {1, 2, 2, 3, 41, 6};
    // fill_n(begin(a), sizeof(a) / sizeof(*a), 0); 
    // for (int i = 0; i < sizeof(a) / sizeof(*a);i++)
    // {
    //     cout << a[i] << " ";
    // }
    sort(begin(a), end(a));
    for (auto aa = begin(a); aa < end(a); aa++)
    {
        cout << *aa << endl;
    }
}