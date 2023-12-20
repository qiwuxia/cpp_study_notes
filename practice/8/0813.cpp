#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};

/**
 * @brief 验证电话号码是否有效
 * @param s
 * @return int
 * @author renxiaoyang
 * @date 2023-12-20
 */
int valid(string s)
{
    return 1;
}

/**
 * @brief 格式化字符串
 * @param s
 * @return string
 * @author renxiaoyang
 * @date 2023-12-20
 */
string format(string s)
{
    return s;
}

int main()
{
    string line, word;
    vector<PersonInfo> people; //保存来自文件的所有记录
    ifstream fin("C:\\Users\\Administrator\\Documents\\GitHub\\cpp_study_notes\\practice\\8\\0813.txt");
    if (fin)
    {
        // 逐行从输入读取数据，直至fin遇到文件尾（或其他错误）
        while (getline(fin, line))
        {
            PersonInfo info;                  // 创建一个保存此纪录数据的对象
            istringstream record(line);
            record >> info.name;
            while (record >> word)
            {
                info.phones.push_back(word);    //保存号码
            }
            people.push_back(info);             //将此记录追加到people末尾
        }
        
        for (const auto &entry : people)
        {
            ostringstream formatted, badNums; // 每个循环新创建的对象
            for (const auto &nums : entry.phones) // 对每个数(字符出形式)
            {
                if (!valid(nums))
                {
                    badNums << "" << nums; // 将数的祖父穿形式存入badNums;
                }
                else
                {
                    // 将格式化的字符串“写入” formatted
                    formatted << " " << format(nums);
                }
            }

            if (badNums.str().empty()) // 没有错误的数
            {
                cout << entry.name << " " << formatted.str() << endl; //打印名字和格式化的数

            }
            else
            {
                cerr << "input error: " << entry.name << ": " << badNums.str() << endl; //打印名字和错误的数
            }
        }
    }
    else
    {
        cerr << "no files" << endl;
    }

}
