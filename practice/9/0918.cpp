#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main()
{
    string str;
    list<string> dstrs;
    while (cin >> str)
    {
        dstrs.emplace_back(str);
    }
    auto dstr = dstrs.begin();
    while(dstr != dstrs.end())
    {
        cout << *dstr << ' ';
        dstr++;
    }

    cout << endl;
    return 0;
}