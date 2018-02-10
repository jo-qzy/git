#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//÷±Ω”≤Â»Î≈≈–Ú

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

void direct_sort(int dst[], int size);

int main()
{
	int arr[10] = { 5,9,8,2,4,6,3,1,10,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	direct_sort(arr, size);
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
void direct_sort(int dst[], int size)
{
	int i = 0, j = 0;
	int tmp = 0, flag = 0;
	for (i = 0; i < size; i++)
	{
		flag = i;
		for (j = i; j < size; j++)
		{
			if (dst[j] < dst[flag])
			{
				flag = j;
			}
		}
		tmp = dst[flag];
		while (flag > i)
		{
			dst[flag] = dst[flag - 1];
			flag--;
		}
		dst[i] = tmp;
	}
}