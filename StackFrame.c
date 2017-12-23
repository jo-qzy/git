#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int add(int x, int y)
{
    int z = x + y;
    return z;
}

int main()
{
    int a = 0xAAAAAAAA;
    int b = 0xBBBBBBBB;
    int c = add(a, b);
    system("pause");
    return 0;
}