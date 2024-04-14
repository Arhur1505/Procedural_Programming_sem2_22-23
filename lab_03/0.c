#include <stdio.h>

int main()
{
    unsigned int i = 0x11223344;
    unsigned char *p = (unsigned char *)&i;
    for (size_t j = 0; j < sizeof i; j++)
    {
        printf("%X", *(p + j));
    }

    return 0;
}