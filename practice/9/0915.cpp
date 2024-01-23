#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(0));
    vector<int> ivec1, ivec2;
    for (int i = 0; i < 10; i++)
    {
        ivec1.emplace_back(rand() % 10);
        ivec2.emplace_back(rand() % 11);
    }
    cout << "ivec1: ";
    for (auto num : ivec1)
    {
        cout << num << ' ';
    }
    cout << endl;
    cout << "ivec2: ";
    for (auto num : ivec2)
    {
        cout << num << ' ';
    }
    cout << endl;

    if (ivec1 < ivec2)
        cout << "ivec2大" << endl;
    else
        cout << "ivec1大" << endl;

    return 0;
}