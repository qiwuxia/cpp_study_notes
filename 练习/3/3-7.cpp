#include <iostream>
#include <string>

using namespace::std;

int main()
{
    string s1("hello world");
    for(char &c : s1)
    {
        c = 'X';
    }
    cout << s1<<endl;
    return 0;
}