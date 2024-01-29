#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s1;
    char c;
    s1.reserve(100);
    
    while (cin >> c)
    {
        s1.push_back(c);

    }
    cout << s1 << endl;
    return 0;
}