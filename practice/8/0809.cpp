#include <iostream>
#include <sstream>


using namespace std;

istream &rcin(istream &cs)
{
    char s;
    string ss;
    cs >> s;
    while (!cs.eof())
    {
        ss += s;
        if (cs.fail())
        {
            cs.clear();
            continue;
        }
        cs >> s;
    }
    cout << "eof:"
         << "  " << ss << endl;
    cin.clear();
    cs >> s;
    while (!cs.fail())
    {
        ss += s;
        if (cs.eof())
        {
            cs.clear();
            continue;
        }
        cs >> s;
        auto now = cs.fail();
        auto now2 = cs.eof();
        auto now3 = cs.bad();
    }
    cout << "fail:"
         << "  " << ss << endl;

    return cs;
}

int main()
{
    string str;
    int i = 5;
    int i_eof, i_fail;
    cout << unitbuf;
    cin.tie(nullptr);
    return 0;
}