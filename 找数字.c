#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//有两个数只出现一次，剩余数均出现两次

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

void find_num(int dst[], size_t size);

int main()
{
	int arr[] = { 1,3,5,7,9,7,5,3,1,4,6,6 };//9和4
	int size = sizeof(arr) / sizeof(arr[0]);
	find_num(arr, size);
	system("pause");
	return 0;
}

void find_num(int dst[], size_t size)
{
	int i = 0;//当做循环变量和计数器
	int flag = 0;//flag作为分组的标志
	int data1 = 0, data2 = 0;
	for (i = 0; i < size; i++)
	{
		flag ^= dst[i];
	}
	i = 0;
	while ((flag & 1) != 1)
	{
		flag = flag >> 1;
		i++;
	}
	flag = 1 << i;
	for (i = 0; i < size; i++)
	{
		if (flag & dst[i])
		{
			data1 ^= dst[i];
		}
		else
		{
			data2 ^= dst[i];
		}
	}
	printf("%d,%d\n", data1, data2);
}