#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream readin("..//123.txt");

    vector<string> restr;
    string str = "";
    char c;
    if (readin)
    {
        while (readin>>str)
        {
            restr.push_back(str);
        }
    }
    // if (readin)
    // {
    //     readin.unsetf(ios::skipws);  // ÊäÈëÁ÷Ä¬ÈÏºöÂÔ¿Õ°××Ö·û£¬´Ë²Ù×÷È¡ÏûÄ¬ÈÏµÄºöÂÔ¿Õ°××Ö·û
    //     readin >> c;
    //     while (!readin.eof())
    //     {
    //         if (c == '\n')
    //         {
    //                 restr.push_back(str);
    //                 str = "";
    //         }
    //         else
    //         {
    //             str += c;
    //         }
    //         readin >> c;
    //     }
    // }
    restr.push_back(str);

    readin.close();
    for (auto sttr : restr)
    {
        cout << sttr << endl;
    }
    cout << restr.size() << endl;
    return 0;
}