#include <iostream>
#include <string>

using namespace ::std;

int main()
{
    string s1, s2;
    getline(cin,s1);
    int i = 0;
    for(auto c:s1)
    {
        if(!ispunct(c))
            s2+=c;
    }
    cout <<s2<<endl;
    return 0;
}