#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)

//��������ֻ����һ�Σ�ʣ��������������

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <assert.h>
#include <stdarg.h>

void find_num(int dst[], size_t size);

int main()
{
	int arr[] = { 1,3,5,7,9,7,5,3,1,4,6,6 };//9��4
	int size = sizeof(arr) / sizeof(arr[0]);
	find_num(arr, size);
	system("pause");
	return 0;
}

void find_num(int dst[], size_t size)
{
	int i = 0;//����ѭ�������ͼ�����
	int flag = 0;//flag��Ϊ����ı�־
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