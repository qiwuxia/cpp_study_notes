#include <string>
#include <iostream>

using namespace std;

void MyReplace(string &s, string oldstr, string newstr)
{
    auto l = oldstr.size();
    if (s.size()<l)
        return;
    auto s_str = s.begin();
    while (s_str <= s.end() - l)
    {
        auto iter1 = s_str;
        auto iter2 = oldstr.begin();
        while ((iter2 != oldstr.end()) && (*iter1 == *iter2))
        {
            iter1++;
            iter2++;
        }

        if (iter2 == oldstr.end())
        {
            s_str = s.erase(s_str, iter1);
            s_str = s.insert(s_str, newstr.begin(), newstr.end());
            s_str = s_str + newstr.size();
        }
        else
        {
            s_str++;

        }
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