#include <iostream>
#include <vector>

using namespace::std;

int main()
{
    vector<int> ivec1{1,2,3,4,5};
    vector<int> ivec2{1,2,3};
    ivec1 = ivec2;
    for(auto c : ivec1)
        cout << c << " "  <<endl;
    return 0;
}