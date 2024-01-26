#include <iostream>
#include <cstdlib>
#include <forward_list>
#include <string>

using namespace std;

int found_insert(forward_list<string> &sflist, string flist, string ilist)
{
    auto prev = sflist.before_begin();
    auto sflistIter = sflist.begin();
    while (sflistIter != sflist.end())
    {
        /* code */
        if (*sflistIter == flist)
        {
            sflist.insert_after(sflistIter, ilist);
            return 0;
        }
        else
        {
            prev = sflistIter;
            sflistIter++;
        }
    }
    sflist.insert_after(prev, ilist);
    return 0;
}

int main()
{
    forward_list<string> sflst = {"Hello", "!","world","!"};
    found_insert(sflst, "Hello", "你好");
    for (auto curr = sflst.cbegin(); curr !=sflst.cend(); curr++)
        cout << *curr << " ";
   
    cout <<  endl;
    found_insert(sflst, "!", "?");
    for (auto curr = sflst.cbegin(); curr !=sflst.cend(); curr++)
        cout << *curr << " ";
    cout << endl;
    found_insert(sflst, "Bye", "再见");
    for (auto curr = sflst.cbegin(); curr !=sflst.cend(); curr++)
        cout << *curr << " ";
    cout <<  endl;
    return 0;
}