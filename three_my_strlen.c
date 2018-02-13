#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//三种strlen的写法

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

int my_strlen(const char* dst);
int my_strlen1(const char* dst);
int my_strlen2(const char* dst);

int main()
{
	char* p = NULL;
	printf("%d\n", my_strlen1(p));
	system("pause");
	return 0;
}

int my_strlen(const char* dst)
{
	assert(dst);
	char* start = dst;
	while (*dst != '\0')
	{
		dst++;
	}
	return dst - start;
}

int my_strlen1(const char* dst)
{
	assert(dst);
	if (*dst == '\0')
	{
		return 0;
	}
	return 1 + my_strlen1(dst + 1);
}

int my_strlen2(const char* dst)
{
	assert(dst);
	int count = 0;
	while (dst++ != '\0')
	{
		count++;
	}
	return count;
}