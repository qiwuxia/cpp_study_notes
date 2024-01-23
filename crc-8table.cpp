#include <iostream>
#include <fstream>

using namespace std;

unsigned char crc_check (unsigned char value, unsigned char init)
{
    unsigned char crc= 0;
    crc = value;
    for (int i = 0; i < 8;i++)
    {
        if (crc & 0x80)
        {
            crc = (crc << 1) ^ 0x31;
        }
        else
        {
            crc <<= 1;
        }
    }
    return crc;
}



int main()
{
    int8_t init = 0xFF;
    ofstream out("table.c", ofstream::out);
    out << "uint8_t crctable[] ={";
    for (uint16_t i = 0; i <= 0xFF; i++)
    {
        if (0 == (i%16))
            out << endl;
        out << "0x"<< hex << (uint16_t)crc_check((uint8_t)i, 0xFF) << ", ";

    }
    out << "};" << endl;
    // uint8_t crc = crc_check(0xDC, 0xFF);
    // crc = crc_check(0xBA, crc);
    // cout << (uint16_t)crc << endl;
    // return 0;
}


