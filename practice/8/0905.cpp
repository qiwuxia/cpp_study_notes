#include <iostream>
#include <vector>

using namespace std;

vector<int>::const_iterator  find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int inum)
{
    while (begin < end)
    {
        if (*begin == inum)
            return begin;
        begin++;
    }
    return begin;
}

int main()
{
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7};
    vector<int>::const_iterator findresualt ;

    findresualt = find(ivec.cbegin(), ivec.cend(), 6);
    if (findresualt == ivec.cend())
        cout << "未找到" << endl;
    else
        cout << "已找到:" << *findresualt << endl;
    findresualt = find(ivec.cbegin(), ivec.cend(), 69);
    if (findresualt == ivec.cend())
        cout << "未找到" << endl;
    else
        cout << "已找到:" << *findresualt << endl;
    return 0;
}