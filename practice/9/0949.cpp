#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string up_str = "bhifkltABCDEFGHIJKLMNOPRSTUVWXYZ";
string down_str = "gpqy";
string middle_str = "acemnorsuvwxz";
string all_str = "jQ";
string noonly_mid = "jQgpqybhifkltABCDEFGHIJKLMNOPRSTUVWXYZ";

int main()
{
    fstream fs("str.txt");
    int len = 0;
    int len_max = 0;
    string s;
    string res;
    while (fs>>s)
    {
        if (s.find_first_not_of(middle_str)!= string::npos)
        {
            continue;
        }

        if (s.size() > len_max)
        {
            res = s;
            len_max = s.size();
        }
    }
    cout << s << endl;
    return 0;
}