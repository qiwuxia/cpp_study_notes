#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
    vector<string> svec1(10); // 10个元素的vector
    vector<string> svec2(24); // 24个元素的vector
    for (auto i : svec1)
    {
        cout << i;
    }
    cout << endl;
    swap(svec1, svec2);
    for (auto i : svec1)
    {
        cout << i;
    }
    cout << endl;
    return 0;
}