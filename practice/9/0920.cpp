#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <ctime>
#include <cstdlib>


using namespace std;

int main()
{
    system("color 06");
    srand(time(0));
    list<int> ilists;
    deque<int> ideq1, ideq2;
    auto iListIter = ilists.begin();
    uint32_t nums = rand()%100;
    while(nums--)
    {
        ilists.push_back(rand() % 10);

    }
    iListIter = ilists.begin();
    while (iListIter != ilists.end())
    {
        cout << *iListIter << " ";
        iListIter++;
    }
    cout << endl;
    iListIter = ilists.begin();
    while (iListIter!= ilists.end())
    {
        if(*iListIter % 2)
        {
            ideq1.push_back(*iListIter);
        }
        else
        {
            ideq2.push_back(*iListIter);
        }
        iListIter++;
    }
    cout << "ideq1: ";
    for (auto iDeq1Iter : ideq1)
    {
        cout << " " << iDeq1Iter;
    }
    cout << endl;
    cout << "ideq2: ";
    for (auto iDeq2Iter : ideq2)
    {
        cout << " " << iDeq2Iter;
    }
    cout << endl;
    return 0;
}