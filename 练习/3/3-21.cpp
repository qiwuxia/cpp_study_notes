/*
ʹ�õ���������
��дһ�γ��򣬰���ϵ3.13��vector����������;��������������
3.13
vector<int> v1;
vector<int> v2(10);
vector<int> v3(10, 42);
vector<int> v4{10};
vector<int> v5{10,42};
vector<string> v6{10};
vector<string> v7{10, "hi"};
*/

#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> v1;
    std::vector<int> v2(10);
    std::vector<int> v3(10, 42);
    std::vector<int> v4{10};
    std::vector<int> v5{10, 42};
    std::vector<std::string> v6{10};
    std::vector<std::string> v7{10, "hi"};
    int num =0;
    for(auto vec1 = v1.cbegin(); vec1!=v1.cend();vec1++)
    {
        std::cout<<*vec1<<std::endl;
        num++;
    }
    std::cout<<"v1��������"<<num<<std::endl;

    num = 0;
    for(auto vec1 = v2.cbegin(); vec1!=v2.cend();vec1++)
    {
        std::cout<<*vec1<<std::endl;
        num++;
    }
    std::cout<<"v2��������"<<num<<std::endl;
    num = 0;
    for(auto vec1 = v3.cbegin(); vec1!=v3.cend();vec1++)
    {
        std::cout<<*vec1<<std::endl;
        num++;
    }
    std::cout<<"v3��������"<<num<<std::endl;
    num = 0;
    for(auto vec1 = v4.cbegin(); vec1!=v4.cend();vec1++)
    {
        std::cout<<*vec1<<std::endl;
        num++;
    }
    std::cout<<"v4��������"<<num<<std::endl;

}