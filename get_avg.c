#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int Get_Avg(int x, int y);

int main()
{
	printf("%d\n", Get_Avg(1,3));
	system("pause");
	return 0;
}

int Get_Avg(int x, int y)
{
	return ((x&y) + ((x^y) >> 1));
}