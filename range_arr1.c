#define _CRT_SECURE_NO_WARNINGS 1

//调整数组使奇数全部都位于偶数前面。
//题目：
//输入一个整数数组，实现一个函数
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分
//所有偶数位于数组的后半部分
//我的额外扩展：
//将前后两部分用冒泡排序来进行重新排序

#include <stdio.h>
#include <windows.h>

void range(int arr[], int size);

int main()
{
	int i = 0;
	int arr[] = { 5,2,3,10,1,6,7,8,9 };//排序后的序列应为1,3,5,7,9,2,6,8,10
	int size = sizeof(arr) / sizeof(arr[0]);
	range(arr, size);
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	system("pause");
	return 0;
}

void range(int arr[], int size)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int head = 0;
	for (i = 0; i < size; i++)//如果为奇数，前移至arr下标为head的地方，head往后移一个位置
	{
		if (arr[i] % 2 == 1)
		{
			tmp = arr[head];
			arr[head] = arr[i];
			arr[i] = tmp;
			head++;
		}
	}
	for (i = 0; i < head; i++)//冒泡排序（奇数部分）
	{
		for (j = i; j < head; j++)
			if (arr[j] < arr[i])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
	}
	for (i = head; i < size; i++)//冒泡排序（偶数部分）
	{
		for (j = i; j < size; j++)
			if (arr[j] < arr[i])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
	}
}