#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec(10);
    for(auto ive : ivec)
    {
        cout << "第一个" << ive << ' ';
    }
    cout << endl;

    vector<int> ivec2(10, 1);
    for(auto ive : ivec2)
    {
        cout << "第二个" << ive << ' ';
    }
    cout << endl;

    vector<int> ivec3{1, 2, 3, 4, 5};
    for(auto ive : ivec3)
    {
        cout << "第三个" << ive << ' ';
    }
    cout << endl;

    vector<int> ivec4 = {6, 1, 2, 3, 4, 5};
    for(auto ive : ivec4)
    {
        cout << "第四个" << ive << ' ';
    }
    cout << endl;

    vector<int> ivec5(ivec4.begin() + 1, ivec4.end() - 1);
    for(auto ive : ivec5)
    {
        cout << "第五个" << ive << ' ';
    }
    cout << endl;
    vector<int> ivec6(ivec4);
    for(auto ive : ivec6)
    {
        cout << "第liu个" << ive << ' ';
    }
    cout << endl;
}