#define _CRT_SECURE_NO_WARNINGS 1

//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//�ҳ����������֣����ʵ�֡�

#include <stdio.h>
#include <windows.h>

void sort(int arr[], int size);
void find_diff1(int arr[], int size);
void find_diff2(int arr[], int size);
void print_arr(int arr[], int size);

int main()
{
	int i = 0;
	int arr[] = { 1,5,6,8,9,2,1,6,9,2 };//��ͬ�����֣�5��8
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("ԭ���飺");
	print_arr(arr, size);
	sort(arr, size);
	printf("λ����ʵ�֣�\n");
	find_diff1(arr, size);
	printf("����ʵ�֣�\n");
	
	printf("�����飺");
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

//˼·1��λ���㷨
void find_diff1(int arr[], int size)
{
	int flag = 0;//flag��Ϊ���������������
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

//˼·2������
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
	printf("��ͬ����:");
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