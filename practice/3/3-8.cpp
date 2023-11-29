#include <iostream>
#include <string>

using namespace ::std;

int main()
{
    string s1("hello world");
    decltype(s1.size()) i = 0;
    while (i < s1.size())
    {
        s1[i] = 'x';
        i++;
    }

    cout << s1 << endl;
    for (i = 0; i < s1.size(); s1[i] = toupper(s1[i]), i++)
        ;
    cout << s1 << endl;

    return 0;
}