#include <iostream>
#include <vector>
#include <string>
using namespace::std;

int main(void)
{
    vector<int> ivec = {1,2,3,4,5,6,7,8,9,10};
    auto cas = ivec.begin();
    cout<<*cas<<endl;
    ++cas;
    cout<<*cas<<endl;
    --cas;
    cout<<*cas<<endl;
    cas+=3;
    cout<<*cas<<endl;
    return 0;
}