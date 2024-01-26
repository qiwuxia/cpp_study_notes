#include <iostream>
#include <list>
#include <vector>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> iFlist;
    auto iFlistIter = iFlist.before_begin();
    iFlist.insert_after(iFlistIter, {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89});
    iFlistIter = iFlist.begin();

    cout << "原始iFlist:";
    while (iFlistIter != iFlist.end())
    {
        cout << " " << *iFlistIter;
        iFlistIter++;
    }
    cout << endl;

    auto prev = iFlist.cbefore_begin();
    iFlistIter = iFlist.before_begin();

    while (iFlistIter != iFlist.end())
    {
        if (*iFlistIter % 2)
        {
            iFlistIter = iFlist.erase_after(prev);
        }
        else
        {
            prev = iFlistIter;
            iFlistIter++;
        }
    }
    cout << "List \"iFlist\" after removing odd elements:";
    iFlistIter = iFlist.begin();
    while (iFlistIter != iFlist.end())
    {
        cout << ' ' << *iFlistIter;
        iFlistIter++;
    }
    cout << endl;
    return 0;
}