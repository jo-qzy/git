#define _CRT_SECURE_NO_WARNINGS 1

//��������ʹ����ȫ����λ��ż��ǰ�档
//��Ŀ��
//����һ���������飬ʵ��һ������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿��
//����ż��λ������ĺ�벿��
//�ҵĶ�����չ��
//��ǰ����������ð��������������������

#include <stdio.h>
#include <windows.h>

void range(int arr[], int size);

int main()
{
	int i = 0;
	int arr[] = { 5,2,3,10,1,6,7,8,9 };//����������ӦΪ1,3,5,7,9,2,6,8,10
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
	for (i = 0; i < size; i++)//���Ϊ������ǰ����arr�±�Ϊhead�ĵط���head������һ��λ��
	{
		if (arr[i] % 2 == 1)
		{
			tmp = arr[head];
			arr[head] = arr[i];
			arr[i] = tmp;
			head++;
		}
	}
	for (i = 0; i < head; i++)//ð�������������֣�
	{
		for (j = i; j < head; j++)
			if (arr[j] < arr[i])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
	}
	for (i = head; i < size; i++)//ð������ż�����֣�
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