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
 * @brief ��֤�绰�����Ƿ���Ч
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
 * @brief ��ʽ���ַ���
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
    vector<PersonInfo> people; //���������ļ������м�¼
    ifstream fin("C:\\Users\\Administrator\\Documents\\GitHub\\cpp_study_notes\\practice\\8\\0813.txt");
    if (fin)
    {
        // ���д������ȡ���ݣ�ֱ��fin�����ļ�β������������
        while (getline(fin, line))
        {
            PersonInfo info;                  // ����һ������˼�¼���ݵĶ���
            istringstream record(line);
            record >> info.name;
            while (record >> word)
            {
                info.phones.push_back(word);    //�������
            }
            people.push_back(info);             //���˼�¼׷�ӵ�peopleĩβ
        }
        
        for (const auto &entry : people)
        {
            ostringstream formatted, badNums; // ÿ��ѭ���´����Ķ���
            for (const auto &nums : entry.phones) // ��ÿ����(�ַ�����ʽ)
            {
                if (!valid(nums))
                {
                    badNums << "" << nums; // �������游����ʽ����badNums;
                }
                else
                {
                    // ����ʽ�����ַ�����д�롱 formatted
                    formatted << " " << format(nums);
                }
            }

            if (badNums.str().empty()) // û�д������
            {
                cout << entry.name << " " << formatted.str() << endl; //��ӡ���ֺ͸�ʽ������

            }
            else
            {
                cerr << "input error: " << entry.name << ": " << badNums.str() << endl; //��ӡ���ֺʹ������
            }
        }
    }
    else
    {
        cerr << "no files" << endl;
    }

}
