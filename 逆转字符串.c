#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//Äæ×ª×Ö·û´®

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

char* reverse(char* dst);

int main()
{
	char arr[] = "bit-tech";
	printf("%s\n", reverse(arr));
	system("pause");
	return 0;
}

char* reverse(char* dst)
{
	assert(dst);
	char* end = dst, *start = dst;
	while (*(end + 1) != '\0')
	{
		end++;
	}
	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++, end--;
	}
	return dst;
}