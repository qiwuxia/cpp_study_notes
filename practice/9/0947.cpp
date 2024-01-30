#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s = "av2c3d7R4E6";
    int a = 0, len = s.size();
    while (a < len)
    {
        if ((a = s.find_first_of("0123456789", a)) != string::npos)
        {
            cout << s[a] << ' ';
            a++;
        }
        else
        {
            break;
        }
    }
    a = 0;
    cout << endl;
    while (a < len)
    {
        if ((a = s.find_first_not_of("0123456789", a)) != string::npos)
        {
            cout << s[a] << ' ';
            a++;
        }
        else
        {
            break;
        }
    }
    return 0;
}