#include <iostream>
#include <vector>

using namespace std;

bool find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int inum)
{
    while (begin < end)
    {
        if (*begin == inum)
            return true;
        begin++;
    }
    return false;
}

int main()
{
    bool findresualt;
    vector<int> ivec{1, 2, 3, 4, 5, 6, 7};
    findresualt = find(ivec.cbegin(), ivec.cend(), 6);
    cout << findresualt << endl;
    findresualt = find(ivec.cbegin(), ivec.cend(), 69);
    cout << findresualt << endl;
    return 0;
}