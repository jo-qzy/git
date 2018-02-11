#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//求斐波那契数列的第n个数

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

int fib(size_t num);

int main()
{
	printf("%d\n", fib(4));
	system("pause");
	return 0;
}
int fib(size_t num)
{
	int arr[3] = { 1,1 };
	int tmp = 0;
	num = num - 2;
	while (num--)
	{
		tmp = arr[1];
		arr[1] = arr[0] + arr[1];
		arr[0] = tmp;
	}
	return arr[1];
}