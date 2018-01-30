#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//挨个打印整数的每一个数

#include <stdio.h>
#include <windows.h>
#include <math.h>

void print(int num);

int main()
{
	int num = 1234;
	print(num);
	printf("\n");
	system("pause");
	return 0;
}

void print(int num)
{
	if (num > 9)
	{
		print(num / 10);
	}
	printf("%d ", num % 10);
}