// 0935 vector的capacity值得是当前容器分配的內存空间的大小， size是当前容器内拥有的数目大小
// 0936 不会，当capcity等于size时，增加元素会重新分配内存空间
// list内的元素地址不连续，不需要一段连续的空间    array在定义时就固定了大小，因此两者都不需要capacity成员函数
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
    cout << "ivec.size(): " << ivec.size() << "  ivec.capacity():  " << ivec.capacity() << endl;
    ivec.insert(ivec.end(), 5, 6);
    cout << "ivec.size(): " << ivec.size() << "  ivec.capacity():  " << ivec.capacity() << endl;
    ivec.insert(ivec.end(), 1, 10);
    cout << "ivec.size(): " << ivec.size() << "  ivec.capacity():  " << ivec.capacity() << endl;
    ivec.insert(ivec.end(), 10, 10);

    cout << "ivec.size(): " << ivec.size() << "  ivec.capacity():  " << ivec.capacity() << endl;
    ivec.reserve(50);
    cout << "ivec.size(): " << ivec.size() << "  ivec.capacity():  " << ivec.capacity() << endl;
    ivec.reserve(10);

    cout << "ivec.size(): " << ivec.size() << "  ivec.capacity():  " << ivec.capacity() << endl;
    ivec.shrink_to_fit();
    cout << "ivec.size(): " << ivec.size() << "  ivec.capacity():  " << ivec.capacity() << endl;
    return 0;
}

// 0939 