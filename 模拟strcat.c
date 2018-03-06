#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//Ä£Äâstrcat

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

char* my_strcat(char* dst, char* src);

int main()
{
	char str1[20] = "hello ";
	char str2[] = "world!";
	printf("%s\n",my_strcat(str1, str2));
	system("pause");
	return 0;
}

char* my_strcat(char* dst, char* src)
{
	assert(dst);
	assert(src);
	char* start = dst;
	while (*start)
	{
		start++;
	}
	while (*(src-1))
	{
		*start = *src;
		start++, src++;
	}
	return dst;
}