#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//��쳲��������еĵ�n����(�ݹ�)

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
	if (num <= 2)
	{
		return 1;
	}
	return fib(num - 1) + fib(num - 2);
}