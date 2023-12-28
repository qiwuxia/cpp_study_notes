#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec{1, 2, 3, 4, 5, 6};
    auto x = ivec.rbegin();
    x++;
    cout << *x << endl;
    return 0;
}