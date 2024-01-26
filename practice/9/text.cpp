#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <string>


using namespace std;

int main()
{
    vector<int> ivec1 = {1, 2, 3, 4, 5, 6};
    auto ivec1begin = ivec1.begin();
    auto ivec1end = ivec1.end();
    cout << "原始Ivec1: ";
    for (auto ivec : ivec1)
        cout << ivec << " ";
    cout << endl
         << "begin: " << &*ivec1begin << " end: " << &*ivec1end << endl;
    cout << ivec1.capacity() << endl;

    ivec1.push_back(0);
    cout << ivec1.capacity() << endl; // 查询容器的大小范围

        for (auto ivec : ivec1)
        cout << ivec << " ";
    cout << endl
         << "begin: " << &*ivec1begin << " end: " << &*ivec1end << endl;
    ivec1begin = ivec1.begin(); // 结果显示添加元素会使vector整个对象存储空间的重新分配
    ivec1end = ivec1.end();
    cout << endl
         << "begin: " << &*ivec1begin << " end: " << &*ivec1end << endl;
        ivec1.push_back(0);
    cout << ivec1.capacity() << endl;

        for (auto ivec : ivec1)
        cout << ivec << " ";
    cout << endl
         << "begin: " << &*ivec1begin << " end: " << &*ivec1end << endl;
    ivec1begin = ivec1.begin(); // 结果显示添加元素会使vector整个对象存储空间的重新分配
    ivec1end = ivec1.end();
    cout << endl
         << "begin: " << &*ivec1begin << " end: " << &*ivec1end << endl;


    cout << ivec1.max_size() << endl;

    return 0;

    // string strs = "你好";
    
    // auto strbegin = strs.begin();
    // strs.insert(0, "hello");
    // cout << strs << endl;
}