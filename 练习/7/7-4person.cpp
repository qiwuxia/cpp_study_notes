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

    string Name() const { return name; } // ����������Ӧ�ñ�����Ϊ������Ա��������Ϊ���۷����������Ƿ��ص�ַ���ں������ڲ���֪ʶ�������ݳ�Ա��ֵ�����������κθı�
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
    ou << "������" << out.Name() << " " << "��ַ��" << out.Address();
    return ou;
}
Person_messge:: Person_messge(istream &is)
{
    is >> this->name>>this->address;
}