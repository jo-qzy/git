#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//÷±Ω”≤Â»Î≈≈–Ú

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

void direct_insert(int arr[], size_t size);

int main()
{
	int a[10] = { 5,10,7,8,6,4,3,1,2,9 };
	int size = sizeof(a) / sizeof(a[0]);
	int i = 0;
	direct_insert(a, size);
	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

void direct_insert(int arr[],size_t size)
{
	int i = 0, j = 0, k =0;
	int tmp;
	for (i = 0; i < size; i++)
	{
		tmp = arr[i];
		for (j = 0; j < i; j++)
		{
			if (tmp <= arr[j])
			{
				for (k = i; k > j; k--)
				{
					arr[k] = arr[k - 1];
				}
				arr[j] = tmp;
				break;
			}
		}
	}
}