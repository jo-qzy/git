#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int FindDiff(int arr[], int size);

int main()
{
	int arr[] = { 1, 2, 2, 1, 5, 4, 3, 4, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", FindDiff(arr, size));
	system("pause");
	return 0;
}

int FindDiff(int arr[], int size)
{
	int tmp = 0;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		tmp = tmp^arr[i];//��ͬ�������Ϊ0�������������ͬ����������Ϊ0
	}
	return tmp;
}