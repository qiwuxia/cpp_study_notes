#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

using namespace std;

// 1002
int main()
{
    list<string> slist;
    string s;
    cout << "输入字符串" << endl;
    while (cin >> s)
    {
        slist.push_back(s);
    }
    cout << "结束";
    if (cin.goodbit)
    {
    cin.clear();
    cin.ignore(1024,'\n');
    }
    cin.clear();

    cout << endl
         << "指定字符春：";
    cin >> s;
    cout << count(slist.begin(), slist.end(), s);

}

// 1001
//  int main()
//  {
//      vector<int> ivec;

//     int a;
//     ivec.reserve(10);
//     cout << "输入数字（非数字键结束）：";
//     while (cin >> a)
//     {
//         ivec.push_back(a);
//     }
//     cin.clear();
//     cin.ignore(10,'\n');
//     cout<< endl
//         << "给定一个检查值：";

//     cin >> a;
//     cout << count(ivec.begin(), ivec.end(), a) << endl;
//     return 0;
// }
