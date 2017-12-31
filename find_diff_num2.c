#define _CRT_SECURE_NO_WARNINGS 1

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//找出这两个数字，编程实现。

#include <stdio.h>
#include <windows.h>

void sort(int arr[], int size);
void find_diff(int arr[], int size);
void print_arr(int arr[], int size);

int main()
{
	int i = 0;
	int arr[] = { 1,5,6,8,9,2,1,6,9,2 };//不同的数字，5和8
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("原数组：");
	print_arr(arr, size);
	sort(arr,size);
	printf("新数组：");
	print_arr(arr, size);
	find_diff(arr, size);
	system("pause");
	return 0;
}

void print_arr(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void sort(int arr[], int size)
{
	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		int j = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				arr[j] ^= arr[j + 1];
				arr[j + 1] ^= arr[j];
				arr[j] ^= arr[j + 1];
			}
		}
	}
}

void find_diff(int arr[], int size)
{
	printf("不同的数:");
	int i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			i += 2;
		}
		else
		{
			printf("%d ",arr[i]);
			i++;
		}
	}
	printf("\n");
}