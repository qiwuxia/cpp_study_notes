#include <iostream>
#include <string>

using namespace std;

string inser_appen(string s, string pre, string end)
{
    s.insert(s.begin(), pre.begin(), pre.end());
    return s.append(end);
}

int main()
{
    string s = "zhang";
    cout << inser_appen(s, "Mr.", "III");
    return 0;
}