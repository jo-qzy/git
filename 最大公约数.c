#define _CRT_SECURE_NO_WARNINGS 1

//输入两个数，求最大公约数（辗转相除法）

#include <stdio.h>
#include <windows.h>
#include <math.h>

#pragma warning(disable:4996)

int main()
{
	int x = 0, y = 0;
	printf("input two nums:");
	scanf("%d%d", &x, &y);
	while (1)
	{
		if (x > y)
		{
			if (x % y == 0)
			{
				printf("最大公约数为:%d\n", y);
				break;
			}
			x = x % y;
		}
		else
		{
			if (y % x == 0)
			{
				printf("最大公约数为:%d\n", x);
				break;
			}
			y = y % x;
		}
	}
	system("pause");
	return 0;
}