#include <stdio.h>

int main()
{
    unsigned long ulong = 65530;
    unsigned short ushort = 65530;
    printf("ulong = %hd, ushort = %hd", (short)ulong, (short)ushort);
}