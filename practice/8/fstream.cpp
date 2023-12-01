#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream isn("0801.cpp");
    ofstream osn("0901.cpp");
    char astr;
    
    string sstr;
    // while (!isn.eof())
    // {
    // isn >> astr;
    // sstr += astr;
    // }
osn << isn.rdbuf() << endl;
osn << 123 << endl;
//osn << sstr;
return 0;
}