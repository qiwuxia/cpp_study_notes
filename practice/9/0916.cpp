#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <list>
using namespace std;

int vec_list_com(vector<int> ivec, list<int> ilis)
{
    if (ivec.size() != ilis.size())
        return 0;
    
}

int main()
{
    srand(time(0));
    vector<int> ivec1;
    list<int> ilis;
    for (int i = 0; i < 10; i++)
    {
        ivec1.emplace_back(rand() % 10);
        ilis.emplace_back(rand() % 11);
    }
    cout << "ivec1: ";
    for (auto num : ivec1)
    {
        cout << num << ' ';
    }
    cout << endl;
    cout << "ilis: ";
    for (auto num : ilis)
    {
        cout << num << ' ';
    }
    cout << endl;

    if (vec_list_com(ivec1, ilis))
        cout << "ivec2大" << endl;
    else
        cout << "ilis大" << endl;

    return 0;
}