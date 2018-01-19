#define _CRT_SECURE_NO_WARNINGS 1

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
//找出这两个数字，编程实现。

#include <stdio.h>
#include <windows.h>

void sort(int arr[], int size);
void find_diff1(int arr[], int size);
void find_diff2(int arr[], int size);
void print_arr(int arr[], int size);

int main()
{
	int i = 0;
	int arr[] = { 1,5,6,8,9,2,1,6,9,2 };//不同的数字，5和8
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("原数组：");
	print_arr(arr, size);
	sort(arr, size);
	printf("位运算实现：\n");
	find_diff1(arr, size);
	printf("排序实现：\n");
	
	printf("新数组：");
	print_arr(arr, size);
	find_diff2(arr, size);
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

//思路1：位运算法
void find_diff1(int arr[], int size)
{
	int flag = 0;//flag作为分类两个组的依据
	int i = 0;
	int data1 = 0, data2 = 0;
	for (i = 0; i < size; i++)
	{
		flag ^= arr[i];
	}
	i = 0;
	while (flag & 1 != 1)
	{
		flag = flag >> 1;
		i++;
	}
	flag = 1 << i;
	for (i = 0; i < size; i++)
	{
		if ((flag ^ arr[i]) & 1 == 1)
			data1 ^= arr[i];
		else
			data2 ^= arr[i];
	}
	printf("%d %d\n", data1, data2);
}

//思路2：排序法
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

void find_diff2(int arr[], int size)
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