
#include<iostream>

#include <vector>
using namespace std;


// int main()
// {
//     int a[10];
//     for (int i = 0; i < 10;i++)
//     {
//         a[i] = i;
//         cout << a[i]<<' ';
//     }
//     getchar();
//     return 0;
// }

int main ()
{
    vector<int> a;
    for (int i = 0; i < 10;i++)
    {
        a.emplace_back(i);
        cout << a[i] << ' ';
    }
    getchar();
    return 0;
}

//3-33 如果不初始化scores，scores的数组内的数为未知数，导致计算不准确