#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <cstdlib>

using namespace std;

class Person_messge{
private:
    string name;
    string address;
public:
    string Name() const { return name; } // 这两个函数应该被定义为常量成员函数，因为不论返回姓名还是返回地址，在函数体内部都知识堆区数据成员的值，而不会做任何改变
    string Address() const { return address; }
};