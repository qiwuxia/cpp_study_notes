#include <string>
#include <iostream>

using namespace std;

void MyReplace(string &s, string oldstr, string newstr)
{
    int p = 0;
    cout << (p = s.find(oldstr, p));
    while ((p =  s.find(oldstr, p)) != string::npos)
    {
        s.replace(p, oldstr.size(), newstr);
        p += newstr.size();
    }
    
}


int main()
{
    string s = "asdathothhothrusa sada";

    MyReplace(s, "tho", "though");
    cout << s << endl;
    MyReplace(s, "thru", "through");
    cout << s << endl;
    return 0;
}