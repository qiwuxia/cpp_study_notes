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
    string Name() const { return name; } // ����������Ӧ�ñ�����Ϊ������Ա��������Ϊ���۷����������Ƿ��ص�ַ���ں������ڲ���֪ʶ�������ݳ�Ա��ֵ�����������κθı�
    string Address() const { return address; }
};