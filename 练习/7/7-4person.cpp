#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <cstdlib>

using namespace std;
//istream &read(istream &in, Person_messge &ins);
ostream &printf_person(ostream &ou, Person_messge &out);
class Person_messge{
public:

    string Name() const { return name; } // 这两个函数应该被定义为常量成员函数，因为不论返回姓名还是返回地址，在函数体内部都知识堆区数据成员的值，而不会做任何改变
    string Address() const { return address; }
    Person_messge() = default;
    Person_messge(string na, string addr) : name(na),address(addr) {}
    Person_messge(istream &is);
private:
    string name;
    string address;
};

// istream &read(istream &in, Person_messge &ins)
// {
//     in >> ins.name >> ins.address;
//     return in;
// }
ostream &printf_person(ostream &ou, Person_messge &out)
{
    ou << "姓名：" << out.Name() << " " << "地址：" << out.Address();
    return ou;
}
Person_messge:: Person_messge(istream &is)
{
    is >> this->name>>this->address;
}