#define _CRT_SECURE_NO_WARNINGS 1

//���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);

#include <stdio.h>

int main()
{
	int arr[3][3] = { 1,3,4,2,4,5,4,5,6 };
	int i = 0;
	int size = sizeof(arr)/sizeof(arr[0]);
	int num = 10;
	int j = size - 1;
	while(i < size && i >= 0 && j < size && j >= 0)
	{
		if (arr[i][j] > num)
		{
			i++;
		}
		if (arr[i][j] < num)
		{
			j--;
		}
		if (arr[i][j] == num)
		{
			printf("find it!\n");
			system("pause");
			return 0;
		}
	}
	printf("no!\n");
	system("pause");
	return 0;
}