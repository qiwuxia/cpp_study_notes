#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    string line, word;
    vector<string> vecline;
    ifstream fin("file_name.txt");
    istringstream instr;
    if (fin)
    {
        while (getline(fin, line))
        {
            vecline.push_back((line));
        }
        for(auto strline: vecline)
        {
            instr.str(strline);
            while(instr >> word)
            {
                cout << word << endl;
            }
            word = "";
            instr.clear();
        }   
    }
    else
    {
        cerr << "no file?" << endl;
    }
}