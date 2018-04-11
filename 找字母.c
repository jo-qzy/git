#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <Windows.h>

int Find_Char(const char* dst, int k);

int main()
{
	char arr[100] = { 0 };
	int k = 0;
	scanf("%s %d", arr, &k);
	printf("%c",(char)Find_Char(arr, k));
	system("pause");
	return 0;
}

int Find_Char(const char* dst, int k)
{
	char* start = dst;
	int size = strlen(dst);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		int j = 0;
		for (j = i + 1; j < size; j++)
		{
			if (*(start + i) == *(start + j))
			{
				k--;
			}
			if (k == 1)
			{
				return *(start + i);
			}
		}
	}
	return -1;
}