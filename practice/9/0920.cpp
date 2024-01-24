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
    srand(time(0));
    list<int> ilists;
    deque<int> ideq1, ideq2;
    auto iListIter = ilists.begin();
    uint32_t nums = rand()%100;
    while(nums--)
    {
        
    }
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
    }
}