/*练习3.22：修改之前那个输出text第一段的程序，首先把text的第一段全都改成大
写形式，然后再输出它。

for (auto it text.cbegin();it != text.cend()&&!it->empty();++it)
        cout <*it <endl;
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> text;
    string s;
    while (getline(cin, s))
    {
        text.push_back(s);
    }

    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
        for(auto it2 = it->begin(); it2 != it->end(); ++it2)
        {
           *it2 =  toupper(*it2);
        }
        cout << *it <<  endl;
    }
}