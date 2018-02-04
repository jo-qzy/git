#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//求参数的平均数，参数可变

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

int avg(int num, ...);

int main()
{
	printf("%d\n", avg(7, 1, 2, 3, 4, 5, 6, 7));
	system("pause");
	return 0;
}

int avg(int n, ...)
{
	va_list num;
	va_start(num, n);
	int sum = 0;
	int i = n;
	while (i--)
	{
		sum += va_arg(num, int);
	}
	va_end(num);
	return sum / n;
}