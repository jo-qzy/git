#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//求输入数二进制序列中1的个数

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

int count(int num);

int main()
{
	int num = 1231;
	printf("%d\n", count(num));
	system("pause");
	return 0;
}

int count(int num)
{
	unsigned char* p = &(unsigned char)num;
	int i = 0, count = 0;
	for (; i < 4; i++)
	{
		while (*p != 0)
		{
			if ((*p & 1) == 1)
			{
				count++;
			}
			*p = *p >> 1;
		}
		p++;
	}
	return count;
}