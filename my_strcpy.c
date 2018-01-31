#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//Ä£Äâstrcpy

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>

char* my_strcpy(char* dst, const char* src);

int main()
{
	char* src = "abc123";
	char arr[10] = { 0 };
	printf("%s\n", my_strcpy(arr, src));
	system("pause");
	return 0;
}

char* my_strcpy(char* dest, const char* src)
{
	assert(dest);
	assert(src);
	char* ret = dest;
	while (*dest++ = *src++)
	{
	}
	return ret;
}