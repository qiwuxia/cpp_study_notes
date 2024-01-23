#include <list>
#include <iostream>
#include <vector>
#include <string>


using std::list;
using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::endl;


int main()
{
    list<char *> clist = {"123", "char1", "wssad"};
    vector<string> vstrs;
    vstrs.assign(clist.crbegin(),clist.crbegin());
    for (auto vstr : vstrs)
        cout << vstr << endl;
    return 0;

}