#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <Windows.h>

int FindMostNum(int dst[], int size);

int main()
{
	int arr[100] = { 0 };
	int size = 0, i = 0;
	scanf("%d", &size);
	for (i; i < size; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("%d\n", FindMostNum(arr, size));
	system("pause");
	return 0;
}

int FindMostNum(int dst[], int size)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0; i < size / 2; i++)
	{
		count = 0;
		for (j = i; j < size; j++)
		{
			if (dst[j] == dst[i])
			{
				count++;
			}
			if (count == size / 2)
			{
				return dst[i];
			}
		}
	}
	return 0;
}