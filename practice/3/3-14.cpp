#include <iostream>
#include <string>
#include <vector>

using namespace::std;

int main()
{
    vector<string> s1;
    string  c;
    char c1 ;
    while (cin >> c)
    {
        s1.push_back(c);
        cout<<"Y:¼ÌÐø£¬N:ÍË³ö";
        cin>>c1;
        if(c1=='N')
        break;

    }
    // while(i==0)
    // {
    // cout << s1[i-1] << " ";
    // i--;
    // }
    // }
    for (auto mu : s1)
    {
        cout << mu <<endl;
    }
    cout <<endl;
    return 0;
}