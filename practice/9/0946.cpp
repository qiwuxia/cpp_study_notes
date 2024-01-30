#include <iostream>
#include <string>

using namespace std;

string in_apd(string s, string pre, string end)
{
    s.insert(0, pre);
    s.insert(s.size(), end);
    return s;
}

int main()
{
    string s = "nihap";
    cout << in_apd(s, "Mr.r", "Jr.");
    return 0;
    
}