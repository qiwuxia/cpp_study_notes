#include <iostream>

using namespace std;

istream& rcin(istream& cs)
{
    char s;
    string ss;
    cs >> s;
    while(!cs.eof())
    {
        ss += s;
        if (cs.fail())
        {
            cs.clear();
            continue;
        }
        cs >> s;
    }
    cout << ss << endl;
    return cs;
}

int main ()
{
    string str;
    int i = 5;
    rcin(cin);
    return 0;
}