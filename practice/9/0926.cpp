#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> ivec;
    list<int> ilist;

    for (auto i : ia)
    {
        ivec.push_back(i);
        ilist.push_back(i);
    }
    cout << "ivec:";
    for(auto i : ivec)
    {
        cout << ' ' << i;
    }
    cout << endl;

    cout << "ilist";
    for(auto i : ilist)
    {
        cout << ' ' << i;
    }
    cout << endl;
    auto iVecIter = ivec.begin();
    auto iListIter = ilist.begin();
    while (ivec.end()!=iVecIter)
    {
        if (*iVecIter%2 == 0)
        {
            iVecIter = ivec.erase(iVecIter);
        }
        else
        {
            iVecIter++;
        }

    }
    while (ilist.end()!=iListIter)
    {
        /* code */
        if (*iListIter%2)
        {
            iListIter = ilist.erase(iListIter);
        }
        else
        {
            iListIter++;
        }
    }
        cout << "ivec:";
    for(auto i : ivec)
    {
        cout << ' ' << i;
    }
    cout << endl;

    cout << "ilist";
    for(auto i : ilist)
    {
        cout << ' ' << i;
    }
    cout << endl;
}