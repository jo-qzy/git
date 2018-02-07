#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//É¾³ý×Ö·û´®µÄa£¬¸´ÖÆ×Ö·û´®µÄb

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

char* delete_a(char* dst);

int main()
{
	char arr[20] = "aabazxaabc";
	printf("%s\n", delete_a(arr));
	system("pause");
	return 0;
}

char* delete_a(char* dst)
{
	char arr[20] = "";
	char* p = arr;
	char* start = dst;
	while (*dst != '\0')
	{
		if (*dst == 'a')
		{
			dst++;
			continue;
		}
		*p = *dst;
		p++;
		if (*dst == 'b')
		{
			*p = *dst;
			p++;
		}
		dst++;
	}
	p = arr;
	dst = start;
	while (*(p - 1) != '\0')
	{
		*dst = *p;
		p++, dst++;
	}
	return start;
}