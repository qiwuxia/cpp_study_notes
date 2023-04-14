/*
使用迭代器做：
编写一段程序，把联系3.13中vector对象的容量和具体内容输出出来
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
    std::cout<<"v1的容量是"<<num<<std::endl;

    num = 0;
    for(auto vec1 = v2.cbegin(); vec1!=v2.cend();vec1++)
    {
        std::cout<<*vec1<<std::endl;
        num++;
    }
    std::cout<<"v2的容量是"<<num<<std::endl;
    num = 0;
    for(auto vec1 = v3.cbegin(); vec1!=v3.cend();vec1++)
    {
        std::cout<<*vec1<<std::endl;
        num++;
    }
    std::cout<<"v3的容量是"<<num<<std::endl;
    num = 0;
    for(auto vec1 = v4.cbegin(); vec1!=v4.cend();vec1++)
    {
        std::cout<<*vec1<<std::endl;
        num++;
    }
    std::cout<<"v4的容量是"<<num<<std::endl;

}