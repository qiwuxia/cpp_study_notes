#include <iostream>
#include <vector>
#include <string>

using namespace ::std;
int main(void)
{
    vector<int> ivec;
    int a, i = 0;
    char c;
    while (cin >> a)
    {
        ivec.push_back(a);
        cout << "N退出" << endl;
        cin >> c;
        if (c == 'N' || c == 'n')
            break;
    }
    if (ivec.empty())
        return 0;
    cout<<ivec.size()<<endl;
    if (ivec.size() % 2 == 0)
    {
        for (int j = 0; j < ivec.size(); j++, j++)
        {
            cout << ivec[j] + ivec[j + 1];
            cout << " ";
        }
    }
    else
    {
        for (int j = 0; j < ivec.size() - 1; j++, j++)
        {
            cout << ivec[j] + ivec[j + 1];
            cout << " ";
        }
        cout << ivec[ivec.size() - 1];
    }
    cout << endl
         << "----------------------" << endl;
    if (ivec.size() % 2 == 0)
    {
        for (int j = 0, k = ivec.size(); j < k / 2; j++)
        {
            cout << ivec[j] + ivec[k - 1];
            cout << " ";
        }
    }
    else
    {
        for (int j = 0, k = ivec.size(); j < k / 2; j++)
        {
            cout << ivec[j] + ivec[k - 1];
            cout << " ";
        }
        cout << ivec[ivec.size() / 2];
    }
    return 0;
}