#include <iostream>
#include <string>
#include <vector>
using namespace::std;
int main(void)
{
    vector<string> vt;
    string c;
    char c1;
    while (cin >>c)
    {
        vt.push_back(c);
        cout << "Y继续" <<endl;
        cin>>c1;
        if(c1 != 'Y')
            break;
    }   
    for(auto &em :vt)
    {
        for(auto &c2 :em)
            c2 = toupper(c2);
        cout << em <<endl;
    }
    return 0;
}