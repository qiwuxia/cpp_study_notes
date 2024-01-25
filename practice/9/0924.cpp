#include <vector>
#include <iostream>
#include <string>
using namespace std;


int main()
{
    vector<int> ivec;
    try
    {
        throw("nihao ");
        cout << ivec.at(0) << endl;
        cout << ivec[0] << endl;
        cout << ivec.front() << endl;
        cout << *ivec.begin() << endl;
    }
    catch (const char * e)
    {
        cout << e << endl;
    }


}