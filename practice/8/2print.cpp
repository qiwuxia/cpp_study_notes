#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;
int main()
{
    int in1 = -2;
    int in2 = -2;
    uint32_t uin1, uin2;
    uint64_t res;
    uin1 = static_cast<uint32_t>(in1);
    uin2 = static_cast<uint32_t>(in2);
    cout << "in1:" << in1 << "   "
         << "uin1:" << uin1<< endl;
    cout << "in2:" << in2 << "   "
         << "uin2:" <<uin2<< endl;
    res = (uint64_t)(((((int32_t)uin1 << 16) >> 16) * (((int32_t)uin2 << 16) >> 16)) + ((((int32_t)uin1) >> 16) * (((int32_t)uin2) >> 16)) + 0);
    cout << "sum:" << res << endl;

    return 0;
}
