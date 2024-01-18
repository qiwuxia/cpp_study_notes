#include <iostream>

using namespace std;


unsigned char crc_high_first(unsigned char *ptr, unsigned char len)
{
    unsigned char i;
    unsigned char crc = 0xFF; /* 计算的初始crc值 */

    while(len--)
    {
        crc ^= *ptr++;  /* 每次先与需要计算的数据异或,计算完指向下一数据 */  
        for (i=8; i>0; --i)   /* 下面这段计算过程与计算一个字节crc一样 */  
        { 
            if (crc & 0x80)
                crc = (crc << 1) ^ 0x31;
            else
                crc = (crc << 1);
        }
    }
 
    return (crc); 
}

// unsigned  char crc(unsigned char value)
// {
//     unsigned crc == 0xFF;
//     for 
// }

int main()
{
    unsigned char crc;
    unsigned char value[2] = {0xDC, 0xBA};

    crc = crc_high_first(value, 2);
    cout << crc << endl;
}