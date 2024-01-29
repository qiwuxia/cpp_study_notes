#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<char> cvec = {'1', '2', '3', '4'};
    // cvec.push_back('\0');

    // //可行
    // string s1;
    // s1.assign(cvec.begin(), cvec.end());
    // cout << s1 << endl;

    // //可行
    // string s1(&cvec[0], 4);
    // cout << s1 << endl;

    //可行， vector的data成员函数返回其內存空间的首地址
    string s1(cvec.data(), cvec.size());
    cout << s1 << endl;
    return 0;
}